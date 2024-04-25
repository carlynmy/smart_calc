// Implementation setters class PolishNotation

// Copyright (C) 2023-2023 School 21 License

#include <stdexcept>
#include <string>

#include "../list_user_function/list_user_function.h"
#include "../list_variable/list_variable.h"
#include "../variable/variable.h"
#include "polish_notation.h"

namespace s21 {

const std::string& PolishNotation::GetExpression() const { return expr_; }

const ListVariable& PolishNotation::GetListVariable() const {
  return list_variable_;
}

const ListUserFunction& PolishNotation::GetListUserFunction() const {
  return list_user_function_;
}

bool PolishNotation::IsDataInput() const { return is_data_input_; }

bool PolishNotation::IsTranslate() const { return is_translate_; }

// ------------------------------------------------------------------------- //

void PolishNotation::SetExpression(const std::string& expr) {
  is_data_input_ = true;
  is_translate_ = false;
  expr_ = expr;
}

void PolishNotation::SetListVariable(const ListVariable& list_variable) {
  is_translate_ = false;
  list_variable_ = list_variable;
}

void PolishNotation::SetListUserFunction(
    const ListUserFunction& list_user_function) {
  is_translate_ = false;
  list_user_function_ = list_user_function;
}

void PolishNotation::UpdateVariableValue(const Variable& var) {
  UpdateVariableValue(var.GetName(), var.GetValue());
}

void PolishNotation::UpdateVariableValue(const std::string& name,
                                         double value) {
  Variable* var = list_variable_.Get(name);
  if (var == nullptr) throw std::logic_error(kErrorMsgs[kUndefinedVar]);
  var->SetValue(value);
}

}  // namespace s21
