// Implementation paint methods class WidgetGraph

// Copyright (C) 2023-2023 School 21 License

#include <QPainter>
#include <QPoint>
#include <QString>

#include "../mainwindow/mainwindow.h"
#include "widgetgraph.h"

namespace s21 {

void WidgetGraph::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  PaintFillArea(&painter);

  if (!IsValidData()) return;
  ReCalcSteps();

  PaintBoard(&painter);
  if (draw_axis_x_) PaintAxisX(&painter);
  if (draw_axis_y_) PaintAxisY(&painter);
  PaintBorder(&painter);

  if (mainwindow_ != nullptr) PaintGraphs(&painter);

  event->accept();
}

void WidgetGraph::PaintFillArea(QPainter* painter) {
  painter->fillRect(rect(), kColorArea);
}

void WidgetGraph::PaintBorder(QPainter* painter) {
  painter->setPen(kColorBorder);
  int y_max = height() - 1;
  int x_max = width() - 1;
  painter->drawLine(0, 0, x_max, 0);
  painter->drawLine(0, y_max, x_max, y_max);
  painter->drawLine(0, 0, 0, y_max);
  painter->drawLine(x_max, 0, x_max, y_max);
}

void WidgetGraph::PaintAxisX(QPainter* painter) {
  painter->setPen(kColorAxis);
  painter->drawLine(RealToCoord({x_min_, 0}), RealToCoord({x_max_, 0}));
}

void WidgetGraph::PaintAxisY(QPainter* painter) {
  painter->setPen(kColorAxis);
  painter->drawLine(RealToCoord({0, y_min_}), RealToCoord({0, y_max_}));
}

void WidgetGraph::PaintBoard(QPainter* painter) {
  double x_step = UsedXStep();
  double x_small_step = x_step / 5;
  int i = static_cast<int>(x_min_ / x_step) - 1;
  for (; x_step * i < x_max_; ++i) {
    double x_now = x_step * i;
    if (draw_grid_) DrawGridXLine(painter, x_now);
    if (draw_grid_ && draw_small_grid_)
      DrawSmallGridXLine(painter, x_now, x_small_step);
    if (draw_nums_on_axis_ && draw_axis_x_) DrawNumsOnAxisX(painter, x_now);
  }

  double y_step = UsedYStep();
  double y_small_step = y_step / 5;
  i = static_cast<int>(y_min_ / y_step) - 1;
  for (; y_step * i < y_max_; ++i) {
    double y_now = y_step * i;
    if (draw_grid_) DrawGridYLine(painter, y_now);
    if (draw_grid_ && draw_small_grid_)
      DrawSmallGridYLine(painter, y_now, y_small_step);
    if (draw_nums_on_axis_ && draw_axis_y_) DrawNumsOnAxisY(painter, y_now);
  }

  if (draw_nums_on_axis_ && (draw_axis_x_ || draw_axis_y_))
    DrawZeroNum(painter);
}

void WidgetGraph::DrawGridXLine(QPainter* painter, double x_now) {
  painter->setPen(kColorGrid);
  painter->drawLine(RealToCoord({x_now, y_min_}), RealToCoord({x_now, y_max_}));
}

void WidgetGraph::DrawSmallGridXLine(QPainter* painter, double x_now,
                                     double x_small_step) {
  painter->setPen(kColorSmallGrid);
  for (int j = 1; j < 5; ++j) {
    double x_small_now = x_now + x_small_step * j;
    painter->drawLine(RealToCoord({x_small_now, y_min_}),
                      RealToCoord({x_small_now, y_max_}));
  }
}

void WidgetGraph::DrawNumsOnAxisX(QPainter* painter, double x_now) {
  if (x_now == 0) return;
  painter->setPen(kColorNums);
  QString text = FloatToQString(x_now);
  QPoint coord = RealToCoord({x_now, 0});
  coord.setY(coord.y() + 15);
  painter->drawText(coord, text);
}

void WidgetGraph::DrawGridYLine(QPainter* painter, double y_now) {
  painter->setPen(kColorGrid);
  painter->drawLine(RealToCoord({x_min_, y_now}), RealToCoord({x_max_, y_now}));
}

void WidgetGraph::DrawSmallGridYLine(QPainter* painter, double y_now,
                                     double y_small_step) {
  painter->setPen(kColorSmallGrid);
  for (int j = 1; j < 5; ++j) {
    double y_small_now = y_now + y_small_step * j;
    painter->drawLine(RealToCoord({x_min_, y_small_now}),
                      RealToCoord({x_max_, y_small_now}));
  }
}

void WidgetGraph::DrawNumsOnAxisY(QPainter* painter, double y_now) {
  if (y_now == 0) return;
  painter->setPen(kColorNums);
  QString text = FloatToQString(-y_now);
  QPoint coord = RealToCoord({0, y_now});
  coord.setX(coord.x() + 5);
  painter->drawText(coord, text);
}

void WidgetGraph::DrawZeroNum(QPainter* painter) {
  painter->setPen(kColorNums);
  QString text = FloatToQString(0);
  QPoint coord = RealToCoord({0, 0});
  coord.setX(coord.x() - 10);
  coord.setY(coord.y() + 15);
  painter->drawText(coord, text);
}

void WidgetGraph::PaintGraphs(QPainter* painter) {
  WidgetListWidget::iterator func_i =
      mainwindow_->widget_list_graph_vars_->Begin();
  mainwindow_->controller_->GraphListBegin();
  for (; func_i != mainwindow_->widget_list_graph_vars_->End(); ++func_i) {
    WidgetFunc* func = reinterpret_cast<WidgetFunc*>(&*func_i);
    if (!func->IsDrawn() || func->IsHide()) continue;

    PaintGraph(painter, func->GetColor());

    mainwindow_->controller_->GraphListNext();
  }
}

void WidgetGraph::PaintGraph(QPainter* painter, const QColor& color) {
  painter->setPen(color);
  mainwindow_->controller_->GraphBegin();
  while (!mainwindow_->controller_->GraphEnd()) {
    s21::Point model_point = mainwindow_->controller_->GraphNext();
    QPoint qpoint(model_point.x, model_point.y);
    painter->drawPoint(qpoint);
  }
}

}  // namespace s21
