// Implementation class Model

// Copyright (C) 2023-2023 School 21 License

#include "model.h"

#include <cstddef>
#include <stdexcept>
#include <string>
#include <utility>

#include "credit/credit.h"
#include "deposit/deposit.h"

namespace s21 {

const Model::FuncAddFormula Model::kArrFuncAddFormula[] = {
    nullptr,
    &Model::AddVar,
    &Model::AddNamelessFunc,
    &Model::AddNamelessFuncY,
    &Model::AddNamelessFuncEq,
    &Model::AddNamelessFuncEqY,
    &Model::AddFunc0,
    &Model::AddFunc1,
    &Model::AddFunc1Y,
    &Model::AddFuncN,
    &Model::AddPoint,
    nullptr};

Model::Model() {}
Model::~Model() {}

// ------------------------------------------------------------------------- //
//                                Formulas                                   //
// ------------------------------------------------------------------------- //

void Model::SetXYMayBeVar(bool answer) { x_and_y_may_be_var_ = answer; }

std::pair<Model::TypeFormula, std::string> Model::AddFormula(
    const std::string& str, bool add_graph) {
  TypeFormula type = DefineTypeFormula(str);
  std::string name;
  if (type != kTypeEquation && type != kTypeInvFormula)
    name = (this->*(kArrFuncAddFormula[type]))(str, add_graph);

  return {type, name};
}

void Model::ClearFormulas() {
  list_variable_.Clear();
  list_user_function_.Clear();
  list_graph_.Clear();
  point_names.clear();
  polish_notation_.SetListVariable(list_variable_);
  polish_notation_.SetListUserFunction(list_user_function_);
}

// ------------------------------------------------------------------------- //
//                               Calculator                                  //
// ------------------------------------------------------------------------- //

double Model::CalculatorCalc(const std::string& expr) {
  polish_notation_.SetExpression(expr);
  polish_notation_.Translate();
  return polish_notation_.Calc();
}

// ------------------------------------------------------------------------- //
//                                  Graph                                    //
// ------------------------------------------------------------------------- //

void Model::GraphSetXMax(double x_max) {
  list_graph_.SetXMax(x_max);
  graph_x_max_ = x_max;
}
void Model::GraphSetXMin(double x_min) {
  list_graph_.SetXMin(x_min);
  graph_x_min_ = x_min;
}
void Model::GraphSetYMax(double y_max) {
  list_graph_.SetYMax(y_max);
  graph_y_max_ = y_max;
}
void Model::GraphSetYMin(double y_min) {
  list_graph_.SetYMin(y_min);
  graph_y_min_ = y_min;
}
void Model::GraphSetXSize(size_t x_size) {
  list_graph_.SetXSize(x_size);
  graph_x_size_ = x_size;
}
void Model::GraphSetYSize(size_t y_size) {
  list_graph_.SetYSize(y_size);
  graph_y_size_ = y_size;
}

// ------------------------------------------------------------------------- //

void Model::GraphListBegin() {
  list_graph_i_ = list_graph_.Begin();
  selected_graph_ = *list_graph_i_;
}
void Model::GraphListNext() {
  ++list_graph_i_;
  selected_graph_ = *list_graph_i_;
}
bool Model::GraphListEnd() { return list_graph_i_ == list_graph_.End(); }

// ------------------------------------------------------------------------- //

void Model::GraphBegin() { selected_graph_->Begin(); }

Point Model::GraphNext() { return selected_graph_->Next(); }

bool Model::GraphEnd() { return selected_graph_->IsEnd(); }

// ------------------------------------------------------------------------- //
//                             Credit calculator                             //
// ------------------------------------------------------------------------- //

void Model::CreditCalc(std::string sum, std::string rate, int time_unit,
                       std::string time_unit_count, int credit_type) {
  credit_.SetSum(StrToDouble(sum));
  credit_.SetRate(StrToDouble(rate));
  credit_.SetTimeUnit(static_cast<Credit::TimeUnit>(time_unit));
  credit_.SetTimeUnitCount(StrToSize(time_unit_count));
  credit_.SetCreditType(static_cast<Credit::CreditTypes>(credit_type));

  credit_.Calc();
}

double Model::CreditAnswerMonthPay() { return credit_.GetAnswerMonthPay(); }
double Model::CreditAnswerOverPay() { return credit_.GetAnswerOverPay(); }
double Model::CreditAnswerTotalPay() { return credit_.GetAnswerTotalPay(); }

// ------------------------------------------------------------------------- //
//                             Deposit calculator                            //
// ------------------------------------------------------------------------- //

void Model::DepositCalc(std::string sum, int pay_unit,
                        std::string pay_unit_count, std::string rate,
                        std::string tax, Date date_start, int pay_period,
                        int capitalisation) {
  deposit_.SetSum(StrToDouble(sum));
  deposit_.SetPayUnit(static_cast<Deposit::PayUnits>(pay_unit));
  deposit_.SetPayUnitCount(StrToSize(pay_unit_count));
  deposit_.SetRate(StrToDouble(rate));
  deposit_.SetTax(StrToDouble(tax));
  deposit_.SetDateStart(date_start);
  deposit_.SetPayPeriod(static_cast<Deposit::PayPeriod>(pay_period));
  deposit_.SetCapitalisation(static_cast<bool>(capitalisation));

  deposit_.Calc();
}

void Model::DepositAddInputMoney(const Date& date, const std::string& money) {
  deposit_.AddIncrease(date, StrToDouble(money));
}

void Model::DepositAddOutputMoney(const Date& date, const std::string& money) {
  deposit_.AddDecrease(date, StrToDouble(money));
}

void Model::DepositClearInputOutputMoney() { deposit_.ClearIncreseDecrease(); }

double Model::DepositAnswerRate() { return deposit_.GetAnswerRate(); }
double Model::DepositAnswerTax() { return deposit_.GetAnswerTax(); }
double Model::DepositAnswerSum() { return deposit_.GetAnswerSum(); }

// ------------------------------------------------------------------------- //
//                                Utils                                      //
// ------------------------------------------------------------------------- //

double Model::StrToDouble(const std::string& str) {
  return CalculatorCalc(str);
}

int Model::StrToInt(const std::string& str) {
  double double_value = StrToDouble(str);
  if (double_value != static_cast<int>(double_value))
    throw std::logic_error(kErrorMsgs[kErrNotInt]);
  return static_cast<int>(double_value);
}
size_t Model::StrToSize(const std::string& str) {
  double double_value = StrToDouble(str);
  if (double_value != static_cast<size_t>(double_value))
    throw std::logic_error(kErrorMsgs[kErrNegNum]);
  return static_cast<size_t>(double_value);
}

void Model::GraphSetSize(Graph* graph) {
  graph->SetXMax(graph_x_max_);
  graph->SetXMin(graph_x_min_);
  graph->SetYMax(graph_y_max_);
  graph->SetYMin(graph_y_min_);
  graph->SetXSize(graph_x_size_);
  graph->SetYSize(graph_y_size_);
}

}  // namespace s21
