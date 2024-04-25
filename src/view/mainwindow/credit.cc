// Implemetation credit calculator methods class MainWindow

// Copyright (C) 2023-2023 School 21 License

#include <QString>
#include <exception>
#include <string>

#include "mainwindow.h"

namespace s21 {

void MainWindow::CreditCalcClicked() {
  std::string sum = ui->lineEdit_credit_input_sum->text().toStdString();
  std::string rate = ui->lineEdit_credit_input_rate->text().toStdString();
  int time_unit = ui->comboBox_credit_input_time_unit->currentIndex();
  std::string time = ui->lineEdit_credit_input_time->text().toStdString();
  int type = ui->comboBox_credit_input_type->currentIndex();

  try {
    controller_->CreditCalc(sum, rate, time_unit, time, type);
  } catch (const std::exception& exception) {
    ui->label_credit_info->setText(exception.what());
    return;
  }

  QString month_pay = FloatToQString(controller_->CreditAnswerMonthPay());
  QString over_pay = FloatToQString(controller_->CreditAnswerOverPay());
  QString total_pay = FloatToQString(controller_->CreditAnswerTotalPay());

  ui->label_credit_answer_month_pay->setText(month_pay);
  ui->label_credit_answer_over_pay->setText(over_pay);
  ui->label_credit_answer_total_pay->setText(total_pay);

  ui->label_credit_info->setText("");
}

}  // namespace s21
