// Implementation class TokenParser

// Copyright (C) 2023-2023 School 21 License

#include "token_parser.h"

#include <cmath>
#include <cstddef>
#include <string>

#include "../sm_exceptions/invalid_expression.h"
#include "../token/token.h"

namespace s21 {

TokenParser::TokenParser(const std::string& str, size_t i,
                         const ListVariable* list_variable,
                         const ListUserFunction* list_user_function)
    : str_(str),
      i_(i),
      list_variable_(list_variable),
      list_user_function_(list_user_function) {}

TokenParser::~TokenParser() {}

// ------------------------------------------------------------------------- //

const std::string& TokenParser::GetStr() const { return str_; }

size_t TokenParser::GetI() const { return i_; }

// ------------------------------------------------------------------------- //

void TokenParser::SetStr(const std::string& str) { str_ = str; }
void TokenParser::SetI(size_t i) { i_ = i; }

void TokenParser::SetListVariable(const ListVariable* list_variable) {
  list_variable_ = list_variable;
}

void TokenParser::SetListUserFunction(
    const ListUserFunction* list_user_function) {
  list_user_function_ = list_user_function;
}

// ------------------------------------------------------------------------- //

Token TokenParser::NextToken(const Token& prev_token) {
  while (i_ < str_.length() && std::isspace(str_[i_])) ++i_;
  if (i_ == str_.length()) return Token(Token::kNull, i_, 0);

  Token token = NextTokenNum();
  if (token.IsNull()) token = NextTokenSpecialToken();
  if (token.IsNull()) token = NextTokenSpecialCharOperation(prev_token);
  if (token.IsNull()) token = NextTokenWord();

  return token;
}

Token TokenParser::NextTokenNum() {
  if (!IsNumChar(str_[i_])) return Token(Token::kNull);

  size_t len = 1;
  bool dot_flag = false;
  bool exp_flag = false;
  bool break_flag = false;
  while (!break_flag) {
    char ch = str_[i_ + len - 1];
    if (i_ + len > str_.length()) {
      --len;
      break_flag = true;
    } else if (ch == '.') {
      if (dot_flag) {
        break_flag = true;
        --len;
      } else {
        dot_flag = true;
      }

    } else if (ch == 'E') {
      if (exp_flag) {
        break_flag = true;
        --len;
      } else {
        dot_flag = true;
        exp_flag = true;
      }

    } else if (ch == '+' || ch == '-') {
      if (str_[i_ + len - 2] != 'E') {
        break_flag = true;
        --len;
      }

    } else if (!(ch >= '0' && ch <= '9')) {
      --len;
      break_flag = true;
    }

    if (!break_flag) ++len;
  }

  double num = std::stod(str_.substr(i_, len));
  Token token(Token::kNum, num, i_, len);
  i_ += len;

  return token;
}

Token TokenParser::NextTokenSpecialToken() {
  Token token(Token::kNull);
  const SpecialToken* special_token =
      SpecialToken::GetSpecitalToken(str_.substr(i_, 1));
  if (special_token != nullptr) {
    token = Token(Token::kSpecialToken, special_token, i_, 1);
    ++i_;
  }
  return token;
}

Token TokenParser::NextTokenSpecialCharOperation(const Token& prev_token) {
  size_t operand_count = 2;

  if (prev_token.IsNull())
    operand_count = 1;
  else if (prev_token.IsSpecialToken() &&
           prev_token.GetSpecialToken()->IsOpenBracket())
    operand_count = 1;
  else if (prev_token.IsOper() && !prev_token.GetOperation()->IsPostfix())
    operand_count = 1;

  Token token(Token::kNull);
  const Operation* oper =
      Operation::GetSpecialCharOperator(str_.substr(i_, 1), operand_count);
  if (oper != nullptr) {
    token = Token(Token::kOperation, oper, i_, 1);
    ++i_;
  }

  return token;
}

Token TokenParser::NextTokenWord() {
  Token token = Token(Token::kNull, i_, 0);
  size_t token_len = 1;
  while (token.IsNull()) {
    if (i_ + token_len > str_.length()) {
      throw InvalidExpr(kErrorMsgs[kUndefinedToken], i_, token_len - 1);
    }

    if (!IsAviCharWithWordToken(str_[i_ + token_len - 1])) {
      throw InvalidExpr(kErrorMsgs[kUndefinedToken], i_, token_len - 1);
    }

    std::string substr = str_.substr(i_, token_len);
    const Operation* oper = nullptr;
    const Variable* var = nullptr;
    const UserFunction* user_func = nullptr;

    oper = Operation::GetOperation(substr);
    if (oper != nullptr) token = Token(Token::kOperation, oper, i_, token_len);

    if (token.IsNull()) {
      var = list_variable_->Get(substr);
      if (var != nullptr) token = Token(Token::kVar, var, i_, token_len);
    }

    if (token.IsNull()) {
      user_func = list_user_function_->Get(substr);
      if (user_func != nullptr)
        token = Token(Token::kUserFunc, user_func, i_, token_len);
    }

    ++token_len;
  }

  i_ += token_len - 1;
  return token;
}

std::string TokenParser::NextWord() {
  while (i_ < str_.length() && std::isspace(str_[i_])) ++i_;
  if (i_ == str_.length()) return "";

  if (!IsAviCharWithWordToken(str_[i_]) || IsNumChar(str_[i_])) return "";

  size_t len = 1;
  while (IsAviCharWithWordToken(str_[i_ + len - 1])) {
    ++len;
  }

  std::string word = str_.substr(i_, len - 1);
  i_ += len - 1;
  return word;
}

double TokenParser::NextNum() {
  while (i_ < str_.length() && std::isspace(str_[i_])) ++i_;
  if (i_ == str_.length()) return NAN;

  bool neg_flag = false;
  if (str_[i_] == '-') {
    ++i_;
    neg_flag = true;
  }

  Token token = NextTokenNum();
  if (token.IsNull()) {
    if (neg_flag) --i_;
    return NAN;
  }

  if (neg_flag) return -token.GetNum();
  return token.GetNum();
}

// ------------------------------------------------------------------------- //

bool TokenParser::ContainToken(const Token& token) {
  Token next_token = token;
  do {
    try {
      next_token = NextToken();
    } catch (const InvalidExpr&) {
      std::string next_word = NextWord();
      if (next_word == "") return false;
      continue;
    }
    if (next_token == token) return true;

  } while (!next_token.IsNull());

  return false;
}

// ------------------------------------------------------------------------- //

bool TokenParser::IsNumChar(char c) {
  return ((c >= '0' && c <= '9') || c == '.');
}

bool TokenParser::IsAviCharWithWordToken(char c) {
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' ||
          (c >= '0' && c <= '9'));
}

}  // namespace s21
