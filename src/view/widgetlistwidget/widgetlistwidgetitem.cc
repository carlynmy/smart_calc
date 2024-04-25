// Implementation class WidgetListWidgetItem

// Copyright (C) 2023-2023 School 21 License

#include "widgetlistwidgetitem.h"

#include <QDrag>
#include <QEvent>
#include <QMimeData>
#include <QMouseEvent>
#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <QWidget>

namespace s21 {

// ------------------------------------------------------------------------- //
//                              Constructor                                  //
// ------------------------------------------------------------------------- //

WidgetListWidgetItem::WidgetListWidgetItem(int w, int h, QWidget* item,
                                           QWidget* parent)
    : QWidget{parent} {
  setMaximumSize(w, h);
  setMinimumSize(w, h);
  setGeometry(0, 0, w, h);

  SetItem(item);

  timer_ = new QTimer();
  timer_->setSingleShot(true);
  timer_->setInterval(kDragTime);

  connect(this, &WidgetListWidgetItem::EndTimer, timer_, &QTimer::stop);
  connect(this, QOverload<int>::of(&WidgetListWidgetItem::StartTimer), timer_,
          QOverload<int>::of(&QTimer::start));
  connect(timer_, &QTimer::timeout, this, &WidgetListWidgetItem::DoDrag);
}

WidgetListWidgetItem::~WidgetListWidgetItem() {
  delete timer_;
  delete item_;
  DestroyDrag();
}

// ------------------------------------------------------------------------- //
//                            Getters and Setters                            //
// ------------------------------------------------------------------------- //

QWidget* WidgetListWidgetItem::GetItem() { return item_; }

const QWidget* WidgetListWidgetItem::GetItem() const { return item_; }

void WidgetListWidgetItem::SetItem(QWidget* widget) {
  item_ = widget;
  item_->setParent(this);
  item_->installEventFilter(this);
}

// ------------------------------------------------------------------------- //
//                           Drag And Drop methods                           //
// ------------------------------------------------------------------------- //

bool WidgetListWidgetItem::eventFilter(QObject* object, QEvent* event) {
  if (object == nullptr) return false;

  if (event->type() == QEvent::MouseButtonPress)
    mousePressEvent(reinterpret_cast<QMouseEvent*>(event));

  else if (event->type() == QEvent::MouseButtonRelease)
    emit EndTimer();

  return false;
}

void WidgetListWidgetItem::mousePressEvent(QMouseEvent* event) {
  if (!(event->buttons() & Qt::LeftButton)) return;
  emit StartTimer(kDragTime);
}

void WidgetListWidgetItem::DoDrag() {
  emit ExcpectDrag(true);

  DestroyDrag();

  drag_ = new QDrag(this);
  QMimeData* drag_mime_data = new QMimeData;
  QPixmap pixmap(size());
  render(&pixmap);
  drag_->setMimeData(drag_mime_data);
  drag_->setPixmap(pixmap);

  this->hide();
  drag_->exec(Qt::CopyAction | Qt::MoveAction);
  this->show();

  DestroyDrag();
  emit DropEventEnd(this);
  emit ExcpectDrag(false);
}

void WidgetListWidgetItem::DestroyDrag() {
  if (drag_ != nullptr) {
    delete drag_;
    drag_ = nullptr;
  }
}

}  // namespace s21
