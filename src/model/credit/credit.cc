// Implementation class Credit

// Copyright (C) 2023-2023 School 21 License

#include "credit.h"

#include <cmath>
#include <cstddef>
#include <stdexcept>

namespace s21 {

Credit::Credit() : Credit(0, 0, kUnitMonth, 0, kAnnuity) {}

Credit::Credit(double sum, double rate, TimeUnit time_unit,
               size_t time_unit_count, CreditTypes credit_type)
    : sum_(sum),
      rate_(rate),
      time_unit_(time_unit),
      time_unit_count_(time_unit_count),
      credit_type_(credit_type) {}

Credit::~Credit() {}

// ------------------------------------------------------------------------- //

void Credit::SetSum(double sum) { sum_ = sum; }

void Credit::SetRate(double rate) { rate_ = rate; }

void Credit::SetTimeUnit(TimeUnit time_unit) { time_unit_ = time_unit; }

void Credit::SetTimeUnitCount(size_t time_unit_count) {
  time_unit_count_ = time_unit_count;
}

void Credit::SetCreditType(CreditTypes credit_type) {
  credit_type_ = credit_type;
}

// ------------------------------------------------------------------------- //

double Credit::GetAnswerMonthPay() const { return answer_month_pay_; }

double Credit::GetAnswerOverPay() const { return answer_over_pay_; }

double Credit::GetAnswerTotalPay() const { return answer_total_pay_; }

// ------------------------------------------------------------------------- //

void Credit::Calc() {
  HandleInvalidData();
  if (credit_type_ == kAnnuity)
    CalcAnnuity();
  else
    CalcDifferentiated();
}

void Credit::HandleInvalidData() const {
  if (sum_ <= 0)
    throw std::logic_error(kErrorMsgs[kNegSum]);
  else if (rate_ < 0)
    throw std::logic_error(kErrorMsgs[kNegRate]);
  else if (time_unit_count_ == 0)
    throw std::logic_error(kErrorMsgs[kZeroDays]);
}

size_t Credit::CalcMonthCount() const {
  if (time_unit_ == kUnitMonth) {
    return time_unit_count_;

  } else {
    return time_unit_count_ * 12;
  }
}

void Credit::CalcAnnuity() {
  double month_rate = rate_ / 12;
  size_t month_count = CalcMonthCount();
  double sum_with_rate = pow(month_rate / 100 + 1, month_count) * sum_;

  double some = 1;
  for (size_t i = 1; i < month_count; ++i) {
    some += std::pow(month_rate / 100 + 1, month_count - i);
  }

  answer_month_pay_ = sum_with_rate / some;
  answer_total_pay_ = answer_month_pay_ * month_count;
  answer_over_pay_ = answer_total_pay_ - sum_;
}

void Credit::CalcDifferentiated() {
  double month_rate = rate_ / 12;
  size_t month_count = CalcMonthCount();
  double month_pay_hard = sum_ / month_count;

  answer_month_pay_ = month_pay_hard;

  answer_total_pay_ = 0;
  double rem_sum = sum_;
  for (size_t i = 0; i < month_count; ++i) {
    double pay = (month_rate / 100 * rem_sum + month_pay_hard);
    answer_total_pay_ += pay;
    rem_sum -= month_pay_hard;
  }

  answer_over_pay_ = answer_total_pay_ - sum_;
}

}  // namespace s21
