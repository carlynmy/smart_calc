// Declaration class CalcualtionError

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_SM_EXCEPTIONS_CALCULATION_ERROR_H_
#define SMART_CALC_V_2_MODEL_SM_EXCEPTIONS_CALCULATION_ERROR_H_

#include <exception>
#include <string>

namespace s21 {

class CalculationError : public std::exception {
 public:
  CalculationError(const std::string& what) : what_(what) {}

  const char* what() const noexcept override { return what_.c_str(); }

 private:
  std::string what_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_SM_EXCEPTIONS_CALCULATION_ERROR_H_
