// Declaration class WidgetListWidget

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_VIEW_WIDGETLISTWIDGET_WIDGETLISTWIDGET_H_
#define SMART_CALC_V_2_VIEW_WIDGETLISTWIDGET_WIDGETLISTWIDGET_H_

#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QPoint>
#include <QWidget>
#include <cstddef>
#include <list>
#include <utility>

#include "widgetlistwidgetdelimline.h"
#include "widgetlistwidgetitem.h"
#include "widgetlistwidgetiterator.h"

namespace s21 {

/// @brief Widget list widgets with drag and drop. To use set new widget to
/// QScrollArea
class WidgetListWidget : public QWidget {
  Q_OBJECT

 public:
  using iterator = WidgetListWidgetIterator;
  using const_iterator = WidgetListWidgetConstIterator;

  explicit WidgetListWidget(int w, QWidget* parent = nullptr);
  ~WidgetListWidget();

  // ----------------------------------------------------------------------- //
  //                               Element access                            //
  // ----------------------------------------------------------------------- //

  /// @brief Access to first item
  QWidget* Front();

  /// @brief Access to first item
  const QWidget* Front() const;

  /// @brief Access to last item
  QWidget* Back();

  /// @brief Access to last item
  const QWidget* Back() const;

  // ----------------------------------------------------------------------- //
  //                                 Iterator                                //
  // ----------------------------------------------------------------------- //

  iterator Begin();
  const_iterator Begin() const;

  iterator End();
  const_iterator End() const;

  // ----------------------------------------------------------------------- //
  //                             List methods                                //
  // ----------------------------------------------------------------------- //

  /// @brief Add widget.
  /// @warning Ownership to memory widget are transfered to WidgetListWidget
  void AddWidget(QWidget* widget);

  /// @brief Remove widget
  /// @warning Memory to widget will be freed. If widget dont contain in list -
  /// undefined behavior
  void RemoveWidget(const QWidget* widget);

  /// @brief Get count elements in list
  size_t Count() const;

  /// @brief Check if item contains in list
  bool IsContains(const QWidget* item) const;

  /// @brief Insert widget before other widget
  /// @warning Both widgets need be contain in this list, if not - undefined
  /// behavior
  void InsertBefore(QWidget* widget, QWidget* before_this);

  // ----------------------------------------------------------------------- //
  //                          Drag And Drop methods                          //
  // ----------------------------------------------------------------------- //

 private slots:
  void DropEventEnd(WidgetListWidgetItem* this_widget);
  void ExcpectDrag(bool answer);

 signals:
  /// @brief Emited when widget inserted before before_this, if insertion invoke
  /// by drag and drop
  void WidgetInsertedBefore(QWidget* widget, QWidget* before_this);

 private:
  using ListItem = std::pair<WidgetListWidgetItem*, WidgetListWidgetDelimLine*>;
  using List = std::list<ListItem>;

  const static size_t kDelimLineSize = 5;

  void dragEnterEvent(QDragEnterEvent* event) override;
  void dragMoveEvent(QDragMoveEvent* event) override;

  // ----------------------------------------------------------------------- //

  ListItem FindCloserLine(QPoint point);

  // ----------------------------------------------------------------------- //

  WidgetListWidgetItem* CreateWidgetListWidgetItem(int w, int h,
                                                   QWidget* widget);
  static void AddSpRetain(QWidget* widget);

  List item_list_;
  ListItem item_selected_ = {nullptr, nullptr};
  size_t item_count_ = 0;
  bool excpect_drag_ = false;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_VIEW_WIDGETLISTWIDGET_WIDGETLISTWIDGET_H_
