#include <gtest/gtest.h>

#include <cmath>

#include "../../../model/operation/operation.h"
#include "../../../model/polish_notation/polish_notation.h"
#include "../../../model/special_token/special_token.h"
#include "../../test.h"
#include "test_polish_notation.h"

class TestPolishNotationPossibilitesSpaces : public TestPolishNotation {
 public:
  static inline int count_ = 6;
  static inline TestPolishNotationData test_data_[] = {
      {"      pi     ", M_PI},
      {"2  +3 +   1\t-1*(     1+ 1 )", 4},
      {"sin (  pi  )", 0},
      {"\t\t\t\t\t\t\t\t\n\nsin\n\nsqrt(   pi    pi  )", 0},
      {"2   pi", 2 * M_PI},
      {"3 + - 2", 1}};
};

class TestPolishNotationPossibilitesMultInterpret : public TestPolishNotation {
 public:
  static inline int count_ = 11;
  static inline TestPolishNotationData test_data_[] = {
      {"2pi", 2 * M_PI},       {"2(2+3)", 10},
      {"2cos(pi)", -2},        {"pipi", M_PI* M_PI},
      {"pi(2+3)", M_PI * 5},   {"picos(pi)", -M_PI},
      {"(2)pi", 2 * M_PI},     {"(1+2)(3+1)", 12},
      {"(1+2)cos(pi)", -3},    {"2picos(sin(pi))", 2 * M_PI},
      {"ee/e/eee/e/epi", M_PI}};
};

class TestPolishNotationPossibilitesBracketsInterpret
    : public TestPolishNotation {
 public:
  static inline int count_ = 9;
  static inline TestPolishNotationData test_data_[] = {
      {"sinpi", 0},
      {"cossinpi", 1},
      {"cos0cos-pi", -1},
      {"sqrtsqrt(pipipipisqrtsqrt1)", M_PI},
      {"2esincospipisinsinsqrt(9)pi", -6.350523354},
      {"3+3*(3-5*(-(7+-2--+--+-3)))", 42},
      {"(((((((((((((2)))))))))))))", 2},
      {"--2", 2},
      {"------+++-+---+-2", -2}};
};

class TestPolishNotationPossibilitesBrackets : public TestPolishNotation {
 public:
  static inline int count_ = 4;
  static inline TestPolishNotationData test_data_[] = {
      {"3[3+1]", 12},
      {"pi{3+4}", 7 * M_PI},
      {"pi{3+[3-7(3-1)]}", -8 * M_PI},
      {"sin{4pi[3[({{((1))}})]]}", 0}};
};

class TestPolishNotationPossibilitesBracketsException
    : public TestPolishNotation {
 public:
  static inline int count_ = 2;
  static inline TestPolishNotationExceptionTranslatorData test_data_[] = {
      {"1+[2+(3])", {"", 5, 3}}, {"[2+cos(pi]+1)", {"", 6, 4}}};
};

class TestPolishNotationPossibilitesManyParamFunction
    : public TestPolishNotation {
 public:
  static inline int count_ = 19;
  static inline TestPolishNotationData test_data_[] = {
      {"pow(3, 2)", 9},
      {"pow(3, 0)", 1},
      {"2pow(1, pieesin0 2)", 2},
      {"(1+1)pow(1, pieesin0 2)", 2},
      {"pow(3, pow(2, pow(pow(1, 1), pow(9, 0.5))))", 9},
      {"pow(2*(3 - ((2-1)(3))), 3)", 0},
      {"pow(3, 2*(3 - ((2-1)(3))))", 1},
      {"pow((5 - ((2-1)(3))), 3)", 8},
      {"pow(3, (5 - ((2-1)(3))))", 9},

      {"get_pi()", M_PI},
      {"get_pi", M_PI},
      {"2pi+3get_pi()", 5 * M_PI},
      {"pow(get_pi(), 2)", M_PI* M_PI},
      {"get_pi(3)", M_PI * 3},
      {"get_pi(3-2)", M_PI},
      {"get_pi(get_pi())", M_PI* M_PI},
      {"get_piget_pi()", M_PI* M_PI},
      {"get_piget_pi", M_PI* M_PI},
      {"get_pi(get_pi)", M_PI* M_PI}

  };
};

