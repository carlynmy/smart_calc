// Declaration class TokenParser

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_TOKEN_PARSER_TOKEN_PARSER_H_
#define SMART_CALC_V_2_MODEL_TOKEN_PARSER_TOKEN_PARSER_H_

#include <cstddef>
#include <string>

#include "../list_user_function/list_user_function.h"
#include "../list_variable/list_variable.h"
#include "../operation/operation.h"
#include "../special_token/special_token.h"
#include "../token/token.h"

namespace s21 {

class TokenParser {
 public:
  TokenParser(const std::string& str = "", size_t i = 0,
              const ListVariable* list_variable = nullptr,
              const ListUserFunction* list_user_function = nullptr);

  ~TokenParser();

  // ----------------------------------------------------------------------- //

  const std::string& GetStr() const;
  size_t GetI() const;

  // ----------------------------------------------------------------------- //

  void SetStr(const std::string& str);
  void SetI(size_t i);
  void SetListVariable(const ListVariable* list_variable);
  void SetListUserFunction(const ListUserFunction* list_user_function);

  // ----------------------------------------------------------------------- //

  /// @brief Get next token
  /// @param prev_token Need to differentiate some tokens
  /// @exception s21::InvalidExpression if token undefined
  /// @return if expression end return null-token, otherwise next token
  Token NextToken(const Token& prev_token = Token(Token::kNull));

  /// @brief Get next word. Word is sequence symbols AZ, az, _, 09, not start 09
  /// @return "" if expression end or no word here, othrewise next word
  std::string NextWord();

  /// @brief Get next num
  /// @return NAN if next not num, otherwise next num
  double NextNum();

  // ----------------------------------------------------------------------- //

  bool ContainToken(const Token& token);

 private:
  enum ErrorIndexes { kUndefinedToken };

  static inline const std::string kErrorMsgs[] = {"Неопределенный токен"};

  Token NextTokenNum();
  Token NextTokenSpecialToken();
  Token NextTokenSpecialCharOperation(const Token& prev_token);
  Token NextTokenWord();

  static bool IsNumChar(char c);
  static bool IsAviCharWithWordToken(char c);

  std::string str_;
  size_t i_;
  const ListVariable* list_variable_;
  const ListUserFunction* list_user_function_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_TOKEN_PARSER_TOKEN_PARSER_H_
