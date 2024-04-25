// Declaration class Controller

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_CONTROLLER_CONTROLLER_H_
#define SMART_CALC_V_2_CONTROLLER_CONTROLLER_H_

#include "../model/model.h"

namespace s21 {

/// @brief class Controller use to interact with Model
class Controller {
 public:
  Controller(Model* model);

  ~Controller();

  // ----------------------------------------------------------------------- //
  //                               Formulas                                  //
  // ----------------------------------------------------------------------- //

  void SetXYMayBeVar(bool answer);

  /// @exception s21::InvalidExpression if invalid expression given
  /// @exception s21::InvalidExpression if invalid formula name
  /// @exception s21::InvalidExpression if invalid local var name
  std::pair<Model::TypeFormula, std::string> AddFormula(const std::string& str,
                                                        bool add_graph = true);

  void ClearFormulas();

  // ----------------------------------------------------------------------- //
  //                              Calculator                                 //
  // ----------------------------------------------------------------------- //

  /// @brief Calculate infix expression, uses formulas: vars and func added
  /// before
  /// @exception s21::InvalidExpr if invalid expression
  /// @exception s21::CalculationError if result cant be calculated
  double CalculatorCalc(const std::string& expr);

  // ----------------------------------------------------------------------- //
  //                                 Graph                                   //
  // ----------------------------------------------------------------------- //

  /// @brief Set x max value to graph
  void GraphSetXMax(double x_max);

  /// @brief Set x min value to graph
  void GraphSetXMin(double x_min);

  /// @brief Set y max value to graph
  void GraphSetYMax(double y_max);

  /// @brief Set y min value to graph
  void GraphSetYMin(double y_min);

  /// @brief Set x size value to graph in pixels
  void GraphSetXSize(size_t x_size);

  /// @brief Set x max value to graph in pixels
  void GraphSetYSize(size_t y_size);

  // ----------------------------------------------------------------------- //

  /// @brief Start iterating to list graph
  void GraphListBegin();

  /// @brief Take next graph from list graph
  /// @warning Undefined behavior if list graph is end
  void GraphListNext();

  /// @brief Check if list graph is end
  bool GraphListEnd();

  // ----------------------------------------------------------------------- //

  /// @brief Start iterating to selected graph
  /// @warning Undefined behavior if graph not selected by GraphListBegin method
  void GraphBegin();

  /// @brief Get next point from graph
  /// @warning Undefined behavior if graph is end
  Point GraphNext();

  /// @brief Check if graph is end
  bool GraphEnd();

  // ----------------------------------------------------------------------- //
  //                            Credit calculator                            //
  // ----------------------------------------------------------------------- //

  /// @brief Calculate credit
  /// @exception std::logic_error if invalid data input
  void CreditCalc(std::string sum, std::string rate, int time_unit,
                  std::string time_unit_count, int credit_type);

  double CreditAnswerMonthPay();
  double CreditAnswerOverPay();
  double CreditAnswerTotalPay();

  // ----------------------------------------------------------------------- //
  //                            Deposit calculator                           //
  // ----------------------------------------------------------------------- //

  /// @brief Calculate deposit
  /// @exception std::logic_error if invalid data input
  void DepositCalc(std::string sum, int pay_unit, std::string pay_unit_count,
                   std::string rate, std::string tax, Date date_start,
                   int pay_period, int capitalisation);

  void DepositAddInputMoney(const Date& date, const std::string& money);
  void DepositAddOutputMoney(const Date& date, const std::string& money);
  void DepositClearInputOutputMoney();

  double DepositAnswerRate();
  double DepositAnswerTax();
  double DepositAnswerSum();

  // ----------------------------------------------------------------------- //
  //                               Utils                                     //
  // ----------------------------------------------------------------------- //

  /// @exception s21::InvalidExpr if invalid expression
  /// @exception s21::CalculationError if result cant be calculated
  double StrToDouble(const std::string& str);

  /// @exception s21::InvalidExpr if invalid expression
  /// @exception s21::CalculationError if result cant be calculated
  /// @exception std::logic_error if result not int
  int StrToInt(const std::string& str);

  /// @exception s21::InvalidExpr if invalid expression
  /// @exception s21::CalculationError if result cant be calculated
  /// @exception std::logic_error if result not size
  size_t StrToSize(const std::string& str);

  Model::TypeFormula DefineTypeFormula(const std::string& str) const;

 private:
  Model* model_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_CONTROLLER_CONTROLLER_H_
