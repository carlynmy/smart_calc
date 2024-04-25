// Implementation class WidgetVar

// Copyright (C) 2023-2023 School 21 License

#include "widgetvar.h"

#include <QEvent>
#include <QIcon>
#include <QLineEdit>
#include <QMouseEvent>
#include <QObject>
#include <QPixmap>
#include <QPushButton>
#include <QString>
#include <QWidget>

#include "ui_widgetvar.h"

namespace s21 {

class WidgetFunc;

WidgetVar::WidgetVar(QWidget* parent, QString value, bool is_term,
                     WidgetFunc* pair_widget)
    : QWidget(parent), ui(new ::Ui::WidgetVar) {
  ui->setupUi(this);
  is_term_ = is_term;
  SetupWidgetVar();

  SetText(value);
  SetType(kTypeNull);
  SetName("");
  SetPairWidget(pair_widget);
}

WidgetVar::~WidgetVar() { delete ui; }

// ------------------------------------------------------------------------- //

WidgetFunc* WidgetVar::GetPairWidget() const { return pair_widget_; }

WidgetVar::Type WidgetVar::GetType() const { return type_; }

QString WidgetVar::GetText() const { return ui->lineEdit_value->text(); }

bool WidgetVar::IsTerm() const { return is_term_; }

const QLineEdit* WidgetVar::GetLineEdit() const { return ui->lineEdit_value; }

const QString& WidgetVar::GetName() const { return name_; }

// ------------------------------------------------------------------------- //

void WidgetVar::SetPairWidget(WidgetFunc* widget) { pair_widget_ = widget; }

void WidgetVar::SetType(Type type) {
  type_ = type;
  SetIcon(ui->pushButton_type, kTypeImages[type].first);
}

void WidgetVar::SetText(const QString& text) {
  ui->lineEdit_value->setText(text);
}

void WidgetVar::SetTerm() { DoTerm(); }

void WidgetVar::SetUnterm() { DoUnterm(); }

void WidgetVar::SetName(const QString& name) {
  ui->pushButton_var->setText(name);
  name_ = name;

  if (name_.isEmpty()) {
    ui->pushButton_var->setEnabled(false);
  } else {
    ui->pushButton_var->setEnabled(true);
  }
}

// ------------------------------------------------------------------------- //

bool WidgetVar::eventFilter(QObject* object, QEvent* event) {
  if (event->type() == QEvent::MouseButtonPress && is_term_)
    TermWidgetClicked();

  if (object == ui->lineEdit_value && event->type() == QEvent::FocusIn)
    emit LineEditSelect(ui->lineEdit_value);

  if (parent() != nullptr) return parent()->eventFilter(object, event);

  return false;
}

void WidgetVar::LineEditTextChanged() {
  if (is_term_) TermWidgetClicked();
  emit FormulaUpdate();
}

void WidgetVar::mousePressEvent(QMouseEvent* event) {
  if (is_term_) TermWidgetClicked();
  event->accept();
}

// ------------------------------------------------------------------------- //

void WidgetVar::TermWidgetClicked() {
  DoUnterm();
  emit WidgetUnTerm(this);
}

void WidgetVar::DoUnterm() {
  is_term_ = false;

  ui->pushButton_delete->show();
  ui->pushButton_type->show();
  ui->pushButton_var->show();

  ui->lineEdit_value->setStyleSheet(kStyleLineEdit);
  ui->lineEdit_value->setGeometry(kRectLineEdit);
  ui->lineEdit_value->setText("");
}

void WidgetVar::DoTerm() {
  is_term_ = true;

  ui->pushButton_delete->hide();
  ui->pushButton_type->hide();
  ui->pushButton_var->hide();

  ui->lineEdit_value->setStyleSheet(kStyleLineEditTerm);
  ui->lineEdit_value->setGeometry(kRectLineEditTerm);
}

// ------------------------------------------------------------------------- //

void WidgetVar::SetIcon(QPushButton* button, const QString& path) {
  if (path.isEmpty()) {
    button->setIcon(QIcon());
    return;
  }

  QPixmap pixmap(path);
  QIcon icon(pixmap);
  button->setIcon(icon);
  button->setIconSize(button->size());
}

}  // namespace s21
