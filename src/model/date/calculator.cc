// Implementation calculator methods class Date
// Include add, sub, plus operator overload, minus operator overload

// Copyright (C) 2023-2023 School 21 License

#include <cstddef>
#include <cstdint>
#include <stdexcept>

#include "date.h"

namespace s21 {

void Date::AddDay(ssize_t count) {
  if (count < 0) {
    SubDay(-count);
    return;
  }

  uint16_t day_in_year = (IsLeapYear() ? 366 : 365);
  while (count > day_in_year) {
    AddYear(1);
    count -= day_in_year;
    day_in_year = (IsLeapYear() ? 366 : 365);
  }

  uint8_t day_in_month = GetMaxDay();
  while (count > day_in_month) {
    AddMonth(1);
    count -= day_in_month;
    day_in_month = GetMaxDay();
  }

  if (count > day_in_month - GetDay()) {
    count -= day_in_month - GetDay() + 1;
    AddMonth(1);
    SetDay(1);
  }

  SetDay(GetDay() + count);
}

void Date::SubDay(ssize_t count) {
  if (count < 0) {
    AddDay(-count);
    return;
  }

  uint16_t day_in_year = (IsLeapYear() ? 366 : 365);
  while (count > day_in_year) {
    SubYear(1);
    day_in_year = (IsLeapYear() ? 366 : 365);
    count -= day_in_year;
  }

  uint8_t day_in_month = GetMaxDay();
  while (count > day_in_month) {
    SubMonth(1);
    day_in_month = GetMaxDay();
    count -= day_in_month;
  }

  if (count >= GetDay()) {
    count -= GetDay();
    SubMonth(1);
    SetDay(GetMaxDay());
  }

  SetDay(GetDay() - count);
}

void Date::AddMonth(ssize_t count) {
  if (count < 0) {
    SubMonth(-count);
    return;
  }

  ssize_t year_count = count / 12;
  AddYear(year_count);
  uint8_t month_count = count % 12;

  if (month_count > static_cast<uint8_t>(kDecember - GetMonth())) {
    month_count -= kDecember - GetMonth() + 1;
    SetMonth(kJanuary);
    AddYear(1);
  }

  SetMonth(static_cast<Months>(GetMonth() + month_count));
}

void Date::SubMonth(ssize_t count) {
  if (count < 0) {
    AddMonth(-count);
    return;
  }

  ssize_t year_count = count / 12;
  SubYear(year_count);
  uint8_t month_count = count % 12;

  if (month_count >= static_cast<uint8_t>(GetMonth())) {
    month_count -= GetMonth();
    SetMonth(kDecember);
    SubYear(1);
  }

  SetMonth(static_cast<Months>(static_cast<uint8_t>(GetMonth()) - month_count));
}

void Date::AddYear(ssize_t count) {
  if (count < 0) {
    SubYear(-count);
    return;
  }

  SetYear(GetYear() + count);
}

void Date::SubYear(ssize_t count) {
  if (count < 0) {
    AddYear(-count);
    return;
  }

  if (static_cast<ssize_t>(GetYear()) < count)
    throw std::underflow_error(kErrorMsgs[kUnderflow]);

  SetYear(GetYear() - count);
}

void Date::Add(ssize_t day_count, ssize_t month_count, ssize_t year_count) {
  AddDay(day_count);
  AddMonth(month_count);
  AddYear(year_count);
}

void Date::Sub(ssize_t day_count, ssize_t month_count, ssize_t year_count) {
  SubDay(day_count);
  SubMonth(month_count);
  SubYear(year_count);
}

Date& Date::operator++() {
  AddDay(1);
  return *this;
}

Date& Date::operator--() {
  SubDay(1);
  return *this;
}

Date Date::operator+(ssize_t day_count) const {
  Date ans(*this);
  ans.AddDay(day_count);
  return ans;
}

Date Date::operator-(ssize_t day_count) const {
  Date ans(*this);
  ans.SubDay(day_count);
  return ans;
}

Date operator+(ssize_t day_count, Date& date) {
  Date ans(date);
  ans.AddDay(day_count);
  return ans;
}

Date operator-(ssize_t day_count, Date& date) {
  Date ans(date);
  ans.SubDay(day_count);
  return ans;
}

Date& Date::operator+=(ssize_t day_count) {
  AddDay(day_count);
  return *this;
}

Date& Date::operator-=(ssize_t day_count) {
  AddDay(day_count);
  return *this;
}

}  // namespace s21
