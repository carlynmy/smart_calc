// Declaration class Credit

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_CREDIT_CREDIT_H_
#define SMART_CALC_V_2_MODEL_CREDIT_CREDIT_H_

#include <cstddef>
#include <string>

namespace s21 {

/// @brief Class Credit is used for calculate month pay, over pay, total pay in
/// credit. To use fill in the input data by construct or by using
/// setters, then invoke method Calc, then get answers by using getters.
class Credit {
 public:
  enum TimeUnit { kUnitMonth, kUnitYear };
  enum CreditTypes { kAnnuity, kDifferentiated };

  // ----------------------------------------------------------------------- //

  Credit();

  /// @param sum Sum of credit
  /// @param rate Rate of credit in percent
  /// @param time_unit Сredit time unit in enum TimeUnit
  /// @param time_unit_count Time
  /// @param credit_type Type of credit in enum CreditTypes
  Credit(double sum, double rate, TimeUnit time_unit, size_t time_unit_count,
         CreditTypes credit_type);

  ~Credit();

  // ----------------------------------------------------------------------- //

  /// @param sum Sum of credit
  void SetSum(double sum);

  /// @param rate Rate of credit in percent
  void SetRate(double rate);

  /// @param time_unit Сredit time unit in enum TimeUnit
  void SetTimeUnit(TimeUnit time_unit);

  /// @param time_unit_count Time
  void SetTimeUnitCount(size_t time_unit_count);

  /// @param credit_type Type of credit in enum CreditTypes
  void SetCreditType(CreditTypes credit_type);

  // ----------------------------------------------------------------------- //

  double GetAnswerMonthPay() const;
  double GetAnswerOverPay() const;
  double GetAnswerTotalPay() const;

  // ----------------------------------------------------------------------- //

  /// @brief Calculate answers
  /// @exception std::logic_error if invalid data input
  /// @warning Undefined behavior if data not input
  void Calc();

  // ----------------------------------------------------------------------- //

 private:
  enum ErrorIndexes { kNegSum, kNegRate, kZeroDays };

  static inline const std::string kErrorMsgs[] = {"Отрицательная сумма кредита",
                                                  "Отрицательная ставка",
                                                  "Количество дней - ноль"};

  void HandleInvalidData() const;
  void CalcAnnuity();
  void CalcDifferentiated();
  size_t CalcMonthCount() const;

  double sum_;
  double rate_;
  TimeUnit time_unit_;
  size_t time_unit_count_;
  CreditTypes credit_type_;

  double answer_month_pay_;
  double answer_over_pay_;
  double answer_total_pay_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_CREDIT_CREDIT_H_
