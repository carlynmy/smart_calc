// Declaration class InvalidExpr

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_SM_EXCEPTIONS_INVALID_EXPRESSION_H_
#define SMART_CALC_V_2_MODEL_SM_EXCEPTIONS_INVALID_EXPRESSION_H_

#include <cstddef>
#include <exception>
#include <string>

#include "../token/token.h"

namespace s21 {

class InvalidExpr : public std::exception {
 public:
  InvalidExpr(const std::string& what);

  InvalidExpr(const std::string& what, size_t i_start_err, size_t len_err);

  InvalidExpr(const std::string& what, const Token& token,
              const Token& prev_token);

  ~InvalidExpr();

  // ----------------------------------------------------------------------- //

  const char* what() const noexcept override;
  size_t GetIndexStartErr() const;
  size_t GetLenErr() const;

 private:
  std::string what_;
  size_t i_start_err_;
  size_t len_err_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_SM_EXCEPTIONS_INVALID_EXPRESSION_H_
