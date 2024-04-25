
#include <gtest/gtest.h>

#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <string>

#include "../../../model/date/date.h"
#include "../../test.h"

struct TestDateCalculatorData {
  s21::Date date_a;
  ssize_t day;
  ssize_t month;
  ssize_t year;
  s21::Date date_res;
};

class TestDateCalculator : public testing::TestWithParam<int> {
 public:
  static inline int count_ = 27;
  static inline TestDateCalculatorData test_data_[] = {
      {{1, 1, 1}, 1, 0, 0, {2, 1, 1}},
      {{1, 1, 1}, 11, 0, 0, {12, 1, 1}},
      {{20, 1, 1}, 20, 0, 0, {9, 2, 1}},
      {{20, 4, 1}, 20, 0, 0, {10, 5, 1}},
      {{20, 2, 1}, 20, 0, 0, {12, 3, 1}},
      {{20, 2, 4}, 20, 0, 0, {11, 3, 4}},
      {{20, 2, 100}, 20, 0, 0, {12, 3, 100}},
      {{20, 2, 400}, 20, 0, 0, {11, 3, 400}},
      {{1, 1, 1}, 0, 1, 0, {1, 2, 1}},
      {{1, 1, 1}, 0, 11, 0, {1, 12, 1}},
      {{1, 10, 1}, 0, 2, 0, {1, 12, 1}},
      {{1, 10, 1}, 0, 3, 0, {1, 1, 2}},
      {{20, 12, 1}, 20, 0, 0, {9, 1, 2}},
      {{1, 1, 1}, 0, 13, 0, {1, 2, 2}},
      {{1, 1, 1}, 0, 121, 0, {1, 2, 11}},
      {{1, 1, 1}, 31, 0, 0, {1, 2, 1}},
      {{1, 2, 1}, 31, 0, 0, {4, 3, 1}},
      {{1, 2, 4}, 31, 0, 0, {3, 3, 4}},
      {{1, 2, 100}, 31, 0, 0, {4, 3, 100}},
      {{1, 2, 400}, 31, 0, 0, {3, 3, 400}},
      {{1, 1, 1}, 365, 0, 0, {1, 1, 2}},
      {{1, 1, 4}, 366, 0, 0, {1, 1, 5}},
      {{1, 1, 100}, 365, 0, 0, {1, 1, 101}},
      {{1, 1, 400}, 366, 0, 0, {1, 1, 401}},
      {{1, 1, 4}, 365, 0, 0, {31, 12, 4}},
      {{31, 12, 4}, 1, 0, 0, {1, 1, 5}},
      {{1, 1, 0}, 0, 0, 124, {1, 1, 124}}};
};

TEST_P(TestDateCalculator, Add) {
  int num_test = this->GetParam();
  TestDateCalculatorData& data = TestDateCalculator::test_data_[num_test];

  s21::Date date_a(data.date_a);
  s21::Date date_res(data.date_res);

  date_a.Add(data.day, data.month, data.year);

  ASSERT_EQ(static_cast<int>(date_a.GetDay()),
            static_cast<int>(date_res.GetDay()));
  ASSERT_EQ(static_cast<int>(date_a.GetMonth()),
            static_cast<int>(date_res.GetMonth()));
  ASSERT_EQ(static_cast<int>(date_a.GetYear()),
            static_cast<int>(date_res.GetYear()));
}

TEST_P(TestDateCalculator, AddNeg) {
  int num_test = this->GetParam();
  TestDateCalculatorData& data = TestDateCalculator::test_data_[num_test];

  s21::Date date_a(data.date_res);
  s21::Date date_res(data.date_a);

  date_a.Add(-data.day, -data.month, -data.year);

  ASSERT_EQ(static_cast<int>(date_a.GetDay()),
            static_cast<int>(date_res.GetDay()));
  ASSERT_EQ(static_cast<int>(date_a.GetMonth()),
            static_cast<int>(date_res.GetMonth()));
  ASSERT_EQ(static_cast<int>(date_a.GetYear()),
            static_cast<int>(date_res.GetYear()));
}

TEST_P(TestDateCalculator, Sub) {
  int num_test = this->GetParam();
  TestDateCalculatorData& data = TestDateCalculator::test_data_[num_test];

  s21::Date date_a(data.date_res);
  s21::Date date_res(data.date_a);

  date_a.Sub(data.day, data.month, data.year);

  ASSERT_EQ(static_cast<int>(date_a.GetDay()),
            static_cast<int>(date_res.GetDay()));
  ASSERT_EQ(static_cast<int>(date_a.GetMonth()),
            static_cast<int>(date_res.GetMonth()));
  ASSERT_EQ(static_cast<int>(date_a.GetYear()),
            static_cast<int>(date_res.GetYear()));
}

TEST_P(TestDateCalculator, SubNeg) {
  int num_test = this->GetParam();
  TestDateCalculatorData& data = TestDateCalculator::test_data_[num_test];

  s21::Date date_a(data.date_a);
  s21::Date date_res(data.date_res);

  date_a.Sub(-data.day, -data.month, -data.year);

  ASSERT_EQ(static_cast<int>(date_a.GetDay()),
            static_cast<int>(date_res.GetDay()));
  ASSERT_EQ(static_cast<int>(date_a.GetMonth()),
            static_cast<int>(date_res.GetMonth()));
  ASSERT_EQ(static_cast<int>(date_a.GetYear()),
            static_cast<int>(date_res.GetYear()));
}

TEST(TestDateCalculator, SubUnderflow) {
  s21::Date date_a(4, 4, 4);
  s21::Date date_b(1, 1, 5);
  s21::Date date_res(1, 1, 0);

  ASSERT_THROW(date_a.Sub(date_b.GetDay(), date_b.GetMonth(), date_b.GetYear()),
               std::underflow_error);
}

INSTANTIATE_TEST_SUITE_P(My, TestDateCalculator,
                         testing::Range(0, TestDateCalculator::count_));
