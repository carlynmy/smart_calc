// Implementation setters methods class Date
// Include SetDate

// Copyright (C) 2023-2023 School 21 License

#include <cinttypes>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <stdexcept>

#include "date.h"

namespace s21 {

void Date::SetDate(uint8_t day, Months month, size_t year) {
  Date date(day, month, year);
  *this = date;
}

void Date::SetDate(uint8_t day, uint8_t month, size_t year) {
  SetDate(day, static_cast<Months>(month), year);
}

void Date::SetDate(const std::string& str) {
  uint8_t day;
  uint8_t month;
  size_t year;

  std::string format = "%" + std::string(SCNu8) + GetDelim() + "%" +
                       std::string(SCNu8) + GetDelim() + "%" +
                       std::string(SCNuMAX);

  uint8_t scan_count = sscanf(str.c_str(), format.c_str(), &day, &month, &year);
  if (scan_count != 3) throw std::logic_error(kErrorMsgs[kInvDate]);

  SetDate(day, month, year);
}

void Date::SetDelim(const std::string& delim) { delim_ = delim; }

// ------------------------------------------------------------------------- //

uint8_t Date::GetDay() const { return day_; }

Date::Months Date::GetMonth() const { return month_; }

size_t Date::GetYear() const { return year_; }

const std::string& Date::GetDelim() const { return delim_; }

}  // namespace s21
