// Implementation class WidgetGraph

// Copyright (C) 2023-2023 School 21 License

#include "widgetgraph.h"

#include <QMouseEvent>
#include <QPoint>
#include <QResizeEvent>
#include <QString>
#include <QWheelEvent>
#include <QWidget>
#include <cmath>
#include <string>

#include "../mainwindow/mainwindow.h"

namespace s21 {

WidgetGraph::WidgetGraph(QWidget* parent, MainWindow* mainwindow)
    : QWidget{parent} {
  mainwindow_ = mainwindow;
  ReCalcSteps();
}

WidgetGraph::~WidgetGraph() {}

// ------------------------------------------------------------------------- //

void WidgetGraph::resizeEvent(QResizeEvent* event) {
  SetXRange(x_min_, x_max_, true);
  emit FieldChanged(kFieldWidth);
  emit FieldChanged(kFieldHeight);
  event->accept();
}

void WidgetGraph::mousePressEvent(QMouseEvent* event) {
  move_last_pos_ = event->pos();
  event->accept();
}

void WidgetGraph::mouseMoveEvent(QMouseEvent* event) {
  QPoint pos = event->pos();

  Point real_last_pos = CoordToReal(move_last_pos_);
  Point real_pos = CoordToReal(pos);
  double delta_x = real_last_pos.x - real_pos.x;
  double delta_y = real_last_pos.y - real_pos.y;

  double new_x_max = x_max_ + delta_x;
  double new_x_min = x_min_ + delta_x;
  double new_y_max = y_max_ + delta_y;
  double new_y_min = y_min_ + delta_y;
  SetXRange(new_x_min, new_x_max, false);
  SetYRange(new_y_min, new_y_max, false);
  emit FieldChanged(kFieldXMax);
  emit FieldChanged(kFieldXMin);
  emit FieldChanged(kFieldYMax);
  emit FieldChanged(kFieldYMin);

  move_last_pos_ = pos;
  update();
  event->accept();
}

void WidgetGraph::wheelEvent(QWheelEvent* event) {
  int delta = -reinterpret_cast<QWheelEvent*>(event)->angleDelta().y();
  delta /= 120;
  double add_x = delta * x_step_;
  if (delta < 0 && x_step_ == kGraphMinStep) return;

  double new_x_max = x_max_ + add_x;
  double new_x_min = x_min_ - add_x;

  SetXRange(new_x_min, new_x_max, true);
  emit FieldChanged(kFieldXMax);
  emit FieldChanged(kFieldXMin);
}

// ------------------------------------------------------------------------- //

double WidgetGraph::GetXMin() const { return x_min_; }

double WidgetGraph::GetXMax() const { return x_max_; }

double WidgetGraph::GetYMin() const { return y_min_; }

double WidgetGraph::GetYMax() const { return y_max_; }

double WidgetGraph::GetXStep() const { return UsedXStep(); }

double WidgetGraph::GetYStep() const { return UsedYStep(); }

// ------------------------------------------------------------------------- //

void WidgetGraph::SetMainWindow(MainWindow* mainwindow) {
  mainwindow_ = mainwindow;
}

void WidgetGraph::SetXRange(double x_min, double x_max, bool update_y) {
  x_min_ = x_min;
  x_max_ = x_max;

  if (!update_y) return;

  double k = static_cast<double>(width()) / height();
  y_min_ = x_min / k;
  y_max_ = x_max / k;
  emit FieldChanged(kFieldYMax);
  emit FieldChanged(kFieldYMin);
}

void WidgetGraph::SetYRange(double y_min, double y_max, bool update_x) {
  y_min_ = y_min;
  y_max_ = y_max;

  if (!update_x) return;

  double k = static_cast<double>(width()) / height();
  x_min_ = y_min * k;
  x_max_ = y_max * k;
  emit FieldChanged(kFieldXMax);
  emit FieldChanged(kFieldXMin);
}

void WidgetGraph::SetXMin(double x_min) { x_min_ = x_min; }

void WidgetGraph::SetXMax(double x_max) { x_max_ = x_max; }

void WidgetGraph::SetYMin(double y_min) { y_min_ = y_min; }

void WidgetGraph::SetYMax(double y_max) { y_max_ = y_max; }

void WidgetGraph::SetXStep(double x_step) { user_x_step_ = x_step; }

void WidgetGraph::SetYStep(double y_step) { user_y_step_ = y_step; }

void WidgetGraph::DrawAxisX(bool answer) { draw_axis_x_ = answer; }

void WidgetGraph::DrawAxisY(bool answer) { draw_axis_y_ = answer; }

void WidgetGraph::DrawGrid(bool answer) { draw_grid_ = answer; }

void WidgetGraph::DrawSmallGrid(bool answer) { draw_small_grid_ = answer; }

void WidgetGraph::DrawNumsOnAxis(bool answer) { draw_nums_on_axis_ = answer; }

// ------------------------------------------------------------------------- //

int WidgetGraph::XRealToCoord(double x_real) {
  return (x_real - x_min_) * (width() - 1) / (x_max_ - x_min_);
}

int WidgetGraph::YRealToCoord(double y_real) {
  return (y_real - y_min_) * (height() - 1) / (y_max_ - y_min_);
}

double WidgetGraph::XCoordToReal(int x_coord) {
  return static_cast<double>(x_coord) / (width() - 1) * (x_max_ - x_min_) +
         x_min_;
}

double WidgetGraph::YCoordToReal(int y_coord) {
  return static_cast<double>(y_coord) / (height() - 1) * (y_max_ - y_min_) +
         y_min_;
}

QPoint WidgetGraph::RealToCoord(Point point) {
  QPoint qpoint;
  qpoint.setX(XRealToCoord(point.x));
  qpoint.setY(YRealToCoord(point.y));
  return qpoint;
}

WidgetGraph::Point WidgetGraph::CoordToReal(QPoint qpoint) {
  Point point;
  point.x = XCoordToReal(qpoint.x());
  point.y = YCoordToReal(qpoint.y());
  return point;
}

// ------------------------------------------------------------------------- //

void WidgetGraph::ReCalcSteps() {
  CalcMaxStepCount();
  CalcXStep();
  CalcYStep();
}

void WidgetGraph::CalcXStep() {
  double x_size = x_max_ - x_min_;
  double max_step = x_size / max_step_count_;

  int power = 0;

  // find exponent
  while (max_step > 10) {
    max_step /= 10;
    ++power;
  }
  while (max_step < 1) {
    max_step *= 10;
    --power;
  }

  // define step is 1 or 2 or 5
  if (max_step <= 1) {
    x_step_ = 1;
  } else if (max_step <= 2) {
    x_step_ = 2;
  } else if (max_step <= 5) {
    x_step_ = 5;
  } else {
    x_step_ = 1;
    ++power;
  }

  x_step_ *= std::pow(10, power);
  if (x_step_ < kGraphMinStep) x_step_ = kGraphMinStep;
}

void WidgetGraph::CalcYStep() { y_step_ = x_step_; }

void WidgetGraph::CalcMaxStepCount() {
  max_step_count_ = width() / kMaxPixelStepCount;
}

double WidgetGraph::UsedXStep() const {
  if (user_x_step_ == 0) return x_step_;
  return user_x_step_;
}
double WidgetGraph::UsedYStep() const {
  if (user_y_step_ == 0) return y_step_;
  return user_y_step_;
}

bool WidgetGraph::IsValidData() const {
  if (x_min_ >= x_max_) return false;
  if (y_min_ >= y_max_) return false;
  if (user_x_step_ < 0) return false;
  if (user_y_step_ < 0) return false;
  if (x_max_ - x_min_ < kGraphMinDiff) return false;

  return true;
}

// ------------------------------------------------------------------------- //

std::string WidgetGraph::FloatToString(double value) {
  std::string str = std::to_string(value);
  while (str.back() == '0') str.pop_back();
  if (str.back() == '.') str.pop_back();
  if (value >= 1e5 || value <= -1e5) {
    int exp_count = 0;
    while (str.back() == '0') {
      str.pop_back();
      ++exp_count;
    }
    str.append("e+");
    str.append(FloatToString(exp_count));
  }

  return str;
}

QString WidgetGraph::FloatToQString(double value) {
  return QString(FloatToString(value).c_str());
}

}  // namespace s21
