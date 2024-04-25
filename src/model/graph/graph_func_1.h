// Declaration class GraphFunc1X

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_GRAPH_GRAPH_FUNC_1_H_
#define SMART_CALC_V_2_MODEL_GRAPH_GRAPH_FUNC_1_H_

#include <cstddef>

#include "../user_function/user_function.h"
#include "graph.h"

namespace s21 {

class GraphFunc1X : public Graph {
 public:
  GraphFunc1X(const UserFunction& function);
  ~GraphFunc1X();

  //  ---------------------------------------------------------------------  //

  void Begin() override;
  Point Next() override;

 private:
  enum PointPos { kPosNull, kPosIn, kPosOutUp, kPosOutDown };

  void CalcNext();

  UserFunction function_;

  double x_delta_;
  double y_delta_;

  double x_prev_;
  double y_prev_;
  int x_coord_prev_ = -1;
  int y_coord_prev_;
  PointPos pos_prev_ = kPosNull;

  int x_connect_;
  int y_connect_;

  double x_next_;
  double y_next_;
  int x_coord_next_;
  int y_coord_next_;
  PointPos pos_next_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_GRAPH_GRAPH_FUNC_1_H_
