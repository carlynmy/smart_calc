// Declaration class SpecialToken

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_SPECIAL_TOKEN_SPECIAL_TOKEN_H_
#define SMART_CALC_V_2_MODEL_SPECIAL_TOKEN_SPECIAL_TOKEN_H_

#include <list>
#include <string>

namespace s21 {

/// @brief Class SpecialToken and static defind special tokens
class SpecialToken {
 public:
  enum SpecitalTokenType {
    kOpenBracket,
    kCloseBracket,
    kOperandDelimetr,
    kEqualSign
  };

  // ----------------------------------------------------------------------- //

  SpecialToken(SpecitalTokenType special_token_type, const std::string& name,
               const std::string& eq_bracket = "");

  ~SpecialToken();

  // ----------------------------------------------------------------------- //

  SpecitalTokenType GetSpecitalTokenType() const;
  const std::string& GetName() const;

  // ----------------------------------------------------------------------- //

  bool IsOpenBracket() const;
  bool IsCloseBracket() const;

  bool IsEqualOpenBracket(const std::string& bracket) const;
  bool IsEqualCloseBracket(const std::string& bracket) const;

  bool IsEqualSign() const;
  bool IsOperandDelimetr() const;

  // ----------------------------------------------------------------------- //

  bool operator==(const SpecialToken& other) const;

  // ----------------------------------------------------------------------- //

  /// @brief Get const pointer to special token
  /// @return Const pointer to special token, if special token didnt exist
  /// nullptr
  static const SpecialToken* GetSpecitalToken(const std::string& name);

 private:
  static std::list<SpecialToken> list_special_token_;

  SpecitalTokenType special_token_type_;
  std::string name_;
  std::string eq_bracket_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_SPECIAL_TOKEN_SPECIAL_TOKEN_H_
