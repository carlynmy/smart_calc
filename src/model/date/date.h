// Declaration class Date

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_DATE_DATE_H_
#define SMART_CALC_V_2_MODEL_DATE_DATE_H_

#include <array>
#include <cstddef>
#include <cstdint>
#include <ostream>
#include <string>

namespace s21 {

/// @brief Class for work with date
class Date {
 public:
  enum Months : uint8_t {
    kJanuary = 1,
    kFebruary,
    kMart,
    kApril,
    kMay,
    kJune,
    kJule,
    kAugust,
    kSenteber,
    kOctober,
    kNovember,
    kDecember
  };

  // ----------------------------------------------------------------------- //

  /// @brief Default constructor, creates 01/01/1970 date
  Date();

  /// @brief Creates date from input
  /// @exception std::logic_error if invalid data input
  Date(uint8_t day, Months month, size_t year);

  /// @brief Creates date from input
  /// @exception std::logic_error if invalid data input
  Date(uint8_t day, uint8_t month, size_t year);

  /// @brief Creates date from string, use delim (default "/")
  /// @exception std::logic_error if invalid data input
  Date(const std::string& str, const std::string& delim = "/");

  ~Date();

  // ----------------------------------------------------------------------- //

  /// @brief Sets new date from input
  /// @exception std::logic_error if invalid data input
  void SetDate(uint8_t day, Months month, size_t year);

  /// @brief Sets new date from input
  /// @exception std::logic_error if invalid data input
  void SetDate(uint8_t day, uint8_t month, size_t year);

  /// @brief Sets new date from string, use setted delim
  /// @exception std::logic_error if invalid data input
  void SetDate(const std::string& str);

  /// @brief Sets delim, uses for transform Date to std::string and back
  void SetDelim(const std::string& delim);

  uint8_t GetDay() const;
  Months GetMonth() const;
  size_t GetYear() const;
  const std::string& GetDelim() const;

  // ----------------------------------------------------------------------- //

  bool IsLeapYear() const;
  bool IsMonth30Days() const;
  bool IsMonth31Days() const;

  /// @brief Returns max days in current month
  uint8_t GetMaxDay() const;

  // ----------------------------------------------------------------------- //

  /// @brief Add count days to current date
  /// @exception std::underflow_error if result less then min
  void AddDay(ssize_t count);

  /// @brief Sub count days to current date
  /// @exception std::underflow_error if result less then min
  void SubDay(ssize_t count);

  /// @brief Add count months to current date
  /// @exception std::underflow_error if result less then min
  void AddMonth(ssize_t count);

  /// @brief Sub count months to current date
  /// @exception std::underflow_error if result less then min
  void SubMonth(ssize_t count);

  /// @brief Add count years to current date
  /// @exception std::underflow_error if result less then min
  void AddYear(ssize_t count);

  /// @brief Sub count years to current date
  /// @exception std::underflow_error if result less then min
  void SubYear(ssize_t count);

  /// @brief Add day_count days, month_count months, year_count years to current
  /// date
  /// @exception std::underflow_error if result less then min
  void Add(ssize_t day_count, ssize_t month_count, ssize_t year_count);

  /// @brief Sub day_count days, month_count months, year_count years to current
  /// date
  /// @exception std::underflow_error if result less then min
  void Sub(ssize_t day_count, ssize_t month_count, ssize_t year_count);

  /// @brief Add 1 day to current date, may use to iterate to date
  Date& operator++();

  /// @brief Sub 1 day to current date, may use to iterate to date
  /// @exception std::underflow_error if result less then min
  Date& operator--();

  /// @brief Return new date being the sum this and day_count days
  /// @exception std::underflow_error if result less then min
  Date operator+(ssize_t day_count) const;

  /// @brief Return new date being the sub this and day_count days
  /// @exception std::underflow_error if result less then min
  Date operator-(ssize_t day_count) const;

  /// @brief Return new date being the sum this and day_count days
  /// @exception std::underflow_error if result less then min
  friend Date operator+(ssize_t day_count, Date& date);

  /// @brief Return new date being the sub this and day_count days
  /// @exception std::underflow_error if result less then min
  friend Date operator-(ssize_t day_count, Date& date);

  /// @brief Add count days to current date
  /// @exception std::underflow_error if result less then min
  Date& operator+=(ssize_t day_count);

  /// @brief Sub count days to current date
  /// @exception std::underflow_error if result less then min
  Date& operator-=(ssize_t day_count);

  // ----------------------------------------------------------------------- //

  bool operator==(const Date& other) const;
  bool operator!=(const Date& other) const;
  bool operator<(const Date& other) const;
  bool operator<=(const Date& other) const;
  bool operator>(const Date& other) const;
  bool operator>=(const Date& other) const;

  // ----------------------------------------------------------------------- //

  /// @brief Returns string representation of Date, use setted delim to delim
  /// numbers
  std::string ToString() const;

  friend std::ostream& operator<<(std::ostream& out, Date& date);

 private:
  enum ErrorIndexes { kInvDate, kUnderflow };

  static inline std::array<Months, 4> months_30_days = {kApril, kJune,
                                                        kSenteber, kNovember};
  static inline const std::string kErrorMsgs[] = {
      "Неккоректная дата", "Результат меньше минимального"};

  bool IsValid() const;
  void SetDay(uint8_t day) { day_ = day; }
  void SetMonth(Months month) { month_ = month; }
  void SetYear(size_t year) { year_ = year; }

  uint8_t day_;
  Months month_;
  size_t year_;
  std::string delim_ = "/";
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_DATE_DATE_H_
