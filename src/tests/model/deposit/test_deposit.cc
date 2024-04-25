#include <gtest/gtest.h>

#include <cstddef>
#include <stdexcept>

#include "../../../model/date/date.h"
#include "../../../model/deposit/deposit.h"
#include "../../test.h"

struct TestDepositData {
  double sum;
  s21::Deposit::PayUnits pay_unit;
  size_t pay_unit_count;
  double rate;
  double tax;
  s21::Date date_start;
  s21::Deposit::PayPeriod pay_period;
  bool capitalisation;
  double ex_answer_rate;
  double ex_answer_tax;
  double ex_answer_sum;
};

class TestDeposit : public testing::TestWithParam<int> {
 public:
  using Deposit = s21::Deposit;

  static const inline Deposit::PayUnits kDay = Deposit::kPayUnitDay;
  static const inline Deposit::PayUnits kMonth = Deposit::kPayUnitMonth;
  static const inline Deposit::PayUnits kYear = Deposit::kPayUnitYear;

  static const inline Deposit::PayPeriod kInDay = Deposit::kPayInDay;
  static const inline Deposit::PayPeriod kInWeek = Deposit::kPayInWeek;
  static const inline Deposit::PayPeriod kInMonth = Deposit::kPayInMonth;
  static const inline Deposit::PayPeriod kInQuart = Deposit::kPayInQuarter;
  static const inline Deposit::PayPeriod kInHalfYear = Deposit::kPayInHalfYear;
  static const inline Deposit::PayPeriod kInYear = Deposit::kPayInYear;
  static const inline Deposit::PayPeriod kInEnd = Deposit::kPayInEnd;

  static const inline s21::Date date1{20, 10, 2020};
  static const inline s21::Date date2{20, 10, 2021};
};

