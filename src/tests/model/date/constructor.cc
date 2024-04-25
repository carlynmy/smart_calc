#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

#include "../../../model/date/date.h"
#include "../../test.h"

struct TestDateConstructorData {
  int day;
  int month;
  size_t year;
  std::string str;
  std::string delim;
};

struct TestDateConstructorDataException {
  int day;
  int month;
  size_t year;
};

class TestDateConstructor : public testing::TestWithParam<int> {
 public:
  static inline int count_ = 17;
  static inline TestDateConstructorData test_data_[] = {
      {1, 1, 0, "01/01/0", "/"},
      {1, 12, 0, "01/12/0", "/"},
      {5, 5, 1234, "05/05/1234", "/"},
      {5, 5, 12341242352, "05/05/12341242352", "/"},
      {1, 12, 2022, "01/12/2022", "/"},
      {31, 12, 2022, "31/12/2022", "/"},
      {30, 12, 2022, "30/12/2022", "/"},
      {31, 1, 2022, "31/01/2022", "/"},
      {30, 1, 2022, "30/01/2022", "/"},
      {5, 9, 2022, "05/09/2022", "/"},
      {28, 2, 2022, "28/02/2022", "/"},
      {29, 2, 2024, "29/02/2024", "/"},
      {28, 2, 2100, "28/02/2100", "/"},
      {29, 2, 2400, "29/02/2400", "/"},
      {30, 12, 2022, "30-12-2022", "-"},
      {30, 12, 2022, "30.12.2022", "."},
      {30, 12, 2022, "30bobabi bob12bobabi bob2022", "bobabi bob"}};
};

class TestDateConstructorException : public testing::TestWithParam<int> {
 public:
  static inline int count_ = 8;
  static inline TestDateConstructorDataException test_data_[] = {
      {1, 13, 2022},  {1, 0, 2022},  {0, 12, 0},    {0, 12, 2022},
      {32, 12, 2022}, {31, 4, 2022}, {29, 2, 2022}, {29, 2, 2100}};
};

class TestDateConstructorString : public testing::TestWithParam<int> {
 public:
  static inline int count_ = 16;
  static inline TestDateConstructorData test_data_[] = {
      {1, 1, 0, "01/01/0", "/"},
      {1, 12, 0, "01/12/0", "/"},
      {5, 5, 1234, "05/05/1234", "/"},
      {5, 5, 12341242352, "05/05/012341242352", "/"},
      {1, 12, 2022, "01/12/2022", "/"},
      {31, 12, 2022, "31/12/2022", "/"},
      {30, 12, 2022, "30/12/2022", "/"},
      {31, 1, 2022, "31/01/2022", "/"},
      {30, 1, 2022, "30/1/2022", "/"},
      {5, 9, 2022, "05/09/2022", "/"},
      {28, 2, 2022, "28/02/2022", "/"},
      {28, 2, 2022, "28/2/2022", "/"},
      {28, 2, 2022, "28/00002/2022", "/"},
      {29, 2, 2024, "29/02/2024", "/"},
      {28, 2, 2100, "28/02/2100", "/"},
      {29, 2, 2400, "29/02/2400", "/"}};
};

class TestDateConstructorStringException : public testing::TestWithParam<int> {
 public:
  static inline int count_ = 14;
  static inline std::string test_data_[]{
      "1/13/2022",  "1/0/2022",   "0/12/0",     "0/12/2022",
      "32/12/2022", "31/04/2022", "29/2/2022",  "29/2/2100",

      "1/1g/",      "gs/2/3",     "1341234123", "",
      "asfasfasf",  "    //0"};
};

TEST(TestDateConstructor, Default) {
  s21::Date date(1, 1, 1970);

  ASSERT_EQ(date.GetDay(), 1);
  ASSERT_EQ(date.GetMonth(), static_cast<s21::Date::Months>(1));
  ASSERT_EQ(date.GetYear(), 1970);

  date.SetDelim("/");
  ASSERT_EQ(date.ToString(), "01/01/1970");
}

TEST_P(TestDateConstructor, Param) {
  int num_test = this->GetParam();
  TestDateConstructorData& data = TestDateConstructor::test_data_[num_test];

  s21::Date date(data.day, data.month, data.year);

  ASSERT_EQ(date.GetDay(), data.day);
  ASSERT_EQ(date.GetMonth(), static_cast<s21::Date::Months>(data.month));
  ASSERT_EQ(date.GetYear(), data.year);

  date.SetDelim(data.delim);
  ASSERT_EQ(date.ToString(), data.str);
}

