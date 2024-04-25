// Implementation methods to hide show lists MainWindow class

// Copyright (C) 2023-2023 School 21 License

#include <QSizePolicy>

#include "mainwindow.h"

namespace s21 {

void MainWindow::CalcVarListHideClicked() {
  if (calc_var_list_hide_)
    CalcVarListShow();
  else
    CalcVarListHide();
}

void MainWindow::GraphVarListHideClicked() {
  if (graph_func_list_hide_)
    GraphFuncListShow();
  else
    GraphFuncListHide();
}

void MainWindow::GraphMenuHideClicked() {
  if (graph_menu_hide_)
    GraphMenuShow();
  else
    GraphMenuHide();
}

void MainWindow::DepositInListClicked() {
  if (deposit_in_list_hide_)
    DepositInlistShow();
  else
    DepositInlistHide();
}

void MainWindow::DepositOutListClicked() {
  if (deposit_out_list_hide_)
    DepositOutlistShow();
  else
    DepositOutlistHide();
}

void MainWindow::CalcVarListHide() {
  ui->horizontalSpacer_3->changeSize(0, 0, QSizePolicy::Minimum,
                                     QSizePolicy::Minimum);
  ui->horizontalSpacer_9->changeSize(0, 0, QSizePolicy::Minimum,
                                     QSizePolicy::Minimum);
  ui->horizontalSpacer_4->changeSize(0, 0, QSizePolicy::Minimum,
                                     QSizePolicy::Minimum);
  ui->horizontalSpacer_6->changeSize(0, 0, QSizePolicy::Minimum,
                                     QSizePolicy::Minimum);

  ui->widget_calc_head->layout()->invalidate();
  ui->widget_calc->layout()->invalidate();

  ui->widget_calc_vars->hide();
  calc_var_list_hide_ = true;
}

void MainWindow::CalcVarListShow() {
  ui->horizontalSpacer_3->changeSize(40, 20, QSizePolicy::Expanding,
                                     QSizePolicy::Expanding);
  ui->horizontalSpacer_4->changeSize(421, 20, QSizePolicy::Fixed,
                                     QSizePolicy::Fixed);
  ui->horizontalSpacer_9->changeSize(10, 20, QSizePolicy::Fixed,
                                     QSizePolicy::Fixed);
  ui->horizontalSpacer_6->changeSize(40, 20, QSizePolicy::Expanding,
                                     QSizePolicy::Expanding);

  ui->widget_calc_head->layout()->invalidate();
  ui->widget_calc->layout()->invalidate();

  ui->widget_calc_vars->show();
  calc_var_list_hide_ = false;
}

void MainWindow::GraphFuncListHide() {
  ui->scrollArea_graph_vars->hide();
  graph_func_list_hide_ = true;
}

void MainWindow::GraphFuncListShow() {
  ui->scrollArea_graph_vars->show();
  graph_func_list_hide_ = false;
}

void MainWindow::GraphMenuHide() {
  ui->widget_graph_menu->hide();
  graph_menu_hide_ = true;
}

void MainWindow::GraphMenuShow() {
  ui->widget_graph_menu->show();
  graph_menu_hide_ = false;
}

void MainWindow::DepositInlistHide() {
  ui->scrollArea_widget_deposit_list_in->hide();
  deposit_in_list_hide_ = true;
}

void MainWindow::DepositInlistShow() {
  ui->scrollArea_widget_deposit_list_in->show();
  deposit_in_list_hide_ = false;
}

void MainWindow::DepositOutlistHide() {
  ui->scrollArea_widget_deposit_list_out->hide();
  deposit_out_list_hide_ = true;
}

void MainWindow::DepositOutlistShow() {
  ui->scrollArea_widget_deposit_list_out->show();
  deposit_out_list_hide_ = false;
}

}  // namespace s21
