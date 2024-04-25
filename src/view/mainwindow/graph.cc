// Implemetation graph methods class MainWindow

// Copyright (C) 2023-2023 School 21 License

#include <string>

#include "../widgetgraph/widgetgraph.h"
#include "mainwindow.h"

namespace s21 {

void MainWindow::GraphMenuAxisXChanged(int state) {
  ui->widget_graph_graph->DrawAxisX(state);
  ui->widget_graph_graph->update();
}

void MainWindow::GraphMenuAxisYChanged(int state) {
  ui->widget_graph_graph->DrawAxisY(state);
  ui->widget_graph_graph->update();
}

void MainWindow::GraphMenuGridChanged(int state) {
  ui->widget_graph_graph->DrawGrid(state);
  ui->widget_graph_graph->update();
}

void MainWindow::GraphMenuSmallGridChanged(int state) {
  ui->widget_graph_graph->DrawSmallGrid(state);
  ui->widget_graph_graph->update();
}

void MainWindow::GraphMenuNumsOnAxisChanged(int state) {
  ui->widget_graph_graph->DrawNumsOnAxis(state);
  ui->widget_graph_graph->update();
}

void MainWindow::GraphMenuXMaxChanged() {
  double value = 0;
  try {
    value = QStringToCalc(ui->lineEdit_graph_menu_max_x->text());
  } catch (...) {
    return;
  }

  controller_->GraphSetXMax(value);
  ui->widget_graph_graph->SetXMax(value);
  ui->widget_graph_graph->update();
}

void MainWindow::GraphMenuXMinChanged() {
  double value = 0;
  try {
    value = QStringToCalc(ui->lineEdit_graph_menu_min_x->text());
  } catch (...) {
    return;
  }

  controller_->GraphSetXMin(value);
  ui->widget_graph_graph->SetXMin(value);
  ui->widget_graph_graph->update();
}

void MainWindow::GraphMenuYMaxChanged() {
  double value = 0;
  try {
    value = QStringToCalc(ui->lineEdit_graph_menu_max_y->text());
  } catch (...) {
    return;
  }

  controller_->GraphSetYMax(value);
  ui->widget_graph_graph->SetYMax(value);
  ui->widget_graph_graph->update();
}

void MainWindow::GraphMenuYMinChanged() {
  double value = 0;
  try {
    value = QStringToCalc(ui->lineEdit_graph_menu_min_y->text());
  } catch (...) {
    return;
  }

  controller_->GraphSetYMin(value);
  ui->widget_graph_graph->SetYMin(value);
  ui->widget_graph_graph->update();
}

void MainWindow::GraphMenuXStepChanged() {
  std::string expr = ui->lineEdit_graph_menu_step_x->text().toStdString();

  double value;
  try {
    value = controller_->CalculatorCalc(expr);
  } catch (...) {
    value = 0;
  }

  if (value != 0 && value < kGraphMinStep) value = kGraphMinStep;
  if (value < 0) value = 0;
  ui->widget_graph_graph->SetXStep(value);
  ui->widget_graph_graph->update();
}

void MainWindow::GraphMenuYStepChanged() {
  std::string expr = ui->lineEdit_graph_menu_step_y->text().toStdString();

  double value;
  try {
    value = controller_->CalculatorCalc(expr);
  } catch (...) {
    value = 0;
  }

  if (value != 0 && value < kGraphMinStep) value = kGraphMinStep;
  if (value < 0) value = 0;
  ui->widget_graph_graph->SetYStep(value);
  ui->widget_graph_graph->update();
}

void MainWindow::GraphFieldChanged(WidgetGraph::FieldIndexes field) {
  double value;
  switch (field) {
    case WidgetGraph::kFieldXMax:
      value = ui->widget_graph_graph->GetXMax();
      controller_->GraphSetXMax(value);
      ui->lineEdit_graph_menu_max_x->setText(FloatToQString(value));
      break;

    case WidgetGraph::kFieldXMin:
      value = ui->widget_graph_graph->GetXMin();
      controller_->GraphSetXMin(value);
      ui->lineEdit_graph_menu_min_x->setText(FloatToQString(value));
      break;

    case WidgetGraph::kFieldYMax:
      value = ui->widget_graph_graph->GetYMax();
      controller_->GraphSetYMax(value);
      ui->lineEdit_graph_menu_max_y->setText(FloatToQString(value));
      break;

    case WidgetGraph::kFieldYMin:
      value = ui->widget_graph_graph->GetYMin();
      controller_->GraphSetYMin(value);
      ui->lineEdit_graph_menu_min_y->setText(FloatToQString(value));
      break;

    case WidgetGraph::kFieldHeight:
      controller_->GraphSetYSize(ui->widget_graph_graph->height());
      break;

    case WidgetGraph::kFieldWidth:
      controller_->GraphSetXSize(ui->widget_graph_graph->width());
      break;

    default:
      break;
  }

  ui->widget_graph_graph->update();
}

void MainWindow::GraphDefaulSettings() {
  controller_->GraphSetXMax(kGraphXMax);
  controller_->GraphSetXMin(kGraphXMin);
  controller_->GraphSetXSize(ui->widget_graph_graph->width());
  controller_->GraphSetYSize(ui->widget_graph_graph->height());

  ui->checkBox_graph_menu_axis_x->setChecked(true);
  ui->checkBox_graph_menu_axis_y->setChecked(true);
  ui->checkBox_graph_menu_grid->setChecked(true);
  ui->checkBox_graph_menu_small_grid->setChecked(true);
  ui->checkBox_graph_menu_nums_on_axis->setChecked(true);

  ui->widget_graph_graph->DrawAxisX(true);
  ui->widget_graph_graph->DrawAxisY(true);
  ui->widget_graph_graph->DrawGrid(true);
  ui->widget_graph_graph->DrawSmallGrid(true);
  ui->widget_graph_graph->DrawNumsOnAxis(true);
  ui->widget_graph_graph->SetXStep(0);
  ui->widget_graph_graph->SetYStep(0);

  ui->widget_graph_graph->SetXRange(kGraphXMin, kGraphXMax);

  ui->lineEdit_graph_menu_max_x->setText(FloatToQString(kGraphXMax));
  ui->lineEdit_graph_menu_min_x->setText(FloatToQString(kGraphXMin));
  ui->lineEdit_graph_menu_step_x->setText("");
  ui->lineEdit_graph_menu_step_y->setText("");

  ui->widget_graph_graph->update();
}

}  // namespace s21
