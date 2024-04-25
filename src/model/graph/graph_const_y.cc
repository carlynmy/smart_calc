// Implementation class GraphConstY

// Copyright (C) 2023-2023 School 21 License

#include "graph_const.h"

namespace s21 {

GraphConstY::GraphConstY(double x) : x_(x) {
  SetIsEnd(true);
  SetType(kTypeConstY);
}

GraphConstY::~GraphConstY() {}

void GraphConstY::Begin() {
  SetIsEnd(false);
  coord_x_ = XRealToCoord(x_);
  coord_y_ = 0;
}

Point GraphConstY::Next() {
  Point point{coord_x_, coord_y_};

  ++coord_y_;
  if (coord_y_ == static_cast<int>(GetYSize())) SetIsEnd(true);
  return point;
}

}  // namespace s21
