// Implementation class Deposit

// Copyright (C) 2023-2023 School 21 License

#include "deposit.h"

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <map>
#include <stdexcept>
#include <utility>

#include "../date/date.h"

namespace s21 {

Deposit::Deposit() {}

Deposit::Deposit(double sum, PayUnits pay_unit, size_t pay_unit_count,
                 double rate, double tax, Date date_start, PayPeriod pay_period,
                 bool capitalisation)
    : sum_(sum),
      pay_unit_(pay_unit),
      pay_unit_count_(pay_unit_count),
      rate_(rate),
      tax_(tax),
      date_start_(date_start),
      pay_period_(pay_period),
      capitalisation_(capitalisation) {}

Deposit::~Deposit() {}

// ------------------------------------------------------------------------- //

void Deposit::SetSum(double sum) { sum_ = sum; }

void Deposit::SetPayUnit(PayUnits pay_unit) { pay_unit_ = pay_unit; }

void Deposit::SetPayUnitCount(size_t pay_unit_count) {
  pay_unit_count_ = pay_unit_count;
}

void Deposit::SetRate(double rate) { rate_ = rate; }

void Deposit::SetTax(double tax) { tax_ = tax; }

void Deposit::SetDateStart(Date date_start) { date_start_ = date_start; }

void Deposit::SetPayPeriod(PayPeriod pay_period) { pay_period_ = pay_period; }

void Deposit::SetCapitalisation(bool capitalisation) {
  capitalisation_ = capitalisation;
}

void Deposit::AddIncrease(const Date& date, double money) {
  std::map<Date, double>::iterator iter = list_increase_.find(date);

  if (iter != list_increase_.end()) {
    iter->second += money;

  } else {
    list_increase_.insert(std::pair<Date, double>(date, money));
  }
}

void Deposit::AddDecrease(const Date& date, double money) {
  AddIncrease(date, -money);
}

void Deposit::ClearIncreseDecrease() { list_increase_.clear(); }

// ------------------------------------------------------------------------- //

double Deposit::GetAnswerRate() const { return answer_rate_; }

double Deposit::GetAnswerTax() const { return answer_tax_; }

double Deposit::GetAnswerSum() const { return answer_sum_; }

// ------------------------------------------------------------------------- //

void Deposit::Calc() {
  HandleInvalidData();

  answer_rate_ = 0;
  answer_tax_ = 0;
  answer_sum_ = sum_;

  Date date_now(date_start_);
  Date date_end = CalcDateEnd();

  double rate_pay, capitalisation_pay = 0;
  bool need_calc_rate_pay = true;
  for (; date_now < date_end; ++date_now) {
    if (need_calc_rate_pay) {
      rate_pay = CalcRatePay(date_now);
      need_calc_rate_pay = false;
    }

    answer_rate_ += rate_pay;
    capitalisation_pay += rate_pay;

    if (capitalisation_ && IsNeedCapitalisation(date_now)) {
      answer_sum_ += capitalisation_pay;
      capitalisation_pay = 0;
      need_calc_rate_pay = true;
    }

    std::map<Date, double>::iterator iter = list_increase_.find(date_now);
    if (iter != list_increase_.end()) {
      answer_sum_ += iter->second;
      need_calc_rate_pay = true;
      if (answer_sum_ < 0) throw std::logic_error(kErrorMsgs[kBigDecrease]);
    }
  }

  if (capitalisation_)
    answer_sum_ += capitalisation_pay;
  else
    answer_sum_ += answer_rate_;

  answer_tax_ = answer_rate_ * tax_ / 100;
  answer_rate_ -= answer_tax_;
  answer_sum_ -= answer_tax_;
}

void Deposit::HandleInvalidData() const {
  if (sum_ <= 0)
    throw std::logic_error(kErrorMsgs[kNegSum]);
  else if (pay_unit_count_ == 0)
    throw std::logic_error(kErrorMsgs[kZeroDays]);
  else if (rate_ < 0)
    throw std::logic_error(kErrorMsgs[kNegRate]);
  else if (tax_ < 0)
    throw std::logic_error(kErrorMsgs[kNegTax]);
}

Date Deposit::CalcDateEnd() const {
  Date date_end(date_start_);

  if (pay_unit_ == kPayUnitDay) {
    date_end.AddDay(pay_unit_count_);

  } else if (pay_unit_ == kPayUnitMonth) {
    date_end.AddMonth(pay_unit_count_);

  } else {
    date_end.AddYear(pay_unit_count_);
  }

  return date_end;
}

double Deposit::CalcRatePay(const Date& date_now) const {
  uint16_t day_count = date_now.IsLeapYear() ? 366 : 365;
  double rate_day = rate_ / 100 / day_count * answer_sum_;
  return rate_day;
}

bool Deposit::IsNeedCapitalisation(const Date& date_now) const {
  if (pay_period_ == kPayInDay) {
    return true;

  } else if (pay_period_ == kPayInWeek) {
    return IsNextWeek(date_now);

  } else if (pay_period_ == kPayInMonth) {
    return IsDaysEq(date_now);

  } else if (pay_period_ == kPayInQuarter) {
    bool is_next_quarter =
        std::abs((date_start_.GetMonth() - date_now.GetMonth())) % 3 == 0;
    return is_next_quarter && IsDaysEq(date_now);

  } else if (pay_period_ == kPayInHalfYear) {
    bool is_next_half_year =
        std::abs((date_start_.GetMonth() - date_now.GetMonth())) % 2 == 0;
    return is_next_half_year && IsDaysEq(date_now);

  } else if (pay_period_ == kPayInYear) {
    return (date_now.GetDay() == date_start_.GetDay() &&
            date_now.GetMonth() == date_start_.GetMonth());
  }

  return false;
}

bool Deposit::IsDaysEq(const Date& date_now) const {
  bool answer = (date_now.GetDay() == date_start_.GetDay());

  if (answer == false) {
    uint8_t day_max1 = date_now.GetMaxDay();
    uint8_t day_max2 = date_start_.GetMaxDay();

    bool day_on_max1 = day_max1 == date_now.GetDay();
    bool day_on_max2 = day_max2 == date_start_.GetDay();

    if (day_on_max1 && date_now.GetDay() < date_start_.GetDay())
      answer = true;
    else if (day_on_max2 && date_now.GetDay() < date_start_.GetDay())
      answer = true;
  }

  return answer;
}

bool Deposit::IsNextWeek(const Date& date_now) const {
  bool answer = (date_now.GetDay() - date_start_.GetDay()) % 7 == 0;

  if (answer == false) {
    uint8_t day_max1 = date_now.GetMaxDay();
    uint8_t day_max2 = date_start_.GetMaxDay();

    if (day_max1 - date_start_.GetDay() + 1 == date_now.GetDay())
      answer = true;
    else if (day_max2 - date_now.GetDay() + 1 == date_start_.GetDay())
      answer = false;
  }
  return answer;
}

}  // namespace s21
