// Implementation methods lists modifiers MainWindow class

// Copyright (C) 2023-2023 School 21 License

#include <QDate>
#include <QString>
#include <QWidget>
#include <string>
#include <utility>

#include "../widgetfunc/widgetfunc.h"
#include "../widgetlistwidget/widgetlistwidget.h"
#include "../widgetmoneyio/widgetmoneyio.h"
#include "../widgetvar/widgetvar.h"
#include "mainwindow.h"

namespace s21 {

void MainWindow::WidgetListCalcTermClicked(WidgetVar* this_widget) {
  this_widget->GetPairWidget()->SetUnterm();

  std::pair<WidgetVar*, WidgetFunc*> pair_term = CreatePairVarFunc("", true);
  widget_list_calc_vars_->AddWidget(pair_term.first);
  widget_list_graph_vars_->AddWidget(pair_term.second);

  WidgetListCalcUpdateFormulas();
}

void MainWindow::WidgetListGraphTermClicked(WidgetFunc* this_widget) {
  this_widget->GetPairWidget()->SetUnterm();

  std::pair<WidgetVar*, WidgetFunc*> pair_term = CreatePairVarFunc("", true);
  widget_list_calc_vars_->AddWidget(pair_term.first);
  widget_list_graph_vars_->AddWidget(pair_term.second);

  WidgetListGraphUpdateFormulas();
}

void MainWindow::WidgetListDepositTermClicked() {
  WidgetMoneyIO* widget_term = CreateMoneyIO(QDate(), "", 1);
  if (reinterpret_cast<const WidgetMoneyIO*>(widget_list_deposit_in_->Back())
          ->IsTerm())
    widget_list_deposit_out_->AddWidget(widget_term);
  else
    widget_list_deposit_in_->AddWidget(widget_term);
}

// ------------------------------------------------------------------------- //

void MainWindow::WidgetListCalcVarDelete(WidgetVar* this_widget) {
  if (this_widget->GetLineEdit() == line_edit_selected_)
    SetSelectedLine(ui->lineEdit_calc);

  widget_list_graph_vars_->RemoveWidget(this_widget->GetPairWidget());
  widget_list_calc_vars_->RemoveWidget(this_widget);

  WidgetListCalcUpdateFormulas();
}

void MainWindow::WidgetListGraphVarDelete(WidgetFunc* this_widget) {
  widget_list_calc_vars_->RemoveWidget(this_widget->GetPairWidget());
  widget_list_graph_vars_->RemoveWidget(this_widget);

  WidgetListGraphUpdateFormulas();
}

void MainWindow::WidgetListDepositDelete(WidgetMoneyIO* this_widget) {
  if (widget_list_deposit_in_->IsContains(this_widget))
    widget_list_deposit_in_->RemoveWidget(this_widget);
  else
    widget_list_deposit_out_->RemoveWidget(this_widget);
}

// ------------------------------------------------------------------------- //

void MainWindow::WidgetListCalcItemSwitch(QWidget* a, QWidget* b) {
  widget_list_graph_vars_->InsertBefore(
      reinterpret_cast<WidgetVar*>(a)->GetPairWidget(),
      reinterpret_cast<WidgetVar*>(b)->GetPairWidget());
  WidgetListCalcUpdateFormulas();
}

void MainWindow::WidgetListGraphItemSwitch(QWidget* a, QWidget* b) {
  widget_list_calc_vars_->InsertBefore(
      reinterpret_cast<WidgetFunc*>(a)->GetPairWidget(),
      reinterpret_cast<WidgetFunc*>(b)->GetPairWidget());
  WidgetListGraphUpdateFormulas();
}

// ------------------------------------------------------------------------- //

void MainWindow::WidgetListCalcUpdateFormulas() {
  controller_->ClearFormulas();
  controller_->SetXYMayBeVar(x_and_y_may_be_var_);
  WidgetListWidget::iterator i = widget_list_calc_vars_->Begin();
  for (; i != widget_list_calc_vars_->End(); ++i) {
    CalcAddFormula(reinterpret_cast<WidgetVar*>(&*i));
  }

  ui->widget_graph_graph->update();
}

void MainWindow::WidgetListGraphUpdateFormulas() {
  controller_->ClearFormulas();
  controller_->SetXYMayBeVar(x_and_y_may_be_var_);
  WidgetListWidget::iterator i = widget_list_graph_vars_->Begin();
  for (; i != widget_list_graph_vars_->End(); ++i) {
    GraphAddFormula(reinterpret_cast<WidgetFunc*>(&*i));
  }

  ui->widget_graph_graph->update();
}

void MainWindow::CalcAddFormula(WidgetVar* widget) {
  QString expr = widget->GetText();

  std::pair<Model::TypeFormula, std::string> answer;
  bool exception_flag = false;
  try {
    answer = controller_->AddFormula(expr.toStdString(), true);
  } catch (...) {
    exception_flag = true;
    answer.first = Model::kTypeInvFormula;
    answer.second = "";
  }

  WidgetVar::Type type = CalcTranslateType(answer.first);
  if (exception_flag) type = WidgetVar::kTypeErr;

  widget->SetName(QString(answer.second.c_str()));
  widget->SetType(type);
  widget->GetPairWidget()->SetText(widget->GetText());
  widget->GetPairWidget()->SetType(static_cast<WidgetFunc::Type>(type));
}

void MainWindow::GraphAddFormula(WidgetFunc* widget) {
  QString expr = widget->GetText();
  bool add_graph = !widget->IsHide();

  std::pair<Model::TypeFormula, std::string> answer;
  bool exception_flag = false;
  try {
    answer = controller_->AddFormula(expr.toStdString(), add_graph);
  } catch (...) {
    exception_flag = true;
    answer.first = Model::kTypeInvFormula;
    answer.second = "";
  }

  WidgetFunc::Type type = GraphTranslateType(answer.first);
  if (exception_flag) type = WidgetFunc::kTypeErr;

  widget->SetType(type);
  widget->GetPairWidget()->SetText(widget->GetText());
  widget->GetPairWidget()->SetType(static_cast<WidgetVar::Type>(type));
  widget->GetPairWidget()->SetName(QString(answer.second.c_str()));
}

WidgetVar::Type MainWindow::CalcTranslateType(Model::TypeFormula type) {
  if (type == Model::kTypeVar) {
    return WidgetVar::kTypeVar;

  } else if (type == Model::kTypeNamelessFunc ||
             type == Model::kTypeNamelessFuncY ||
             type == Model::kTypeNamelessFuncEq ||
             type == Model::kTypeNamelessFuncEqY || type == Model::kTypeFunc0 ||
             type == Model::kTypeFunc1 || type == Model::kTypeFunc1Y ||
             type == Model::kTypeFuncN) {
    return WidgetVar::kTypeFunc;

  } else if (type == Model::kTypeEquation) {
    return WidgetVar::kTypeEquation;

  } else if (type == Model::kTypePoint) {
    return WidgetVar::kTypePoint;
  }

  return WidgetVar::kTypeErr;
}

WidgetFunc::Type MainWindow::GraphTranslateType(Model::TypeFormula type) {
  if (type == Model::kTypeVar) {
    return WidgetFunc::kTypeVar;

  } else if (type == Model::kTypeNamelessFunc ||
             type == Model::kTypeNamelessFuncY ||
             type == Model::kTypeNamelessFuncEq ||
             type == Model::kTypeNamelessFuncEqY || type == Model::kTypeFunc0 ||
             type == Model::kTypeFunc1 || type == Model::kTypeFunc1Y ||
             type == Model::kTypeFuncN) {
    return WidgetFunc::kTypeFunc;

  } else if (type == Model::kTypeEquation) {
    return WidgetFunc::kTypeEquation;

  } else if (type == Model::kTypePoint) {
    return WidgetFunc::kTypePoint;
  }

  return WidgetFunc::kTypeErr;
}

// ------------------------------------------------------------------------- //

std::pair<WidgetVar*, WidgetFunc*> MainWindow::CreatePairVarFunc(
    const QString& str, bool is_term) {
  WidgetVar* var = CreateVar(str, is_term);
  WidgetFunc* func = CreateFunc(str, is_term);
  var->SetPairWidget(func);
  func->SetPairWidget(var);
  return {var, func};
}

WidgetVar* MainWindow::CreateVar(const QString& str, bool is_term) {
  WidgetVar* widget = new WidgetVar(nullptr, str, is_term);

  connect(widget, &WidgetVar::WidgetUnTerm, this,
          &MainWindow::WidgetListCalcTermClicked);
  connect(widget, &WidgetVar::WidgetDelete, this,
          &MainWindow::WidgetListCalcVarDelete);
  connect(widget, &WidgetVar::NameClicked, this,
          &MainWindow::WidgetListCalcVarAddText);
  connect(widget, &WidgetVar::LineEditSelect, this,
          &MainWindow::SetSelectedLine);
  connect(widget, &WidgetVar::FormulaUpdate, this,
          &MainWindow::WidgetListCalcUpdateFormulas);

  return widget;
}

WidgetFunc* MainWindow::CreateFunc(const QString& str, bool is_term) {
  WidgetFunc* widget = new WidgetFunc(nullptr, str, is_term);

  connect(widget, &WidgetFunc::WidgetUnTerm, this,
          &MainWindow::WidgetListGraphTermClicked);
  connect(widget, &WidgetFunc::WidgetDelete, this,
          &MainWindow::WidgetListGraphVarDelete);
  connect(widget, &WidgetFunc::FormulaUpdate, this,
          &MainWindow::WidgetListGraphUpdateFormulas);

  return widget;
}

WidgetMoneyIO* MainWindow::CreateMoneyIO(const QDate& date, const QString& str,
                                         bool is_term) {
  WidgetMoneyIO* widget = new WidgetMoneyIO(nullptr, date, str, is_term);

  connect(widget, &WidgetMoneyIO::WidgetUnTerm, this,
          &MainWindow::WidgetListDepositTermClicked);
  connect(widget, &WidgetMoneyIO::WidgetDelete, this,
          &MainWindow::WidgetListDepositDelete);

  return widget;
}

}  // namespace s21
