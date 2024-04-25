#include <gtest/gtest.h>

#include <cmath>

#include "../../../model/operation/operation.h"
#include "../../../model/polish_notation/polish_notation.h"
#include "../../test.h"
#include "test_polish_notation.h"

class TestPolishNotationCalcBase : public TestPolishNotation {
 public:
  static inline int count_ = 141;
  static inline TestPolishNotationData test_data_[] = {
      {"1.1 .3", 0.33},
      {"1.1.3", 0.33},

      {"0", 0},
      {"5", 5},
      {"123.424", 123.424},
      {"0.124", 0.124},
      {".233", 0.233},
      {"123.456E2", 12345.6},
      {"123.456E02", 12345.6},
      {"123.456E+2", 12345.6},
      {"123.456E+02", 12345.6},
      {"123.456E-2", 1.23456},
      {"123.456E-02", 1.23456},
      {"123.456E0", 123.456},
      {"123.456E-00", 123.456},
      {".123E-02", 0.00123},
      {"e", M_E},
      {"pi", M_PI},

      {"+0", 0},
      {"+5", 5},
      {"+e", M_E},
      {"-0", 0},
      {"-5.2", -5.2},
      {"-pi", -M_PI},
      {"-123.424", -123.424},
      {"-0.124", -0.124},
      {"-.233", -0.233},
      {"-123.456E2", -12345.6},
      {"-123.456E02", -12345.6},
      {"-123.456E+2", -12345.6},
      {"-123.456E+02", -12345.6},
      {"-123.456E-2", -1.23456},
      {"-123.456E-02", -1.23456},
      {"-123.456E0", -123.456},
      {"-123.456E-00", -123.456},
      {"-.123E-02", -0.00123},

      {"5+0", 5},
      {"5-0", 5},
      {"1+3", 4},
      {"2.2+e", 2.2 + M_E},
      {"4-pi", 4 - M_PI},
      {"4-(3-2)", 3},

      {"5*0", 0},
      {"5*1", 5},
      {"0*5", 0},
      {"1*5", 5},
      {"5*2", 10},
      {"5*e", 5 * M_E},
      {"5*(-1)", -5},
      {"-5*(-1)", 5},
      {"-5*(-0)", 0},

      {"5/5", 1},
      {"5/1", 5},
      {"5/(-1)", -5},
      {"-5/5", -1},
      {"5/2", 2.5},
      {"5/e", 5 / M_E},
      {"0/123", 0},
      {"e/2", M_E / 2},

      {"0^1", 0},
      {"0^5", 0},
      {"0^3.5", 0},

      {"1^0", 1},
      {"1^1", 1},
      {"1^(-1)", 1},
      {"1^5", 1},
      {"1^3.5", 1},
      {"1^(-5)", 1},
      {"1^(-5.3)", 1},

      {"(-1)^0", 1},
      {"(-1)^1", -1},
      {"(-1)^(-1)", -1},
      {"(-1)^6", 1},
      {"(-1)^(-5)", -1},

      {"3^0", 1},
      {"3^1", 3},
      {"3^(-1)", 1.0 / 3.0},
      {"3^4", 81},
      {"3^3.5", 46.7653718044},
      {"3^(-4)", 1.0 / 81.0},
      {"3^(-.5)", 0.5773502692},

      {"1.5^0", 1.0},
      {"1.5^1", 1.5},
      {"1.5^(-1)", 2.0 / 3.0},
      {"1.5^5", 7.59375},
      {"1.5^3.5", 4.1335139409},
      {"1.5^(-5)", 0.1316872428},
      {"1.5^(-3.5)", 0.2419249129},

      {"(-3)^0", 1.0},
      {"(-3)^1", -3.0},
      {"(-3)^(-1)", -1.0 / 3.0},
      {"(-3)^4", 81.0},
      {"(-3)^(-4)", 0.012345679},

      {"(-1.5)^0", 1.0},
      {"(-1.5)^1", -1.5},
      {"(-1.5)^(-1)", -2.0 / 3.0},
      {"(-1.5)^3", -3.375},
      {"(-1.5)^(-3)", -0.2962962963},

      {"5mod2", 1.0},
      {"-5mod 2", -1},
      {"5mod2.5", 0},
      {"5mod2.2", 0.6},
      {"(-5)mod(-2)", -1},
      {"(-5)mod(-2.2)", -0.6},

      {"5!", 120},
      {"1!", 1},
      {"0!", 1},

      {"cos(pi)", -1},
      {"cos(2*pi)", 1},
      {"cos(pi/2)", 0},
      {"cos(pi/3)", 1.0 / 2.0},
      {"sin(pi)", 0},
      {"sin(2pi)", 0},
      {"sin(pi/2)", 1.0},
      {"sin(pi/6)", 1.0 / 2.0},
      {"tan(pi)", 0},
      {"tan(2pi)", 0},
      {"tan(pi/3)", 1.7320508076},

      {"acos(-1)", M_PI},
      {"acos(1)", 0},
      {"acos(0)", M_PI / 2},
      {"acos(0.5)", M_PI / 3},
      {"asin(0)", 0},
      {"asin(1)", M_PI / 2},
      {"asin(0.5)", M_PI / 6},
      {"atan(0)", 0},
      {"atan(1.7320508076)", M_PI / 3},

      {"sqrt(100)", 10},
      {"sqrt(pi*pi)", M_PI},
      {"sqrt(0.25)", 0.5},
      {"sqrt(1)", 1},
      {"sqrt(0)", 0},

      {"ln(e*e)", 2},
      {"ln(e)", 1},
      {"ln(e^pi)", M_PI},
      {"ln(1/e)", -1},
      {"ln(1)", 0},
      {"log(100)", 2},
      {"log(10^e)", M_E},
      {"log(0.01)", -2},
      {"log(1)", 0},
  };
};

