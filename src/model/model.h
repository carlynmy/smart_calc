// Declaration class Model

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_MODEL_H_
#define SMART_CALC_V_2_MODEL_MODEL_H_

#include <cstddef>
#include <string>
#include <utility>

#include "credit/credit.h"
#include "date/date.h"
#include "deposit/deposit.h"
#include "graph/graph.h"
#include "list_graph/list_graph.h"
#include "list_user_function/list_user_function.h"
#include "list_variable/list_variable.h"
#include "operation/operation.h"
#include "polish_notation/polish_notation.h"
#include "sm_exceptions/calculation_error.h"
#include "sm_exceptions/invalid_expression.h"
#include "special_token/special_token.h"
#include "token/token.h"
#include "token_parser/token_parser.h"
#include "user_function/user_function.h"
#include "variable/variable.h"

namespace s21 {

/// @brief Model to Infix expression calculator, graphic calculator, credit
/// calculator, deposit calculator.
/// @brief To use infix expression calculator, add vars and func with AddFormula
/// method, then invoke CalculatorCalc method.
/// @brief To use graphic calculator, add vars and func with AddFormula method,
/// then set x range, y range and board sizes, then start iterating by
/// GraphListBegin and selecting next graph by GraphListNext method while method
/// GraphListEnd returnig false, start iterating to graph by GraphBegin and get
/// next points by GraphNext while GraphEnd returning false.
/// @brief To use credit calculator, fill data by CreditSet* methods, then
/// invoke method CreditCalc, and get answers by CreditAnswer* methods.
/// @brief To use deposit calculator, fill data by DepositSet* methods, then add
/// money input-output by DepositAdd*Money methods, then invoke method
/// DepositCalc, and get answers by DepositAnswer* methods.
class Model {
 public:
  enum TypeFormula {
    kTypeInvFormula,
    kTypeVar,
    kTypeNamelessFunc,
    kTypeNamelessFuncY,
    kTypeNamelessFuncEq,
    kTypeNamelessFuncEqY,
    kTypeFunc0,
    kTypeFunc1,
    kTypeFunc1Y,
    kTypeFuncN,
    kTypePoint,
    kTypeEquation
  };

  Model();
  ~Model();

  // ----------------------------------------------------------------------- //
  //                               Formulas                                  //
  // ----------------------------------------------------------------------- //

  void SetXYMayBeVar(bool answer);

  /// @exception s21::InvalidExpression if invalid expression given
  /// @exception s21::InvalidExpression if invalid formula name
  /// @exception s21::InvalidExpression if invalid local var name
  std::pair<TypeFormula, std::string> AddFormula(const std::string& str,
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

  TypeFormula DefineTypeFormula(const std::string& str) const;

 private:
  enum ErrorIndexes {
    kErrNameNotAviable,
    kErrInvFormula,
    kErrInvNameLocalVar,
    kErrNotInt,
    kErrNegNum
  };

  using FuncAddFormula = std::string (Model::*)(const std::string&, bool);

  const static FuncAddFormula kArrFuncAddFormula[];

  const static inline SpecialToken kEq =
      SpecialToken(SpecialToken::kEqualSign, "=");
  const static inline Variable kVarX = Variable("x", 0);
  const static inline Variable kVarY = Variable("y", 0);
  const static inline Token kTokenX = Token(Token::kVar, &kVarX);
  const static inline Token kTokenY = Token(Token::kVar, &kVarY);
  const static inline Token kTokenEq = Token(Token::kSpecialToken, &kEq);

  static inline const std::string kErrorMsgs[] = {
      "Имя уже занято", "Неккоректная формула",
      "Неккоректное имя локальной переменной", "Поданно не целое число",
      "Поданно отрицательное число"};

  // ----------------------------------------------------------------------- //

  bool IsAviableName(const std::string& name) const;

  bool IsTypePoint(TokenParser& token_parser) const;
  bool IsTypeYEqEquation(TokenParser& token_parser) const;
  bool IsTypeXEqEquation(TokenParser& token_parser) const;
  bool IsTypeVar(TokenParser& token_parser) const;
  bool IsTypeFunc0(TokenParser& token_parser) const;
  bool IsTypeFunc1(TokenParser& token_parser) const;
  bool IsTypeFunc1Y(TokenParser& token_parser) const;
  bool IsTypeFuncN(TokenParser& token_parser) const;
  bool IsEquation(TokenParser& token_parser) const;

  bool IsPolishNotation(const std::string& str) const;

  // ----------------------------------------------------------------------- //

  std::string AddVar(const std::string& str, bool add_graph);
  std::string AddNamelessFunc(const std::string& str, bool add_graph);
  std::string AddNamelessFuncY(const std::string& str, bool add_graph);
  std::string AddNamelessFuncEq(const std::string& str, bool add_graph);
  std::string AddNamelessFuncEqY(const std::string& str, bool add_graph);
  std::string AddFunc0(const std::string& str, bool add_graph);
  std::string AddFunc1(const std::string& str, bool add_graph);
  std::string AddFunc1Y(const std::string& str, bool add_graph);
  std::string AddFuncN(const std::string& str, bool add_graph);
  std::string AddPoint(const std::string& str, bool add_graph);

  // ----------------------------------------------------------------------- //

  void GraphSetSize(Graph* graph);

  ListVariable list_variable_;
  ListUserFunction list_user_function_;
  ListGraph list_graph_;
  std::list<std::string> point_names;

  PolishNotation polish_notation_;
  Credit credit_;
  Deposit deposit_;
  ListGraph::iterator list_graph_i_;
  Graph* selected_graph_;

  bool x_and_y_may_be_var_ = false;
  bool var_x_added = false;
  bool var_y_added = false;

  double graph_x_max_ = 0;
  double graph_x_min_ = 0;
  double graph_y_max_ = 0;
  double graph_y_min_ = 0;
  size_t graph_x_size_ = 0;
  size_t graph_y_size_ = 0;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_MODEL_H_
