// Implementation class Operation

// Copyright (C) 2023-2023 School 21 License

#include "operation.h"

#include <cmath>
#include <cstddef>
#include <list>
#include <string>

#include "../sm_exceptions/calculation_error.h"

namespace s21 {

Operation::Operation(std::string name, size_t priority, size_t operand_count,
                     PositionType position_type, NameType name_type,
                     AssociativeType associative_type, PFunc p_func)
    : name_(name),
      priority_(priority),
      operand_count_(operand_count),
      position_type_(position_type),
      name_type_(name_type),
      associative_type_(associative_type),
      p_func_(p_func) {}

Operation::~Operation() {}

// ------------------------------------------------------------------------- //

size_t Operation::GetOperandCount() const { return operand_count_; }

Operation::PositionType Operation::GetPositionType() const {
  return position_type_;
}

Operation::NameType Operation::GetNameType() const { return name_type_; }

Operation::AssociativeType Operation::GetAssociativeType() const {
  return associative_type_;
}

const std::string& Operation::GetName() const { return name_; }

size_t Operation::GetPriority() const { return priority_; }

Operation::PFunc Operation::GetPFunc() const { return p_func_; }

// ------------------------------------------------------------------------- //

bool Operation::IsUnary() const { return operand_count_ == 1; }

bool Operation::IsBinary() const { return operand_count_ == 2; }

bool Operation::IsPrefix() const { return position_type_ == kPrefix; }

bool Operation::IsInfix() const { return position_type_ == kInfix; }

bool Operation::IsPostfix() const { return position_type_ == kPostfix; }

bool Operation::IsOperator() const { return name_type_ == kSpecialChar; }

bool Operation::IsFunction() const { return IsPrefix() && name_type_ == kWord; }

bool Operation::IsLeftAssociative() const { return associative_type_ == kLeft; }

bool Operation::IsRightAssociative() const {
  return associative_type_ == kRight;
}

bool Operation::IsLessPriority(const Operation& other) const {
  return priority_ < other.priority_;
}

bool Operation::IsEqPriority(const Operation& other) const {
  return priority_ == other.priority_;
}

bool Operation::IsGreaterPriority(const Operation& other) const {
  return priority_ > other.priority_;
}

// ------------------------------------------------------------------------- //

void Operation::SetName(const std::string& name) { name_ = name; }

void Operation::SetOperandCount(size_t operand_count) {
  operand_count_ = operand_count;
}

// ------------------------------------------------------------------------- //

bool Operation::operator==(const Operation& other) const {
  return name_ == other.name_ && priority_ == other.priority_ &&
         operand_count_ == other.operand_count_ &&
         position_type_ == other.position_type_ &&
         name_type_ == other.name_type_ &&
         associative_type_ == other.associative_type_ &&
         p_func_ == other.p_func_;
}

// ------------------------------------------------------------------------- //

double Operation::Calc(const std::list<double>& arg_list) const {
  return (*p_func_)(arg_list);
}

// ------------------------------------------------------------------------- //

const Operation* Operation::GetSpecialCharOperator(const std::string& name,
                                                   size_t operand_count) {
  std::list<Operation>::iterator iter = list_special_char_operator_.begin();
  for (; iter != list_special_char_operator_.end(); ++iter) {
    if (iter->GetName() == name &&
        (iter->GetOperandCount() == operand_count || !iter->IsPrefix()))
      return &(*iter);
  }

  return nullptr;
}

const Operation* Operation::GetOperation(const std::string& str) {
  std::list<Operation>::iterator iter = list_operator_.begin();
  for (; iter != list_operator_.end(); ++iter) {
    if (iter->GetName() == str) return &(*iter);
  }

  return nullptr;
}

// ------------------------------------------------------------------------- //

std::list<Operation> Operation::list_special_char_operator_ = {
    Operation("+", 2, 1, Operation::kPrefix, Operation::kSpecialChar,
              Operation::kLeft, OperUnaryPlus),
    Operation("-", 2, 1, Operation::kPrefix, Operation::kSpecialChar,
              Operation::kLeft, OperUnaryMinus),

    Operation("+", 1, 2, Operation::kInfix, Operation::kSpecialChar,
              Operation::kLeft, OperPlus),
    Operation("-", 1, 2, Operation::kInfix, Operation::kSpecialChar,
              Operation::kLeft, OperMinus),
    Operation("*", 2, 2, Operation::kInfix, Operation::kSpecialChar,
              Operation::kLeft, OperMult),
    Operation("/", 2, 2, Operation::kInfix, Operation::kSpecialChar,
              Operation::kLeft, OperDiv),
    Operation("^", 3, 2, Operation::kInfix, Operation::kSpecialChar,
              Operation::kRight, OperPow),

    Operation("!", 4, 1, Operation::kPostfix, Operation::kSpecialChar,
              Operation::kLeft, OperFact)};

std::list<Operation> Operation::list_operator_ = {

    Operation("sin", 4, 1, Operation::kPrefix, Operation::kWord,
              Operation::kLeft, OperSin),
    Operation("cos", 4, 1, Operation::kPrefix, Operation::kWord,
              Operation::kLeft, OperCos),
    Operation("tan", 4, 1, Operation::kPrefix, Operation::kWord,
              Operation::kLeft, OperTan),

    Operation("asin", 4, 1, Operation::kPrefix, Operation::kWord,
              Operation::kLeft, OperAsin),
    Operation("acos", 4, 1, Operation::kPrefix, Operation::kWord,
              Operation::kLeft, OperAcos),
    Operation("atan", 4, 1, Operation::kPrefix, Operation::kWord,
              Operation::kLeft, OperAtan),

    Operation("ln", 4, 1, Operation::kPrefix, Operation::kWord,
              Operation::kLeft, OperLn),
    Operation("log", 4, 1, Operation::kPrefix, Operation::kWord,
              Operation::kLeft, OperLog),
    Operation("sqrt", 4, 1, Operation::kPrefix, Operation::kWord,
              Operation::kLeft, OperSqrt),

    Operation("mod", 2, 2, Operation::kInfix, Operation::kWord,
              Operation::kLeft, OperMod),

    Operation("pow", 4, 2, Operation::kPrefix, Operation::kWord,
              Operation::kLeft, OperPow),

    Operation("get_pi", 4, 0, Operation::kPrefix, Operation::kWord,
              Operation::kLeft, OperGetPi)

};

// ------------------------------------------------------------------------- //

double Operation::OperUnaryMinus(const std::list<double>& arg_list) {
  double a = arg_list.front();
  return (-1) * a;
}

double Operation::OperUnaryPlus(const std::list<double>& arg_list) {
  double a = arg_list.front();
  return a;
}

double Operation::OperCos(const std::list<double>& arg_list) {
  double a = arg_list.front();
  return cos(a);
}

double Operation::OperSin(const std::list<double>& arg_list) {
  double a = arg_list.front();
  return sin(a);
}

double Operation::OperTan(const std::list<double>& arg_list) {
  double a = arg_list.front();
  if (std::abs(cos(a)) <= 1e-6)
    throw CalculationError(Operation::kErrorMsgs[Operation::kDivZero]);
  return tan(a);
}
double Operation::OperAcos(const std::list<double>& arg_list) {
  double a = arg_list.front();
  return acos(a);
}

double Operation::OperAsin(const std::list<double>& arg_list) {
  double a = arg_list.front();
  return asin(a);
}

double Operation::OperAtan(const std::list<double>& arg_list) {
  double a = arg_list.front();
  return atan(a);
}

double Operation::OperSqrt(const std::list<double>& arg_list) {
  double a = arg_list.front();
  if (a < 0)
    throw CalculationError(Operation::kErrorMsgs[Operation::kNegPowIrr]);
  return sqrt(a);
}
double Operation::OperLn(const std::list<double>& arg_list) {
  double a = arg_list.front();
  if (a <= 0)
    throw CalculationError(Operation::kErrorMsgs[Operation::kNonPositiveLog]);
  return log(a);
}

double Operation::OperLog(const std::list<double>& arg_list) {
  double a = arg_list.front();
  if (a <= 0)
    throw CalculationError(Operation::kErrorMsgs[Operation::kNonPositiveLog]);
  return log10(a);
}

double Operation::OperFact(const std::list<double>& arg_list) {
  double a = arg_list.front();
  if (a != (int64_t)a)
    throw CalculationError(Operation::kErrorMsgs[Operation::kIrrFact]);

  if (a < 0) throw CalculationError(Operation::kErrorMsgs[Operation::kNegFact]);

  if (a == 0 || a == 1) return 1;

  double res = 1;
  for (size_t i = 1; i <= a; ++i) {
    res *= i;
  }
  return res;
}
double Operation::OperPlus(const std::list<double>& arg_list) {
  double a = arg_list.front();
  double b = arg_list.back();
  return a + b;
}

double Operation::OperMinus(const std::list<double>& arg_list) {
  double a = arg_list.front();
  double b = arg_list.back();
  return a - b;
}

double Operation::OperMult(const std::list<double>& arg_list) {
  double a = arg_list.front();
  double b = arg_list.back();
  return a * b;
}

double Operation::OperDiv(const std::list<double>& arg_list) {
  double a = arg_list.front();
  double b = arg_list.back();
  if (std::abs(b) <= 1e-6)
    throw CalculationError(Operation::kErrorMsgs[Operation::kDivZero]);
  return a / b;
}

double Operation::OperPow(const std::list<double>& arg_list) {
  double a = arg_list.front();
  double b = arg_list.back();
  if (a == 0 && b < 0)
    throw CalculationError(Operation::kErrorMsgs[Operation::kZeroPowNeg]);
  else if (a == 0 && b == 0)
    throw CalculationError(Operation::kErrorMsgs[Operation::kZeroPowZero]);
  else if (a < 0 && b != (int64_t)b)
    throw CalculationError(Operation::kErrorMsgs[Operation::kNegPowIrr]);

  return pow(a, b);
}

double Operation::OperMod(const std::list<double>& arg_list) {
  double a = arg_list.front();
  double b = arg_list.back();
  if (std::abs(b) <= 1e-6)
    throw CalculationError(Operation::kErrorMsgs[Operation::kDivZero]);

  return fmod(a, b);
}

double Operation::OperGetPi(const std::list<double>& arg_list) {
  if (!arg_list.empty()) return NAN;
  return M_PI;
}

}  // namespace s21
