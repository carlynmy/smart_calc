#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

#include "../../../model/date/date.h"
#include "../../test.h"

struct TestDateComparatorData {
  s21::Date date_a;
  s21::Date date_b;
};

class TestDateComparatorLess : public testing::TestWithParam<int> {
 public:
  static inline int count_ = 11;
  static inline TestDateComparatorData test_data_[] = {
      {{9, 10, 2020}, {10, 10, 2020}},  {{10, 1, 2020}, {11, 1, 2020}},
      {{30, 1, 2020}, {31, 1, 2020}},   {{1, 1, 2020}, {1, 2, 2020}},
      {{10, 9, 2020}, {10, 10, 2020}},  {{10, 10, 2019}, {10, 10, 2020}},
      {{11, 9, 2020}, {10, 10, 2020}},  {{10, 1, 2019}, {10, 10, 2020}},
      {{11, 11, 2019}, {10, 10, 2020}}, {{10, 10, 2020}, {1, 1, 2021}},
      {{31, 12, 2019}, {10, 10, 2020}}

  };
};

class TestDateComparatorEq : public testing::TestWithParam<int> {
 public:
  static inline int count_ = 4;
  static inline TestDateComparatorData test_data_[] = {
      {{1, 1, 1}, {1, 1, 1}},
      {{5, 5, 5}, {5, 5, 5}},
      {{11, 8, 0}, {11, 8, 0}},
      {{10, 10, 2020}, {10, 10, 2020}}};
};

TEST_P(TestDateComparatorLess, Common) {
  int num_test = this->GetParam();
  TestDateComparatorData& data = TestDateComparatorLess::test_data_[num_test];

  s21::Date date_a(data.date_a);
  s21::Date date_b(data.date_b);

  ASSERT_TRUE(date_a < date_b);
  ASSERT_TRUE(date_a <= date_b);
  ASSERT_TRUE(date_a != date_b);
  ASSERT_TRUE(!(date_a > date_b));
  ASSERT_TRUE(!(date_a >= date_b));
  ASSERT_TRUE(!(date_a == date_b));

  ASSERT_TRUE(date_b > date_a);
  ASSERT_TRUE(date_b >= date_a);
  ASSERT_TRUE(date_b != date_a);
  ASSERT_TRUE(!(date_b < date_a));
  ASSERT_TRUE(!(date_b <= date_a));
  ASSERT_TRUE(!(date_b == date_a));
}

TEST_P(TestDateComparatorEq, Common) {
  int num_test = this->GetParam();
  TestDateComparatorData& data = TestDateComparatorEq::test_data_[num_test];

  s21::Date date_a(data.date_a);
  s21::Date date_b(data.date_b);

  ASSERT_TRUE(date_a == date_b);
  ASSERT_TRUE(date_a <= date_b);
  ASSERT_TRUE(date_a >= date_b);
  ASSERT_TRUE(!(date_a < date_b));
  ASSERT_TRUE(!(date_a > date_b));
  ASSERT_TRUE(!(date_a != date_b));

  ASSERT_TRUE(date_b == date_a);
  ASSERT_TRUE(date_b <= date_a);
  ASSERT_TRUE(date_b >= date_a);
  ASSERT_TRUE(!(date_b < date_a));
  ASSERT_TRUE(!(date_b > date_a));
  ASSERT_TRUE(!(date_b != date_a));
}

INSTANTIATE_TEST_SUITE_P(My, TestDateComparatorLess,
                         testing::Range(0, TestDateComparatorLess::count_));

INSTANTIATE_TEST_SUITE_P(My, TestDateComparatorEq,
                         testing::Range(0, TestDateComparatorEq::count_));