// Implementation class ListGraph

// Copyright (C) 2023-2023 School 21 License

#include "list_graph.h"

#include <cstddef>
#include <list>

#include "../graph/graph.h"

namespace s21 {

ListGraph::ListGraph() {}

ListGraph::~ListGraph() { Clear(); }

// ----------------------------------------------------------------------- //

size_t ListGraph::Size() const { return list_.size(); }

void ListGraph::Add(Graph* graph) { list_.push_back(graph); }

void ListGraph::Clear() {
  iterator i = Begin();
  for (; i != End(); ++i) {
    switch ((*i)->GetType()) {
      case Graph::kTypeConst:
        delete reinterpret_cast<GraphConst*>(*i);
        break;
      case Graph::kTypeConstY:
        delete reinterpret_cast<GraphConstY*>(*i);
        break;
      case Graph::kTypeFunc1:
        delete reinterpret_cast<GraphFunc1X*>(*i);
        break;
      case Graph::kTypeFunc1Y:
        delete reinterpret_cast<GraphFunc1Y*>(*i);
        break;
      case Graph::kTypePoint:
        delete reinterpret_cast<GraphPoint*>(*i);
        break;

      default:
        break;
    }
  }

  list_.clear();
}

void ListGraph::SetXMax(double x_max) {
  SetFieldDouble(x_max, &Graph::SetXMax);
}

void ListGraph::SetXMin(double x_min) {
  SetFieldDouble(x_min, &Graph::SetXMin);
}

void ListGraph::SetYMax(double y_max) {
  SetFieldDouble(y_max, &Graph::SetYMax);
}

void ListGraph::SetYMin(double y_min) {
  SetFieldDouble(y_min, &Graph::SetYMin);
}

void ListGraph::SetXSize(size_t x_size) {
  SetFieldSizeT(x_size, &Graph::SetXSize);
}

void ListGraph::SetYSize(size_t y_size) {
  SetFieldSizeT(y_size, &Graph::SetYSize);
}

void ListGraph::SetFieldDouble(double value, GraphFuncDouble setter) {
  iterator i = Begin();
  for (; i != End(); ++i) ((*i)->*setter)(value);
}

void ListGraph::SetFieldSizeT(size_t value, GraphFuncSizeT setter) {
  iterator i = Begin();
  for (; i != End(); ++i) ((*i)->*setter)(value);
}

// ----------------------------------------------------------------------- //

ListGraph::iterator ListGraph::Begin() { return list_.begin(); }

ListGraph::iterator ListGraph::End() { return list_.end(); }

ListGraph::const_iterator ListGraph::Begin() const { return list_.begin(); }

ListGraph::const_iterator ListGraph::End() const { return list_.end(); }

}  // namespace s21