class TestPolishNotationPossibilitesManyParamFunctionException
    : public TestPolishNotation {
 public:
  static inline int count_ = 16;
  static inline TestPolishNotationExceptionTranslatorData test_data_[] = {
      {"pow()", {"", 3, 2}},
      {"pow(5)", {"", 0, 6}},
      {"(2+3pi/3 )pow()", {"", 13, 2}},
      {"pow(23pipipi)", {"", 0, 13}},
      {"pow((22(pi)), 2pi, 3)", {"", 0, 18}},
      {"pow(pow(3, 5))", {"", 0, 14}},
      {"pow(pow(3), 5)", {"", 4, 6}},
      {"pow( pow( 1, pow(1, 2pow(21)) ), 1)", {"", 21, 7}},
      {"pow(1, pow(2, 3, 4))", {"", 7, 9}},
      {"pow2, 3 + 4", {"", 0, 4}},
      {"pow(, 5)", {"", 3, 2}},
      {"pow(1, )", {"", 5, 3}},
      {"pow(1, 2 + 3* 4", {"", 3, 12}},
      {"pow(3), 4", {"", 0, 6}},
      {"pow,(1,2)", {"", 0, 4}},

      {"get_pi(32, 4)", {"", 7, 3}}

  };
};

class TestPolishNotationPossibilitesUserFuncVar : public TestPolishNotation {
 public:
  static inline int count_ = 32;
  static inline TestPolishNotationData test_data_[] = {
      {"pi", M_PI},
      {"e", M_E},
      {"pi 2", M_PI * 2},
      {"pi*2", M_PI * 2},
      {"pi(2)", M_PI * 2},
      {"var_4", 1},
      {"var_4pi", 1 * M_PI},
      {"_", 1},
      {"var_4_4", 1 * 1 * 4},
      {"4_4var_44", 4 * 1 * 4 * 1 * 4},

      {"return10", 10},
      {"return10()", 10},
      {"return10pi", 10 * M_PI},
      {"return10()pi", 10 * M_PI},
      {"return10(pi)", 10 * M_PI},
      {"return10()(pi)", 10 * M_PI},
      {"nested_return", 100 * M_PI},
      {"nested_return(return10)", 1000 * M_PI},
      {"mult2(5)", 10},
      {"mult22", 4},
      {"mult2pi2", 4 * M_PI},
      {"mult_100pi(5)", 500 * M_PI},
      {"mult_100pi(return10())", 1000 * M_PI},
      {"mult_100pi(return10)", 1000 * M_PI},

      {"ignore_param(3, return10())", 2},
      {"ignore_param(3, return10)", 2},
      {"mult_this(2, 3)", 6},
      {"mult_this(2, return10)", 20},
      {"mult_this(return10, return10(10))", 1000},
      {"INTERSTED_Func(2, 3)", 360},

      {"sum_7Params(1, 2, 3, 2, 1, 2, 1)", 12},
      {"sum_7Params(return10, return10(), sum_7Params(1, 1, 1, 1, 1, 1, 1), 1, "
       "1, 1, 1)",
       31}

  };

