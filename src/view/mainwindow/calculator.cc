// Implemetation calculator methods class MainWindow

// Copyright (C) 2023-2023 School 21 License

#include <QString>
#include <exception>
#include <string>

#include "mainwindow.h"

namespace s21 {

void MainWindow::CalcCalcClicked() {
  QString q_str = ui->lineEdit_calc->text();
  std::string str = q_str.toStdString();
  double res;

  bool exception_flag = false;
  try {
    res = controller_->CalculatorCalc(str);
  } catch (const std::exception& exception) {
    ui->label_calc_info->setText(exception.what());
    exception_flag = true;
  }

  if (!exception_flag) {
    QString str_res = FloatToQString(res);
    ui->lineEdit_calc->setText(str_res);
    last_answer = str_res;
    ui->label_calc_info->setText(last_answer);
  }
}

}  // namespace s21
