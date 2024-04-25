#include <gtest/gtest.h>

#include <cstddef>
#include <stdexcept>

#include "../../../model/credit/credit.h"
#include "../../test.h"

struct TestCreditData {
  double sum;
  double rate;
  s21::Credit::TimeUnit time_unit;
  size_t time_unit_count;
  s21::Credit::CreditTypes credit_type;
  double ex_ans_month_pay;
  double ex_ans_over_pay;
  double ex_ans_total_pay;
};

class TestCreditCommon : public testing::TestWithParam<int> {
 public:
  static const inline s21::Credit::TimeUnit kMonth = s21::Credit::kUnitMonth;
  static const inline s21::Credit::TimeUnit kYear = s21::Credit::kUnitYear;
  static const inline s21::Credit::CreditTypes kAnnuit = s21::Credit::kAnnuity;
  static const inline s21::Credit::CreditTypes kDiffir =
      s21::Credit::kDifferentiated;

  static inline int count_ = 34;
  static inline TestCreditData test_data_[] = {
      {1000, 10, kMonth, 12, kAnnuit, 87.92, 55.04, 1055.04},
      {50, 10, kMonth, 12, kAnnuit, 4.4, 2.8, 52.8},
      {1000000000000, 10, kMonth, 12, kAnnuit, 87915887230.01, 54990646760.12,
       1054990646760.12},
      {1, 10, kMonth, 12, kAnnuit, 0.09, 0.08, 1.08},
      {0.1, 10, kMonth, 12, kAnnuit, 0.01, 0.02, 0.12},
      {1000, 1, kMonth, 12, kAnnuit, 83.79, 5.48, 1005.48},
      {1000, 0.01, kMonth, 12, kAnnuit, 83.34, 0.08, 1000.08},
      {1000, 0, kMonth, 12, kAnnuit, 83.33, 0, 1000},
      {1000, 999, kMonth, 12, kAnnuit, 833.08, 8996.96, 9996.96},
      {1000, 10, kMonth, 6, kAnnuit, 171.56, 29.36, 1029.36},
      {1000, 10, kMonth, 24, kAnnuit, 46.14, 107.36, 1107.36},
      {1000, 10, kMonth, 1, kAnnuit, 1008.33, 8.33, 1008.33},
      {1000, 10, kMonth, 3, kAnnuit, 338.90, 16.70, 1016.70},
      {1000, 10, kMonth, 36, kAnnuit, 32.27, 161.72, 1161.72},
      {1000, 10, kYear, 3, kAnnuit, 32.27, 161.72, 1161.72},
      {1000, 10, kYear, 1, kAnnuit, 87.92, 55.04, 1055.04},
      {1000, 10, kYear, 50, kAnnuit, 8.39, 4034, 5034},

      {1000, 10, kMonth, 12, kDiffir, 83.33, 54.17, 1054.17},
      {50, 10, kMonth, 12, kDiffir, 4.17, 2.71, 52.71},
      {1000000000000, 10, kMonth, 12, kDiffir, 83333333333.33, 54166666666.67,
       1054166666666.67},
      {1, 10, kMonth, 12, kDiffir, 0.08, 0.05, 1.05},
      {0.1, 10, kMonth, 12, kDiffir, 0.01, 0.01, 0.11},
      {1000, 1, kMonth, 12, kDiffir, 83.33, 5.42, 1005.42},
      {1000, 0.01, kMonth, 12, kDiffir, 83.33, 0.05, 1000.05},
      {1000, 0, kMonth, 12, kDiffir, 83.33, 0, 1000},
      {1000, 999, kMonth, 12, kDiffir, 83.33, 5411.25, 6411.25},
      {1000, 10, kMonth, 6, kDiffir, 166.67, 29.17, 1029.17},
      {1000, 10, kMonth, 24, kDiffir, 41.67, 104.17, 1104.17},
      {1000, 10, kMonth, 1, kDiffir, 1000, 8.33, 1008.33},
      {1000, 10, kMonth, 3, kDiffir, 333.33, 16.67, 1016.67},
      {1000, 10, kMonth, 36, kDiffir, 27.78, 154.17, 1154.17},
      {1000, 10, kYear, 3, kDiffir, 27.78, 154.17, 1154.17},
      {1000, 10, kYear, 1, kDiffir, 83.33, 54.17, 1054.17},
      {1000, 10, kYear, 50, kDiffir, 1.67, 2504.17, 3504.17}};
};

class TestCreditExcept : public testing::TestWithParam<int> {
 public:
  static const inline s21::Credit::TimeUnit kMonth = s21::Credit::kUnitMonth;
  static const inline s21::Credit::TimeUnit kYear = s21::Credit::kUnitYear;
  static const inline s21::Credit::CreditTypes kAnnuit = s21::Credit::kAnnuity;
  static const inline s21::Credit::CreditTypes kDiffir =
      s21::Credit::kDifferentiated;

  static inline int count_ = 5;
  static inline TestCreditData test_data_[] = {
      {0, 10, kMonth, 12, kAnnuit, 87.92, 55.04, 1055.04},
      {-100, 10, kMonth, 12, kAnnuit, 87.92, 55.04, 1055.04},
      {1000, -10, kMonth, 12, kAnnuit, 87.92, 55.04, 1055.04},
      {1000, 10, kMonth, 0, kAnnuit, 87.92, 55.04, 1055.04},
      {1000, 10, kYear, 0, kAnnuit, 87.92, 55.04, 1055.04}};
};

TEST_P(TestCreditCommon, Common) {
  int num_test = this->GetParam();
  TestCreditData& data = TestCreditCommon::test_data_[num_test];

  s21::Credit credit(data.sum, data.rate, data.time_unit, data.time_unit_count,
                     data.credit_type);
  credit.Calc();

  double ans_month_pay = credit.GetAnswerMonthPay();
  double ans_over_pay = credit.GetAnswerOverPay();
  double ans_total_pay = credit.GetAnswerTotalPay();

  ASSERT_LE(abs(data.ex_ans_month_pay - ans_month_pay), 1);
  ASSERT_LE(abs(data.ex_ans_over_pay - ans_over_pay), 1);
  ASSERT_LE(abs(data.ex_ans_total_pay - ans_total_pay), 1);
}

TEST_P(TestCreditExcept, Common) {
  int num_test = this->GetParam();
  TestCreditData& data = TestCreditExcept::test_data_[num_test];

  s21::Credit credit(data.sum, data.rate, data.time_unit, data.time_unit_count,
                     data.credit_type);

  ASSERT_THROW(credit.Calc(), std::logic_error);
}

INSTANTIATE_TEST_SUITE_P(My, TestCreditCommon,
                         testing::Range(0, TestCreditCommon::count_));

INSTANTIATE_TEST_SUITE_P(My, TestCreditExcept,
                         testing::Range(0, TestCreditExcept::count_));
