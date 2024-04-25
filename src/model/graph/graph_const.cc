// Implementation class GraphConst

// Copyright (C) 2023-2023 School 21 License

#include "graph_const.h"

namespace s21 {

GraphConst::GraphConst(double y) : y_(y) {
  SetIsEnd(true);
  SetType(kTypeConst);
}

GraphConst::~GraphConst() {}

void GraphConst::Begin() {
  SetIsEnd(false);
  coord_x_ = 0;
  coord_y_ = YRealToCoord(y_);
}

Point GraphConst::Next() {
  Point point{coord_x_, coord_y_};

  ++coord_x_;
  if (coord_x_ == static_cast<int>(GetXSize())) SetIsEnd(true);
  return point;
}

}  // namespace s21
