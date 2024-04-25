// Implementation class WidgetFunc

// Copyright (C) 2023-2023 School 21 License

#include "widgetfunc.h"

#include <QColor>
#include <QEvent>
#include <QIcon>
#include <QMouseEvent>
#include <QObject>
#include <QPixmap>
#include <QPushButton>
#include <QString>
#include <QWidget>
#include <string>

#include "ui_widgetfunc.h"

namespace s21 {

WidgetFunc::WidgetFunc(QWidget* parent, QString value, bool is_term,
                       WidgetVar* pair_widget)
    : QWidget(parent), ui(new ::Ui::WidgetFunc) {
  ui->setupUi(this);
  is_term_ = is_term;
  is_hide_ = false;
  SetupWidgetFunc();

  SetText(value);
  SetType(kTypeNull);
  SetPairWidget(pair_widget);
}

WidgetFunc::~WidgetFunc() { delete ui; }

// ------------------------------------------------------------------------- //

WidgetVar* WidgetFunc::GetPairWidget() const { return pair_widget_; }

WidgetFunc::Type WidgetFunc::GetType() const { return type_; }

QString WidgetFunc::GetText() const { return ui->lineEdit_value->text(); }

bool WidgetFunc::IsTerm() const { return is_term_; }

bool WidgetFunc::IsHide() const { return is_hide_; }

bool WidgetFunc::IsDrawn() const { return IsDrawn(type_); }

QColor WidgetFunc::GetColor() const { return color_; }

// ------------------------------------------------------------------------- //

void WidgetFunc::SetPairWidget(WidgetVar* widget) { pair_widget_ = widget; }

void WidgetFunc::SetType(Type type) {
  type_ = type;
  SetIcon(ui->pushButton_type, kTypeImages[type].first);

  if (IsDrawn(type))
    SetDrawn();
  else
    SetNotDrawn();
}

void WidgetFunc::SetText(const QString& text) {
  ui->lineEdit_value->setText(text);
}

void WidgetFunc::SetTerm() { DoTerm(); }

void WidgetFunc::SetUnterm() { DoUnterm(); }

// ------------------------------------------------------------------------- //

bool WidgetFunc::eventFilter(QObject* object, QEvent* event) {
  if (event->type() == QEvent::MouseButtonPress && is_term_) {
    TermWidgetClicked();
  }

  if (parent() != nullptr) return parent()->eventFilter(object, event);

  return false;
}

void WidgetFunc::mousePressEvent(QMouseEvent* event) {
  if (is_term_) TermWidgetClicked();
  event->accept();
}

void WidgetFunc::LineEditTextChanged() {
  if (is_term_) TermWidgetClicked();

  emit FormulaUpdate();
}

// ------------------------------------------------------------------------- //
void WidgetFunc::TermWidgetClicked() {
  DoUnterm();
  emit WidgetUnTerm(this);
}

void WidgetFunc::DoUnterm() {
  is_term_ = false;

  ui->pushButton_delete->show();
  ui->pushButton_type->show();
  ui->pushButton_hide->show();
  ui->pushButton_color->show();

  ui->lineEdit_value->setStyleSheet(kStyleLineEdit);
  ui->lineEdit_value->setGeometry(kRectLineEdit);
  ui->lineEdit_value->setText("");
}

void WidgetFunc::DoTerm() {
  is_term_ = true;

  ui->pushButton_delete->hide();
  ui->pushButton_type->hide();
  ui->pushButton_hide->hide();
  ui->pushButton_color->hide();

  ui->lineEdit_value->setStyleSheet(kStyleLineEditTerm);
  ui->lineEdit_value->setGeometry(kRectLineEditTerm);
}

// ------------------------------------------------------------------------- //

bool WidgetFunc::IsDrawn(Type type) {
  return type == kTypeFunc || type == kTypeVar || type == kTypePoint;
}

void WidgetFunc::SetDrawn() {
  SetIcon(ui->pushButton_color, kImageNameWave);
  if (is_hide_)
    SetIcon(ui->pushButton_hide, kImageNameHide);
  else
    SetIcon(ui->pushButton_hide, kImageNameShow);

  if (!color_set_) {
    color_ = GetNextColor();
    color_set_ = true;
  }
  SetBackgroundColor(ui->pushButton_color, color_);
  ui->pushButton_hide->setDisabled(false);
  ui->pushButton_color->setDisabled(false);
}

void WidgetFunc::SetNotDrawn() {
  SetIcon(ui->pushButton_color, "");
  SetIcon(ui->pushButton_hide, "");
  SetBackgroundColor(ui->pushButton_color, kColorEmpty);
  ui->pushButton_hide->setDisabled(true);
  ui->pushButton_color->setDisabled(true);
}

// ------------------------------------------------------------------------- //

void WidgetFunc::SetIcon(QPushButton* button, const QString& path) {
  if (path.isEmpty()) {
    button->setIcon(QIcon());
    return;
  }

  QPixmap pixmap(path);
  QIcon icon(pixmap);
  button->setIcon(icon);
  button->setIconSize(button->size());
}

void WidgetFunc::SetBackgroundColor(QWidget* widget, const QColor& color) {
  std::string str;
  str.reserve(40);
  str.append("background-color: rgb(");
  str.append(std::to_string(color.red()));
  str.append(",");
  str.append(std::to_string(color.green()));
  str.append(",");
  str.append(std::to_string(color.blue()));
  str.append(");");

  widget->setStyleSheet(str.c_str());
}

const QColor& WidgetFunc::GetNextColor() {
  const QColor& color = **iter_colors;
  ++iter_colors;
  if (iter_colors == kColors.end()) iter_colors = kColors.begin();
  return color;
}

}  // namespace s21
