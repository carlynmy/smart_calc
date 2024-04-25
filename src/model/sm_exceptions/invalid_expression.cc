// Implementation class InvalidExpr

// Copyright (C) 2023-2023 School 21 License

#include "invalid_expression.h"

#include <cstddef>
#include <exception>
#include <string>

#include "../token/token.h"

namespace s21 {

InvalidExpr::InvalidExpr(const std::string& what) : InvalidExpr(what, 0, 0) {}

InvalidExpr::InvalidExpr(const std::string& what, size_t i_start_err,
                         size_t len_err)
    : what_(what), i_start_err_(i_start_err), len_err_(len_err) {}

InvalidExpr::InvalidExpr(const std::string& what, const Token& token,
                         const Token& prev_token)
    : what_(what) {
  i_start_err_ = prev_token.GetIndexStart();
  len_err_ =
      token.GetIndexStart() - prev_token.GetIndexStart() + token.GetLen();
}

InvalidExpr::~InvalidExpr() {}

// ------------------------------------------------------------------------- //

const char* InvalidExpr::what() const noexcept { return what_.c_str(); }

size_t InvalidExpr::GetIndexStartErr() const { return i_start_err_; }

size_t InvalidExpr::GetLenErr() const { return len_err_; }

}  // namespace s21
