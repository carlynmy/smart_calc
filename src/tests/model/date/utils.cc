#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

#include "../../../model/date/date.h"
#include "../../test.h"

struct TestDateUtilsData {
  s21::Date date;
  bool is_leap;
  bool is_30_days;
  bool is_31_days;
  uint8_t max_days;
};

class TestDateUtils : public testing::TestWithParam<int> {
 public:
  static inline int count_ = 15;
  static inline TestDateUtilsData test_data_[] = {
      {{1, 1, 1}, false, false, true, 31},
      {{1, 3, 1}, false, false, true, 31},
      {{1, 5, 1}, false, false, true, 31},
      {{1, 7, 1}, false, false, true, 31},
      {{1, 8, 1}, false, false, true, 31},
      {{1, 10, 1}, false, false, true, 31},
      {{1, 12, 1}, false, false, true, 31},
      {{1, 4, 1}, false, true, false, 30},
      {{1, 6, 1}, false, true, false, 30},
      {{1, 9, 1}, false, true, false, 30},
      {{1, 11, 1}, false, true, false, 30},
      {{1, 2, 1}, false, false, false, 28},
      {{1, 2, 4}, true, false, false, 29},
      {{1, 2, 100}, false, false, false, 28},
      {{1, 2, 400}, true, false, false, 29}};
};

TEST_P(TestDateUtils, Utils) {
  int num_test = this->GetParam();
  TestDateUtilsData& data = TestDateUtils::test_data_[num_test];

  s21::Date date(data.date);

  ASSERT_EQ(date.IsLeapYear(), data.is_leap);
  ASSERT_EQ(date.IsMonth30Days(), data.is_30_days);
  ASSERT_EQ(date.IsMonth31Days(), data.is_31_days);
  ASSERT_EQ(date.GetMaxDay(), data.max_days);
}

INSTANTIATE_TEST_SUITE_P(My, TestDateUtils,
                         testing::Range(0, TestDateUtils::count_));
