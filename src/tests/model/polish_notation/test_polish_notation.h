#ifndef SMART_CALC_V_2_TESTS_MODEL_POLISH_NOTATION_TEST_POLISH_NOTATION_H_
#define SMART_CALC_V_2_TESTS_MODEL_POLISH_NOTATION_TEST_POLISH_NOTATION_H_

#include <string>

#include "../../../model/polish_notation/polish_notation.h"

struct TestPolishNotationData {
  std::string expr;
  double res;
};

struct TestPolishNotationExceptionTranslatorData {
  std::string expr;
  s21::InvalidExpr exception;
};

class TestPolishNotation : public testing::TestWithParam<int> {
 public:
  static void SetUpTestSuite() {
    s21::ListVariable list_var;
    list_var.Add({"pi", M_PI});
    list_var.Add({"e", M_E});
    list_var.Add({"x", 0});
    polish_notation_.SetListVariable(list_var);
  }

  static inline s21::PolishNotation polish_notation_{};
};

#endif  // SMART_CALC_V_2_TESTS_MODEL_POLISH_NOTATION_TEST_POLISH_NOTATION_H_