TEST_P(TestDateConstructor, ParamWithMonthOverload) {
  int num_test = this->GetParam();
  TestDateConstructorData& data = TestDateConstructor::test_data_[num_test];

  s21::Date date(data.day, static_cast<s21::Date::Months>(data.month),
                 data.year);

  ASSERT_EQ(date.GetDay(), data.day);
  ASSERT_EQ(date.GetMonth(), static_cast<s21::Date::Months>(data.month));
  ASSERT_EQ(date.GetYear(), data.year);

  date.SetDelim(data.delim);
  ASSERT_EQ(date.ToString(), data.str);
}

TEST_P(TestDateConstructor, Copy) {
  int num_test = this->GetParam();
  TestDateConstructorData& data = TestDateConstructor::test_data_[num_test];

  s21::Date date_tmp(data.day, data.month, data.year);
  s21::Date date(date_tmp);

  ASSERT_EQ(date.GetDay(), data.day);
  ASSERT_EQ(date.GetMonth(), static_cast<s21::Date::Months>(data.month));
  ASSERT_EQ(date.GetYear(), data.year);

  date.SetDelim(data.delim);
  ASSERT_EQ(date.ToString(), data.str);
}

TEST_P(TestDateConstructor, Move) {
  int num_test = this->GetParam();
  TestDateConstructorData& data = TestDateConstructor::test_data_[num_test];

  s21::Date date_tmp(data.day, data.month, data.year);
  s21::Date date(std::move(date_tmp));

  ASSERT_EQ(date.GetDay(), data.day);
  ASSERT_EQ(date.GetMonth(), static_cast<s21::Date::Months>(data.month));
  ASSERT_EQ(date.GetYear(), data.year);

  date.SetDelim(data.delim);
  ASSERT_EQ(date.ToString(), data.str);
}

TEST_P(TestDateConstructor, OperatorCopy) {
  int num_test = this->GetParam();
  TestDateConstructorData& data = TestDateConstructor::test_data_[num_test];

  s21::Date date_tmp(data.day, data.month, data.year);
  s21::Date date;
  date = date_tmp;

  ASSERT_EQ(date.GetDay(), data.day);
  ASSERT_EQ(date.GetMonth(), static_cast<s21::Date::Months>(data.month));
  ASSERT_EQ(date.GetYear(), data.year);

  date.SetDelim(data.delim);
  ASSERT_EQ(date.ToString(), data.str);
}

TEST_P(TestDateConstructor, OperatorMove) {
  int num_test = this->GetParam();
  TestDateConstructorData& data = TestDateConstructor::test_data_[num_test];

  s21::Date date_tmp(data.day, data.month, data.year);
  s21::Date date;
  date = std::move(date_tmp);

  ASSERT_EQ(date.GetDay(), data.day);
  ASSERT_EQ(date.GetMonth(), static_cast<s21::Date::Months>(data.month));
  ASSERT_EQ(date.GetYear(), data.year);

  date.SetDelim(data.delim);
  ASSERT_EQ(date.ToString(), data.str);
}

TEST_P(TestDateConstructorException, Param) {
  int num_test = this->GetParam();
  TestDateConstructorDataException& data =
      TestDateConstructorException::test_data_[num_test];

  ASSERT_THROW(s21::Date date(data.day, data.month, data.year),
               std::logic_error);
}

TEST_P(TestDateConstructorString, String) {
  int num_test = this->GetParam();
  TestDateConstructorData& data =
      TestDateConstructorString::test_data_[num_test];

  s21::Date date(data.str);

  ASSERT_EQ(date.GetDay(), data.day);
  ASSERT_EQ(date.GetMonth(), static_cast<s21::Date::Months>(data.month));
  ASSERT_EQ(date.GetYear(), data.year);
}

TEST_P(TestDateConstructorStringException, String) {
  int num_test = this->GetParam();
  std::string& data = TestDateConstructorStringException::test_data_[num_test];

  ASSERT_THROW(s21::Date date(data), std::logic_error);
}

INSTANTIATE_TEST_SUITE_P(My, TestDateConstructor,
                         testing::Range(0, TestDateConstructor::count_));
INSTANTIATE_TEST_SUITE_P(My, TestDateConstructorException,
                         testing::Range(0,
                                        TestDateConstructorException::count_));
INSTANTIATE_TEST_SUITE_P(My, TestDateConstructorString,
                         testing::Range(0, TestDateConstructorString::count_));
INSTANTIATE_TEST_SUITE_P(
    My, TestDateConstructorStringException,
    testing::Range(0, TestDateConstructorStringException::count_));