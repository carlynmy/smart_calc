// Implementation class Graph

// Copyright (C) 2023-2023 School 21 License

#include "graph.h"

#include <cstddef>

namespace s21 {

Graph::Graph() {}

Graph::~Graph() {}

//  -----------------------------------------------------------------------  //

Graph::Type Graph::GetType() const { return type_; }

double Graph::GetXMax() const { return x_max_; }

double Graph::GetXMin() const { return x_min_; }

double Graph::GetYMax() const { return y_max_; }

double Graph::GetYMin() const { return y_min_; }

size_t Graph::GetXSize() const { return x_size_; }

size_t Graph::GetYSize() const { return y_size_; }

//  -----------------------------------------------------------------------  //

void Graph::SetXMax(double x_max) {
  x_max_ = x_max;
  is_end_ = true;
}

void Graph::SetXMin(double x_min) {
  x_min_ = x_min;
  is_end_ = true;
}

void Graph::SetYMax(double y_max) {
  y_max_ = y_max;
  is_end_ = true;
}

void Graph::SetYMin(double y_min) {
  y_min_ = y_min;
  is_end_ = true;
}

void Graph::SetXSize(size_t x_size) {
  x_size_ = x_size;
  is_end_ = true;
}

void Graph::SetYSize(size_t y_size) {
  y_size_ = y_size;
  is_end_ = true;
}

//  -----------------------------------------------------------------------  //

bool Graph::IsEnd() const { return is_end_; }

//  -----------------------------------------------------------------------  //

void Graph::SetType(Type type) { type_ = type; }

void Graph::SetIsEnd(bool is_end) { is_end_ = is_end; }

//  -----------------------------------------------------------------------  //

int Graph::XRealToCoord(double x_real) {
  return (x_real - x_min_) * (x_size_ - 1) / (x_max_ - x_min_);
}

int Graph::YRealToCoord(double y_real) {
  return (-y_real - y_min_) * (y_size_ - 1) / (y_max_ - y_min_);
}

Point Graph::RealToCoord(double x_real, double y_real) {
  return Point{XRealToCoord(x_real), YRealToCoord(y_real)};
}

}  // namespace s21
