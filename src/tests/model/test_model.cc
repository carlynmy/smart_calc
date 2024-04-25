#include <gtest/gtest.h>

#include <cmath>
#include <string>

#include "../../model/model.h"
#include "../test.h"

struct TestModelDefineTypeFormulaData {
  std::string expr;
  s21::Model::TypeFormula type;
  bool x_and_y_may_be_var;
};

class TestModelDefineTypeFormula : public testing::TestWithParam<int> {
 public:
  static inline int count_ = 98;
  static inline TestModelDefineTypeFormulaData test_data_[] = {
      {"A(1, 2)", s21::Model::kTypePoint, 0},
      {"A(1;2)", s21::Model::kTypePoint, 0},
      {"  A{1,   7.76}", s21::Model::kTypePoint, 0},
      {"agfnjaIASYba__asdfaf988(-4,5)", s21::Model::kTypePoint, 0},
      {"sis(1, -2)", s21::Model::kTypePoint, 0},
      {"_(-3, -4)", s21::Model::kTypePoint, 0},

      {"x(3, 4)", s21::Model::kTypeNamelessFunc, 0},
      {"y(1; 2)", s21::Model::kTypeNamelessFuncY, 0},
      {"sin(3, 4)", s21::Model::kTypeNamelessFunc, 0},
      {"A(2, 3}", s21::Model::kTypeNamelessFunc, 0},
      {"A 2,3", s21::Model::kTypeNamelessFunc, 0},
      {"(1, 2)", s21::Model::kTypeNamelessFunc, 0},
      {"my_func(3, 4)", s21::Model::kTypeNamelessFunc, 0},
      {"A(3, ,3)", s21::Model::kTypeNamelessFunc, 0},
      {"A(pi, e)", s21::Model::kTypeNamelessFunc, 0},
      {"A()", s21::Model::kTypeNamelessFunc, 0},
      {"A(3)", s21::Model::kTypeNamelessFunc, 0},
      {"A(3, 3) =", s21::Model::kTypeInvFormula, 0},
      {"A = (3, 4)", s21::Model::kTypeVar, 0},

      {"pi", s21::Model::kTypeNamelessFunc, 0},
      {"e", s21::Model::kTypeNamelessFunc, 0},
      {"12321", s21::Model::kTypeNamelessFunc, 0},
      {"123 + 334", s21::Model::kTypeNamelessFunc, 0},
      {"pieeepi 322 myfunc(3, 4) sin0", s21::Model::kTypeNamelessFunc, 0},
      {"x", s21::Model::kTypeNamelessFunc, 0},
      {"sinx", s21::Model::kTypeNamelessFunc, 0},
      {"pisinx/3+54", s21::Model::kTypeNamelessFunc, 0},
      {"myfuncx", s21::Model::kTypeNamelessFunc, 0},

      {"pisiny", s21::Model::kTypeNamelessFuncY, 0},
      {"y", s21::Model::kTypeNamelessFuncY, 0},
      {"piy/yyyysiny", s21::Model::kTypeNamelessFuncY, 0},

      {"xy", s21::Model::kTypeInvFormula, 0},
      {"sinxy+xy", s21::Model::kTypeInvFormula, 0},
      {"xxxxxxxxxxxxyxxx", s21::Model::kTypeInvFormula, 0},
      {"yyyyyyyyyyxyyyy", s21::Model::kTypeInvFormula, 0},
      {"my_funcxy", s21::Model::kTypeInvFormula, 0},

      {"y = pi", s21::Model::kTypeNamelessFuncEq, 0},
      {"y= e", s21::Model::kTypeNamelessFuncEq, 0},
      {"  y = 12321", s21::Model::kTypeNamelessFuncEq, 0},
      {"y = 123 + 334", s21::Model::kTypeNamelessFuncEq, 0},
      {"y = pieeepi 322 myfunc(3, 4) sin0", s21::Model::kTypeNamelessFuncEq, 0},
      {"y = x", s21::Model::kTypeNamelessFuncEq, 0},
      {"y = sinx", s21::Model::kTypeNamelessFuncEq, 0},
      {"y = pisinx/3+54", s21::Model::kTypeNamelessFuncEq, 0},
      {"y = my_funcx", s21::Model::kTypeNamelessFuncEq, 0},

      {"x = pisiny", s21::Model::kTypeNamelessFuncEqY, 0},
      {"  x = y", s21::Model::kTypeNamelessFuncEqY, 0},
      {"x= piy/yyyysiny", s21::Model::kTypeNamelessFuncEqY, 0},

      {"y = pi", s21::Model::kTypeVar, 1},
      {"y= e", s21::Model::kTypeVar, 1},
      {"  y = 12321", s21::Model::kTypeVar, 1},
      {"y = 123 + 334", s21::Model::kTypeVar, 1},
      {"y = pieeepi 322 myfunc(3, 4) sin0", s21::Model::kTypeVar, 1},

      {"x = pisin2", s21::Model::kTypeVar, 1},
      {"  x = 2", s21::Model::kTypeVar, 1},

      {"a = 5", s21::Model::kTypeVar, 0},
      {"a = pi5pi", s21::Model::kTypeVar, 0},
      {"b = sinpie", s21::Model::kTypeVar, 0},
      {"a = my_var", s21::Model::kTypeVar, 0},

      {"a() = 5", s21::Model::kTypeFunc0, 0},
      {"a() = pi5pi", s21::Model::kTypeFunc0, 0},
      {"b() = sinpie", s21::Model::kTypeFunc0, 0},
      {"adas() = my_var", s21::Model::kTypeFunc0, 0},

      {"a(x) = x5", s21::Model::kTypeFunc1, 0},
      {"ad(x)= xpi5pi", s21::Model::kTypeFunc1, 0},
      {"b(x) = xsinpie", s21::Model::kTypeFunc1, 0},
      {"a(x) = xmy_var", s21::Model::kTypeFunc1, 0},

      {"b(a) =a5", s21::Model::kTypeFunc1, 0},
      {"b(a)= api5pi", s21::Model::kTypeFunc1, 0},
      {"b(a) =asinpie", s21::Model::kTypeFunc1, 0},
      {"b(a) =amy_var", s21::Model::kTypeFunc1, 0},

      {"a(y) = y5", s21::Model::kTypeFunc1Y, 0},
      {"d(y)= ypi5pi", s21::Model::kTypeFunc1Y, 0},
      {"b(y) = ysinpie", s21::Model::kTypeFunc1Y, 0},
      {"a(y) = ymy_var", s21::Model::kTypeFunc1Y, 0},

      {"2x = 2y", s21::Model::kTypeEquation, 0},
      {"xxy*y = xyyx", s21::Model::kTypeEquation, 0},
      {"x^x^x = y", s21::Model::kTypeEquation, 0},
      {"pi*pipi = x", s21::Model::kTypeEquation, 0},
      {"eee = y", s21::Model::kTypeEquation, 0},
      {"x*x + yy = pipi", s21::Model::kTypeEquation, 0},
      {"sin2sin2 = 5", s21::Model::kTypeEquation, 0},
      {"5 = 5", s21::Model::kTypeEquation, 0},

      {"a2x = 2y", s21::Model::kTypeVar, 0},
      {"axxyy = xyyx", s21::Model::kTypeVar, 0},
      {"ax^x^x = y", s21::Model::kTypeInvFormula, 0},
      {"pipipi = ", s21::Model::kTypeInvFormula, 0},
      {"eee = v", s21::Model::kTypeInvFormula, 0},
      {"xx + yy = vpipi", s21::Model::kTypeInvFormula, 0},
      {"sin2sin2 = va", s21::Model::kTypeInvFormula, 0},
      {"5 = A(2, 2)", s21::Model::kTypeInvFormula, 0},

      {"", s21::Model::kTypeNamelessFunc, 0},
      {"  ", s21::Model::kTypeNamelessFunc, 0},
      {"\t\t\t\n \n\n", s21::Model::kTypeNamelessFunc, 0},
      {"asdasd", s21::Model::kTypeNamelessFunc, 0},
      {"asddas =da ads", s21::Model::kTypeVar, 0},
      {"a = a = 3", s21::Model::kTypeVar, 0},
      {"sixx", s21::Model::kTypeNamelessFunc, 0}

  };

  static void SetUpTestSuite() {
    model_.AddFormula("pi = 3.14159265358979323846");
    model_.AddFormula("e = 2.7182818284590452354");
    model_.AddFormula("my_func(a, b) = ab");
    model_.AddFormula("my_var = 2");
  }

  static inline s21::Model model_{};
};

TEST_P(TestModelDefineTypeFormula, Common) {
  int num_test = this->GetParam();
  TestModelDefineTypeFormulaData& test_data =
      TestModelDefineTypeFormula::test_data_[num_test];

  model_.SetXYMayBeVar(test_data.x_and_y_may_be_var);

  s21::Model::TypeFormula type = model_.DefineTypeFormula(test_data.expr);

  ASSERT_EQ(type, test_data.type);
}

INSTANTIATE_TEST_SUITE_P(My, TestModelDefineTypeFormula,
                         testing::Range(0, TestModelDefineTypeFormula::count_));
