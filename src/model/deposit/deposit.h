// Declaration class Deposit

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_DEPOSIT_DEPOSIT_H_
#define SMART_CALC_V_2_MODEL_DEPOSIT_DEPOSIT_H_

#include <cstddef>
#include <map>
#include <string>

#include "../date/date.h"

namespace s21 {

/// @brief Class Deposit is used for calculate accrued rate, tax amount, deposit
/// amount in deposit. To use fill in the input data by construct or by using
/// setters and add increase, decrease using AddIncrease, AddDecrease, then
/// invoke method Calc, then get answers by using getters.
class Deposit {
 public:
  enum PayUnits { kPayUnitDay, kPayUnitMonth, kPayUnitYear };
  enum PayPeriod {
    kPayInDay,
    kPayInWeek,
    kPayInMonth,
    kPayInQuarter,
    kPayInHalfYear,
    kPayInYear,
    kPayInEnd
  };

  // ---------------------------------------------------------------------- //

  Deposit();

  /// @param sum Sum of deposit
  /// @param pay_unit Deposit time unit in enum PayUnits
  /// @param pay_unit_count Time
  /// @param rate Rate of deposit in persent
  /// @param tax Tax of deposit in persent
  /// @param date_start Date start of deposit in Date
  /// @param pay_period Pay period in enum ParPeriod, use if capitalisation is
  /// on
  /// @param capitalisation Capitalisation status on/off
  Deposit(double sum, PayUnits pay_unit, size_t pay_unit_count, double rate,
          double tax, Date date_start, PayPeriod pay_period,
          bool capitalisation);

  ~Deposit();

  // ---------------------------------------------------------------------- //

  /// @param sum Sum of deposit
  void SetSum(double sum);

  /// @param pay_unit Deposit time unit in enum PayUnits
  void SetPayUnit(PayUnits pay_unit);

  /// @param pay_unit_count Time
  void SetPayUnitCount(size_t pay_unit_count);

  /// @param rate Rate of deposit in persent
  void SetRate(double rate);

  /// @param tax Tax of deposit in persent
  void SetTax(double tax);

  /// @param date_start Date start of deposit in Date
  void SetDateStart(Date date_start);

  /// @param pay_period Pay period in enum ParPeriod
  void SetPayPeriod(PayPeriod pay_period);

  /// @param capitalisation Capitalisation status on/off
  void SetCapitalisation(bool capitalisation);

  /// @brief Add increase money on deposit on date
  void AddIncrease(const Date& date, double money);

  /// @brief Add Decrease money on deposit on date
  void AddDecrease(const Date& date, double money);

  /// @brief Clear increase and decrease mooney
  void ClearIncreseDecrease();

  // ---------------------------------------------------------------------- //

  double GetAnswerRate() const;
  double GetAnswerTax() const;
  double GetAnswerSum() const;

  // ---------------------------------------------------------------------- //

  /// @brief Calculate answers
  /// @exception std::logic_error if invalid data input
  /// @warning Undefined behavior if data not input
  void Calc();

 private:
  enum ErrorIndexes { kNegSum, kZeroDays, kNegRate, kNegTax, kBigDecrease };

  static inline const std::string kErrorMsgs[] = {
      "Неккоректная сумма депозита", "Количество дней - ноль",
      "Отрицательная ставка", "Отрицательная налоговая ставка",
      "Сумма после снятия не положительная"};

  void HandleInvalidData() const;
  Date CalcDateEnd() const;
  double CalcRatePay(const Date& date_now) const;
  bool IsNeedCapitalisation(const Date& date_now) const;
  bool IsDaysEq(const Date& date_now) const;
  bool IsNextWeek(const Date& date_now) const;

  double sum_;
  PayUnits pay_unit_;
  size_t pay_unit_count_;
  double rate_;
  double tax_;
  Date date_start_;
  PayPeriod pay_period_;
  bool capitalisation_;
  std::map<Date, double> list_increase_;

  double answer_rate_;
  double answer_tax_;
  double answer_sum_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_DEPOSIT_DEPOSIT_H_
