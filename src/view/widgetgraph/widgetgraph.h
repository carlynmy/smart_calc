// Declaration class WidgetGraph

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_VIEW_WIDGETGRAPH_WIDGETGRAPH_
#define SMART_CALC_V_2_VIEW_WIDGETGRAPH_WIDGETGRAPH_

#include <QColor>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPoint>
#include <QResizeEvent>
#include <QString>
#include <QWheelEvent>
#include <QWidget>
#include <cstddef>
#include <string>

#include "../../controller/controller.h"

namespace s21 {

class MainWindow;

class WidgetGraph : public QWidget {
  Q_OBJECT
 public:
  struct Point {
    double x;
    double y;
  };

  enum FieldIndexes {
    kFieldXMax,
    kFieldXMin,
    kFieldYMax,
    kFieldYMin,
    kFieldXStep,
    kFieldYStep,
    kFieldWidth,
    kFieldHeight
  };

  // ------------------------------------------------------------------------ //

  explicit WidgetGraph(QWidget* parent = nullptr,
                       MainWindow* mainwindow = nullptr);
  ~WidgetGraph();

  // ------------------------------------------------------------------------ //

  double GetXMin() const;
  double GetXMax() const;
  double GetYMin() const;
  double GetYMax() const;

  /// @return if set via SetXStep method return is, otherwise default step used
  double GetXStep() const;

  /// @return if set via SetYStep method return is, otherwise default step used
  double GetYStep() const;

  // ------------------------------------------------------------------------ //

  void SetMainWindow(MainWindow* mainwindow);

  /// @brief Set range for x
  /// @param update_y if true - select the appropriate value for y range
  void SetXRange(double x_min, double x_max, bool update_y = true);

  /// @brief Set range for y
  /// @param update_x if true - select the appropriate value for x range
  void SetYRange(double y_min, double y_max, bool update_x = true);

  void SetXMin(double x_min);
  void SetXMax(double x_max);
  void SetYMin(double y_min);
  void SetYMax(double y_max);

  /// @brief Set x step
  /// @param x_step if 0 - use default step
  void SetXStep(double x_step);

  /// @brief Set y step
  /// @param y_step if 0 - use default step
  void SetYStep(double y_step);

  /// @param answer if true - axis x will be draw
  void DrawAxisX(bool answer);

  /// @param answer if true - axis y will be draw
  void DrawAxisY(bool answer);

  /// @param answer if true - grid will be draw
  void DrawGrid(bool answer);

  /// @param answer if true - small grid will be draw
  /// @warning if draw grid is false - has no effect
  void DrawSmallGrid(bool answer);

  /// @param answer if true - nums on axis will be draw
  /// @warning if draw axis x and axis y is false - has no effect
  void DrawNumsOnAxis(bool answer);

 signals:
  /// @brief Emited when field is changed not by Setters
  void FieldChanged(FieldIndexes field);

 private:
  const static inline size_t kMaxPixelStepCount = 100;
  const static inline QColor kColorArea = QColor(255, 255, 255);
  const static inline QColor kColorBorder = QColor(150, 150, 150);
  const static inline QColor kColorAxis = QColor(0, 0, 0);
  const static inline QColor kColorGrid = QColor(160, 160, 160);
  const static inline QColor kColorSmallGrid = QColor(220, 220, 220);
  const static inline QColor kColorNums = QColor(0, 0, 0);

  const static inline double kGraphMinStep = 1e-6;
  const static inline double kGraphMinDiff = 5e-6;

  void paintEvent(QPaintEvent* event = nullptr) override;
  void resizeEvent(QResizeEvent* event) override;
  void mousePressEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void wheelEvent(QWheelEvent* event) override;

  // ------------------------------------------------------------------------ //

  void PaintFillArea(QPainter* painter);
  void PaintBorder(QPainter* painter);
  void PaintAxisX(QPainter* painter);
  void PaintAxisY(QPainter* painter);
  void PaintBoard(QPainter* painter);
  void DrawGridXLine(QPainter* painter, double x_now);
  void DrawSmallGridXLine(QPainter* painter, double x_now, double x_small_step);
  void DrawNumsOnAxisX(QPainter* painter, double x_now);
  void DrawGridYLine(QPainter* painter, double y_now);
  void DrawSmallGridYLine(QPainter* painter, double y_now, double y_small_step);
  void DrawNumsOnAxisY(QPainter* painter, double y_now);
  void DrawZeroNum(QPainter* painter);
  void PaintGraphs(QPainter* painter);
  void PaintGraph(QPainter* painter, const QColor& color);

  // ------------------------------------------------------------------------ //

  int XRealToCoord(double x_real);
  int YRealToCoord(double y_real);
  double XCoordToReal(int x_coord);
  double YCoordToReal(int y_coord);
  QPoint RealToCoord(Point point);
  Point CoordToReal(QPoint qpoint);

  // ------------------------------------------------------------------------ //

  void ReCalcSteps();
  void CalcXStep();
  void CalcYStep();
  void CalcMaxStepCount();

  double UsedXStep() const;
  double UsedYStep() const;

  bool IsValidData() const;

  // ------------------------------------------------------------------------ //

  std::string FloatToString(double value);
  QString FloatToQString(double value);

  MainWindow* mainwindow_ = nullptr;

  bool draw_axis_x_ = true;
  bool draw_axis_y_ = true;
  bool draw_grid_ = true;
  bool draw_small_grid_ = true;
  bool draw_nums_on_axis_ = true;

  double x_min_ = -10;
  double x_max_ = 10;
  double y_min_ = -7.74;
  double y_max_ = 7.74;
  double x_step_ = 0;
  double y_step_ = 0;

  double user_x_step_ = 0;
  double user_y_step_ = 0;

  int max_step_count_;

  QPoint move_last_pos_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_VIEW_WIDGETGRAPH_WIDGETGRAPH_
