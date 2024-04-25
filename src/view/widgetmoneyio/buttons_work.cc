// Implementation buttons methods class WidgetMoneyIO

// Copyright (C) 2023-2023 School 21 License

#include "widgetmoneyio.h"

namespace s21 {

void WidgetMoneyIO::PushButtonDeletePressed() {
  SetIcon(ui->pushButton_delete, kImageNameDeletePressed);
}

void WidgetMoneyIO::PushButtonDeleteReleased() {
  SetIcon(ui->pushButton_delete, kImageNameDelete);
}

void WidgetMoneyIO::PushButtonDeleteClicked() { emit WidgetDelete(this); }

}  // namespace s21
