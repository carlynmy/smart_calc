#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

#include "../../../model/date/date.h"
#include "../../test.h"

struct TestDateSetDateData {
  s21::Date date_prev;
  int day;
  int month;
  int year;
  std::string date_new_str;
};

class TestDateSetDate : public testing::TestWithParam<int> {
 public:
  static inline int count_ = 12;
  static inline TestDateSetDateData test_data_[] = {
      {{1, 1, 1}, 1, 1, 1, "01/01/1"},
      {{1, 1, 1}, 20, 10, 1124, "20/10/1124"},
      {{20, 10, 1124}, 1, 1, 1, "01/01/1"},
      {{4, 4, 4}, 4, 4, 3, "04/04/3"},
      {{4, 4, 4}, 4, 4, 3, "04/04/3"},
      {{4, 4, 4}, 4, 3, 4, "04/03/4"},
      {{4, 4, 4}, 3, 4, 4, "03/04/4"},
      {{4, 4, 4}, 4, 3, 3, "04/03/3"},
      {{4, 4, 4}, 3, 4, 3, "03/04/3"},
      {{1, 1, 1}, 3, 3, 4, "03/03/4"},
      {{9, 9, 1142214}, 10, 10, 1142214, "10/10/1142214"},
      {{10, 10, 1142214}, 9, 9, 1142214, "09/09/1142214"}};
};

class TestDateSetDateException : public testing::TestWithParam<int> {
 public:
  static inline int count_ = 9;
  static inline TestDateSetDateData test_data_[] = {
      {{1, 1, 1}, 1, 0, 1, "01/00/1"},      {{1, 1, 1}, 0, 1, 1, "00/01/1"},
      {{1, 1, 1}, 1, 13, 1, "01/13/1"},     {{1, 1, 1}, 32, 1, 1, "32/01/1"},
      {{1, 1, 1}, 31, 4, 1, "31/04/1"},     {{1, 1, 1}, 29, 2, 1, "29/02/1"},
      {{1, 1, 1}, 29, 2, 100, "29/02/100"}, {{1, 1, 1}, 30, 2, 4, "30/02/4"},
      {{1, 1, 1}, 30, 2, 400, "30/02/400"}};
};

TEST_P(TestDateSetDate, Param) {
  int num_test = this->GetParam();
  TestDateSetDateData& data = TestDateSetDate::test_data_[num_test];

  s21::Date date(data.date_prev);

  date.SetDate(data.day, data.month, data.year);

  ASSERT_EQ(date.GetDay(), data.day);
  ASSERT_EQ(date.GetMonth(), static_cast<s21::Date::Months>(data.month));
  ASSERT_EQ(date.GetYear(), data.year);
}

TEST_P(TestDateSetDate, ParamWithMonthOverload) {
  int num_test = this->GetParam();
  TestDateSetDateData& data = TestDateSetDate::test_data_[num_test];

  s21::Date date(data.date_prev);

  date.SetDate(data.day, static_cast<s21::Date::Months>(data.month), data.year);
  ASSERT_EQ(date.GetDay(), data.day);
  ASSERT_EQ(date.GetMonth(), static_cast<s21::Date::Months>(data.month));
  ASSERT_EQ(date.GetYear(), data.year);
}

TEST_P(TestDateSetDate, String) {
  int num_test = this->GetParam();
  TestDateSetDateData& data = TestDateSetDate::test_data_[num_test];

  s21::Date date(data.date_prev);

  date.SetDate(data.date_new_str);

  ASSERT_EQ(date.GetDay(), data.day);
  ASSERT_EQ(date.GetMonth(), static_cast<s21::Date::Months>(data.month));
  ASSERT_EQ(date.GetYear(), data.year);
}

TEST_P(TestDateSetDateException, Param) {
  int num_test = this->GetParam();
  TestDateSetDateData& data = TestDateSetDateException::test_data_[num_test];

  s21::Date date(data.date_prev);

  ASSERT_THROW(date.SetDate(data.day, data.month, data.year), std::logic_error);
}

TEST_P(TestDateSetDateException, ParamWithMonthOverload) {
  int num_test = this->GetParam();
  TestDateSetDateData& data = TestDateSetDateException::test_data_[num_test];

  s21::Date date(data.date_prev);

  ASSERT_THROW(
      date.SetDate(data.day, static_cast<s21::Date::Months>(data.month),
                   data.year),
      std::logic_error);
}

TEST_P(TestDateSetDateException, String) {
  int num_test = this->GetParam();
  TestDateSetDateData& data = TestDateSetDateException::test_data_[num_test];

  s21::Date date(data.date_prev);

  ASSERT_THROW(date.SetDate(data.date_new_str), std::logic_error);
}

INSTANTIATE_TEST_SUITE_P(My, TestDateSetDate,
                         testing::Range(0, TestDateSetDate::count_));
INSTANTIATE_TEST_SUITE_P(My, TestDateSetDateException,
                         testing::Range(0, TestDateSetDateException::count_));
