// Declaration class WidgetListWidgetItem

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_VIEW_WIDGETLISTWIDGET_WIDGETLISTWIDGETITEM_H_
#define SMART_CALC_V_2_VIEW_WIDGETLISTWIDGET_WIDGETLISTWIDGETITEM_H_

#include <QDrag>
#include <QEvent>
#include <QMouseEvent>
#include <QObject>
#include <QTimer>
#include <QWidget>

namespace s21 {

/// @brief Item for WidgetListWidget
class WidgetListWidgetItem : public QWidget {
  Q_OBJECT

 public:
  /// @brief Ownership to memory item are transfered to
  /// WidgetListWidgetItem
  explicit WidgetListWidgetItem(int w, int h, QWidget *item,
                                QWidget *parent = nullptr);
  ~WidgetListWidgetItem();

  // ----------------------------------------------------------------------- //

  QWidget *GetItem();
  const QWidget *GetItem() const;

  void SetItem(QWidget *widget);

 private slots:
  void DoDrag();

 signals:
  void DropEventEnd(WidgetListWidgetItem *this_widget);
  void ExcpectDrag(bool answer);
  void StartTimer(int msec);
  void EndTimer();

 private:
  static const int kDragTime = 300;

  bool eventFilter(QObject *object, QEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;

  // ----------------------------------------------------------------------- //

  void DestroyDrag();

  QDrag *drag_ = nullptr;
  QWidget *item_;
  QTimer *timer_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_VIEW_WIDGETLISTWIDGET_WIDGETLISTWIDGETITEM_H_
