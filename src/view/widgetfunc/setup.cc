// Implementation setup methods class WidgetFunc

// Copyright (C) 2023-2023 School 21 License

#include <QLineEdit>
#include <QPushButton>

#include "widgetfunc.h"

namespace s21 {

void WidgetFunc::SetupWidgetFunc() {
  ui->pushButton_type->setDisabled(true);
  ui->pushButton_color->setDisabled(true);
  ui->pushButton_hide->setDisabled(true);

  SetIcon(ui->pushButton_delete, kImageNameDelete);
  SetIcon(ui->pushButton_hide, kImageNameShow);

  ui->lineEdit_value->installEventFilter(this);
  ui->pushButton_hide->installEventFilter(this);
  ui->pushButton_color->installEventFilter(this);
  ui->pushButton_delete->installEventFilter(this);
  ui->pushButton_type->installEventFilter(this);

  if (is_term_) DoTerm();

  Connects();
}

void WidgetFunc::Connects() {
  connect(ui->lineEdit_value, &QLineEdit::textEdited, this,
          &WidgetFunc::LineEditTextChanged);

  connect(ui->pushButton_hide, &QPushButton::pressed, this,
          &WidgetFunc::PushButtonHidePressed);
  connect(ui->pushButton_hide, &QPushButton::released, this,
          &WidgetFunc::PushButtonHideReleased);
  connect(ui->pushButton_hide, &QPushButton::clicked, this,
          &WidgetFunc::PushButtonHideClicked);

  connect(ui->pushButton_color, &QPushButton::pressed, this,
          &WidgetFunc::PushButtonColorPressed);
  connect(ui->pushButton_color, &QPushButton::released, this,
          &WidgetFunc::PushButtonColorReleased);
  connect(ui->pushButton_color, &QPushButton::clicked, this,
          &WidgetFunc::PushButtonColorClicked);

  connect(ui->pushButton_type, &QPushButton::pressed, this,
          &WidgetFunc::PushButtonTypePressed);
  connect(ui->pushButton_type, &QPushButton::released, this,
          &WidgetFunc::PushButtonTypeReleased);
  connect(ui->pushButton_type, &QPushButton::clicked, this,
          &WidgetFunc::PushButtonTypeClicked);

  connect(ui->pushButton_delete, &QPushButton::pressed, this,
          &WidgetFunc::PushButtonDeletePressed);
  connect(ui->pushButton_delete, &QPushButton::released, this,
          &WidgetFunc::PushButtonDeleteReleased);
  connect(ui->pushButton_delete, &QPushButton::clicked, this,
          &WidgetFunc::PushButtonDeleteClicked);
}

}  // namespace s21
