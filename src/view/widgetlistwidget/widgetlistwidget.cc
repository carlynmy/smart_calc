// Implementation class WidgetListWidget

// Copyright (C) 2023-2023 School 21 License

#include "widgetlistwidget.h"

#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QPoint>
#include <QSizePolicy>
#include <QVBoxLayout>
#include <QWidget>
#include <cmath>
#include <cstddef>

#include "widgetlistwidgetdelimline.h"
#include "widgetlistwidgetitem.h"

namespace s21 {

// ------------------------------------------------------------------------- //
//                              Constructor                                  //
// ------------------------------------------------------------------------- //

WidgetListWidget::WidgetListWidget(int w, QWidget* parent) : QWidget{parent} {
  setGeometry(0, 0, w, 0);

  QVBoxLayout* layout = new QVBoxLayout();
  layout->setAlignment(Qt::AlignLeft);
  layout->setGeometry(geometry());
  layout->setSpacing(0);
  layout->setContentsMargins(0, 0, 0, 0);
  this->setLayout(layout);

  setAcceptDrops(true);
}

WidgetListWidget::~WidgetListWidget() {
  List::iterator i = item_list_.begin();
  while (i != item_list_.end()) {
    delete i->first;
    delete i->second;
    ++i;
  }

  delete layout();
}

// ------------------------------------------------------------------------- //
//                              Element access                               //
// ------------------------------------------------------------------------- //

QWidget* WidgetListWidget::Front() { return &*Begin(); }

const QWidget* WidgetListWidget::Front() const { return &*Begin(); }

QWidget* WidgetListWidget::Back() {
  iterator iter = End();
  --iter;
  return &*iter;
}

const QWidget* WidgetListWidget::Back() const {
  const_iterator iter = End();
  --iter;
  return &*iter;
}

// ------------------------------------------------------------------------- //
//                                 Iterator                                  //
// ------------------------------------------------------------------------- //

WidgetListWidget::iterator WidgetListWidget::Begin() {
  return iterator(item_list_.begin());
}

WidgetListWidget::const_iterator WidgetListWidget::Begin() const {
  return const_iterator(item_list_.begin());
}

WidgetListWidget::iterator WidgetListWidget::End() {
  return iterator(item_list_.end());
}

WidgetListWidget::const_iterator WidgetListWidget::End() const {
  return const_iterator(item_list_.end());
}

// ------------------------------------------------------------------------- //
//                               List methods                                //
// ------------------------------------------------------------------------- //

void WidgetListWidget::AddWidget(QWidget* widget) {
  int w = widget->width(), h = widget->height();

  WidgetListWidgetDelimLine* line =
      new WidgetListWidgetDelimLine(w, kDelimLineSize, this);
  WidgetListWidgetItem* item = CreateWidgetListWidgetItem(w, h, widget);

  AddSpRetain(line);
  AddSpRetain(item);

  layout()->addWidget(line);
  layout()->addWidget(item);

  item_list_.push_back({item, line});
  ++item_count_;

  int this_h = item_count_ * (kDelimLineSize + item->height());
  setMinimumHeight(this_h);
  setMaximumHeight(this_h);

  layout()->setGeometry(geometry());

  line->hide();
  item->show();
  widget->show();
}

void WidgetListWidget::RemoveWidget(const QWidget* widget) {
  List::iterator iter = item_list_.begin();
  while (iter->first->GetItem() != widget) ++iter;

  size_t size = iter->first->height();

  layout()->removeWidget(iter->first);
  layout()->removeWidget(iter->second);
  delete iter->first;
  delete iter->second;
  item_list_.erase(iter);

  --item_count_;
  int h = item_count_ * (kDelimLineSize + size);
  setMaximumHeight(h);
  setMinimumHeight(h);

  layout()->setGeometry(geometry());
}

size_t WidgetListWidget::Count() const { return item_count_; }

bool WidgetListWidget::IsContains(const QWidget* item) const {
  List::const_iterator iter = item_list_.begin();
  for (; iter != item_list_.end(); ++iter) {
    if (iter->first->GetItem() == item) return true;
  }

  return false;
}

void WidgetListWidget::InsertBefore(QWidget* widget, QWidget* before_this) {
  List::iterator iter_w = item_list_.begin();
  List::iterator iter_b = item_list_.begin();

  size_t i_w = 0, i_b = 0;
  while (iter_w->first->GetItem() != widget) {
    ++iter_w;
    ++i_w;
  }
  while (iter_b->first->GetItem() != before_this) {
    ++iter_b;
    ++i_b;
  }

  if (i_b > i_w) --i_b;

  layout()->removeWidget(iter_w->first);
  layout()->removeWidget(iter_w->second);

  int pos = i_b * 2;
  (reinterpret_cast<QVBoxLayout*>(layout()))->insertWidget(pos, iter_w->first);
  (reinterpret_cast<QVBoxLayout*>(layout()))->insertWidget(pos, iter_w->second);

  item_list_.erase(iter_w);
  item_list_.insert(iter_b, *iter_w);
}

// ------------------------------------------------------------------------- //
//                           Drag And Drop methods                           //
// ------------------------------------------------------------------------- //

void WidgetListWidget::dragEnterEvent(QDragEnterEvent* event) {
  event->accept();
}

void WidgetListWidget::dragMoveEvent(QDragMoveEvent* event) {
  if (!excpect_drag_) return;

  if (item_selected_.second != nullptr) item_selected_.second->hide();

  ListItem line = FindCloserLine(event->pos());

  if (line.second != item_selected_.second && item_selected_.second != nullptr)
    item_selected_.second->hide();

  item_selected_ = line;
  item_selected_.second->show();
}

void WidgetListWidget::DropEventEnd(WidgetListWidgetItem* this_widget) {
  if (item_selected_.second == nullptr) return;

  item_selected_.second->hide();

  if (this_widget != item_selected_.first) {
    InsertBefore(this_widget->GetItem(), item_selected_.first->GetItem());
    emit WidgetInsertedBefore(this_widget->GetItem(),
                              item_selected_.first->GetItem());
  }
  item_selected_.first = nullptr;
  item_selected_.second = nullptr;
}

void WidgetListWidget::ExcpectDrag(bool answer) { excpect_drag_ = answer; }

WidgetListWidget::ListItem WidgetListWidget::FindCloserLine(QPoint point) {
  List::iterator iter = item_list_.begin();
  int point_y = point.y();
  int diff;
  int prev_diff = INT32_MAX;
  for (; iter != item_list_.end(); ++iter) {
    diff = std::abs(iter->second->y() - point_y);
    if (diff >= prev_diff) {
      if (iter == item_list_.begin()) return *iter;
      return *(--iter);
    }
    prev_diff = diff;
  }

  return item_list_.back();
}

// ------------------------------------------------------------------------- //
//                               Utils methods                               //
// ------------------------------------------------------------------------- //

WidgetListWidgetItem* WidgetListWidget::CreateWidgetListWidgetItem(
    int w, int h, QWidget* widget) {
  WidgetListWidgetItem* item = new WidgetListWidgetItem(w, h, widget, this);
  connect(item, &WidgetListWidgetItem::DropEventEnd, this,
          &WidgetListWidget::DropEventEnd);
  connect(item, &WidgetListWidgetItem::ExcpectDrag, this,
          &WidgetListWidget::ExcpectDrag);

  return item;
}

void WidgetListWidget::AddSpRetain(QWidget* widget) {
  QSizePolicy sp_retain = widget->sizePolicy();
  sp_retain.setRetainSizeWhenHidden(true);
  widget->setSizePolicy(sp_retain);
}

}  // namespace s21
