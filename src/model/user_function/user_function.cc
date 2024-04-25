// Implementation class UserFunction

// Copyright (C) 2023-2023 School 21 License

#include "user_function.h"

#include <list>
#include <stdexcept>
#include <string>

#include "../list_variable/list_variable.h"
#include "../operation/operation.h"
#include "../polish_notation/polish_notation.h"

namespace s21 {

UserFunction::UserFunction(const std::string& name)
    : Operation(name, 4, 0, kPrefix, kWord, kLeft, nullptr) {
  polish_notation_ = new PolishNotation();
}

UserFunction::UserFunction(const std::string& name, const std::string& define,
                           const ListVariable& list_variable,
                           const PolishNotation& polish_notation)
    : UserFunction(name) {
  SetDefine(define);
  SetPolishNotation(polish_notation);
  SetListVariable(list_variable);
}

UserFunction::UserFunction(const UserFunction& other) : Operation(other) {
  if (this == &other) return;
  define_ = other.define_;
  list_variable_ = other.list_variable_;
  is_data_input_ = other.is_data_input_;
  is_translate_ = other.is_translate_;

  polish_notation_ = new PolishNotation(*other.polish_notation_);
}

UserFunction::UserFunction(UserFunction&& other) : Operation(std::move(other)) {
  if (this == &other) return;
  define_ = std::move(other.define_);
  list_variable_ = std::move(other.list_variable_);
  is_data_input_ = std::move(other.is_data_input_);
  is_translate_ = std::move(other.is_translate_);

  polish_notation_ = other.polish_notation_;
  other.polish_notation_ = nullptr;
}

UserFunction& UserFunction::operator=(const UserFunction& other) {
  if (this == &other) return *this;
  Operation::operator=(other);
  define_ = other.define_;
  list_variable_ = other.list_variable_;
  is_data_input_ = other.is_data_input_;
  is_translate_ = other.is_translate_;

  if (polish_notation_ != nullptr) delete polish_notation_;
  polish_notation_ = new PolishNotation(*other.polish_notation_);

  return *this;
}

UserFunction& UserFunction::operator=(UserFunction&& other) {
  if (this == &other) return *this;
  Operation::operator=(std::move(other));
  define_ = std::move(other.define_);
  list_variable_ = std::move(other.list_variable_);
  is_data_input_ = std::move(other.is_data_input_);
  is_translate_ = std::move(other.is_translate_);

  if (polish_notation_ != nullptr) delete polish_notation_;
  polish_notation_ = other.polish_notation_;
  other.polish_notation_ = nullptr;

  return *this;
}

UserFunction::~UserFunction() {
  if (polish_notation_ != nullptr) delete polish_notation_;
}

// ------------------------------------------------------------------------- //

const std::string& UserFunction::GetDefine() const { return define_; }

const ListVariable& UserFunction::GetListVariable() const {
  return list_variable_;
}

const PolishNotation& UserFunction::GetPolishNotation() const {
  return *polish_notation_;
}

// ------------------------------------------------------------------------- //

void UserFunction::SetName(const std::string& name) {
  Operation::SetName(name);
}

void UserFunction::SetDefine(const std::string& define) {
  is_translate_ = false;
  is_data_input_ = true;
  define_ = define;
}

void UserFunction::SetListVariable(const ListVariable& list_variable) {
  is_translate_ = false;

  ListVariable list_var_polish = polish_notation_->GetListVariable();

  ListVariable::iterator i = list_variable_.Begin();
  for (; i != list_variable_.End(); ++i) {
    list_var_polish.Remove(*i);
  }

  list_variable_ = list_variable;

  i = list_variable_.Begin();
  for (; i != list_variable_.End(); ++i) {
    list_var_polish.Add(*i);
  }

  polish_notation_->SetListVariable(list_var_polish);
  this->SetOperandCount(list_variable_.Size());
}

void UserFunction::SetPolishNotation(const PolishNotation& polish_notation) {
  is_translate_ = false;
  if (polish_notation_ != nullptr) delete polish_notation_;
  polish_notation_ = new PolishNotation(polish_notation);
  ListVariable list_var_polish = polish_notation_->GetListVariable();

  ListVariable::iterator i = list_variable_.Begin();
  for (; i != list_variable_.End(); ++i) {
    list_var_polish.Add(*i);
  }

  polish_notation_->SetListVariable(list_var_polish);
}

// ------------------------------------------------------------------------- //

bool UserFunction::operator==(const UserFunction& other) const {
  return (define_ == other.define_ && this->Operation::operator==(other));
}

// ------------------------------------------------------------------------- //

double UserFunction::Calc(const std::list<double>& arg_list) const {
  if (!is_data_input_) throw std::logic_error(kErrorMsgs[kDataNotInput]);
  if (!is_translate_) {
    polish_notation_->SetExpression(define_);
    polish_notation_->Translate();
  }
  ListVariable::const_iterator list_var_i = list_variable_.Begin();
  std::list<double>::const_iterator arg_list_i = arg_list.begin();
  while (list_var_i != list_variable_.End()) {
    polish_notation_->UpdateVariableValue(list_var_i->GetName(), *arg_list_i);
    ++list_var_i;
    ++arg_list_i;
  }

  return polish_notation_->Calc();
}

void UserFunction::Translate() {
  polish_notation_->SetExpression(define_);
  polish_notation_->Translate();
}

}  // namespace s21
