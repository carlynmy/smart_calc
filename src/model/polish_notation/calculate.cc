// Implementation Calc methods class PolishNotation

// Copyright (C) 2023-2023 School 21 License

#include <cstddef>
#include <list>
#include <stack>
#include <stdexcept>

#include "../operation/operation.h"
#include "../token/token.h"
#include "../variable/variable.h"
#include "polish_notation.h"

namespace s21 {

double PolishNotation::Calc() {
  if (!IsTranslate()) throw std::logic_error(kErrorMsgs[kExprNotTranslate]);

  std::stack<double> stack;
  std::list<Token>::iterator iter = polish_notation_.begin();

  while (iter != polish_notation_.end()) {
    Token token = *iter;

    if (token.IsNum()) {
      stack.push(token.GetNum());

    } else if (token.IsVar()) {
      Variable* var = list_variable_.Get(token.GetVariable()->GetName());
      stack.push(var->GetValue());

    } else if (token.IsOper()) {
      const Operation* operation = token.GetOperation();

      std::list<double> arg_list;
      for (size_t i = 0; i < operation->GetOperandCount(); ++i) {
        arg_list.push_front(stack.top());
        stack.pop();
      }

      stack.push(operation->Calc(arg_list));
    }
    ++iter;
  }

  double res = stack.top();
  return res;
}

}  // namespace s21
