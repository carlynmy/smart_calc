// Declaration class WidgetListWidgetIterator

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_VIEW_WIDGETLISTWIDGET_WIDGETLISTWIDGETITERATOR_H_
#define SMART_CALC_V_2_VIEW_WIDGETLISTWIDGET_WIDGETLISTWIDGETITERATOR_H_

#include <QWidget>
#include <list>
#include <utility>

#include "widgetlistwidgetdelimline.h"
#include "widgetlistwidgetitem.h"

namespace s21 {

class WidgetListWidgetConstIterator;

// ------------------------------------------------------------------------- //
//                                iterator                                   //
// ------------------------------------------------------------------------- //

/// @brief Class WidgetListWidgetIterator for WidgetListWidget.
class WidgetListWidgetIterator {
  using ListItem = std::pair<WidgetListWidgetItem*, WidgetListWidgetDelimLine*>;
  using List = std::list<ListItem>;

 public:
  WidgetListWidgetIterator(List::iterator iter);

  ~WidgetListWidgetIterator();

  // --------------------------------------------------------------------- //

  /// @brief Get reference to item to which the iterator points
  QWidget& operator*() const;

  /// @brief Move iterator to next pos
  WidgetListWidgetIterator& operator++();

  /// @brief Move iterator to prev pos
  WidgetListWidgetIterator& operator--();

  // --------------------------------------------------------------------- //

  /// @brief Compare iterators
  /// @return true if iterators points to same item else false
  bool operator==(const WidgetListWidgetIterator& other) const;

  /// @brief Compare iterators
  /// @return true if iterators points to different item else true
  bool operator!=(const WidgetListWidgetIterator& other) const;
  // --------------------------------------------------------------------- //

  /// @brief Cast iterator to const_iterator
  operator WidgetListWidgetConstIterator();

 protected:
  List::iterator iter_;
};

// ------------------------------------------------------------------------- //
//                            Const iterator                                 //
// ------------------------------------------------------------------------- //

/// @brief Class WidgetListWidgetConstIterator for WidgetListWidget. Same as
/// WidgetListWidgetIterator except unreference operator returns const reference
/// to item
class WidgetListWidgetConstIterator {
  using ListItem = std::pair<WidgetListWidgetItem*, WidgetListWidgetDelimLine*>;
  using List = std::list<ListItem>;

 public:
  WidgetListWidgetConstIterator(List::const_iterator iter);

  ~WidgetListWidgetConstIterator();

  // --------------------------------------------------------------------- //

  /// @brief Get const reference to item to which the iterator points
  const QWidget& operator*() const;

  /// @brief Move iterator to next pos
  WidgetListWidgetConstIterator& operator++();

  /// @brief Move iterator to prev pos
  WidgetListWidgetConstIterator& operator--();

  // --------------------------------------------------------------------- //

  /// @brief Compare iterators
  /// @return true if iterators points to same item else false
  bool operator==(const WidgetListWidgetConstIterator& other) const;

  /// @brief Compare iterators
  /// @return true if iterators points to different item else true
  bool operator!=(const WidgetListWidgetConstIterator& other) const;
  // --------------------------------------------------------------------- //

 protected:
  List::const_iterator iter_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_VIEW_WIDGETLISTWIDGET_WIDGETLISTWIDGETITERATOR_H_