class TestDepositCommon : public TestDeposit {
 public:
  static inline int count_ = 52;
  static inline TestDepositData test_data_[] = {
      {1000, kMonth, 12, 10, 0, date1, kInMonth, 0, 99.73, 0, 1099.73},
      {1000000000, kMonth, 12, 10, 0, date1, kInMonth, 0, 99726775.96, 0,
       1099726775.96},
      {10, kMonth, 12, 10, 0, date1, kInMonth, 0, 1, 0, 11},
      {1, kMonth, 12, 10, 0, date1, kInMonth, 0, 0.1, 0, 1.1},
      {0.1, kMonth, 12, 10, 0, date1, kInMonth, 0, 0, 0, 0.1},
      {1000, kMonth, 12, 50, 0, date1, kInMonth, 0, 498.63, 0, 1498.63},
      {1000, kMonth, 12, 100, 0, date1, kInMonth, 0, 997.26, 0, 1997.26},
      {1000, kMonth, 12, 1, 0, date1, kInMonth, 0, 9.97, 0, 1009.97},
      {1000, kMonth, 12, 0, 0, date1, kInMonth, 0, 0, 0, 1000},
      {1000, kMonth, 12, 999, 0, date1, kInMonth, 0, 9962.70, 0, 10962.70},
      {1000, kMonth, 12, 10, 50, date1, kInMonth, 0, 49.86, 49.86, 1049.86},
      {1000, kMonth, 12, 10, 100, date1, kInMonth, 0, 0, 99.73, 1000},
      {1000, kMonth, 12, 10, 1, date1, kInMonth, 0, 98.73, 1, 1098.73},
      {1000, kMonth, 12, 10, 0, date1, kInMonth, 0, 99.73, 0, 1099.73},
      {1000, kMonth, 12, 10, 1000, date1, kInMonth, 0, -897.57, 997.3, 102.43},
      {1000, kMonth, 12, 10, 0, date1, kInMonth, 0, 100, 0, 1100.00},
      {1000, kMonth, 12, 10, 0, date2, kInMonth, 0, 100, 0, 1100.00},
      {1000, kDay, 365, 10, 0, date2, kInMonth, 0, 100, 0, 1100.00},
      {1000, kDay, 366, 10, 0, date1, kInMonth, 0, 100, 0, 1100.00},
      {1000, kYear, 1, 10, 0, date2, kInMonth, 0, 100, 0, 1100.00},
      {1000, kYear, 1, 10, 0, date1, kInMonth, 0, 99.72, 0, 1099.72},
      {1000, kDay, 1, 10, 0, date1, kInMonth, 0, 0.27, 0, 1000.27},
      {1000, kYear, 50, 10, 0, date1, kInMonth, 0, 4989.61, 0, 5989.61},
      {1000, kMonth, 12, 10, 0, date1, kInMonth, 1, 104.63, 0, 1104.63},
      {1000000000, kMonth, 12, 10, 0, date1, kInMonth, 1, 104638819.03, 0,
       1104638819.03},
      {10, kMonth, 12, 10, 0, date1, kInMonth, 1, 1.04, 0, 11.04},
      {1, kMonth, 12, 10, 0, date1, kInMonth, 1, 0.10, 0, 1.10},
      {0.1, kMonth, 12, 10, 0, date1, kInMonth, 1, 0.01, 0, 0.11},
      {1000, kMonth, 12, 50, 0, date1, kInMonth, 1, 631.62, 0, 1631.62},
      {1000, kMonth, 12, 100, 0, date1, kInMonth, 1, 1611.80, 0, 2611.80},
      {1000, kMonth, 12, 1, 0, date1, kInMonth, 1, 10.04, 0, 1010.04},
      {1000, kMonth, 12, 0, 0, date1, kInMonth, 1, 0, 0, 1000},
      {1000, kMonth, 12, 999, 0, date1, kInMonth, 1, 1443051.07, 0, 1444051.07},
      {1000, kMonth, 12, 10, 50, date1, kInMonth, 1, 52.31, 52.31, 1052.31},
      {1000, kMonth, 12, 10, 100, date1, kInMonth, 1, 0, 104.63, 1000},
      {1000, kMonth, 12, 10, 1, date1, kInMonth, 1, 103.58, 1.05, 1103.58},
      {1000, kMonth, 12, 10, 0, date1, kInMonth, 1, 104.63, 0, 1104.63},
      {1000, kMonth, 12, 10, 1000, date1, kInMonth, 1, -941.749, 1046.3, 58.25},
      {1000, kMonth, 12, 10, 0, date1, kInMonth, 1, 104.63, 0, 1104.63},
      {1000, kMonth, 12, 10, 0, date2, kInMonth, 1, 104.71, 0, 1104.71},
      {1000, kDay, 365, 10, 0, date2, kInMonth, 1, 104.71, 0, 1104.71},
      {1000, kDay, 366, 10, 0, date1, kInMonth, 1, 104.63, 0, 1104.63},
      {1000, kYear, 1, 10, 0, date2, kInMonth, 1, 104.71, 0, 1104.71},
      {1000, kYear, 1, 10, 0, date1, kInMonth, 1, 104.63, 0, 1104.63},
      {1000, kDay, 1, 10, 0, date1, kInMonth, 1, 0.27, 0, 1000.27},
      {1000, kYear, 50, 10, 0, date1, kInMonth, 1, 144358.06, 0, 145358.06},
      {1000, kYear, 2, 10, 0, date1, kInDay, 1, 221.21, 0, 1221.21},
      {1000, kYear, 2, 10, 0, date1, kInWeek, 1, 221.09, 0, 1221.09},
      {1000, kYear, 2, 10, 0, date1, kInQuart, 1, 218.32, 0, 1218.32},
      {1000, kYear, 2, 10, 0, date1, kInHalfYear, 1, 219.28, 0, 1219.28},
      {1000, kYear, 2, 10, 0, date1, kInYear, 1, 209.72, 0, 1209.72},
      {1000, kYear, 2, 10, 0, date1, kInEnd, 1, 199.45, 0, 1199.45}};
};

class TestDepositMoneyIncrease : public TestDeposit {
 public:
  static inline int count_ = 3;
  static inline TestDepositData test_data_[] = {
      {1000, kYear, 2, 10, 0, date1, kInMonth, 0, 352.47, 0, 2352.47},
      {1000, kYear, 2, 10, 0, date1, kInMonth, 1, 384.44, 0, 2384.44},
      {1000, kYear, 2, 10, 0, date1, kInDay, 1, 386.14, 0, 2386.14}};
};

