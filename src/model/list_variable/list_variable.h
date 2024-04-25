// Declaration class ListVariable

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_LIST_VARIABLE_LIST_VARIABLE_H_
#define SMART_CALC_V_2_MODEL_LIST_VARIABLE_LIST_VARIABLE_H_

#include <cstddef>
#include <list>
#include <string>

#include "../variable/variable.h"

namespace s21 {

class ListVariable {
  using List = std::list<Variable>;

 public:
  using iterator = typename List::iterator;
  using const_iterator = typename List::const_iterator;

  ListVariable();
  ~ListVariable();

  // ------------------------------------------------------------------------ //

  /// @brief Add variable to list
  void Add(const Variable& var);

  /// @brief Remove variable from list
  /// @return true if remove succes. false if no such var
  bool Remove(const Variable& var);

  /// @brief Remove variable from list by name
  /// @return true if remove succes. false if no such var
  bool Remove(const std::string& name);

  /// @brief Clear list
  void Clear();

  // ------------------------------------------------------------------------ //

  size_t Size() const;

  /// @brief Get pointer to variable
  /// @return Pointer to variable in list, if variable didnt exist nullptr
  Variable* Get(const Variable& var);

  /// @brief Get pointer to variable by name
  /// @return Pointer to variable in list, if variable didnt exist nullptr
  Variable* Get(const std::string& name);

  /// @brief Get const pointer to variable
  /// @return Const pointer to variable in list, if variable didnt exist nullptr
  const Variable* Get(const Variable& var) const;

  /// @brief Get const pointer to variable by name
  /// @return Const pointer to variable in list, if variable didnt exist nullptr
  const Variable* Get(const std::string& name) const;

  // ------------------------------------------------------------------------ //

  iterator Begin();
  iterator End();

  const_iterator Begin() const;
  const_iterator End() const;

 private:
  List list_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_LIST_VARIABLE_LIST_VARIABLE_H_
