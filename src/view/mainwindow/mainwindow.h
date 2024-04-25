// Declaration class MainWindow

// Copyright (C) 2023-2023 School 21 License

#ifndef SMART_CALC_V_2_VIEW_MAINWINDOW_MAINWINDOW_H_
#define SMART_CALC_V_2_VIEW_MAINWINDOW_MAINWINDOW_H_

#include <QMainWindow>
#include <QSizePolicy>
#include <QString>
#include <QWidget>

#include "../../controller/controller.h"
#include "../tmp/headers/ui_mainwindow.h"
#include "../widgetfunc/widgetfunc.h"
#include "../widgetgraph/widgetgraph.h"
#include "../widgetlistwidget/widgetlistwidget.h"
#include "../widgetmoneyio/widgetmoneyio.h"
#include "../widgetvar/widgetvar.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(Controller* controller, QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  // ----------------------------------------------------------------------- //
  //                          Start calculation                              //
  // ----------------------------------------------------------------------- //

  void CalcCalcClicked();
  void CreditCalcClicked();
  void DepositCalcClicked();

  // ----------------------------------------------------------------------- //
  //                           Lists hide/show                               //
  // ----------------------------------------------------------------------- //

  void CalcVarListHideClicked();
  void GraphVarListHideClicked();
  void GraphMenuHideClicked();
  void DepositInListClicked();
  void DepositOutListClicked();

  // ----------------------------------------------------------------------- //
  //                           Lists modifiers                               //
  // ----------------------------------------------------------------------- //

  void WidgetListCalcTermClicked(WidgetVar* this_widget);
  void WidgetListGraphTermClicked(WidgetFunc* this_widget);
  void WidgetListDepositTermClicked();

  void WidgetListCalcVarDelete(WidgetVar* this_widget);
  void WidgetListGraphVarDelete(WidgetFunc* this_widget);
  void WidgetListDepositDelete(WidgetMoneyIO* this_widget);

  void WidgetListCalcItemSwitch(QWidget* a, QWidget* b);
  void WidgetListGraphItemSwitch(QWidget* a, QWidget* b);

  void WidgetListCalcUpdateFormulas();
  void WidgetListGraphUpdateFormulas();

  // ----------------------------------------------------------------------- //
  //                        Calculator buttons                               //
  // ----------------------------------------------------------------------- //

  void CalcButtonClicked();
  void CalcButtonClearClicked();
  void CalcButtonClearAllClicked();
  void CalcButtonEqClicked();

  void WidgetListCalcVarAddText(WidgetVar* this_widget);

  // ----------------------------------------------------------------------- //
  //                                 Graph                                   //
  // ----------------------------------------------------------------------- //

  void GraphMenuAxisXChanged(int state);
  void GraphMenuAxisYChanged(int state);
  void GraphMenuGridChanged(int state);
  void GraphMenuSmallGridChanged(int state);
  void GraphMenuNumsOnAxisChanged(int state);
  void GraphMenuXMaxChanged();
  void GraphMenuXMinChanged();
  void GraphMenuYMaxChanged();
  void GraphMenuYMinChanged();
  void GraphMenuXStepChanged();
  void GraphMenuYStepChanged();

  void GraphFieldChanged(WidgetGraph::FieldIndexes field);
  void GraphDefaulSettings();

  // ----------------------------------------------------------------------- //

  void TabSwitched();
  void SetSelectedLine(QLineEdit* line);

 private:
  enum ErrorIndexes { kInvInput };
  using DepositIOFunc = void (Controller::*)(const Date&, const std::string&);
  friend WidgetGraph;

  const static inline double kGraphXMin = -10;
  const static inline double kGraphXMax = 10;
  const static inline double kGraphMinStep = 1e-6;

  const static inline size_t kScrollSize = 10;
  const static inline QSizePolicy kSizePolicyIgnored =
      QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  const static inline QSizePolicy kSizePolicyPreferred =
      QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  const static inline QString kErrorMsgs[] = {"Введены неккоректные данные"};

  // ----------------------------------------------------------------------- //
  //                                 Setup                                   //
  // ----------------------------------------------------------------------- //

  void SetupMainWindow();
  void SetupWidgeListCalcGraph();
  void SetupWidgetListDepositIn();
  void SetupWidgetListDepositOut();
  void SetupTabWidget();
  void SetupWidgetGraph();
  void Connects();

  // ----------------------------------------------------------------------- //
  //                             Lists hide/show                             //
  // ----------------------------------------------------------------------- //

  void CalcVarListHide();
  void CalcVarListShow();
  void GraphFuncListHide();
  void GraphFuncListShow();
  void GraphMenuHide();
  void GraphMenuShow();
  void DepositInlistHide();
  void DepositInlistShow();
  void DepositOutlistHide();
  void DepositOutlistShow();

  // ----------------------------------------------------------------------- //
  //                         Create widgets for lists                        //
  // ----------------------------------------------------------------------- //

  std::pair<WidgetVar*, WidgetFunc*> CreatePairVarFunc(const QString& str,
                                                       bool is_term);
  WidgetVar* CreateVar(const QString& str, bool is_term);
  WidgetFunc* CreateFunc(const QString& str, bool is_term);
  WidgetMoneyIO* CreateMoneyIO(const QDate& date, const QString& str,
                               bool is_term);

  // ----------------------------------------------------------------------- //
  //                          Deposit input lists                            //
  // ----------------------------------------------------------------------- //

  /// @return true if input success
  bool DepositAddListIncrease();

  /// @return true if input success
  bool DepositAddListDecrease();

  /// @return true if input success
  bool DepositAddList(WidgetListWidget* list, DepositIOFunc func);

  // ----------------------------------------------------------------------- //
  //                        Calculator input formulas                        //
  // ----------------------------------------------------------------------- //

  void CalcAddFormula(WidgetVar* widget);
  void GraphAddFormula(WidgetFunc* widget);

  WidgetVar::Type CalcTranslateType(Model::TypeFormula type);
  WidgetFunc::Type GraphTranslateType(Model::TypeFormula type);

  // ----------------------------------------------------------------------- //

  void AddText(const QString& text);

  // ----------------------------------------------------------------------- //

  bool eventFilter(QObject* object, QEvent* event) override;

  // ----------------------------------------------------------------------- //

  double QStringToCalc(const QString& str);
  QString FloatToQString(double value);

  Controller* controller_;

  bool calc_var_list_hide_ = false;
  bool graph_func_list_hide_ = false;
  bool graph_menu_hide_ = false;
  bool deposit_in_list_hide_ = false;
  bool deposit_out_list_hide_ = false;

  int tab_widget_prev_;

  bool x_and_y_may_be_var_ = true;

  ::Ui::MainWindow* ui;

  WidgetListWidget* widget_list_calc_vars_;
  WidgetListWidget* widget_list_graph_vars_;
  WidgetListWidget* widget_list_deposit_in_;
  WidgetListWidget* widget_list_deposit_out_;

  QLineEdit* line_edit_selected_;

  QString last_answer;
};

}  // namespace s21

#endif  // SMART_CALC_V_2_VIEW_MAINWINDOW_MAINWINDOW_H_