class TestDepositMoneyDecrease : public TestDeposit {
 public:
  static inline int count_ = 3;
  static inline TestDepositData test_data_[] = {
      {1000, kYear, 2, 10, 0, date1, kInMonth, 0, 123.59, 0, 623.59},
      {1000, kYear, 2, 10, 0, date1, kInMonth, 1, 138.11, 0, 638.11},
      {1000, kYear, 2, 10, 0, date1, kInDay, 1, 138.88, 0, 638.88}};
};

class TestDepositMoneyCombo : public TestDeposit {
 public:
  static inline int count_ = 3;
  static inline TestDepositData test_data_[] = {
      {1000, kYear, 2, 10, 0, date1, kInMonth, 0, 414.25, 0, 2914.25},
      {1000, kYear, 2, 10, 0, date1, kInMonth, 1, 447.86, 0, 2947.86},
      {1000, kYear, 2, 10, 0, date1, kInDay, 1, 449.82, 0, 2949.82}};
};

class TestDepositMoneyDecreaseMaximum : public TestDeposit {
 public:
  static inline int count_ = 3;
  static inline TestDepositData test_data_[] = {
      {1000, kYear, 2, 10, 0, date1, kInMonth, 0, 0.27, 0, 0.27},
      {1000, kYear, 2, 10, 0, date1, kInMonth, 1, 0.27, 0, 0.27},
      {1000, kYear, 2, 10, 0, date1, kInDay, 1, 0.27, 0, 0.27}};
};

class TestDepositException : public TestDeposit {
 public:
  static inline int count_ = 7;
  static inline TestDepositData test_data_[] = {
      {-100, kMonth, 12, 10, 0, date1, kInMonth, 0, 99.73, 0, 1099.73},
      {0, kMonth, 12, 10, 0, date1, kInMonth, 0, 99.73, 0, 1099.73},
      {1000, kMonth, 0, 10, 0, date1, kInMonth, 0, 99.73, 0, 1099.73},
      {1000, kDay, 0, 10, 0, date1, kInMonth, 0, 99.73, 0, 1099.73},
      {1000, kYear, 0, 10, 0, date1, kInMonth, 0, 99.73, 0, 1099.73},
      {1000, kMonth, 12, -1, 0, date1, kInMonth, 0, 99.73, 0, 1099.73},
      {1000, kMonth, 12, 10, -5, date1, kInMonth, 0, 99.73, 0, 1099.73}};
};

TEST_P(TestDepositCommon, Common) {
  int num_test = this->GetParam();
  TestDepositData& data = TestDepositCommon::test_data_[num_test];

  s21::Deposit deposit(data.sum, data.pay_unit, data.pay_unit_count, data.rate,
                       data.tax, data.date_start, data.pay_period,
                       data.capitalisation);
  deposit.Calc();

  double answer_rate = deposit.GetAnswerRate();
  double answer_tax = deposit.GetAnswerTax();
  double answer_sum = deposit.GetAnswerSum();

  ASSERT_LE(abs(data.ex_answer_rate - answer_rate), 1);
  ASSERT_LE(abs(data.ex_answer_tax - answer_tax), 1);
  ASSERT_LE(abs(data.ex_answer_sum - answer_sum), 1);
}

TEST_P(TestDepositMoneyIncrease, Common) {
  int num_test = this->GetParam();
  TestDepositData& data = TestDepositMoneyIncrease::test_data_[num_test];

  s21::Deposit deposit(data.sum, data.pay_unit, data.pay_unit_count, data.rate,
                       data.tax, data.date_start, data.pay_period,
                       data.capitalisation);
  deposit.AddIncrease({10, 4, 2021}, 1000);

  deposit.Calc();

  double answer_rate = deposit.GetAnswerRate();
  double answer_tax = deposit.GetAnswerTax();
  double answer_sum = deposit.GetAnswerSum();

  ASSERT_LE(abs(data.ex_answer_rate - answer_rate), 1);
  ASSERT_LE(abs(data.ex_answer_tax - answer_tax), 1);
  ASSERT_LE(abs(data.ex_answer_sum - answer_sum), 1);
}

