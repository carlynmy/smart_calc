// Implemetation calculator buttons methods class MainWindow

// Copyright (C) 2023-2023 School 21 License

#include <QPushButton>
#include <QString>
#include <string>

#include "../widgetvar/widgetvar.h"
#include "mainwindow.h"

namespace s21 {

void MainWindow::CalcButtonClearClicked() {
  QString text = line_edit_selected_->text();
  std::string std_str = text.toStdString();
  std_str.pop_back();
  text = QString(std_str.c_str());
  line_edit_selected_->setText(text);
  if (line_edit_selected_ != ui->lineEdit_calc) WidgetListCalcUpdateFormulas();
}

void MainWindow::CalcButtonClearAllClicked() {
  line_edit_selected_->clear();
  if (line_edit_selected_ != ui->lineEdit_calc) WidgetListCalcUpdateFormulas();
}

void MainWindow::CalcButtonEqClicked() {
  if (line_edit_selected_ == ui->lineEdit_calc)
    CalcCalcClicked();
  else
    AddText(" = ");
}

void MainWindow::CalcButtonClicked() {
  QString text;
  QPushButton* button = reinterpret_cast<QPushButton*>(sender());

  if (button == ui->pushButton_sqr) {
    text = "^2";
  } else {
    text = button->text();
  }

  AddText(text);
}

void MainWindow::AddText(const QString& text) {
  line_edit_selected_->setText(line_edit_selected_->text() + text);
  if (line_edit_selected_ != ui->lineEdit_calc) WidgetListCalcUpdateFormulas();
}

void MainWindow::WidgetListCalcVarAddText(WidgetVar* this_widget) {
  AddText(this_widget->GetName());
}

}  // namespace s21
