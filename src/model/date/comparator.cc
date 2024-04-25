// Implementation comparator methods class Date
// Include comparator operator overloads

// Copyright (C) 2023-2023 School 21 License

#include "date.h"

namespace s21 {

bool Date::operator==(const Date& other) const {
  return ((this->GetDay() == other.GetDay()) &&
          (this->GetMonth() == other.GetMonth()) &&
          (this->GetYear() == other.GetYear()));
}

bool Date::operator<(const Date& other) const {
  bool answer = true;

  if (this->GetYear() > other.GetYear()) {
    answer = false;

  } else if (this->GetYear() == other.GetYear()) {
    if (this->GetMonth() > other.GetMonth()) {
      answer = false;

    } else if (this->GetMonth() == other.GetMonth()) {
      if (this->GetDay() >= other.GetDay()) {
        answer = false;
      }
    }
  }

  return answer;
}

bool Date::operator!=(const Date& other) const { return !(*this == other); }

bool Date::operator<=(const Date& other) const {
  return (*this < other || *this == other);
}

bool Date::operator>(const Date& other) const { return !(*this <= other); }

bool Date::operator>=(const Date& other) const { return !(*this < other); }

}  // namespace s21
