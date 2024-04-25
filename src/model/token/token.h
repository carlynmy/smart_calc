// Declaration class Token

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_TOKEN_TOKEN_H_
#define SMART_CALC_V_2_MODEL_TOKEN_TOKEN_H_

#include <cstddef>

#include "../operation/operation.h"
#include "../special_token/special_token.h"
#include "../user_function/user_function.h"
#include "../variable/variable.h"

namespace s21 {

class Token {
 public:
  enum Type { kNull, kSpecialToken, kOperation, kUserFunc, kVar, kNum };

  Token(Type type = kNull, size_t index_start = 0, size_t len = 0);
  Token(Type type, const SpecialToken* special_token, size_t index_start = 0,
        size_t len = 0);
  Token(Type type, const Operation* operation, size_t index_start = 0,
        size_t len = 0);
  Token(Type type, const UserFunction* user_function, size_t index_start = 0,
        size_t len = 0);
  Token(Type type, const Variable* variable, size_t index_start = 0,
        size_t len = 0);
  Token(Type type, double num, size_t index_start = 0, size_t len = 0);

  ~Token() {}

  // ----------------------------------------------------------------------  //

  Type GetType() const;
  const SpecialToken* GetSpecialToken() const;
  const UserFunction* GetUserFunction() const;
  const Operation* GetOperation() const;
  const Variable* GetVariable() const;
  double GetNum() const;
  size_t GetIndexStart() const;
  size_t GetLen() const;

  // ----------------------------------------------------------------------  //

  bool IsNull() const;
  bool IsSpecialToken() const;
  bool IsOper() const;
  bool IsUserFunction() const;
  bool IsVar() const;
  bool IsNum() const;

  // ----------------------------------------------------------------------  //

  bool operator==(const Token& other) const;

  // ----------------------------------------------------------------------  //

 private:
  enum Type type_;

  union {
    const SpecialToken* special_token_;
    const Operation* operation_;
    const Variable* variable_;
    const UserFunction* user_function_;
    double num_;
  };

  size_t index_start_;
  size_t len_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_TOKEN_TOKEN_H_
