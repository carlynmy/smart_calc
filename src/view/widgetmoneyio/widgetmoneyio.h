// Declaration class WidgetMoneyIO

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_VIEW_WIDGETMONEYIO_WIDGETMONEYIO_H_
#define SMART_CALC_V_2_VIEW_WIDGETMONEYIO_WIDGETMONEYIO_H_

#include <QDate>
#include <QEvent>
#include <QMouseEvent>
#include <QObject>
#include <QPushButton>
#include <QRect>
#include <QString>
#include <QWidget>

#include "tmp/headers/ui_widgetmoneyio.h"

namespace s21 {

namespace Ui {
class WidgetMoneyIO;
}

/// @brief Class representation money input-output.
class WidgetMoneyIO : public QWidget {
  Q_OBJECT

 public:
  explicit WidgetMoneyIO(QWidget *parent = nullptr, QDate date = QDate(0, 0, 0),
                         QString value = "", bool is_term = false);
  ~WidgetMoneyIO();

  // ----------------------------------------------------------------------- //

  QString GetText() const;
  QDate GetDate() const;
  bool IsTerm() const;

 signals:
  /// @brief Emited when widget unterm request
  void WidgetUnTerm();

  /// @brief Emited when widget delete request
  void WidgetDelete(WidgetMoneyIO *this_widget);

 private slots:
  void PushButtonDeletePressed();
  void PushButtonDeleteReleased();
  void PushButtonDeleteClicked();
  void LineEditEditing();

 private:
  const static inline QString kImageNameDelete = ":/cross";
  const static inline QString kImageNameDeletePressed = ":/cross_pressed";

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

  const static inline QRect kRectLineEdit = QRect(100, 0, 101, 37);
  const static inline QRect kRectLineEditTerm = QRect(0, 0, 261, 37);

  void SetupWidgetMoneyIO();
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

  ::Ui::WidgetMoneyIO *ui;

  bool is_term_ = false;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_VIEW_WIDGETMONEYIO_WIDGETMONEYIO_H_
