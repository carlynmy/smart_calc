// Implementation class Controller

// Copyright (C) 2023-2023 School 21 License

#include "controller.h"

namespace s21 {

Controller::Controller(Model* model) : model_(model) {}

Controller::~Controller() {}

// ----------------------------------------------------------------------- //
//                               Formulas                                  //
// ----------------------------------------------------------------------- //

void Controller::SetXYMayBeVar(bool answer) { model_->SetXYMayBeVar(answer); }

std::pair<Model::TypeFormula, std::string> Controller::AddFormula(
    const std::string& str, bool add_graph) {
  return model_->AddFormula(str, add_graph);
}

void Controller::ClearFormulas() { model_->ClearFormulas(); }

// ----------------------------------------------------------------------- //
//                              Calculator                                 //
// ----------------------------------------------------------------------- //

double Controller::CalculatorCalc(const std::string& expr) {
  return model_->CalculatorCalc(expr);
}

// ----------------------------------------------------------------------- //
//                                 Graph                                   //
// ----------------------------------------------------------------------- //

void Controller::GraphSetXMax(double x_max) { model_->GraphSetXMax(x_max); }

void Controller::GraphSetXMin(double x_min) { model_->GraphSetXMin(x_min); }

void Controller::GraphSetYMax(double y_max) { model_->GraphSetYMax(y_max); }

void Controller::GraphSetYMin(double y_min) { model_->GraphSetYMin(y_min); }

void Controller::GraphSetXSize(size_t x_size) { model_->GraphSetXSize(x_size); }

void Controller::GraphSetYSize(size_t y_size) { model_->GraphSetYSize(y_size); }

// ----------------------------------------------------------------------- //

void Controller::GraphListBegin() { model_->GraphListBegin(); }

void Controller::GraphListNext() { model_->GraphListNext(); }

bool Controller::GraphListEnd() { return model_->GraphListEnd(); }

// ----------------------------------------------------------------------- //

void Controller::GraphBegin() { model_->GraphBegin(); }

Point Controller::GraphNext() { return model_->GraphNext(); }

bool Controller::GraphEnd() { return model_->GraphEnd(); }

// ----------------------------------------------------------------------- //
//                            Credit calculator                            //
// ----------------------------------------------------------------------- //

void Controller::CreditCalc(std::string sum, std::string rate, int time_unit,
                            std::string time_unit_count, int credit_type) {
  model_->CreditCalc(sum, rate, time_unit, time_unit_count, credit_type);
}

double Controller::CreditAnswerMonthPay() {
  return model_->CreditAnswerMonthPay();
}

double Controller::CreditAnswerOverPay() {
  return model_->CreditAnswerOverPay();
}

double Controller::CreditAnswerTotalPay() {
  return model_->CreditAnswerTotalPay();
}

// ----------------------------------------------------------------------- //
//                            Deposit calculator                           //
// ----------------------------------------------------------------------- //

void Controller::DepositCalc(std::string sum, int pay_unit,
                             std::string pay_unit_count, std::string rate,
                             std::string tax, Date date_start, int pay_period,
                             int capitalisation) {
  model_->DepositCalc(sum, pay_unit, pay_unit_count, rate, tax, date_start,
                      pay_period, capitalisation);
}

void Controller::DepositAddInputMoney(const Date& date,
                                      const std::string& money) {
  model_->DepositAddInputMoney(date, money);
}

void Controller::DepositAddOutputMoney(const Date& date,
                                       const std::string& money) {
  model_->DepositAddOutputMoney(date, money);
}

void Controller::DepositClearInputOutputMoney() {
  model_->DepositClearInputOutputMoney();
}

double Controller::DepositAnswerRate() { return model_->DepositAnswerRate(); }

double Controller::DepositAnswerTax() { return model_->DepositAnswerTax(); }

double Controller::DepositAnswerSum() { return model_->DepositAnswerSum(); }

// ----------------------------------------------------------------------- //
//                               Utils                                     //
// ----------------------------------------------------------------------- //

double Controller::StrToDouble(const std::string& str) {
  return model_->StrToDouble(str);
}

int Controller::StrToInt(const std::string& str) {
  return model_->StrToInt(str);
}

size_t Controller::StrToSize(const std::string& str) {
  return model_->StrToSize(str);
}

Model::TypeFormula Controller::DefineTypeFormula(const std::string& str) const {
  return model_->DefineTypeFormula(str);
}

}  // namespace s21