class TestPolishNotationCalcBaseException : public TestPolishNotation {
 public:
  static inline int count_ = 40;
  static inline std::string test_data_[] = {"tan(pi/2)",
                                            "tan(3pi/2)",
                                            "tan(7*pi/2)",
                                            "tan(-61*pi/2)",
                                            "tan(pi/2 - 1E-10)",
                                            "tan(pi/2 - 1E-7)",

                                            "sqrt(-1)",
                                            "sqrt(-41244)",
                                            "sqrt(-1E-142)",

                                            "ln(0)",
                                            "ln(-1)",
                                            "ln(-1E-7)",

                                            "log(0)",
                                            "log(-1)",
                                            "log(-1E-7)",

                                            "(-5)!",
                                            "(-2141.124)!",
                                            "124124.4!",
                                            "(5 + 1E-6)!",

                                            "1/0",
                                            "pi/0",
                                            "sin(123*(2+33*(4+4)))/0",
                                            "123*213+3232*23+3/sin(pi)",

                                            "1mod0",
                                            "pimod0",
                                            "sin(123*(2+33*(4+4)))mod0",
                                            "123*213+3232*23+3modsin(pi)",

                                            "0^0",
                                            "0^(0pi)",
                                            "0^(2-2)",
                                            "0^(-2)",
                                            "0^(cos(pi))",
                                            "0^(-2)",
                                            "0^(-2.3)",

                                            "(-1)^2.2",
                                            "(-1)^(-2.2)",
                                            "(-3)^(2.2)",
                                            "(-3)^(-2.2)",
                                            "(-3.5)^(2.2)",
                                            "(-3.5)^(-2.2)"};
};

TEST_P(TestPolishNotationCalcBase, BaseCalc) {
  int num_test = this->GetParam();
  TestPolishNotationData& test_data =
      TestPolishNotationCalcBase::test_data_[num_test];

  polish_notation_.SetExpression(test_data.expr);
  polish_notation_.Translate();
  double res = polish_notation_.Calc();

  ASSERT_LE(std::abs(test_data.res - res), 1E-6);
}

TEST_P(TestPolishNotationCalcBaseException, BaseCalcException) {
  int num_test = this->GetParam();
  std::string& test_data =
      TestPolishNotationCalcBaseException::test_data_[num_test];

  polish_notation_.SetExpression(test_data);
  polish_notation_.Translate();

  ASSERT_THROW(polish_notation_.Calc(), s21::CalculationError);
}

INSTANTIATE_TEST_SUITE_P(My, TestPolishNotationCalcBase,
                         testing::Range(0, TestPolishNotationCalcBase::count_));

INSTANTIATE_TEST_SUITE_P(
    My, TestPolishNotationCalcBaseException,
    testing::Range(0, TestPolishNotationCalcBaseException::count_));
