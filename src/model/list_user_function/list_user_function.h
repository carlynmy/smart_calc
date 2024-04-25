// Declaration class ListUserFunction

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_LIST_USER_FUNCTION_LIST_USER_FUNCTION_H_
#define SMART_CALC_V_2_MODEL_LIST_USER_FUNCTION_LIST_USER_FUNCTION_H_

#include <cstddef>
#include <list>
#include <string>

#include "../user_function/user_function.h"

namespace s21 {

class ListUserFunction {
  using List = std::list<UserFunction>;

 public:
  using iterator = typename List::iterator;
  using const_iterator = typename List::const_iterator;

  ListUserFunction();

  ~ListUserFunction();

  // ----------------------------------------------------------------------- //

  /// @brief Add user function to list
  void Add(const UserFunction& var);

  /// @brief Remove user function from list
  /// @return true if remove success. false if no such item
  bool Remove(const UserFunction& var);

  /// @brief Remove user function from list by name
  /// @return true if remove success. false if no such item
  bool Remove(const std::string& name);

  /// @brief Clear list
  void Clear();

  // ----------------------------------------------------------------------- //

  size_t Size() const;

  /// @brief Get pointer to user function
  /// @return Pointer to user function in list, if user function didnt exist
  /// nullptr
  UserFunction* Get(const UserFunction& var);

  /// @brief Get pointer to user function by name
  /// @return Pointer to user function in list, if user function didnt exist
  /// nullptr
  UserFunction* Get(const std::string& name);

  /// @brief Get const pointer to user function
  /// @return Const pointer to user function in list, if user function didnt
  /// exist nullptr
  const UserFunction* Get(const UserFunction& var) const;

  /// @brief Get const pointer to user function by name
  /// @return Const pointer to user function in list, if user function didnt
  /// exist nullptr
  const UserFunction* Get(const std::string& name) const;

  // ----------------------------------------------------------------------- //

  iterator Begin();
  iterator End();

  const_iterator Begin() const;
  const_iterator End() const;

 private:
  List list_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_LIST_USER_FUNCTION_LIST_USER_FUNCTION_H_
