// Declaration class ListGraph

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_MODEL_LIST_GRAPH_LIST_GRAPH_H_
#define SMART_CALC_V_2_MODEL_LIST_GRAPH_LIST_GRAPH_H_

#include <cstddef>
#include <list>

#include "../graph/graph.h"

namespace s21 {

/// @brief List graph contain pointers to Graph. Ownership to
/// memory graph are transfered to ListGraph
class ListGraph {
  using List = std::list<Graph*>;

 public:
  using iterator = typename List::iterator;
  using const_iterator = typename List::const_iterator;

  ListGraph();
  ListGraph(const ListGraph& other) = delete;
  ListGraph(ListGraph&& other) noexcept = delete;
  ListGraph& operator=(const ListGraph& other) = delete;
  ListGraph& operator=(ListGraph&& other) = delete;
  ~ListGraph();

  // ----------------------------------------------------------------------- //

  size_t Size() const;

  /// @brief Add graph to list
  /// @warning Ownership to memory graph are transfered to ListGraph
  void Add(Graph* graph);

  void Clear();

  void SetXMax(double x_max);
  void SetXMin(double x_min);
  void SetYMax(double y_max);
  void SetYMin(double y_min);
  void SetXSize(size_t x_size);
  void SetYSize(size_t y_size);

  // ----------------------------------------------------------------------- //

  iterator Begin();
  iterator End();
  const_iterator Begin() const;
  const_iterator End() const;

 private:
  using GraphFuncDouble = void (Graph::*)(double);
  using GraphFuncSizeT = void (Graph::*)(size_t);

  void SetFieldDouble(double value, GraphFuncDouble setter);
  void SetFieldSizeT(size_t value, GraphFuncSizeT setter);

  List list_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_MODEL_LIST_GRAPH_LIST_GRAPH_H_
