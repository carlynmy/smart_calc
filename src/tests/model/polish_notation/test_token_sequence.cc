#include <gtest/gtest.h>

#include <cmath>

#include "../../../model/polish_notation/polish_notation.h"
#include "../../test.h"
#include "test_polish_notation.h"

class TestPolishNotationTokenSequence : public TestPolishNotation {
 public:
  static inline int count_ = 57;
  static inline TestPolishNotationData test_data_[] = {{"3", 3},
                                                       {"pi", M_PI},
                                                       {"(3)", 3},
                                                       {"sinpi", 0},
                                                       {"-pi", -M_PI},

                                                       {"3pi", 3 * M_PI},
                                                       {"3 3", 3 * 3},
                                                       {"3(pi)", 3 * M_PI},
                                                       {"(3)", 3},
                                                       {"3sin0", 0},
                                                       {"3+3", 6},
                                                       {"x!", 1},

                                                       {"pipi", M_PI* M_PI},
                                                       {"pi3", M_PI * 3},
                                                       {"pi(pi)", M_PI* M_PI},
                                                       {"(pi)", M_PI},
                                                       {"picos0", M_PI},
                                                       {"pi+pi", 2 * M_PI},
                                                       {"x!", 1},

                                                       {"(3)", 3},
                                                       {"(pi)", M_PI},
                                                       {"((3)pi)", 3 * M_PI},
                                                       {"(-3)", -3},
                                                       {"(sin0)", 0},

                                                       {"(3)", 3},
                                                       {"(3)3", 3 * 3},
                                                       {"(3)pi", 3 * M_PI},
                                                       {"(2+3)(3-1)", 10},
                                                       {"(2+(3))", 5},
                                                       {"(2)sin0", 0},
                                                       {"(2)+3", 5},
                                                       {"(1+2)!", 6},

                                                       {"sin0", 0},
                                                       {"sinpi", 0},
                                                       {"sin(2 - 2)", 0},
                                                       {"sincos(pi/2)", 0},
                                                       {"sin-pi", 0},

                                                       {"-0", 0},
                                                       {"-pi", -M_PI},
                                                       {"-(3 - 2)", -1},
                                                       {"-cos(pi)", 1},
                                                       {"--pi", M_PI},
                                                       {"2sin+pi", 0},
                                                       {"2(-+3)", -6},

                                                       {"1+1", 2},
                                                       {"1+pi", 1 + M_PI},
                                                       {"1+(1+2)", 4},
                                                       {"1+sin0", 1},

                                                       {"1!", 1},
                                                       {"1!3", 3},
                                                       {"1!pi", M_PI},
                                                       {"3!pi", 6 * M_PI},
                                                       {"3!(1+2)", 18},
                                                       {"(3!)", 6},
                                                       {"3!sin(pi/2)", 6},
                                                       {"3!+2", 8},
                                                       {"3!!", 720}};
};

class TestPolishNotationTokenSequenceException : public TestPolishNotation {
 public:
  static inline int count_ = 31;
  static inline TestPolishNotationExceptionTranslatorData test_data_[] = {
      {"", {"", 0, 0}},
      {"b", {"", 0, 1}},
      {"ssindaf", {"", 0, 7}},
      {"   \t\t\n   aff + 2", {"", 9, 3}},
      {"sincosb", {"", 6, 1}},
      {"2pi*3coc(pi)", {"", 5, 3}},
      {"2pi bebra", {"", 4, 5}},
      {"    \t\t \t ", {"", 0, 9}},
      {"pipipipipupipi", {"", 8, 6}},
      {"si n(pi)", {"", 0, 2}},

      {")pi", {"", 0, 1}},
      {"*4", {"", 0, 1}},
      {"!4", {"", 0, 1}},
      {"pi(", {"", 2, 1}},
      {"pi()", {"", 2, 2}},
      {"(*2", {"", 0, 2}},
      {"(!2)", {"", 0, 2}},
      {"2sin", {"", 1, 3}},
      {"2(sin)", {"", 2, 4}},
      {"2sin!pi", {"", 1, 4}},
      {"2(-", {"", 2, 1}},
      {"2(-)", {"", 2, 2}},
      {"2(-!pi)", {"", 2, 2}},
      {"3+", {"", 1, 1}},
      {"(3+)", {"", 2, 2}},
      {"3**3", {"", 1, 2}},
      {"3*!3", {"", 1, 2}},

      {"2+ ) 3", {"", 1, 3}},
      {"3 + (3+8", {"", 4, 4}},
      {"(2+1))", {"", 0, 6}},
      {"2+3(", {"", 3, 1}}};
};

TEST_P(TestPolishNotationTokenSequence, Common) {
  int num_test = this->GetParam();
  TestPolishNotationData& test_data =
      TestPolishNotationTokenSequence::test_data_[num_test];

  polish_notation_.SetExpression(test_data.expr);
  polish_notation_.Translate();
  double res = polish_notation_.Calc();

  ASSERT_LE(std::abs(test_data.res - res), 1E-6);
}

TEST_P(TestPolishNotationTokenSequenceException, Common) {
  int num_test = this->GetParam();
  TestPolishNotationExceptionTranslatorData& test_data =
      TestPolishNotationTokenSequenceException::test_data_[num_test];

  polish_notation_.SetExpression(test_data.expr);

  bool exception_flag = false;
  try {
    polish_notation_.Translate();

  } catch (const s21::InvalidExpr& exception) {
    exception_flag = true;
    ASSERT_EQ(test_data.exception.GetIndexStartErr(),
              exception.GetIndexStartErr());
    ASSERT_EQ(test_data.exception.GetLenErr(), exception.GetLenErr());
  }

  ASSERT_TRUE(exception_flag);
}

INSTANTIATE_TEST_SUITE_P(
    My, TestPolishNotationTokenSequence,
    testing::Range(0, TestPolishNotationTokenSequence::count_));

INSTANTIATE_TEST_SUITE_P(
    My, TestPolishNotationTokenSequenceException,
    testing::Range(0, TestPolishNotationTokenSequenceException::count_));
