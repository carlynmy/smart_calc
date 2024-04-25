// Implementation class Token

// Copyright (C) 2023-2023 School 21 License

#include "token.h"

#include <cstddef>

#include "../operation/operation.h"
#include "../special_token/special_token.h"
#include "../user_function/user_function.h"
#include "../variable/variable.h"

namespace s21 {

Token::Token(Type type, size_t index_start, size_t len)
    : type_(type), index_start_(index_start), len_(len) {}

Token::Token(Type type, const SpecialToken* special_token, size_t index_start,
             size_t len)
    : Token(type, index_start, len) {
  special_token_ = special_token;
}

Token::Token(Type type, const Operation* operation, size_t index_start,
             size_t len)
    : Token(type, index_start, len) {
  operation_ = operation;
}

Token::Token(Type type, const UserFunction* user_function, size_t index_start,
             size_t len)
    : Token(type, index_start, len) {
  user_function_ = user_function;
}

Token::Token(Type type, const Variable* variable, size_t index_start,
             size_t len)
    : Token(type, index_start, len) {
  variable_ = variable;
}

Token::Token(Type type, double num, size_t index_start, size_t len)
    : Token(type, index_start, len) {
  num_ = num;
}

// ------------------------------------------------------------------------- //

Token::Type Token::GetType() const { return type_; }

const SpecialToken* Token::GetSpecialToken() const { return special_token_; }

const UserFunction* Token::GetUserFunction() const { return user_function_; }

const Operation* Token::GetOperation() const { return operation_; }

const Variable* Token::GetVariable() const { return variable_; }

double Token::GetNum() const { return num_; }

size_t Token::GetIndexStart() const { return index_start_; }

size_t Token::GetLen() const { return len_; }

// ------------------------------------------------------------------------- //

bool Token::IsNull() const { return type_ == kNull; }

bool Token::IsSpecialToken() const { return type_ == kSpecialToken; }

bool Token::IsOper() const { return type_ == kOperation || type_ == kUserFunc; }

bool Token::IsUserFunction() const { return type_ == kUserFunc; }

bool Token::IsVar() const { return type_ == kVar; }

bool Token::IsNum() const { return type_ == kNum; }

// ------------------------------------------------------------------------- //

bool Token::operator==(const Token& other) const {
  if (type_ != other.type_) return false;

  if (type_ == kNull) {
    return true;

  } else if (type_ == kSpecialToken) {
    const SpecialToken* sp_a = GetSpecialToken();
    const SpecialToken* sp_b = other.GetSpecialToken();
    return *sp_a == *sp_b;

  } else if (type_ == kOperation) {
    const Operation* op_a = GetOperation();
    const Operation* op_b = other.GetOperation();
    return *op_a == *op_b;

  } else if (type_ == kUserFunc) {
    const UserFunction* uf_a = GetUserFunction();
    const UserFunction* uf_b = other.GetUserFunction();
    return *uf_a == *uf_b;

  } else if (type_ == kVar) {
    const Variable* v_a = GetVariable();
    const Variable* v_b = other.GetVariable();
    return *v_a == *v_b;

  } else if (type_ == kNum) {
    double n_a = GetNum();
    double n_b = other.GetNum();
    return n_a == n_b;
  }

  return false;
}

}  // namespace s21
