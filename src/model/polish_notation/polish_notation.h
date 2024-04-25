// Declaration class PolishNotation

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_POLISH_NOTATION_POLISH_NOTATION_H_
#define SMART_CALC_V_2_MODEL_POLISH_NOTATION_POLISH_NOTATION_H_

#include <cstddef>
#include <list>
#include <stack>
#include <string>

#include "../list_user_function/list_user_function.h"
#include "../list_variable/list_variable.h"
#include "../sm_exceptions/invalid_expression.h"
#include "../token/token.h"

namespace s21 {

/// @brief Class PolishNotation is used for calculate infix expressions. To use
/// fill the input data by construct or by using setters, then invoke method
/// Translate to validate and translate expression to polish notation, then
/// invoke method Calc to get result.
class PolishNotation {
 public:
  enum TypeTokenSeq {
    kSeqValid,                         // Token sequence id valid
    kSeqNeedMult,                      // Beetwen tokens need mult sign
    kSeqInvalid,                       // Token sequence is invalid
    kSeqBracketCloseImmediately,       // Open bracket then close bracket
    kSeqOpenBracketAfterZeroParamFunc  // Function with zero then open bracket

  };

  PolishNotation();
  PolishNotation(const std::string& expr,
                 const ListVariable& list_variable = {},
                 const ListUserFunction& list_user_function = {});
  ~PolishNotation();

  // ----------------------------------------------------------------------- //

  const std::string& GetExpression() const;
  const ListVariable& GetListVariable() const;
  const ListUserFunction& GetListUserFunction() const;

  /// @brief Set expression. You will need to call again method Translate
  void SetExpression(const std::string& expr);

  /// @brief Set list variable. You will need to call again method Translate
  void SetListVariable(const ListVariable& list_variable);

  /// @brief Set list user function. You will need to call again method
  /// Translate
  void SetListUserFunction(const ListUserFunction& list_user_function);

  /// @brief Update value of variable
  /// @exception std::logic_error if invalid name given
  void UpdateVariableValue(const Variable& var);

  /// @brief Update value of variable
  /// @exception std::logic_error if invalid name given
  void UpdateVariableValue(const std::string& name, double value);

  // ----------------------------------------------------------------------- //

  bool IsDataInput() const;
  bool IsTranslate() const;

  // ----------------------------------------------------------------------- //

  /// @brief Validate and translate infix expression
  /// @exception std::logic_error if data not input. s21::InvalidExpr if invalid
  /// expr given
  void Translate();

  /// @brief Calculate result of expression. Expression must be validate and
  /// translate by method Translate
  /// @exception std::logic_error if expression not translate.
  /// s21::Calculation_error if result cant be calculated
  double Calc();

  // ----------------------------------------------------------------------- //

  /// @brief Define type of token sequence from enum TypeTokenSeq
  static TypeTokenSeq GetTypeTokenSeq(const Token& a, const Token& b);

 private:
  enum ErrorIndexes {
    kDataNotInput,
    kExprNotTranslate,
    kUndefinedVar,
    kEmptyExpr,
    kBadTokenSequence,
    kUndefinedToken,
    kBadBrackets
  };

  struct FuncInfo {
    Token func;
    Token open_bracket;
    size_t need_delim;
    size_t br_counter;
  };

  static inline const std::string kErrorMsgs[] = {
      "Не введеные входные данные",
      "Выражение не валидировано и не переведенно",
      "Не существует переменной с таким названием",
      "Пустое выражение",
      "Неккоректная последовательность токенов",
      "Неопределенный токен",
      "Не согласованы скобки"};

  void ValidateSequence(const Token& token, const Token& prev_token,
                        std::stack<Token>& stack,
                        bool& is_prev_open_bracket_after_zero_param_func);
  void ValidateManyParamFunction(const Token& token, const Token& prev_token,
                                 std::stack<FuncInfo>& func_stack);

  void ThrowInvalidSeq(const Token& prev_token, const Token& token);
  void PushMultToken(std::stack<Token>& stack);

  void PushToken(std::stack<Token>& stack, const Token& token);

  void PopUntilLessPriority(std::stack<Token>& stack, size_t priotity);
  void PopUntilOpenBracket(std::stack<Token>& stack,
                           const Token& bracket_token);
  void PopUntilOpenBracketD(std::stack<Token>& stack);
  void PopAll(std::stack<Token>& stack, size_t expr_len);

  std::string expr_;
  ListVariable list_variable_;
  ListUserFunction list_user_function_;

  std::list<Token> polish_notation_;
  bool is_data_input_ = false;
  bool is_translate_ = false;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_POLISH_NOTATION_POLISH_NOTATION_H_
