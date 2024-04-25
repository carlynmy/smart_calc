// Implementation add formula methods class Model

// Copyright (C) 2023-2023 School 21 License

#include <list>
#include <string>

#include "graph/graph.h"
#include "model.h"
#include "sm_exceptions/invalid_expression.h"
#include "token_parser/token_parser.h"
#include "user_function/user_function.h"
#include "variable/variable.h"

namespace s21 {

std::string Model::AddPoint(const std::string& str, bool add_graph) {
  TokenParser token_parser(str, 0, &list_variable_, &list_user_function_);
  std::string name = token_parser.NextWord();
  token_parser.NextToken();  // (
  double x = token_parser.NextNum();
  token_parser.NextToken();  // ,
  double y = token_parser.NextNum();

  if (add_graph) {
    GraphPoint* graph = new GraphPoint(x, y);
    GraphSetSize(graph);
    list_graph_.Add(graph);
  }
  point_names.push_back(name);

  return name;
}

std::string Model::AddNamelessFunc(const std::string& str, bool add_graph) {
  std::list<double> l = {0};
  ListVariable list_variable;
  if (!var_x_added) {
    Variable var_x("x", 0);
    list_variable.Add(var_x);
  }
  UserFunction func("", str, list_variable, polish_notation_);
  func.Translate();

  if (add_graph) {
    GraphFunc1X* graph = new GraphFunc1X(func);
    GraphSetSize(graph);
    list_graph_.Add(graph);
  }

  return "";
}

std::string Model::AddNamelessFuncY(const std::string& str, bool add_graph) {
  std::list<double> l = {0};
  ListVariable list_variable;
  if (!var_y_added) {
    Variable var_y("y", 0);
    list_variable.Add(var_y);
  }
  UserFunction func("", str, list_variable, polish_notation_);
  func.Translate();

  if (add_graph) {
    GraphFunc1Y* graph = new GraphFunc1Y(func);
    GraphSetSize(graph);
    list_graph_.Add(graph);
  }

  return "";
}

std::string Model::AddVar(const std::string& str, bool add_graph) {
  TokenParser token_parser(str, 0, &list_variable_, &list_user_function_);
  std::string name = token_parser.NextWord();
  if (!IsAviableName(name)) throw InvalidExpr(kErrorMsgs[kErrNameNotAviable]);
  if (!x_and_y_may_be_var_ && (name == "x" || name == "y"))
    throw InvalidExpr(kErrorMsgs[kErrNameNotAviable]);

  token_parser.NextToken();
  std::string define = str.substr(token_parser.GetI());
  double value = CalculatorCalc(define);
  Variable var(name, value);
  list_variable_.Add(var);
  polish_notation_.SetListVariable(list_variable_);

  if (add_graph) {
    GraphConst* graph = new GraphConst(value);
    GraphSetSize(graph);
    list_graph_.Add(graph);
  }

  return name;
}
std::string Model::AddNamelessFuncEq(const std::string& str, bool add_graph) {
  return AddNamelessFunc(str.substr(str.find("=") + 1), add_graph);
}
std::string Model::AddNamelessFuncEqY(const std::string& str, bool add_graph) {
  return AddNamelessFuncY(str.substr(str.find("=") + 1), add_graph);
}

std::string Model::AddFunc0(const std::string& str, bool add_graph) {
  TokenParser token_parser(str, 0, &list_variable_, &list_user_function_);
  std::string name = token_parser.NextWord();
  if (!IsAviableName(name) || name == "x" || name == "y")
    throw InvalidExpr(kErrorMsgs[kErrNameNotAviable]);

  token_parser.NextToken();  // (
  token_parser.NextToken();  // )
  token_parser.NextToken();  // =
  std::string define = str.substr(token_parser.GetI());
  UserFunction func(name, define, {}, polish_notation_);
  list_user_function_.Add(func);
  polish_notation_.SetListUserFunction(list_user_function_);

  if (add_graph) {
    GraphConst* graph = new GraphConst(func.Calc({}));
    GraphSetSize(graph);
    list_graph_.Add(graph);
  }

  return name;
}

std::string Model::AddFunc1(const std::string& str, bool add_graph) {
  TokenParser token_parser(str, 0, &list_variable_, &list_user_function_);
  std::string name = token_parser.NextWord();
  if (!IsAviableName(name) || name == "x" || name == "y")
    throw InvalidExpr(kErrorMsgs[kErrNameNotAviable]);

  token_parser.NextToken();  // (
  std::string var_name = token_parser.NextWord();
  if (!IsAviableName(var_name))
    throw InvalidExpr(kErrorMsgs[kErrInvNameLocalVar]);

  token_parser.NextToken();  // )
  token_parser.NextToken();  // =
  std::string define = str.substr(token_parser.GetI());
  ListVariable list_var;
  list_var.Add({var_name, 0});
  UserFunction func(name, define, list_var, polish_notation_);
  list_user_function_.Add(func);
  polish_notation_.SetListUserFunction(list_user_function_);

  if (add_graph) {
    GraphFunc1X* graph = new GraphFunc1X(func);
    GraphSetSize(graph);
    list_graph_.Add(graph);
  }

  return name;
}

std::string Model::AddFunc1Y(const std::string& str, bool add_graph) {
  TokenParser token_parser(str, 0, &list_variable_, &list_user_function_);
  std::string name = token_parser.NextWord();
  if (!IsAviableName(name) || name == "x" || name == "y")
    throw InvalidExpr(kErrorMsgs[kErrNameNotAviable]);

  token_parser.NextToken();  // (
  std::string var_name = token_parser.NextWord();
  if (!IsAviableName(var_name))
    throw InvalidExpr(kErrorMsgs[kErrInvNameLocalVar]);

  token_parser.NextToken();  // )
  token_parser.NextToken();  // =
  std::string define = str.substr(token_parser.GetI());
  ListVariable list_var;
  list_var.Add({var_name, 0});
  UserFunction func(name, define, list_var, polish_notation_);
  list_user_function_.Add(func);
  polish_notation_.SetListUserFunction(list_user_function_);

  if (add_graph) {
    GraphFunc1Y* graph = new GraphFunc1Y(func);
    GraphSetSize(graph);
    list_graph_.Add(graph);
  }

  return name;
}

std::string Model::AddFuncN(const std::string& str, bool add_graph) {
  if (add_graph) add_graph = false;
  TokenParser token_parser(str, 0, &list_variable_, &list_user_function_);
  std::string name = token_parser.NextWord();
  if (!IsAviableName(name) || name == "x" || name == "y")
    throw InvalidExpr(kErrorMsgs[kErrNameNotAviable]);

  Token open_br = token_parser.NextToken();

  ListVariable list_var;
  std::string var_name;
  Token next_token;
  bool break_flag = false;
  while (!break_flag) {
    var_name = token_parser.NextWord();
    next_token = token_parser.NextToken();
    if (!IsAviableName(name)) throw InvalidExpr(kErrorMsgs[kErrNameNotAviable]);

    list_var.Add({var_name, 0});
    if (next_token.IsSpecialToken() &&
        next_token.GetSpecialToken()->IsEqualOpenBracket(
            open_br.GetSpecialToken()->GetName())) {
      break_flag = true;

    } else if (!next_token.IsSpecialToken() ||
               !next_token.GetSpecialToken()->IsOperandDelimetr()) {
      throw InvalidExpr(kErrorMsgs[kErrInvFormula]);
    }
  }

  Token eq_sign = token_parser.NextToken();
  if (!eq_sign.IsSpecialToken() || !eq_sign.GetSpecialToken()->IsEqualSign())
    throw InvalidExpr(kErrorMsgs[kErrInvFormula]);

  std::string define = str.substr(token_parser.GetI());
  UserFunction func(name, define, list_var, polish_notation_);
  list_user_function_.Add(func);
  polish_notation_.SetListUserFunction(list_user_function_);

  return name;
}

}  // namespace s21
