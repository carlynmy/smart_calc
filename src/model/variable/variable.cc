// Implementation class Variable

// Copyright (C) 2023-2023 School 21 License

#include "variable.h"

#include <string>

namespace s21 {

Variable::Variable() : Variable("", 0.0l) {}

Variable::Variable(std::string name, double value)
    : name_(name), value_(value) {}

Variable::~Variable() {}

const std::string& Variable::GetName() const { return name_; }

void Variable::SetName(std::string name) { name_ = name; }

double Variable::GetValue() const { return value_; }

void Variable::SetValue(double value) { value_ = value; }

bool Variable::operator==(const Variable& other) const {
  return name_ == other.name_ && value_ == other.value_;
}

}  // namespace s21
