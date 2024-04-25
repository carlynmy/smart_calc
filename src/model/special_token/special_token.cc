// Implementation class SpecialToken

// Copyright (C) 2023-2023 School 21 License

#include "special_token.h"

#include <list>
#include <string>

namespace s21 {

SpecialToken::SpecialToken(SpecitalTokenType special_token_type,
                           const std::string& name,
                           const std::string& eq_bracket)
    : special_token_type_(special_token_type),
      name_(name),
      eq_bracket_(eq_bracket) {}

SpecialToken::~SpecialToken() {}

// ------------------------------------------------------------------------- //

SpecialToken::SpecitalTokenType SpecialToken::GetSpecitalTokenType() const {
  return special_token_type_;
}

const std::string& SpecialToken::GetName() const { return name_; }

// ------------------------------------------------------------------------- //

bool SpecialToken::IsOpenBracket() const {
  return special_token_type_ == kOpenBracket;
}

bool SpecialToken::IsCloseBracket() const {
  return special_token_type_ == kCloseBracket;
}

bool SpecialToken::IsEqualOpenBracket(const std::string& bracket) const {
  return SpecialToken::IsCloseBracket() && eq_bracket_ == bracket;
}

bool SpecialToken::IsEqualCloseBracket(const std::string& bracket) const {
  return SpecialToken::IsOpenBracket() && eq_bracket_ == bracket;
}

bool SpecialToken::IsEqualSign() const {
  return special_token_type_ == kEqualSign;
}

bool SpecialToken::IsOperandDelimetr() const {
  return special_token_type_ == kOperandDelimetr;
}

// ------------------------------------------------------------------------- //

bool SpecialToken::operator==(const SpecialToken& other) const {
  return special_token_type_ == other.special_token_type_ &&
         name_ == other.name_ && eq_bracket_ == other.eq_bracket_;
}

// ------------------------------------------------------------------------- //

const SpecialToken* SpecialToken::GetSpecitalToken(const std::string& name) {
  std::list<SpecialToken>::iterator iter = list_special_token_.begin();
  for (; iter != list_special_token_.end(); ++iter) {
    if (iter->GetName() == name) return &(*iter);
  }

  return nullptr;
}

// ------------------------------------------------------------------------- //

std::list<SpecialToken> SpecialToken::list_special_token_ = {
    SpecialToken(SpecialToken::kOpenBracket, "(", ")"),
    SpecialToken(SpecialToken::kCloseBracket, ")", "("),
    SpecialToken(SpecialToken::kOpenBracket, "[", "]"),
    SpecialToken(SpecialToken::kCloseBracket, "]", "["),
    SpecialToken(SpecialToken::kOpenBracket, "{", "}"),
    SpecialToken(SpecialToken::kCloseBracket, "}", "{"),
    SpecialToken(SpecialToken::kOperandDelimetr, ","),
    SpecialToken(SpecialToken::kOperandDelimetr, ";"),
    SpecialToken(SpecialToken::kEqualSign, "="),
};

}  // namespace s21
