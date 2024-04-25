// Implementation define formula methods class Model

// Copyright (C) 2023-2023 School 21 License

#include <cmath>
#include <list>
#include <string>

#include "list_variable/list_variable.h"
#include "model.h"
#include "operation/operation.h"
#include "sm_exceptions/invalid_expression.h"
#include "token/token.h"
#include "token_parser/token_parser.h"

namespace s21 {

bool Model::IsAviableName(const std::string& name) const {
  if (name == "") return false;

  if (Operation::GetOperation(name) != nullptr) return false;

  if (list_user_function_.Get(name) != nullptr) return false;

  if (list_variable_.Get(name) != nullptr) return false;

  std::list<std::string>::const_iterator i = point_names.begin();
  for (; i != point_names.end(); ++i) {
    if (*i == name) return false;
  }

  return true;
}

Model::TypeFormula Model::DefineTypeFormula(const std::string& str) const {
  ListVariable list_variable(list_variable_);
  if (!var_x_added) list_variable.Add(kVarX);
  if (!var_y_added) list_variable.Add(kVarY);
  TokenParser token_parser(str, 0, &list_variable, &list_user_function_);
  bool contain_eq_sign = token_parser.ContainToken(kTokenEq);

  if (!contain_eq_sign) {
    if (IsTypePoint(token_parser)) return kTypePoint;

    token_parser.SetI(0);
    bool contain_x = token_parser.ContainToken(kTokenX);
    token_parser.SetI(0);
    bool contain_y = token_parser.ContainToken(kTokenY);
    if (contain_x && contain_y) return kTypeInvFormula;
    if (contain_y) return kTypeNamelessFuncY;
    return kTypeNamelessFunc;
  }

  if (IsTypeYEqEquation(token_parser)) {
    if (x_and_y_may_be_var_) return kTypeVar;
    return kTypeNamelessFuncEq;
  } else if (IsTypeXEqEquation(token_parser)) {
    if (x_and_y_may_be_var_) return kTypeVar;
    return kTypeNamelessFuncEqY;
  }

  if (IsTypeVar(token_parser)) return kTypeVar;
  if (IsTypeFunc0(token_parser)) return kTypeFunc0;
  if (IsTypeFunc1Y(token_parser)) return kTypeFunc1Y;
  if (IsTypeFunc1(token_parser)) return kTypeFunc1;
  if (IsTypeFuncN(token_parser)) return kTypeFuncN;
  if (IsEquation(token_parser)) return kTypeEquation;

  return kTypeInvFormula;
}

bool Model::IsTypePoint(TokenParser& token_parser) const {
  token_parser.SetI(0);
  std::string name;
  Token token1, token3, token5, token_null;
  double num2 = NAN, num4 = NAN;
  bool exception_flag = false;

  try {
    name = token_parser.NextWord();
    token1 = token_parser.NextToken();
    num2 = token_parser.NextNum();
    token3 = token_parser.NextToken();
    num4 = token_parser.NextNum();
    token5 = token_parser.NextToken();
    token_null = token_parser.NextToken();
  } catch (const InvalidExpr&) {
    exception_flag = true;
  }

  bool name_ok = IsAviableName(name) && name != "x" && name != "y";
  bool token1_ok =
      token1.IsSpecialToken() && token1.GetSpecialToken()->IsOpenBracket();
  bool token2_ok = num2 != NAN;
  bool token3_ok =
      token3.IsSpecialToken() && token3.GetSpecialToken()->IsOperandDelimetr();
  bool token4_ok = num4 != NAN;
  bool token5_ok = token1_ok && token5.IsSpecialToken() &&
                   token5.GetSpecialToken()->IsEqualOpenBracket(
                       token1.GetSpecialToken()->GetName());
  bool token_null_ok = token_null.IsNull();

  // if is Point
  if (!exception_flag && name_ok && token1_ok && token2_ok && token3_ok &&
      token4_ok && token5_ok && token_null_ok)
    return true;

  return false;
}

bool Model::IsTypeYEqEquation(TokenParser& token_parser) const {
  token_parser.SetI(0);
  Token token_y, token_eq;
  bool exception_flag = false;

  try {
    token_y = token_parser.NextToken();
    token_eq = token_parser.NextToken();
  } catch (const InvalidExpr&) {
    exception_flag = true;
  }

  bool token_y_ok = token_y == kTokenY;
  bool token_eq_ok = token_eq == kTokenEq;

  if (!exception_flag && token_y_ok && token_eq_ok) return true;

  return false;
}

bool Model::IsTypeXEqEquation(TokenParser& token_parser) const {
  token_parser.SetI(0);
  Token token_x, token_eq;
  bool exception_flag = false;

  try {
    token_x = token_parser.NextToken();
    token_eq = token_parser.NextToken();
  } catch (const InvalidExpr&) {
    exception_flag = true;
  }

  bool token_x_ok = token_x == kTokenX;
  bool token_eq_ok = token_eq == kTokenEq;

  if (!exception_flag && token_x_ok && token_eq_ok) return true;

  return false;
}

bool Model::IsTypeVar(TokenParser& token_parser) const {
  token_parser.SetI(0);
  std::string name;
  Token token_eq, token_not_null;
  bool exception_flag = false;

  try {
    name = token_parser.NextWord();
    token_eq = token_parser.NextToken();
  } catch (const InvalidExpr&) {
    exception_flag = true;
  }

  bool name_ok = IsAviableName(name) &&
                 (x_and_y_may_be_var_ || (name != "x" && name != "y")) &&
                 !IsPolishNotation(name);
  bool token_eq_ok = token_eq == kTokenEq;

  if (!exception_flag && name_ok && token_eq_ok) return true;

  return false;
}

bool Model::IsTypeFunc0(TokenParser& token_parser) const {
  token_parser.SetI(0);
  std::string name;
  Token token_open_br, token_close_br, token_eq;
  bool exception_flag = false;

  try {
    name = token_parser.NextWord();
    token_open_br = token_parser.NextToken();
    token_close_br = token_parser.NextToken();
    token_eq = token_parser.NextToken();
  } catch (const InvalidExpr&) {
    exception_flag = true;
  }

  bool name_ok = IsAviableName(name) && name != "x" && name != "y";
  bool token_open_br_ok = token_open_br.IsSpecialToken() &&
                          token_open_br.GetSpecialToken()->IsOpenBracket();
  bool token_close_br_ok = token_open_br_ok &&
                           token_close_br.IsSpecialToken() &&
                           token_close_br.GetSpecialToken()->IsEqualOpenBracket(
                               token_open_br.GetSpecialToken()->GetName());
  bool token_eq_ok = token_eq == kTokenEq;

  if (!exception_flag && token_open_br_ok && token_close_br_ok && name_ok &&
      token_eq_ok)
    return true;

  return false;
}

bool Model::IsTypeFunc1(TokenParser& token_parser) const {
  token_parser.SetI(0);
  std::string name, var_name;
  Token token_open_br, token_close_br, token_eq;
  bool exception_flag = false;

  try {
    name = token_parser.NextWord();
    token_open_br = token_parser.NextToken();
    var_name = token_parser.NextWord();
    token_close_br = token_parser.NextToken();
    token_eq = token_parser.NextToken();
  } catch (const InvalidExpr&) {
    exception_flag = true;
  }

  bool name_ok = IsAviableName(name) && name != "x" && name != "y";
  bool token_open_br_ok = token_open_br.IsSpecialToken() &&
                          token_open_br.GetSpecialToken()->IsOpenBracket();
  bool var_name_ok = IsAviableName(name) || var_name == kVarX.GetName();
  bool token_close_br_ok = token_open_br_ok &&
                           token_close_br.IsSpecialToken() &&
                           token_close_br.GetSpecialToken()->IsEqualOpenBracket(
                               token_open_br.GetSpecialToken()->GetName());
  bool token_eq_ok = token_eq == kTokenEq;

  if (!exception_flag && token_open_br_ok && var_name_ok && token_close_br_ok &&
      name_ok && token_eq_ok)
    return true;

  return false;
}

bool Model::IsTypeFunc1Y(TokenParser& token_parser) const {
  token_parser.SetI(0);
  std::string name, var_name;
  Token token_open_br, token_close_br, token_eq;
  bool exception_flag = false;

  try {
    name = token_parser.NextWord();
    token_open_br = token_parser.NextToken();
    var_name = token_parser.NextWord();
    token_close_br = token_parser.NextToken();
    token_eq = token_parser.NextToken();
  } catch (const InvalidExpr&) {
    exception_flag = true;
  }

  bool name_ok = IsAviableName(name) && name != "x" && name != "y";
  bool token_open_br_ok = token_open_br.IsSpecialToken() &&
                          token_open_br.GetSpecialToken()->IsOpenBracket();
  bool var_name_ok = var_name == kVarY.GetName();
  bool token_close_br_ok = token_open_br_ok &&
                           token_close_br.IsSpecialToken() &&
                           token_close_br.GetSpecialToken()->IsEqualOpenBracket(
                               token_open_br.GetSpecialToken()->GetName());
  bool token_eq_ok = token_eq == kTokenEq;

  if (!exception_flag && token_open_br_ok && var_name_ok && token_close_br_ok &&
      name_ok && token_eq_ok)
    return true;

  return false;
}

bool Model::IsTypeFuncN(TokenParser& token_parser) const {
  token_parser.SetI(0);
  std::string name, var_name, var_2_name;
  Token token_open_br, token_delim, token_next;
  bool exception_flag = false;

  try {
    name = token_parser.NextWord();
    token_open_br = token_parser.NextToken();
    var_name = token_parser.NextWord();
    token_delim = token_parser.NextToken();
    var_2_name = token_parser.NextWord();
    token_next = token_parser.NextToken();

  } catch (const InvalidExpr&) {
    exception_flag = true;
  }

  bool name_ok = IsAviableName(name) && name != "x" && name != "y";
  bool token_open_br_ok = token_open_br.IsSpecialToken() &&
                          token_open_br.GetSpecialToken()->IsOpenBracket();
  bool var_name_ok = IsAviableName(var_name) || var_name == kVarX.GetName() ||
                     var_name == kVarY.GetName();
  bool token_delim_ok = token_delim.IsSpecialToken() &&
                        token_delim.GetSpecialToken()->IsOperandDelimetr();
  bool var_2_name_ok = IsAviableName(var_2_name) ||
                       var_2_name == kVarX.GetName() ||
                       var_2_name == kVarY.GetName();
  bool token_next_ok = (token_next.IsSpecialToken() &&
                        token_next.GetSpecialToken()->IsOperandDelimetr()) ||
                       (token_open_br_ok && token_next.IsSpecialToken() &&
                        token_next.GetSpecialToken()->IsEqualOpenBracket(
                            token_open_br.GetSpecialToken()->GetName()));

  if (!exception_flag && name_ok && token_open_br_ok && var_name_ok &&
      token_delim_ok && var_2_name_ok && token_next_ok)
    return true;

  return false;
}

bool Model::IsEquation(TokenParser& token_parser) const {
  token_parser.SetI(0);
  size_t index_eq = token_parser.GetStr().find(kEq.GetName());
  std::string left_expr = token_parser.GetStr().substr(0, index_eq);
  std::string right_expr =
      token_parser.GetStr().substr(index_eq + kEq.GetName().length());
  bool exception_flag = false;

  ListVariable list_variable(list_variable_);
  if (!var_x_added) list_variable.Add(kVarX);
  if (!var_y_added) list_variable.Add(kVarY);
  PolishNotation polish_notation(left_expr, list_variable, list_user_function_);
  try {
    polish_notation.Translate();
    polish_notation.SetExpression(right_expr);
    polish_notation.Translate();
  } catch (const InvalidExpr&) {
    exception_flag = true;
  }

  if (!exception_flag) return true;

  return false;
}

bool Model::IsPolishNotation(const std::string& str) const {
  ListVariable list_variable(list_variable_);
  if (!var_x_added) list_variable.Add(kVarX);
  if (!var_y_added) list_variable.Add(kVarY);
  TokenParser token_parser(str, 0, &list_variable, &list_user_function_);
  Token token_1, token_2;

  bool exception_flag = false;
  try {
    token_1 = token_parser.NextToken();
    token_2 = token_parser.NextToken();
  } catch (const InvalidExpr&) {
    exception_flag = true;
  }

  if (!exception_flag && !token_1.IsNull() && !token_2.IsNull()) return true;

  return false;
}

}  // namespace s21
