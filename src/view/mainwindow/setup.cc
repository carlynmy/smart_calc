// Implementation setup methods MainWindow class

// Copyright (C) 2023-2023 School 21 License

#include <QCheckBox>
#include <QDate>
#include <QLineEdit>
#include <QPushButton>
#include <utility>

#include "../widgetfunc/widgetfunc.h"
#include "../widgetlistwidget/widgetlistwidget.h"
#include "../widgetmoneyio/widgetmoneyio.h"
#include "../widgetvar/widgetvar.h"
#include "mainwindow.h"

namespace s21 {

void MainWindow::SetupMainWindow() {
  ui->lineEdit_calc->installEventFilter(this);
  SetSelectedLine(ui->lineEdit_calc);

  SetupWidgeListCalcGraph();
  SetupWidgetListDepositIn();
  SetupWidgetListDepositOut();

  WidgetListCalcUpdateFormulas();

  SetupTabWidget();
  SetupWidgetGraph();

  Connects();
}

void MainWindow::SetupWidgeListCalcGraph() {
  std::pair<WidgetVar*, WidgetFunc*> pair_pi =
      CreatePairVarFunc("pi = 3.1415", false);
  std::pair<WidgetVar*, WidgetFunc*> pair_e =
      CreatePairVarFunc("e = 2.78", false);
  std::pair<WidgetVar*, WidgetFunc*> pair_term = CreatePairVarFunc("", true);

  int var_w = pair_term.first->width();
  int func_w = pair_term.second->width();

  widget_list_calc_vars_ = new WidgetListWidget(var_w, this);
  widget_list_graph_vars_ = new WidgetListWidget(func_w, this);
  ui->scrollArea_calc_vars->setWidgetResizable(false);
  ui->scrollArea_graph_vars->setWidgetResizable(false);
  ui->scrollArea_calc_vars->setWidget(widget_list_calc_vars_);
  ui->scrollArea_graph_vars->setWidget(widget_list_graph_vars_);

  widget_list_calc_vars_->AddWidget(pair_pi.first);
  widget_list_calc_vars_->AddWidget(pair_e.first);
  widget_list_calc_vars_->AddWidget(pair_term.first);

  widget_list_graph_vars_->AddWidget(pair_pi.second);
  widget_list_graph_vars_->AddWidget(pair_e.second);
  widget_list_graph_vars_->AddWidget(pair_term.second);

  connect(widget_list_calc_vars_, &WidgetListWidget::WidgetInsertedBefore, this,
          &MainWindow::WidgetListCalcItemSwitch);
  connect(widget_list_graph_vars_, &WidgetListWidget::WidgetInsertedBefore,
          this, &MainWindow::WidgetListGraphItemSwitch);
}

void MainWindow::SetupWidgetListDepositIn() {
  WidgetMoneyIO* widget_term = CreateMoneyIO(QDate(), "", true);

  int widget_w = widget_term->width();

  widget_list_deposit_in_ = new WidgetListWidget(widget_w, this);

  ui->scrollArea_widget_deposit_list_in->setWidgetResizable(false);
  ui->scrollArea_widget_deposit_list_in->setWidget(widget_list_deposit_in_);

  widget_list_deposit_in_->AddWidget(widget_term);
}

void MainWindow::SetupWidgetListDepositOut() {
  WidgetMoneyIO* widget_term = CreateMoneyIO(QDate(), "", true);

  int widget_w = widget_term->width();

  widget_list_deposit_out_ = new WidgetListWidget(widget_w, this);

  ui->scrollArea_widget_deposit_list_out->setWidgetResizable(false);
  ui->scrollArea_widget_deposit_list_out->setWidget(widget_list_deposit_out_);

  widget_list_deposit_out_->AddWidget(widget_term);
}

void MainWindow::SetupTabWidget() {
  tab_widget_prev_ = 0;
  ui->tabWidget->widget(1)->setSizePolicy(kSizePolicyIgnored);
  ui->tabWidget->widget(3)->setSizePolicy(kSizePolicyIgnored);

  ui->tabWidget->widget(0)->setSizePolicy(kSizePolicyPreferred);
  ui->tabWidget->widget(0)->resize(ui->tabWidget->widget(0)->minimumSizeHint());
  ui->tabWidget->widget(0)->adjustSize();
}

void MainWindow::SetupWidgetGraph() {
  ui->widget_graph_graph->SetMainWindow(this);
  GraphDefaulSettings();
}

void MainWindow::Connects() {
  connect(ui->pushButton_calc_var_list_hide, &QPushButton::clicked, this,
          &MainWindow::CalcVarListHideClicked);
  connect(ui->pushButton_graph_vars_hide, &QPushButton::clicked, this,
          &MainWindow::GraphVarListHideClicked);
  connect(ui->pushButton_graph_menu_hide, &QPushButton::clicked, this,
          &MainWindow::GraphMenuHideClicked);
  connect(ui->pushButton_deposit_list_in_hide, &QPushButton::clicked, this,
          &MainWindow::DepositInListClicked);
  connect(ui->pushButton_deposit_list_out_hide, &QPushButton::clicked, this,
          &MainWindow::DepositOutListClicked);

  connect(ui->tabWidget, &QTabWidget::currentChanged, this,
          &MainWindow::TabSwitched);

  connect(ui->pushButton_credit_start, &QPushButton::clicked, this,
          &MainWindow::CreditCalcClicked);
  connect(ui->pushButton_deposit_start, &QPushButton::clicked, this,
          &MainWindow::DepositCalcClicked);

  connect(ui->pushButton_num1, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_num2, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_num3, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_num4, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_num5, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_num6, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_num7, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_num8, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_num9, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_num0, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_dot, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_plus, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_minus, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_mul, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_div, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_bracket_open, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_bracket_close, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_acos, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_asin, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_atan, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_cos, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_sin, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_tan, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_log, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_ln, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_sqrt, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_mod, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_comma, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_fact, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);

  connect(ui->pushButton_pow, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_sqr, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);
  connect(ui->pushButton_e, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClicked);

  connect(ui->pushButton_clear, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClearClicked);
  connect(ui->pushButton_clear_all, &QPushButton::clicked, this,
          &MainWindow::CalcButtonClearAllClicked);
  connect(ui->pushButton_eq, &QPushButton::clicked, this,
          &MainWindow::CalcButtonEqClicked);

  connect(ui->checkBox_graph_menu_axis_x, &QCheckBox::stateChanged, this,
          &MainWindow::GraphMenuAxisXChanged);
  connect(ui->checkBox_graph_menu_axis_y, &QCheckBox::stateChanged, this,
          &MainWindow::GraphMenuAxisYChanged);
  connect(ui->checkBox_graph_menu_grid, &QCheckBox::stateChanged, this,
          &MainWindow::GraphMenuGridChanged);
  connect(ui->checkBox_graph_menu_small_grid, &QCheckBox::stateChanged, this,
          &MainWindow::GraphMenuSmallGridChanged);
  connect(ui->checkBox_graph_menu_nums_on_axis, &QCheckBox::stateChanged, this,
          &MainWindow::GraphMenuNumsOnAxisChanged);

  connect(ui->lineEdit_graph_menu_max_x, &QLineEdit::textEdited, this,
          &MainWindow::GraphMenuXMaxChanged);
  connect(ui->lineEdit_graph_menu_min_x, &QLineEdit::textEdited, this,
          &MainWindow::GraphMenuXMinChanged);
  connect(ui->lineEdit_graph_menu_max_y, &QLineEdit::textEdited, this,
          &MainWindow::GraphMenuYMaxChanged);
  connect(ui->lineEdit_graph_menu_min_y, &QLineEdit::textEdited, this,
          &MainWindow::GraphMenuYMinChanged);
  connect(ui->lineEdit_graph_menu_step_x, &QLineEdit::textEdited, this,
          &MainWindow::GraphMenuXStepChanged);
  connect(ui->lineEdit_graph_menu_step_y, &QLineEdit::textEdited, this,
          &MainWindow::GraphMenuYStepChanged);

  connect(ui->pushButton_graph_menu_restore, &QPushButton::clicked, this,
          &MainWindow::GraphDefaulSettings);
  connect(ui->widget_graph_graph, &WidgetGraph::FieldChanged, this,
          &MainWindow::GraphFieldChanged);
}

}  // namespace s21
