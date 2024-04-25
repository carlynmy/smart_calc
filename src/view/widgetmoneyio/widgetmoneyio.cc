// Implementation class WidgetMoneyIO

// Copyright (C) 2023-2023 School 21 License

#include "widgetmoneyio.h"

#include <QDate>
#include <QEvent>
#include <QIcon>
#include <QMouseEvent>
#include <QObject>
#include <QPixmap>
#include <QPushButton>
#include <QString>
#include <QWidget>

#include "ui_widgetmoneyio.h"

namespace s21 {

WidgetMoneyIO::WidgetMoneyIO(QWidget* parent, QDate date, QString value,
                             bool is_term)
    : QWidget(parent), ui(new ::Ui::WidgetMoneyIO) {
  ui->setupUi(this);
  is_term_ = is_term;
  SetupWidgetMoneyIO();
  ui->dateEdit->setDate(date);
  ui->lineEdit_value->setText(value);
}

WidgetMoneyIO::~WidgetMoneyIO() { delete ui; }

// ------------------------------------------------------------------------- //

QString WidgetMoneyIO::GetText() const { return ui->lineEdit_value->text(); }

QDate WidgetMoneyIO::GetDate() const { return ui->dateEdit->date(); }

bool WidgetMoneyIO::IsTerm() const { return is_term_; }

// ------------------------------------------------------------------------- //

bool WidgetMoneyIO::eventFilter(QObject* object, QEvent* event) {
  if (event->type() == QEvent::MouseButtonPress && is_term_) {
    TermWidgetClicked();
  }

  if (parent() != nullptr) return parent()->eventFilter(object, event);

  return false;
}

void WidgetMoneyIO::mousePressEvent(QMouseEvent* event) {
  if (is_term_) TermWidgetClicked();
  event->accept();
}

void WidgetMoneyIO::LineEditEditing() {
  if (is_term_) TermWidgetClicked();
}

// ------------------------------------------------------------------------- //

void WidgetMoneyIO::TermWidgetClicked() {
  DoUnterm();
  emit WidgetUnTerm();
}

void WidgetMoneyIO::DoUnterm() {
  is_term_ = false;

  ui->pushButton_delete->show();
  ui->label_unit->show();
  ui->dateEdit->show();

  ui->lineEdit_value->setStyleSheet(kStyleLineEdit);
  ui->lineEdit_value->setGeometry(kRectLineEdit);
  ui->lineEdit_value->setText("");
}

void WidgetMoneyIO::DoTerm() {
  is_term_ = true;

  ui->pushButton_delete->hide();
  ui->label_unit->hide();
  ui->dateEdit->hide();

  ui->lineEdit_value->setStyleSheet(kStyleLineEditTerm);
  ui->lineEdit_value->setGeometry(kRectLineEditTerm);
}

// ------------------------------------------------------------------------- //

void WidgetMoneyIO::SetIcon(QPushButton* button, const QString& path) {
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
