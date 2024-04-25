// Implementation MainWindow class

// Copyright (C) 2023-2023 School 21 License

#include "mainwindow.h"

#include <QEvent>
#include <QLineEdit>
#include <QMainWindow>
#include <QObject>
#include <QString>
#include <QWidget>
#include <clocale>

#include "../../controller/controller.h"
#include "../tmp/headers/ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(Controller* controller, QWidget* parent)
    : QMainWindow(parent), controller_(controller), ui(new ::Ui::MainWindow) {
  ui->setupUi(this);
  std::setlocale(LC_ALL, "C");

  SetupMainWindow();
}

MainWindow::~MainWindow() {
  delete widget_list_calc_vars_;
  delete widget_list_graph_vars_;
  delete widget_list_deposit_in_;
  delete widget_list_deposit_out_;
  delete ui;
}

void MainWindow::TabSwitched() {
  SetSelectedLine(ui->lineEdit_calc);

  int new_index = ui->tabWidget->currentIndex();

  ui->tabWidget->widget(tab_widget_prev_)->setSizePolicy(kSizePolicyIgnored);

  ui->tabWidget->widget(new_index)->setSizePolicy(kSizePolicyPreferred);
  ui->tabWidget->widget(new_index)->resize(
      ui->tabWidget->widget(new_index)->minimumSizeHint());
  ui->tabWidget->widget(new_index)->adjustSize();

  if (new_index == 0) {
    x_and_y_may_be_var_ = true;
    WidgetListCalcUpdateFormulas();
    widget_list_calc_vars_->layout()->invalidate();

  } else if (new_index == 1) {
    x_and_y_may_be_var_ = false;
    WidgetListGraphUpdateFormulas();
    widget_list_graph_vars_->layout()->invalidate();

  } else {
    x_and_y_may_be_var_ = true;
  }

  tab_widget_prev_ = new_index;
}

void MainWindow::SetSelectedLine(QLineEdit* line) {
  line_edit_selected_ = line;
}

bool MainWindow::eventFilter(QObject* object, QEvent* event) {
  if (object == ui->lineEdit_calc && event->type() == QEvent::FocusIn) {
    SetSelectedLine(ui->lineEdit_calc);
  }

  return false;
}

double MainWindow::QStringToCalc(const QString& str) {
  return controller_->CalculatorCalc(str.toStdString());
}

QString MainWindow::FloatToQString(double value) {
  return QString(std::to_string(value).c_str());
}

}  // namespace s21