  static void SetUpTestSuite() {
    s21::ListVariable list_var;
    list_var.Add({"pi", M_PI});
    list_var.Add({"e", M_E});
    list_var.Add({"var_4", 1});
    list_var.Add({"_", 1});

    s21::ListUserFunction list_user_func;
    s21::ListVariable list_var_uf;

    s21::PolishNotation func_return_10_pn("", list_var, list_user_func);
    s21::UserFunction func_return_10("return10", "10", list_var_uf,
                                     func_return_10_pn);
    list_user_func.Add(func_return_10);

    s21::PolishNotation func_nested_return_pn("", list_var, list_user_func);
    s21::UserFunction func_nested_return("nested_return", "10return10pi",
                                         list_var_uf, func_nested_return_pn);
    list_user_func.Add(func_nested_return);

    list_var_uf.Add({"a", 0});

    s21::PolishNotation func_mult2_pn("", list_var, list_user_func);
    s21::UserFunction func_mult2("mult2", "2a", list_var_uf, func_mult2_pn);
    list_user_func.Add(func_mult2);

    s21::PolishNotation func_mult_100pi_pn("", list_var, list_user_func);
    s21::UserFunction func_mult_100pi("mult_100pi", "a*nested_return",
                                      list_var_uf, func_mult_100pi_pn);
    list_user_func.Add(func_mult_100pi);

    list_var_uf.Add({"b", 0});

    s21::PolishNotation func_ignore_param_pn("", list_var, list_user_func);
    s21::UserFunction func_ignore_param("ignore_param", "2", list_var_uf,
                                        func_ignore_param_pn);
    list_user_func.Add(func_ignore_param);

    s21::PolishNotation func_mult_this_pn("", list_var, list_user_func);
    s21::UserFunction func_mult_this("mult_this", "ab", list_var_uf,
                                     func_mult_this_pn);
    list_user_func.Add(func_mult_this);

    s21::PolishNotation func_INTERSTED_Func_pn("", list_var, list_user_func);
    s21::UserFunction func_INTERSTED_Func(
        "INTERSTED_Func", "mult_this(a, b)mult_this(a,b)return10", list_var_uf,
        func_INTERSTED_Func_pn);
    list_user_func.Add(func_INTERSTED_Func);

    list_var_uf.Add({"c3", 0});
    list_var_uf.Add({"c4", 0});
    list_var_uf.Add({"c5", 0});
    list_var_uf.Add({"c6", 0});
    list_var_uf.Add({"c7", 0});

    s21::PolishNotation func_sum_7Params_pn("", list_var, list_user_func);
    s21::UserFunction func_sum_7Params("sum_7Params", "a+b+c3+c4+c5+c6+c7",
                                       list_var_uf, func_sum_7Params_pn);
    list_user_func.Add(func_sum_7Params);

    polish_notation_.SetListVariable(list_var);
    polish_notation_.SetListUserFunction(list_user_func);
  }

  static inline s21::PolishNotation polish_notation_{};
};

class TestPolishNotationPossibilitesUserFuncVarException
    : public TestPolishNotation {
 public:
  static inline int count_ = 16;
  static inline TestPolishNotationExceptionTranslatorData test_data_[] = {
      {"pow()", {"", 3, 2}},
      {"pow(5)", {"", 0, 6}},
      {"(2+3pi/3 )pow()", {"", 13, 2}},
      {"pow(23pipipi)", {"", 0, 13}},
      {"pow((22(pi)), 2pi, 3)", {"", 0, 18}},
      {"pow(pow(3, 5))", {"", 0, 14}},
      {"pow(pow(3), 5)", {"", 4, 6}},
      {"pow( pow( 1, pow(1, 2pow(21)) ), 1)", {"", 21, 7}},
      {"pow(1, pow(2, 3, 4))", {"", 7, 9}},
      {"pow2, 3 + 4", {"", 0, 4}},
      {"pow(, 5)", {"", 3, 2}},
      {"pow(1, )", {"", 5, 3}},
      {"pow(1, 2 + 3* 4", {"", 3, 12}},
      {"pow(3), 4", {"", 0, 6}},
      {"pow,(1,2)", {"", 0, 4}},

      {"get_pi(32, 4)", {"", 7, 3}}

  };
};

TEST_P(TestPolishNotationPossibilitesSpaces, PossibilitesSpaces) {
  int num_test = this->GetParam();
  TestPolishNotationData& test_data =
      TestPolishNotationPossibilitesSpaces::test_data_[num_test];

  polish_notation_.SetExpression(test_data.expr);
  polish_notation_.Translate();
  double res = polish_notation_.Calc();

  ASSERT_LE(std::abs(test_data.res - res), 1E-6);
}

TEST_P(TestPolishNotationPossibilitesMultInterpret, PossibilitesMultInterpret) {
  int num_test = this->GetParam();
  TestPolishNotationData& test_data =
      TestPolishNotationPossibilitesMultInterpret::test_data_[num_test];

  polish_notation_.SetExpression(test_data.expr);
  polish_notation_.Translate();
  double res = polish_notation_.Calc();

  ASSERT_LE(std::abs(test_data.res - res), 1E-6);
}

TEST_P(TestPolishNotationPossibilitesBracketsInterpret,
       PosibilitesBracketsInterpret) {
  int num_test = this->GetParam();
  TestPolishNotationData& test_data =
      TestPolishNotationPossibilitesBracketsInterpret::test_data_[num_test];

  polish_notation_.SetExpression(test_data.expr);
  polish_notation_.Translate();
  double res = polish_notation_.Calc();

  ASSERT_LE(std::abs(test_data.res - res), 1E-6);
}

