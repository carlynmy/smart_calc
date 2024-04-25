// Implementation class GraphFunc1Y

// Copyright (C) 2023-2023 School 21 License

#include "graph_func_1_y.h"

#include <list>

#include "../sm_exceptions/calculation_error.h"
#include "../sm_exceptions/invalid_expression.h"

namespace s21 {

GraphFunc1Y::GraphFunc1Y(const UserFunction& function) : function_(function) {
  SetIsEnd(true);
  SetType(kTypeFunc1Y);
}

GraphFunc1Y::~GraphFunc1Y() {}

void GraphFunc1Y::Begin() {
  SetIsEnd(false);
  x_delta_ = (GetXMax() - GetXMin()) / (GetXSize() - 1);
  y_delta_ = (GetYMax() - GetYMin()) / (GetYSize() - 1);
  y_next_ = GetYMin();
  y_coord_next_ = 0;

  CalcNext();
}

Point GraphFunc1Y::Next() {
  bool points_in = pos_prev_ == kPosIn && pos_next_ == kPosIn;
  bool point_out_up = (pos_prev_ == kPosOutUp && pos_next_ == kPosIn) ||
                      (pos_prev_ == kPosIn && pos_next_ == kPosOutUp);
  bool point_out_down = (pos_prev_ == kPosOutDown && pos_next_ == kPosIn) ||
                        (pos_prev_ == kPosIn && pos_next_ == kPosOutDown);

  bool need_connect =
      (y_coord_prev_ == y_coord_next_ - 1) && (x_connect_ != x_coord_next_);

  Point point;
  if (need_connect && (points_in || point_out_up || point_out_down)) {
    point.x = x_connect_;

    int diff = std::abs(x_coord_next_ - x_coord_prev_);
    if (std::abs(x_connect_ - x_coord_prev_) < diff / 2)
      point.y = y_coord_prev_;
    else
      point.y = y_coord_next_;

    if (x_coord_prev_ < x_coord_next_)
      ++x_connect_;
    else
      --x_connect_;

  } else {
    point.x = x_coord_next_;
    point.y = y_coord_next_;

    x_prev_ = x_next_;
    y_prev_ = y_next_;
    x_coord_prev_ = x_coord_next_;
    y_coord_prev_ = y_coord_next_;
    pos_prev_ = pos_next_;

    x_connect_ = x_coord_prev_;
    y_connect_ = y_coord_prev_;

    y_next_ += y_delta_;
    ++y_coord_next_;
    CalcNext();
  }

  return point;
}

void GraphFunc1Y::CalcNext() {
  bool exception_flag = true;
  while (exception_flag && y_coord_next_ != static_cast<int>(GetYSize() - 1)) {
    std::list<double> arg_list;
    arg_list.push_back(y_next_);

    exception_flag = false;
    try {
      x_next_ = function_.Calc(arg_list);

    } catch (const CalculationError&) {
      exception_flag = true;
      ++y_coord_next_;
      y_next_ += y_delta_;
    } catch (const InvalidExpr&) {
      SetIsEnd(true);
    }
  }

  if (x_next_ < GetXMin())
    pos_next_ = kPosOutDown;
  else if (x_next_ > GetXMax())
    pos_next_ = kPosOutUp;
  else
    pos_next_ = kPosIn;

  x_coord_next_ = XRealToCoord(x_next_);
  if (y_coord_next_ == static_cast<int>(GetYSize() - 1)) SetIsEnd(true);
}

}  // namespace s21
