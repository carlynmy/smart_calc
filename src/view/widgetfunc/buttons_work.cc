// Implementation buttons methods class WidgetFunc

// Copyright (C) 2023-2023 School 21 License

#include <QColor>
#include <QColorDialog>

#include "widgetfunc.h"

namespace s21 {

void WidgetFunc::PushButtonHidePressed() {
  if (is_hide_) {
    SetIcon(ui->pushButton_hide, kImageNameHidePressed);
  } else {
    SetIcon(ui->pushButton_hide, kImageNameShowPressed);
  }
}

void WidgetFunc::PushButtonHideReleased() {
  if (is_hide_) {
    SetIcon(ui->pushButton_hide, kImageNameHide);
  } else {
    SetIcon(ui->pushButton_hide, kImageNameShow);
  }
}

void WidgetFunc::PushButtonHideClicked() {
  if (is_hide_) {
    SetIcon(ui->pushButton_hide, kImageNameShow);
    is_hide_ = false;
  } else {
    SetIcon(ui->pushButton_hide, kImageNameHide);
    is_hide_ = true;
  }

  emit FormulaUpdate();
}

// ------------------------------------------------------------------------- //

void WidgetFunc::PushButtonDeletePressed() {
  SetIcon(ui->pushButton_delete, kImageNameDeletePressed);
}

void WidgetFunc::PushButtonDeleteReleased() {
  SetIcon(ui->pushButton_delete, kImageNameDelete);
}

void WidgetFunc::PushButtonDeleteClicked() { emit WidgetDelete(this); }

// ------------------------------------------------------------------------- //

void WidgetFunc::PushButtonColorPressed() {
  SetIcon(ui->pushButton_color, kImageNameWavePressed);
}

void WidgetFunc::PushButtonColorReleased() {
  SetIcon(ui->pushButton_color, kImageNameWave);
}

void WidgetFunc::PushButtonColorClicked() {
  QColorDialog color_dialog(this);
  color_dialog.setOptions(QColorDialog::DontUseNativeDialog);

  if (color_dialog.exec()) {
    color_ = color_dialog.selectedColor();
    SetBackgroundColor(ui->pushButton_color, color_);
    emit FormulaUpdate();
  }
}

// ------------------------------------------------------------------------- //

void WidgetFunc::PushButtonTypePressed() { return; }

void WidgetFunc::PushButtonTypeReleased() { return; }

void WidgetFunc::PushButtonTypeClicked() { return; }

}  // namespace s21
