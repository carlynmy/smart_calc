// Implementation construct methods class PolishNotation
// Include constructors, destructor, operator assigment overload

// Copyright (C) 2023-2023 School 21 License

#include <string>

#include "../list_user_function/list_user_function.h"
#include "../list_variable/list_variable.h"
#include "polish_notation.h"

namespace s21 {

PolishNotation::PolishNotation() {}

PolishNotation::PolishNotation(const std::string& expr,
                               const ListVariable& list_variable,
                               const ListUserFunction& list_user_function) {
  expr_ = expr;
  list_variable_ = list_variable;
  list_user_function_ = list_user_function;
  is_data_input_ = true;
}

PolishNotation::~PolishNotation() {}

}  // namespace s21
