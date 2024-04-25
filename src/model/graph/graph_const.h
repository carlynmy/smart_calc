// Declaration class GraphConst

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_GRAPH_GRAPH_CONST_H_
#define SMART_CALC_V_2_MODEL_GRAPH_GRAPH_CONST_H_

#include "graph.h"

namespace s21 {

class GraphConst : public Graph {
 public:
  GraphConst(double y);
  ~GraphConst();

  void Begin() override;
  Point Next() override;

 private:
  double y_;
  int coord_x_;
  int coord_y_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_GRAPH_GRAPH_CONST_H_
