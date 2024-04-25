// Declaration class Operation

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_OPERATION_OPERATION_H_
#define SMART_CALC_V_2_MODEL_OPERATION_OPERATION_H_

#include <cstddef>
#include <list>
#include <string>

#include "../sm_exceptions/calculation_error.h"

namespace s21 {

/// @brief Class operation and static defind operations
class Operation {
 public:
  enum PositionType { kPrefix, kInfix, kPostfix };
  enum NameType { kSpecialChar, kWord };
  enum AssociativeType { kRight, kLeft };

  using PFunc = double (*)(const std::list<double>&);

  // ----------------------------------------------------------------------- //

  Operation(std::string name, size_t priority, size_t operand_count,
            PositionType position_type, NameType name_type,
            AssociativeType associative_type, PFunc p_func);

  virtual ~Operation();

  // ----------------------------------------------------------------------- //

  size_t GetOperandCount() const;
  PositionType GetPositionType() const;
  NameType GetNameType() const;
  AssociativeType GetAssociativeType() const;
  const std::string& GetName() const;
  size_t GetPriority() const;
  PFunc GetPFunc() const;

  // ----------------------------------------------------------------------- //

  bool IsUnary() const;
  bool IsBinary() const;
  bool IsPrefix() const;
  bool IsInfix() const;
  bool IsPostfix() const;
  bool IsOperator() const;
  bool IsFunction() const;
  bool IsLeftAssociative() const;
  bool IsRightAssociative() const;

  bool IsLessPriority(const Operation& other) const;
  bool IsEqPriority(const Operation& other) const;
  bool IsGreaterPriority(const Operation& other) const;

  // ----------------------------------------------------------------------- //

  bool operator==(const Operation& other) const;

  // ----------------------------------------------------------------------- //

  /// @brief Get const pointer to special char operation
  /// @return Const pointer to operation, if operation didnt exist nullptr
  static const Operation* GetSpecialCharOperator(const std::string& name,
                                                 size_t operand_count);

  /// @brief Get const pointer to operation
  /// @return Const pointer to operation, if operation didnt exist nullptr
  static const Operation* GetOperation(const std::string& name);

  // ----------------------------------------------------------------------- //

  /// @brief Calculate result
  /// @param arg_list Argument list
  /// @exception s21::Calculation_error if result cant be calculated
  virtual double Calc(const std::list<double>& arg_list) const;

 protected:
  void SetName(const std::string& name);
  void SetOperandCount(size_t operand_count);

 private:
  enum ErrorIndexes {
    kDivZero,
    kNonPositiveLog,
    kZeroPowZero,
    kZeroPowNeg,
    kNegPowIrr,
    kIrrFact,
    kNegFact
  };

  static std::list<Operation> list_special_char_operator_;
  static std::list<Operation> list_operator_;

  static inline const std::string kErrorMsgs[] = {
      "Деление на ноль",
      "Логарифм от не положительного числа",
      "Ноль в степени ноль",
      "Ноль в отрицательной степени",
      "Отрицательно число в иррациональной степени",
      "Факториал от иррационального числа",
      "Факториал от отрицательного числа"};

  static double OperUnaryMinus(const std::list<double>& arg_list);
  static double OperUnaryPlus(const std::list<double>& arg_list);

  static double OperCos(const std::list<double>& arg_list);
  static double OperSin(const std::list<double>& arg_list);
  static double OperTan(const std::list<double>& arg_list);
  static double OperAcos(const std::list<double>& arg_list);
  static double OperAsin(const std::list<double>& arg_list);
  static double OperAtan(const std::list<double>& arg_list);
  static double OperSqrt(const std::list<double>& arg_list);
  static double OperLn(const std::list<double>& arg_list);
  static double OperLog(const std::list<double>& arg_list);

  static double OperFact(const std::list<double>& arg_list);

  static double OperPlus(const std::list<double>& arg_list);
  static double OperMinus(const std::list<double>& arg_list);
  static double OperMult(const std::list<double>& arg_list);
  static double OperDiv(const std::list<double>& arg_list);
  static double OperPow(const std::list<double>& arg_list);
  static double OperMod(const std::list<double>& arg_list);

  static double OperGetPi(const std::list<double>& arg_list);

  std::string name_;
  size_t priority_;
  size_t operand_count_;
  PositionType position_type_;
  NameType name_type_;
  AssociativeType associative_type_;

  PFunc p_func_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_OPERATION_OPERATION_H_
