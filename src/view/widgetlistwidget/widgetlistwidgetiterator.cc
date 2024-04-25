// Implementation class WidgetListWidgetIterator

// Copyright (C) 2023-2023 School 21 License

#include "widgetlistwidgetiterator.h"

#include <QWidget>
#include <list>

namespace s21 {

// ------------------------------------------------------------------------- //
//                                iterator                                   //
// ------------------------------------------------------------------------- //

WidgetListWidgetIterator::WidgetListWidgetIterator(List::iterator iter)
    : iter_(iter) {}

WidgetListWidgetIterator::~WidgetListWidgetIterator() {}

QWidget& WidgetListWidgetIterator::operator*() const {
  return *iter_->first->GetItem();
}

WidgetListWidgetIterator& WidgetListWidgetIterator::operator++() {
  ++iter_;
  return *this;
}

WidgetListWidgetIterator& WidgetListWidgetIterator::operator--() {
  --iter_;
  return *this;
}

bool WidgetListWidgetIterator::operator==(
    const WidgetListWidgetIterator& other) const {
  return iter_ == other.iter_;
}

bool WidgetListWidgetIterator::operator!=(
    const WidgetListWidgetIterator& other) const {
  return !(*this == other);
}

WidgetListWidgetIterator::operator WidgetListWidgetConstIterator() {
  return WidgetListWidgetConstIterator(iter_);
}

// ------------------------------------------------------------------------- //
//                            Const iterator                                 //
// ------------------------------------------------------------------------- //

WidgetListWidgetConstIterator::WidgetListWidgetConstIterator(
    List::const_iterator iter)
    : iter_(iter) {}

WidgetListWidgetConstIterator::~WidgetListWidgetConstIterator() {}

const QWidget& WidgetListWidgetConstIterator::operator*() const {
  return *iter_->first->GetItem();
}

WidgetListWidgetConstIterator& WidgetListWidgetConstIterator::operator++() {
  ++iter_;
  return *this;
}

WidgetListWidgetConstIterator& WidgetListWidgetConstIterator::operator--() {
  --iter_;
  return *this;
}

bool WidgetListWidgetConstIterator::operator==(
    const WidgetListWidgetConstIterator& other) const {
  return iter_ == other.iter_;
}

bool WidgetListWidgetConstIterator::operator!=(
    const WidgetListWidgetConstIterator& other) const {
  return !(*this == other);
}

}  // namespace s21
