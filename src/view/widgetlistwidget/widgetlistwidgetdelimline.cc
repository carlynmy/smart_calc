// Implementation class WidgetListWidgetDelimLine

// Copyright (C) 2023-2023 School 21 License

#include "widgetlistwidgetdelimline.h"

#include <QPaintEvent>
#include <QPainter>
#include <QWidget>

namespace s21 {

WidgetListWidgetDelimLine::WidgetListWidgetDelimLine(int w, int h,
                                                     QWidget *parent)
    : QWidget{parent} {
  setMinimumSize(w, h);
  setMaximumSize(w, h);
  setGeometry(0, 0, w, h);
}

WidgetListWidgetDelimLine::~WidgetListWidgetDelimLine() {}

void WidgetListWidgetDelimLine::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setPen(Qt::white);
  int w = width(), h = height();

  painter.drawLine(0, 0, 0, h);
  painter.drawLine(w - 1, 0, w - 1, h);
  painter.drawLine(0, h / 2, w - 1, h / 2);

  event->accept();
}

}  // namespace s21