TEST_P(TestPolishNotationPossibilitesBrackets, PosibilitesBracketsInterpret) {
  int num_test = this->GetParam();
  TestPolishNotationData& test_data =
      TestPolishNotationPossibilitesBrackets::test_data_[num_test];

  polish_notation_.SetExpression(test_data.expr);
  polish_notation_.Translate();
  double res = polish_notation_.Calc();

  ASSERT_LE(std::abs(test_data.res - res), 1E-6);
}

TEST_P(TestPolishNotationPossibilitesBracketsException,
       PosibilitesBracketsException) {
  int num_test = this->GetParam();
  TestPolishNotationExceptionTranslatorData& test_data =
      TestPolishNotationPossibilitesBracketsException::test_data_[num_test];

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

TEST_P(TestPolishNotationPossibilitesManyParamFunction,
       PossibilitesManyParamFunction) {
  int num_test = this->GetParam();
  TestPolishNotationData& test_data =
      TestPolishNotationPossibilitesManyParamFunction::test_data_[num_test];

  polish_notation_.SetExpression(test_data.expr);
  polish_notation_.Translate();
  double res = polish_notation_.Calc();

  ASSERT_LE(std::abs(test_data.res - res), 1E-6);
}

TEST_P(TestPolishNotationPossibilitesManyParamFunctionException,
       PossibilitesManyParamFunctionException) {
  int num_test = this->GetParam();
  TestPolishNotationExceptionTranslatorData& test_data =
      TestPolishNotationPossibilitesManyParamFunctionException::test_data_
          [num_test];

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

TEST_P(TestPolishNotationPossibilitesUserFuncVar, PossibilitesUserFuncVar) {
  int num_test = this->GetParam();

  TestPolishNotationData& test_data =
      TestPolishNotationPossibilitesUserFuncVar::test_data_[num_test];

  polish_notation_.SetExpression(test_data.expr);

  polish_notation_.Translate();
  double res = polish_notation_.Calc();

  ASSERT_LE(std::abs(test_data.res - res), 1E-6);
}

TEST_P(TestPolishNotationPossibilitesUserFuncVarException,
       PossibilitesUserFuncVarException) {
  int num_test = this->GetParam();
  TestPolishNotationExceptionTranslatorData& test_data =
      TestPolishNotationPossibilitesUserFuncVarException::test_data_[num_test];

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
    My, TestPolishNotationPossibilitesSpaces,
    testing::Range(0, TestPolishNotationPossibilitesSpaces::count_));

INSTANTIATE_TEST_SUITE_P(
    My, TestPolishNotationPossibilitesMultInterpret,
    testing::Range(0, TestPolishNotationPossibilitesMultInterpret::count_));

INSTANTIATE_TEST_SUITE_P(
    My, TestPolishNotationPossibilitesBracketsInterpret,
    testing::Range(0, TestPolishNotationPossibilitesBracketsInterpret::count_));

INSTANTIATE_TEST_SUITE_P(
    My, TestPolishNotationPossibilitesBrackets,
    testing::Range(0, TestPolishNotationPossibilitesBrackets::count_));

INSTANTIATE_TEST_SUITE_P(
    My, TestPolishNotationPossibilitesBracketsException,
    testing::Range(0, TestPolishNotationPossibilitesBracketsException::count_));

INSTANTIATE_TEST_SUITE_P(
    My, TestPolishNotationPossibilitesManyParamFunction,
    testing::Range(0, TestPolishNotationPossibilitesManyParamFunction::count_));

INSTANTIATE_TEST_SUITE_P(
    My, TestPolishNotationPossibilitesManyParamFunctionException,
    testing::Range(
        0, TestPolishNotationPossibilitesManyParamFunctionException::count_));

INSTANTIATE_TEST_SUITE_P(
    My, TestPolishNotationPossibilitesUserFuncVar,
    testing::Range(0, TestPolishNotationPossibilitesUserFuncVar::count_));

INSTANTIATE_TEST_SUITE_P(
    My, TestPolishNotationPossibilitesUserFuncVarException,
    testing::Range(0,
                   TestPolishNotationPossibilitesUserFuncVarException::count_));
