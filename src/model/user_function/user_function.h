// Declaration class UserFunction

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_USER_FUNCTION_USER_FUNCTION_H_
#define SMART_CALC_V_2_MODEL_USER_FUNCTION_USER_FUNCTION_H_

#include <list>
#include <string>

#include "../list_variable/list_variable.h"
#include "../operation/operation.h"

namespace s21 {

class PolishNotation;

/// @brief UserFunction with 3 fiels - name, list variables, polish
/// notation. To use fill in the input data by construct or by using setters/
/// Then invoke method Calc
class UserFunction : public Operation {
 public:
  UserFunction(const std::string& name = "");
  UserFunction(const std::string& name, const std::string& define,
               const ListVariable& list_variable,
               const PolishNotation& polish_notation);
  UserFunction(const UserFunction& other);
  UserFunction(UserFunction&& other);

  UserFunction& operator=(const UserFunction& other);
  UserFunction& operator=(UserFunction&& other);

  ~UserFunction();

  // ----------------------------------------------------------------------- //

  const std::string& GetDefine() const;
  const ListVariable& GetListVariable() const;
  const PolishNotation& GetPolishNotation() const;

  void SetName(const std::string& name);
  void SetDefine(const std::string& define);
  void SetListVariable(const ListVariable& define);
  void SetPolishNotation(const PolishNotation& define);

  // ----------------------------------------------------------------------- //

  bool operator==(const UserFunction& other) const;

  // ----------------------------------------------------------------------- //

  /// @brief Calcualte result by given arguments
  /// @exception std::logic_error if data not input
  /// @exception s21::InvalidExpr if invalid expr given
  double Calc(const std::list<double>& arg_list) const override;

  /// @brief Translate  and validate function define
  /// @exception s21::InvalidExpr if invalid define
  void Translate();

 private:
  enum ErrorIndexes { kDataNotInput };

  static inline const std::string kErrorMsgs[] = {"Не введеные входные данные"};

  std::string define_;
  ListVariable list_variable_;
  PolishNotation* polish_notation_;

  bool is_data_input_ = false;
  bool is_translate_ = false;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_USER_FUNCTION_USER_FUNCTION_H_