TEST_P(TestDepositMoneyDecrease, Common) {
  int num_test = this->GetParam();
  TestDepositData& data = TestDepositMoneyDecrease::test_data_[num_test];

  s21::Deposit deposit(data.sum, data.pay_unit, data.pay_unit_count, data.rate,
                       data.tax, data.date_start, data.pay_period,
                       data.capitalisation);
  deposit.AddDecrease({10, 4, 2021}, 500);

  deposit.Calc();

  double answer_rate = deposit.GetAnswerRate();
  double answer_tax = deposit.GetAnswerTax();
  double answer_sum = deposit.GetAnswerSum();

  ASSERT_LE(abs(data.ex_answer_rate - answer_rate), 1);
  ASSERT_LE(abs(data.ex_answer_tax - answer_tax), 1);
  ASSERT_LE(abs(data.ex_answer_sum - answer_sum), 1);
}

TEST_P(TestDepositMoneyCombo, Common) {
  int num_test = this->GetParam();
  TestDepositData& data = TestDepositMoneyCombo::test_data_[num_test];

  s21::Deposit deposit(data.sum, data.pay_unit, data.pay_unit_count, data.rate,
                       data.tax, data.date_start, data.pay_period,
                       data.capitalisation);
  deposit.AddDecrease({10, 4, 2022}, 1000);
  deposit.AddDecrease({10, 10, 2021}, -1000);
  deposit.AddIncrease({10, 4, 2021}, 1000);
  deposit.AddDecrease({10, 4, 2021}, 500);
  deposit.AddIncrease({1, 12, 2021}, 1000);

  deposit.Calc();

  double answer_rate = deposit.GetAnswerRate();
  double answer_tax = deposit.GetAnswerTax();
  double answer_sum = deposit.GetAnswerSum();

  ASSERT_LE(abs(data.ex_answer_rate - answer_rate), 1);
  ASSERT_LE(abs(data.ex_answer_tax - answer_tax), 1);
  ASSERT_LE(abs(data.ex_answer_sum - answer_sum), 1);
}

TEST_P(TestDepositMoneyDecreaseMaximum, Common) {
  int num_test = this->GetParam();
  TestDepositData& data = TestDepositMoneyDecreaseMaximum::test_data_[num_test];

  s21::Deposit deposit(data.sum, data.pay_unit, data.pay_unit_count, data.rate,
                       data.tax, data.date_start, data.pay_period,
                       data.capitalisation);
  deposit.AddDecrease({21, 10, 2020}, 1000);

  deposit.Calc();

  double answer_rate = deposit.GetAnswerRate();
  double answer_tax = deposit.GetAnswerTax();
  double answer_sum = deposit.GetAnswerSum();

  ASSERT_LE(abs(data.ex_answer_rate - answer_rate), 1);
  ASSERT_LE(abs(data.ex_answer_tax - answer_tax), 1);
  ASSERT_LE(abs(data.ex_answer_sum - answer_sum), 1);
}

TEST_P(TestDepositException, Common) {
  int num_test = this->GetParam();
  TestDepositData& data = TestDepositException::test_data_[num_test];

  s21::Deposit deposit(data.sum, data.pay_unit, data.pay_unit_count, data.rate,
                       data.tax, data.date_start, data.pay_period,
                       data.capitalisation);

  ASSERT_THROW(deposit.Calc(), std::logic_error);
}

TEST(TestDepositException, AfterDecreaseNeg) {
  s21::Deposit deposit(1000, s21::Deposit::kPayUnitMonth, 12, 10, 0,
                       {20, 10, 2020}, s21::Deposit::kPayInMonth, 1);

  deposit.AddDecrease({21, 10, 2020}, 100220.27);

  ASSERT_THROW(deposit.Calc(), std::logic_error);
}

INSTANTIATE_TEST_SUITE_P(My, TestDepositCommon,
                         testing::Range(0, TestDepositCommon::count_));

INSTANTIATE_TEST_SUITE_P(My, TestDepositMoneyIncrease,
                         testing::Range(0, TestDepositMoneyIncrease::count_));

INSTANTIATE_TEST_SUITE_P(My, TestDepositMoneyDecrease,
                         testing::Range(0, TestDepositMoneyDecrease::count_));

INSTANTIATE_TEST_SUITE_P(My, TestDepositMoneyCombo,
                         testing::Range(0, TestDepositMoneyCombo::count_));

INSTANTIATE_TEST_SUITE_P(
    My, TestDepositMoneyDecreaseMaximum,
    testing::Range(0, TestDepositMoneyDecreaseMaximum::count_));

INSTANTIATE_TEST_SUITE_P(My, TestDepositException,
                         testing::Range(0, TestDepositException::count_));
