// Implementation buttons methods class WidgetVar

// Copyright (C) 2023-2023 School 21 License

#include "widgetvar.h"

namespace s21 {

void WidgetVar::PushButtonDeletePressed() {
  SetIcon(ui->pushButton_delete, kImageNameDeletePressed);
}

void WidgetVar::PushButtonDeleteReleased() {
  SetIcon(ui->pushButton_delete, kImageNameDelete);
}

void WidgetVar::PushButtonDeleteClicked() { emit WidgetDelete(this); }

// ------------------------------------------------------------------------- //

void WidgetVar::PushButtonTypePressed() { return; }

void WidgetVar::PushButtonTypeReleased() { return; }

void WidgetVar::PushButtonTypeClicked() { return; }

// ------------------------------------------------------------------------- //

void WidgetVar::PushButtonNameClicked() { emit NameClicked(this); }

}  // namespace s21
