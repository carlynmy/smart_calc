// Implemetation deposit calculator methods class MainWindow

// Copyright (C) 2023-2023 School 21 License

#include <../../controller/controller.h>

#include <QDate>
#include <QString>
#include <exception>
#include <stdexcept>
#include <string>

#include "../widgetlistwidget/widgetlistwidget.h"
#include "mainwindow.h"

namespace s21 {

void MainWindow::DepositCalcClicked() {
  controller_->DepositClearInputOutputMoney();
  if (!DepositAddListIncrease()) return;
  if (!DepositAddListDecrease()) return;

  std::string sum = ui->lineEdit_deposit_input_sum->text().toStdString();
  int time_unit = ui->comboBox_deposit_input_time_unit->currentIndex();
  std::string time = ui->lineEdit_deposit_input_time->text().toStdString();
  std::string rate = ui->lineEdit_deposit_input_rate->text().toStdString();
  std::string tax = ui->lineEdit_deposit_input_tax->text().toStdString();
  int pay_period = ui->comboBox_deposit_input_pay_unit_unit->currentIndex();
  int capitalisation = ui->checkBox_deposit_input_capitalisation->isChecked();

  QDate q_date = ui->dateEdit_deposit_date_start->date();
  Date date(q_date.day(), q_date.month(), q_date.year());

  try {
    controller_->DepositCalc(sum, time_unit, time, rate, tax, date, pay_period,
                             capitalisation);
  } catch (const InvalidExpr& exception) {
    ui->label_deposit_info->setText(kErrorMsgs[kInvInput]);
    return;
  } catch (const CalculationError& exception) {
    ui->label_deposit_info->setText(kErrorMsgs[kInvInput]);
    return;
  } catch (const std::logic_error& exception) {
    ui->label_deposit_info->setText(exception.what());
    return;
  }

  QString ans_rate = FloatToQString(controller_->DepositAnswerRate());
  QString ans_tax = FloatToQString(controller_->DepositAnswerTax());
  QString ans_sum = FloatToQString(controller_->DepositAnswerSum());

  ui->label_deposit_answer_rate->setText(ans_rate);
  ui->label_deposit_answer_tax->setText(ans_tax);
  ui->label_deposit_answer_sum->setText(ans_sum);

  ui->label_deposit_info->setText("");
}

bool MainWindow::DepositAddListIncrease() {
  return DepositAddList(widget_list_deposit_in_,
                        &Controller::DepositAddInputMoney);
}

bool MainWindow::DepositAddListDecrease() {
  return DepositAddList(widget_list_deposit_out_,
                        &Controller::DepositAddOutputMoney);
}

bool MainWindow::DepositAddList(WidgetListWidget* list, DepositIOFunc func) {
  WidgetListWidget::iterator i = list->Begin();
  WidgetListWidget::iterator term = list->End();
  --term;
  for (; i != term; ++i) {
    WidgetMoneyIO* money_io = reinterpret_cast<WidgetMoneyIO*>(&*i);
    QDate q_date = money_io->GetDate();
    Date date(q_date.day(), q_date.month(), q_date.year());
    std::string value = money_io->GetText().toStdString();

    try {
      (controller_->*func)(date, value);
    } catch (const InvalidExpr& exception) {
      ui->label_deposit_info->setText(kErrorMsgs[kInvInput]);
      return false;
    } catch (const std::logic_error& exception) {
      ui->label_deposit_info->setText(exception.what());
      return false;
    }
  }

  return true;
}

}  // namespace s21
