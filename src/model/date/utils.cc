// Implementation utils methods class Date
// Include IsLeapYear, IsMonth30Days, IsMonth31Days, GetMaxDay, ToString,
// operator<< overload

// Copyright (C) 2023-2023 School 21 License

#include <array>
#include <cstddef>
#include <cstdint>
#include <ostream>
#include <sstream>
#include <string>

#include "date.h"

namespace s21 {

bool Date::IsLeapYear() const {
  return ((year_ % 4 == 0 && year_ % 100 != 0) || year_ % 400 == 0);
}

bool Date::IsMonth30Days() const {
  std::array<Months, 4>::iterator i = months_30_days.begin();
  for (; i != months_30_days.end(); ++i) {
    if (*i == month_) return true;
  }

  return false;
}

bool Date::IsMonth31Days() const {
  return month_ != kFebruary && !IsMonth30Days();
}

uint8_t Date::GetMaxDay() const {
  if (IsMonth31Days())
    return 31;
  else if (IsMonth30Days())
    return 30;
  else if (IsLeapYear())
    return 29;

  return 28;
}

std::string Date::ToString() const {
  std::ostringstream out;

  if (GetDay() < 10) out << '0';
  out << static_cast<uint32_t>(GetDay()) << GetDelim();
  if (static_cast<int>(GetMonth()) < 10) out << '0';
  out << static_cast<uint32_t>(GetMonth()) << GetDelim();
  out << GetYear();

  return out.str();
}

std::ostream& operator<<(std::ostream& out, Date& date) {
  out << date.ToString();
  return out;
}

bool Date::IsValid() const {
  if (day_ == 0 || month_ < kJanuary)
    return false;
  else if (day_ > 31 || month_ > kDecember)
    return false;
  else if (IsMonth30Days() && day_ == 31)
    return false;
  else if (month_ == kFebruary && GetMaxDay() < day_)
    return false;

  return true;
}

}  // namespace s21
