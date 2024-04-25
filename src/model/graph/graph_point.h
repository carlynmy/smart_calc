// Declaration class GraphPoint

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_GRAPH_GRAPH_POINT_H_
#define SMART_CALC_V_2_MODEL_GRAPH_GRAPH_POINT_H_

#include "graph.h"

namespace s21 {

class GraphPoint : public Graph {
 public:
  GraphPoint(double x, double y);
  ~GraphPoint();

  void Begin() override;
  Point Next() override;

 private:
  double x_;
  double y_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_GRAPH_GRAPH_POINT_H_
