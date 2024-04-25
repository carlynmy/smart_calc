// Declaration class GraphConstY

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_GRAPH_GRAPH_CONST_Y_H_
#define SMART_CALC_V_2_MODEL_GRAPH_GRAPH_CONST_Y_H_

#include "graph.h"

namespace s21 {

class GraphConstY : public Graph {
 public:
  GraphConstY(double x);
  ~GraphConstY();

  void Begin() override;
  Point Next() override;

 private:
  double x_;
  int coord_x_;
  int coord_y_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_GRAPH_GRAPH_CONST_Y_H_
