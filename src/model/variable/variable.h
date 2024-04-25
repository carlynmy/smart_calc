// Declaration class Variable

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_VARIABLE_VARIABLE_H_
#define SMART_CALC_V_2_MODEL_VARIABLE_VARIABLE_H_

#include <string>

namespace s21 {

/// @brief Variable with two fields - name and value
class Variable {
 public:
  Variable();
  Variable(std::string name, double value);
  ~Variable();

  const std::string& GetName() const;

  void SetName(std::string name);

  double GetValue() const;

  void SetValue(double value);

  bool operator==(const Variable& other) const;

 private:
  std::string name_;
  double value_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_VARIABLE_VARIABLE_H_
