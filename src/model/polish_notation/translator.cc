// Implementation Translator methods class PolishNotation

// Copyright (C) 2023-2023 School 21 License

#include <cstddef>
#include <list>
#include <stack>
#include <stdexcept>

#include "../operation/operation.h"
#include "../sm_exceptions/invalid_expression.h"
#include "../special_token/special_token.h"
#include "../token/token.h"
#include "../token_parser/token_parser.h"
#include "polish_notation.h"

namespace s21 {

void PolishNotation::Translate() {
  if (!IsDataInput()) throw std::logic_error(kErrorMsgs[kDataNotInput]);

  polish_notation_.clear();

  std::stack<Token> stack;

  Token token;
  Token prev_token = Token(Token::kNull);
  Token prev_prev_token = Token(Token::kNull);

  // stack functions with 2 or many params. Use to validate input
  std::stack<FuncInfo> func_stack;
  bool is_prev_open_bracket_after_zero_param_func = false;

  TokenParser token_parser(expr_, 0, &list_variable_, &list_user_function_);
  do {
    token = token_parser.NextToken(prev_token);

    ValidateSequence(token, prev_token, stack,
                     is_prev_open_bracket_after_zero_param_func);
    ValidateManyParamFunction(token, prev_token, func_stack);

    PushToken(stack, token);

    prev_prev_token = prev_token;
    prev_token = token;
  } while (!token.IsNull());

  PopAll(stack, expr_.length());
  if (polish_notation_.empty())
    throw InvalidExpr(kErrorMsgs[kEmptyExpr], 0, expr_.length());

  is_translate_ = true;
}

void PolishNotation::ValidateSequence(
    const Token& token, const Token& prev_token, std::stack<Token>& stack,
    bool& is_prev_open_bracket_after_zero_param_func) {
  TypeTokenSeq type_token_seq = GetTypeTokenSeq(prev_token, token);

  if (type_token_seq == kSeqInvalid) {
    ThrowInvalidSeq(prev_token, token);

  } else if (type_token_seq == kSeqNeedMult) {
    PushMultToken(stack);

  } else if (type_token_seq == kSeqBracketCloseImmediately) {
    // Token sequence "()" allowed only after zero param func
    if (!is_prev_open_bracket_after_zero_param_func)
      ThrowInvalidSeq(prev_token, token);
    // Delete mult operation and open bracket we added prematurely
    Token br = stack.top();
    stack.pop();
    stack.pop();
    stack.push(br);
    is_prev_open_bracket_after_zero_param_func = false;

  } else if (type_token_seq == kSeqOpenBracketAfterZeroParamFunc) {
    // Prematurely add mult sign
    PushMultToken(stack);
    is_prev_open_bracket_after_zero_param_func = true;
  }
}

void PolishNotation::ValidateManyParamFunction(
    const Token& token, const Token& prev_token,
    std::stack<FuncInfo>& func_stack) {
  bool is_prev_many_param_func =
      prev_token.IsOper() && prev_token.GetOperation()->IsPrefix() &&
      prev_token.GetOperation()->GetOperandCount() > 1;

  if (is_prev_many_param_func) {
    bool is_open_br =
        token.IsSpecialToken() && token.GetSpecialToken()->IsOpenBracket();
    if (!is_open_br) {
      ThrowInvalidSeq(prev_token, token);

    } else {
      size_t need_delim = prev_token.GetOperation()->GetOperandCount() - 1;
      FuncInfo func_info{prev_token, token, need_delim, 0};
      func_stack.push(func_info);
    }
  }

  if (!token.IsSpecialToken()) return;

  SpecialToken::SpecitalTokenType type =
      token.GetSpecialToken()->GetSpecitalTokenType();
  if (type == SpecialToken::kOperandDelimetr) {
    if (func_stack.empty())
      ThrowInvalidSeq(prev_token, token);
    else if (func_stack.top().need_delim == 0)
      ThrowInvalidSeq(func_stack.top().func, token);
    else
      --func_stack.top().need_delim;

  } else if (type == SpecialToken::kOpenBracket && !func_stack.empty()) {
    ++func_stack.top().br_counter;

  } else if (type == SpecialToken::kCloseBracket && !func_stack.empty()) {
    --func_stack.top().br_counter;

    if (func_stack.top().br_counter == 0 && func_stack.top().need_delim != 0)
      ThrowInvalidSeq(func_stack.top().func, token);
    else if (func_stack.top().br_counter == 0)
      func_stack.pop();
  }
}

void PolishNotation::ThrowInvalidSeq(const Token& prev_token,
                                     const Token& token) {
  size_t start = prev_token.GetIndexStart();
  size_t len =
      token.GetIndexStart() - prev_token.GetIndexStart() + token.GetLen();
  throw InvalidExpr(kErrorMsgs[kBadTokenSequence], start, len);
}

void PolishNotation::PushMultToken(std::stack<Token>& stack) {
  Token mul_token(Token::kOperation, Operation::GetSpecialCharOperator("*", 2));
  PushToken(stack, mul_token);
}

void PolishNotation::PushToken(std::stack<Token>& stack, const Token& token) {
  if (token.IsNum() || token.IsVar()) {
    polish_notation_.push_back(token);

  } else if (token.IsSpecialToken()) {
    const SpecialToken* special_token = token.GetSpecialToken();
    if (special_token->IsOpenBracket()) {
      stack.push(token);

    } else if (special_token->IsCloseBracket()) {
      PopUntilOpenBracket(stack, token);

    } else if (special_token->IsOperandDelimetr()) {
      PopUntilOpenBracketD(stack);
    }

  } else if (token.IsOper()) {
    const Operation* oper = token.GetOperation();
    if (oper->IsPostfix()) {
      polish_notation_.push_back(token);

    } else if (oper->IsPrefix()) {
      stack.push(token);

    } else if (oper->IsInfix()) {
      PopUntilLessPriority(stack, oper->GetPriority());
      stack.push(token);
    }
  }
}

void PolishNotation::PopUntilLessPriority(std::stack<Token>& stack,
                                          size_t priotity) {
  while (!stack.empty()) {
    Token token = stack.top();

    if (token.IsSpecialToken()) break;

    const Operation* operation = token.GetOperation();
    if (operation->IsPrefix()) {
      polish_notation_.push_back(token);
      stack.pop();

    } else if (operation->GetPriority() > priotity) {
      polish_notation_.push_back(token);
      stack.pop();

    } else if (operation->GetPriority() == priotity &&
               operation->IsLeftAssociative()) {
      polish_notation_.push_back(token);
      stack.pop();

    } else {
      break;
    }
  }
}

void PolishNotation::PopUntilOpenBracket(std::stack<Token>& stack,
                                         const Token& bracket_token) {
  const std::string& bracket = bracket_token.GetSpecialToken()->GetName();
  while (!stack.empty()) {
    Token token = stack.top();
    stack.pop();

    if (token.IsSpecialToken()) {
      const SpecialToken* special_token = token.GetSpecialToken();
      if (special_token->IsEqualCloseBracket(bracket)) {
        if (!stack.empty() && stack.top().IsOper() &&
            stack.top().GetOperation()->IsPrefix()) {
          polish_notation_.push_back(stack.top());
          stack.pop();
        }
        return;

      } else {
        size_t index_start = token.GetIndexStart();
        size_t len = bracket_token.GetIndexStart() - index_start + 1;
        throw InvalidExpr(kErrorMsgs[kBadBrackets], index_start, len);
      }

    } else {
      polish_notation_.push_back(token);
    }
  }

  size_t index_start = 0;
  size_t len = bracket_token.GetIndexStart() - index_start + 1;
  throw InvalidExpr(kErrorMsgs[kBadBrackets], index_start, len);
}

void PolishNotation::PopUntilOpenBracketD(std::stack<Token>& stack) {
  while (!stack.empty()) {
    Token token = stack.top();

    if (token.IsSpecialToken()) {
      const SpecialToken* special_token = token.GetSpecialToken();
      if (special_token->IsOpenBracket()) return;

    } else {
      stack.pop();
      polish_notation_.push_back(token);
    }
  }
}

void PolishNotation::PopAll(std::stack<Token>& stack, size_t expr_len) {
  while (!stack.empty()) {
    Token& token = stack.top();
    if (!token.IsOper()) {
      size_t index_start = token.GetIndexStart();
      size_t len = expr_len - index_start;
      throw InvalidExpr(kErrorMsgs[kBadBrackets], index_start, len);
    }

    polish_notation_.push_back(token);
    stack.pop();
  }
}

}  // namespace s21
