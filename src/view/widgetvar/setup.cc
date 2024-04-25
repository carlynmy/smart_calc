// Implementation setup methods class WidgetVar

// Copyright (C) 2023-2023 School 21 License

#include <QLineEdit>
#include <QPushButton>

#include "widgetvar.h"

namespace s21 {

void WidgetVar::SetupWidgetVar() {
  ui->pushButton_type->setDisabled(true);

  SetIcon(ui->pushButton_delete, kImageNameDelete);

  ui->lineEdit_value->installEventFilter(this);
  ui->pushButton_delete->installEventFilter(this);
  ui->pushButton_type->installEventFilter(this);
  ui->pushButton_var->installEventFilter(this);

  if (is_term_) DoTerm();

  Connects();
}

void WidgetVar::Connects() {
  connect(ui->pushButton_type, &QPushButton::pressed, this,
          &WidgetVar::PushButtonTypePressed);
  connect(ui->pushButton_type, &QPushButton::released, this,
          &WidgetVar::PushButtonTypeReleased);
  connect(ui->pushButton_type, &QPushButton::clicked, this,
          &WidgetVar::PushButtonTypeClicked);

  connect(ui->pushButton_delete, &QPushButton::pressed, this,
          &WidgetVar::PushButtonDeletePressed);
  connect(ui->pushButton_delete, &QPushButton::released, this,
          &WidgetVar::PushButtonDeleteReleased);
  connect(ui->pushButton_delete, &QPushButton::clicked, this,
          &WidgetVar::PushButtonDeleteClicked);

  connect(ui->pushButton_var, &QPushButton::clicked, this,
          &WidgetVar::PushButtonNameClicked);

  connect(ui->lineEdit_value, &QLineEdit::textEdited, this,
          &WidgetVar::LineEditTextChanged);
}

}  // namespace s21
