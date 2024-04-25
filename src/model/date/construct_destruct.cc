// Implementation construct methods class Date
// Include constructors, destructor

// Copyright (C) 2023-2023 School 21 License

#include <cstddef>
#include <cstdint>
#include <string>

#include "date.h"

namespace s21 {

Date::Date() : Date(1, kJanuary, 1970) {}

Date::Date(uint8_t day, Months month, size_t year)
    : day_(day), month_(month), year_(year) {
  if (!IsValid()) throw std::logic_error(kErrorMsgs[kInvDate]);
}

Date::Date(uint8_t day, uint8_t month, size_t year)
    : Date(day, static_cast<Months>(month), year) {}

Date::Date(const std::string& str, const std::string& delim) {
  SetDelim(delim);
  SetDate(str);
}

Date::~Date() {}

}  // namespace s21
