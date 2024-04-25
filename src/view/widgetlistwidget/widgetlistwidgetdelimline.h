// Declaration class WidgetListWidgetDelimLine

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_VIEW_WIDGETLISTWIDGET_WIDGETLISTWIDGETDELIMLINE_H_
#define SMART_CALC_V_2_VIEW_WIDGETLISTWIDGET_WIDGETLISTWIDGETDELIMLINE_H_

#include <QPaintEvent>
#include <QWidget>

namespace s21 {

class WidgetListWidgetDelimLine : public QWidget {
 public:
  explicit WidgetListWidgetDelimLine(int w = 0, int h = 0,
                                     QWidget *parent = nullptr);
  ~WidgetListWidgetDelimLine();

  void paintEvent(QPaintEvent *event = nullptr) override;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_VIEW_WIDGETLISTWIDGET_WIDGETLISTWIDGETDELIMLINE_H_
