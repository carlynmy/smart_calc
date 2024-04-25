// Implementation setup methods class WidgetMoneyIO

// Copyright (C) 2023-2023 School 21 License

#include <QLineEdit>
#include <QPushButton>

#include "widgetmoneyio.h"

namespace s21 {

void WidgetMoneyIO::SetupWidgetMoneyIO() {
  SetIcon(ui->pushButton_delete, kImageNameDelete);

  ui->lineEdit_value->installEventFilter(this);
  ui->dateEdit->installEventFilter(this);
  ui->pushButton_delete->installEventFilter(this);

  if (is_term_) DoTerm();

  Connects();
}

void WidgetMoneyIO::Connects() {
  connect(ui->lineEdit_value, &QLineEdit::textEdited, this,
          &WidgetMoneyIO::LineEditEditing);

  connect(ui->pushButton_delete, &QPushButton::pressed, this,
          &WidgetMoneyIO::PushButtonDeletePressed);
  connect(ui->pushButton_delete, &QPushButton::released, this,
          &WidgetMoneyIO::PushButtonDeleteReleased);
  connect(ui->pushButton_delete, &QPushButton::clicked, this,
          &WidgetMoneyIO::PushButtonDeleteClicked);
}

}  // namespace s21
