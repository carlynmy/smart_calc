// Declaration class WidgetVar

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_VIEW_WIDGETVAR_WIDGETVAR_H_
#define SMART_CALC_V_2_VIEW_WIDGETVAR_WIDGETVAR_H_

#include <QEvent>
#include <QLineEdit>
#include <QMouseEvent>
#include <QObject>
#include <QPushButton>
#include <QRect>
#include <QString>
#include <QWidget>
#include <utility>

#include "tmp/headers/ui_widgetvar.h"

namespace s21 {

namespace Ui {
class WidgetVar;
}

class WidgetFunc;

/// @brief Class representation var, func, equation, point, etc in calculator
/// mode. Contain pointer to pair WidgetFunc, wich representain same object in
/// plot mode.
class WidgetVar : public QWidget {
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

  explicit WidgetVar(QWidget *parent = nullptr, QString value = "",
                     bool is_term = false, WidgetFunc *pair_widget = nullptr);
  ~WidgetVar();

  // ----------------------------------------------------------------------- //

  /// @warning may return nullptr if not have pair widget
  WidgetFunc *GetPairWidget() const;

  Type GetType() const;
  QString GetText() const;
  bool IsTerm() const;

  const QString &GetName() const;
  const QLineEdit *GetLineEdit() const;

  // ----------------------------------------------------------------------- //

  void SetPairWidget(WidgetFunc *widget);
  void SetType(Type type);
  void SetText(const QString &text);
  void SetTerm();
  void SetUnterm();

  void SetName(const QString &name);

 signals:
  /// @brief Emited when unterm requested
  void WidgetUnTerm(WidgetVar *this_widget);

  /// @brief Emited when delete requested
  void WidgetDelete(WidgetVar *this_widget);

  /// @brief Emited when text formula edited by user
  void FormulaUpdate();

  /// @brief Emited when button with name clicked
  void NameClicked(WidgetVar *this_widget);

  /// @brief Emited when QlineEdit with formula clicked
  void LineEditSelect(QLineEdit *line);

 private slots:
  void PushButtonDeletePressed();
  void PushButtonDeleteReleased();
  void PushButtonDeleteClicked();
  void PushButtonTypePressed();
  void PushButtonTypeReleased();
  void PushButtonTypeClicked();
  void PushButtonNameClicked();
  void LineEditTextChanged();

 private:
  const static inline QString kImageNameDelete = ":/cross";
  const static inline QString kImageNameDeletePressed = ":/cross_pressed";

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
      kTypeImages[] = {{kImageNameTypeErr, kImageNameTypeErr},
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

  void SetupWidgetVar();
  void Connects();

  // ----------------------------------------------------------------------- //

  bool eventFilter(QObject *object, QEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;

  // ----------------------------------------------------------------------- //

  void TermWidgetClicked();
  void DoUnterm();
  void DoTerm();

  // ----------------------------------------------------------------------- //

  static void SetIcon(QPushButton *button, const QString &path);

  ::Ui::WidgetVar *ui;
  bool is_term_;
  Type type_;
  QString name_;
  WidgetFunc *pair_widget_;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_VIEW_WIDGETVAR_WIDGETVAR_H_
