// Declaration class Graph

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_GRAPH_GRAPH_H_
#define SMART_CALC_V_2_MODEL_GRAPH_GRAPH_H_

#include <cstddef>

namespace s21 {

struct Point {
  int x;
  int y;
};

/// @brief Abstract class graph use to get graph representation function. To use
/// fill data via setters, then invoke method Begin, then invoke method Next
/// while IsEnd returns false.
class Graph {
 public:
  enum Type { kTypeConst, kTypeConstY, kTypeFunc1, kTypeFunc1Y, kTypePoint };

  Graph();
  virtual ~Graph();

  //  ---------------------------------------------------------------------  //
  Type GetType() const;
  double GetXMax() const;
  double GetXMin() const;
  double GetYMax() const;
  double GetYMin() const;
  size_t GetXSize() const;
  size_t GetYSize() const;

  void SetXMax(double x_max);
  void SetXMin(double x_min);
  void SetYMax(double y_max);
  void SetYMin(double y_min);
  void SetXSize(size_t x_size);
  void SetYSize(size_t y_size);

  //  ---------------------------------------------------------------------  //

  /// @brief Check if graph is end
  bool IsEnd() const;

  /// @brief Start
  virtual void Begin() = 0;

  /// @brief Get next point
  /// @warning Undefined behavior if graph is end
  virtual Point Next() = 0;

 protected:
  void SetType(Type type);
  void SetIsEnd(bool is_end);

  int XRealToCoord(double x_real);
  int YRealToCoord(double y_real);
  Point RealToCoord(double x_real, double y_real);

 private:
  double x_max_ = 0;
  double x_min_ = 0;
  double y_max_ = 0;
  double y_min_ = 0;
  size_t x_size_ = 0;
  size_t y_size_ = 0;

  bool is_end_ = true;
  Type type_;
};

}  // namespace s21

#include "graph_const.h"
#include "graph_const_y.h"
#include "graph_func_1.h"
#include "graph_func_1_y.h"
#include "graph_point.h"

#endif  // SMART_CALC_V_2_MODEL_GRAPH_GRAPH_H_
