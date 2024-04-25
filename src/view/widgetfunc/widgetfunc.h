// Declaration class WidgetFunc

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_VIEW_WIDGETFUNC_WIDGETFUNC_H_
#define SMART_CALC_V_2_VIEW_WIDGETFUNC_WIDGETFUNC_H_

#include <QColor>
#include <QEvent>
#include <QMouseEvent>
#include <QObject>
#include <QPushButton>
#include <QRect>
#include <QString>
#include <QWidget>
#include <utility>
#include <vector>

#include "tmp/headers/ui_widgetfunc.h"

namespace s21 {

namespace Ui {
class WidgetFunc;
}

class WidgetVar;

/// @brief Class representation var, func, equation, point, etc in plot
/// mode. Contain pointer to pair WidgetVar, wich representain same object in
/// calculator mode.
class WidgetFunc : public QWidget {
  Q_OBJECT

 public:
  enum Type {
    kTypeNull,
    kTypeErr,
    kTypeVar,
    kTypeFunc,
    kTypeEquation,
    kTypePoint
  };

  explicit WidgetFunc(QWidget *parent = nullptr, QString value = "",
                      bool is_term = false, WidgetVar *pair_widget = nullptr);
  ~WidgetFunc();

  // ----------------------------------------------------------------------- //

  /// @warning may return nullptr if not have pair widget
  WidgetVar *GetPairWidget() const;

  Type GetType() const;
  QString GetText() const;
  bool IsTerm() const;

  bool IsHide() const;
  bool IsDrawn() const;
  QColor GetColor() const;

  void SetPairWidget(WidgetVar *widget);
  void SetType(Type type);
  void SetText(const QString &text);
  void SetTerm();
  void SetUnterm();

 signals:
  /// @brief Emited when unterm requested
  void WidgetUnTerm(WidgetFunc *this_widget);

  /// @brief Emited when delete requested
  void WidgetDelete(WidgetFunc *this_widget);

  /// @brief Emited when text formula edited by user or hide/show state changed
  void FormulaUpdate();

 private slots:
  void PushButtonHidePressed();
  void PushButtonHideReleased();
  void PushButtonHideClicked();
  void PushButtonDeletePressed();
  void PushButtonDeleteReleased();
  void PushButtonDeleteClicked();
  void PushButtonColorPressed();
  void PushButtonColorReleased();
  void PushButtonColorClicked();
  void PushButtonTypePressed();
  void PushButtonTypeReleased();
  void PushButtonTypeClicked();
  void LineEditTextChanged();

 private:
  const static inline QString kImageNameDelete = ":/cross";
  const static inline QString kImageNameDeletePressed = ":/cross_pressed";

  const static inline QString kImageNameWave = ":/wave";
  const static inline QString kImageNameWavePressed = ":/wave_pressed";

  const static inline QString kImageNameShow = ":/hide";
  const static inline QString kImageNameShowPressed = ":/hide_pressed";
  const static inline QString kImageNameHide = ":/show";
  const static inline QString kImageNameHidePressed = ":/show_pressed";

  const static inline QString kImageNameTypeErr = ":/type_err";
  const static inline QString kImageNameTypeErrPressed = ":/type_err_pressed";
  const static inline QString kImageNameTypeVar = ":/type_var";
  const static inline QString kImageNameTypeVarPressed = ":/type_var_pressed";
  const static inline QString kImageNameTypeFunc = ":/type_func";
  const static inline QString kImageNameTypeFuncPressed = ":/type_func_pressed";
  const static inline QString kImageNameTypeEquation = ":/type_equation";
  const static inline QString kImageNameTypeEquationPressed =
      ":/type_equation_pressed";
  const static inline QString kImageNameTypePoint = ":/type_point";
  const static inline QString kImageNameTypePointPressed =
      ":/type_point_pressed";

  const static inline std::pair<const QString &, const QString &>
      kTypeImages[] = {{kImageNameTypeErr, kImageNameTypeErrPressed},
                       {kImageNameTypeErr, kImageNameTypeErrPressed},
                       {kImageNameTypeVar, kImageNameTypeVarPressed},
                       {kImageNameTypeFunc, kImageNameTypeFuncPressed},
                       {kImageNameTypeEquation, kImageNameTypeEquationPressed},
                       {kImageNameTypePoint, kImageNameTypePointPressed}};

  const static inline QString kStyleLineEdit =
      "QLineEdit{"
      "background-color: rgb(52, 53, 56); "
      "border-top: 1px solid rgb(150, 150, 150); "
      "border-left: 0px solid rgb(150, 150, 150); "
      "border-bottom: 1px solid rgb(150, 150, 150); "
      "border-right: 1px solid rgb(150, 150, 150);}";
  const static inline QString kStyleLineEditTerm =
      "QLineEdit{"
      "color: qlineargradient("
      "spread:pad, x1:0 y1:0, x2:0 y2:1,"
      "stop:0 rgba(0, 0, 0, 255), "
      "stop:1 rgba(255, 255, 255, 255));"
      "background: qlineargradient("
      "x1:0 y1:0, x2:0 y2:1, "
      "stop:0 rgb(52, 53, 56), "
      "stop:1 rgb(42, 43, 46));"
      "border-top: 1px solid rgb(150, 150, 150); "
      "border-left: 1px solid qlineargradient("
      "x1:0 y1:0, x2:0 y2:1, "
      "stop:0 rgb(150, 150, 150), "
      "stop:1 rgb(42, 43, 46));"
      "border-bottom: 0px solid rgb(150, 150, 150); "
      "border-right: 1px solid qlineargradient("
      "x1:0 y1:0, x2:0 y2:1, "
      "stop:0 rgb(150, 150, 150), "
      "stop:1 rgb(42, 43, 46));}";

  const static inline QRect kRectLineEdit = QRect(61, 0, 211, 37);
  const static inline QRect kRectLineEditTerm = QRect(30, 0, 242, 37);

  const static inline QColor kColorEmpty = QColor(95, 99, 104);
  const static inline std::vector<const QColor *> kColors{
      &QColorConstants::Red,       &QColorConstants::Green,
      &QColorConstants::Blue,      &QColorConstants::Cyan,
      &QColorConstants::Magenta,   &QColorConstants::Yellow,
      &QColorConstants::DarkRed,   &QColorConstants::DarkGreen,
      &QColorConstants::DarkBlue,  &QColorConstants::DarkMagenta,
      &QColorConstants::DarkYellow};

  void SetupWidgetFunc();
  void Connects();

  // ----------------------------------------------------------------------- //

  bool eventFilter(QObject *object, QEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;

  // ----------------------------------------------------------------------- //

  void TermWidgetClicked();
  void DoUnterm();
  void DoTerm();

  // ----------------------------------------------------------------------- //

  static bool IsDrawn(Type type);
  void SetDrawn();
  void SetNotDrawn();

  // ----------------------------------------------------------------------- //

  static void SetIcon(QPushButton *button, const QString &path);
  static void SetBackgroundColor(QWidget *widget, const QColor &color);
  static const QColor &GetNextColor();

  static inline std::vector<const QColor *>::const_iterator iter_colors =
      kColors.begin();

  ::Ui::WidgetFunc *ui;

  bool is_term_;
  Type type_;
  bool is_hide_;
  QColor color_;
  bool color_set_ = false;
  WidgetVar *pair_widget_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_VIEW_WIDGETFUNC_WIDGETFUNC_H_
