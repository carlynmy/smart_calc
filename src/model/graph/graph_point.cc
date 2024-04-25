// Implementation class GraphPoint

// Copyright (C) 2023-2023 School 21 License

#include "graph_point.h"

namespace s21 {

GraphPoint::GraphPoint(double x, double y) : x_(x), y_(y) {
  SetIsEnd(true);
  SetType(kTypePoint);
}

GraphPoint::~GraphPoint() {}

void GraphPoint::Begin() {
  if (x_ < GetXMin() || x_ > GetXMax() || y_ > -GetYMin() || y_ < -GetYMax())
    SetIsEnd(true);
  else
    SetIsEnd(false);
}

Point GraphPoint::Next() {
  SetIsEnd(true);
  Point point = RealToCoord(x_, y_);
  return point;
}

}  // namespace s21
