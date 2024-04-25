/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widgetgraph/widgetgraph.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_calc;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_calc_head;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_calc_var_list_hide;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_calc;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_calc_vars;
    QFormLayout *formLayout;
    QScrollArea *scrollArea_calc_vars;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_calc_2;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_calc_3;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_eq;
    QPushButton *pushButton_bracket_open;
    QPushButton *pushButton_bracket_close;
    QPushButton *pushButton_num2;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_fact;
    QPushButton *pushButton_comma;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_num3;
    QPushButton *pushButton_clear_all;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_div;
    QPushButton *pushButton_num8;
    QPushButton *pushButton_num5;
    QPushButton *pushButton_num9;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_num0;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_num1;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_num6;
    QPushButton *pushButton_e;
    QPushButton *pushButton_num4;
    QPushButton *pushButton_sqr;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_log;
    QPushButton *pushButton_num7;
    QLabel *label_calc_info;
    QLineEdit *lineEdit_calc;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tab_graph;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_graph_head;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_graph_vars_hide;
    QPushButton *pushButton_graph_menu_hide;
    QSpacerItem *horizontalSpacer_11;
    QWidget *widget_graph;
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *scrollArea_graph_vars;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    s21::WidgetGraph *widget_graph_graph;
    QWidget *widget_graph_menu;
    QCheckBox *checkBox_graph_menu_axis_x;
    QLineEdit *lineEdit_graph_menu_min_x;
    QLabel *label_graph_menu_axis_x_info;
    QLineEdit *lineEdit_graph_menu_max_x;
    QLabel *label_graph_menu_step_x_info;
    QLineEdit *lineEdit_graph_menu_step_x;
    QCheckBox *checkBox_graph_menu_grid;
    QCheckBox *checkBox_graph_menu_small_grid;
    QCheckBox *checkBox_graph_menu_nums_on_axis;
    QLineEdit *lineEdit_graph_menu_max_y;
    QLineEdit *lineEdit_graph_menu_min_y;
    QLabel *label_graph_menu_step_y_info;
    QLineEdit *lineEdit_graph_menu_step_y;
    QCheckBox *checkBox_graph_menu_axis_y;
    QLabel *label_graph_menu_axis_y_info;
    QPushButton *pushButton_graph_menu_restore;
    QWidget *tab_credit;
    QVBoxLayout *verticalLayout_10;
    QWidget *widget_credit_head;
    QWidget *widget_credit;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_credit_2;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_9;
    QWidget *widget_credit_3;
    QWidget *widget_credit_answer;
    QVBoxLayout *verticalLayout_16;
    QSpacerItem *verticalSpacer_10;
    QLabel *label_credit_answer_month_pay_info;
    QLabel *label_credit_answer_month_pay;
    QSpacerItem *verticalSpacer_11;
    QLabel *label_credit_answer_over_pay_info;
    QLabel *label_credit_answer_over_pay;
    QSpacerItem *verticalSpacer_12;
    QLabel *label_credit_answer_total_pay_info;
    QLabel *label_credit_answer_total_pay;
    QSpacerItem *verticalSpacer_13;
    QPushButton *pushButton_credit_start;
    QLineEdit *lineEdit_credit_input_sum;
    QLineEdit *lineEdit_credit_input_time;
    QLabel *label_credit_input_sum;
    QLabel *label_credit_input_time;
    QLabel *label_credit_input_type;
    QLabel *label_credit_input_sum_unit;
    QComboBox *comboBox_credit_input_time_unit;
    QComboBox *comboBox_credit_input_type;
    QLineEdit *lineEdit_credit_input_rate;
    QLabel *label_credit_input_rate_unit;
    QLabel *label_credit_input_rate;
    QLabel *label_credit_info;
    QSpacerItem *verticalSpacer_14;
    QWidget *tab_deposit;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_deposit_head;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_deposit_head_left;
    QPushButton *pushButton_deposit_list_out_hide;
    QPushButton *pushButton_deposit_list_in_hide;
    QSpacerItem *pushButton_deposit_list_out_hide_2;
    QWidget *widget_deposit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_deposit_left;
    QScrollArea *scrollArea_widget_deposit_list_out;
    QWidget *scrollAreaWidgetContents_5;
    QVBoxLayout *verticalLayout_13;
    QWidget *widget_deposit_2;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_deposit_up;
    QSpacerItem *verticalSpacer_deposit_up_eq_label;
    QWidget *widget_deposit_3;
    QWidget *widget_deposit_answer;
    QVBoxLayout *verticalLayout_15;
    QSpacerItem *verticalSpacer;
    QLabel *label_deposit_answer_rate_info;
    QLabel *label_deposit_answer_rate;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_deposit_answer_tax_info;
    QLabel *label_deposit_answer_tax;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_deposit_answer_sum_info;
    QLabel *label_deposit_answer_sum;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_deposit_start;
    QLineEdit *lineEdit_deposit_input_sum;
    QLineEdit *lineEdit_deposit_input_time;
    QLineEdit *lineEdit_deposit_input_rate;
    QLineEdit *lineEdit_deposit_input_tax;
    QLabel *label_deposit_input_sum;
    QLabel *label_deposit_input_time;
    QLabel *label_deposit_input_rate;
    QLabel *label_deposit_input_tax;
    QLabel *label_deposit_input_pay_unit;
    QLabel *label_deposit_input_capitalisation;
    QCheckBox *checkBox_deposit_input_capitalisation;
    QLabel *label_deposit_input_sum_unit;
    QComboBox *comboBox_deposit_input_time_unit;
    QLabel *label_deposit_input_rate_unit;
    QLabel *label_deposit_input_tax_unit;
    QComboBox *comboBox_deposit_input_pay_unit_unit;
    QLabel *label_deposit_input_date_start;
    QDateEdit *dateEdit_deposit_date_start;
    QLabel *label_deposit_info;
    QSpacerItem *verticalSpacer_deposit_down;
    QScrollArea *scrollArea_widget_deposit_list_in;
    QWidget *scrollAreaWidgetContents_6;
    QVBoxLayout *verticalLayout_14;
    QSpacerItem *horizontalSpacer_deposit_right;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1517, 718);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow {\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(146, 147, 149)\n"
"}\n"
"\n"
"QWidget {\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(42, 43, 46);\n"
"}\n"
"\n"
"QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(95, 99, 104);\n"
"	color: white;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(115, 119, 124);\n"
"	color: white;\n"
"}\n"
"\n"
"QLabel {\n"
"	background-color: rgb(52, 53, 56);\n"
"	color: white;\n"
"}\n"
"\n"
"QLineEdit {\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(52, 53, 56);\n"
"	color: white;\n"
"}\n"
"\n"
"QDateEdit {\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(52, 53, 56);\n"
"	color: white;\n"
"}\n"
" \n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab_calc = new QWidget();
        tab_calc->setObjectName(QString::fromUtf8("tab_calc"));
        tab_calc->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_4 = new QVBoxLayout(tab_calc);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_calc_head = new QWidget(tab_calc);
        widget_calc_head->setObjectName(QString::fromUtf8("widget_calc_head"));
        widget_calc_head->setMinimumSize(QSize(0, 50));
        widget_calc_head->setMaximumSize(QSize(16777215, 50));
        widget_calc_head->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(widget_calc_head);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        horizontalSpacer_4 = new QSpacerItem(400, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        pushButton_calc_var_list_hide = new QPushButton(widget_calc_head);
        pushButton_calc_var_list_hide->setObjectName(QString::fromUtf8("pushButton_calc_var_list_hide"));
        pushButton_calc_var_list_hide->setMinimumSize(QSize(350, 30));
        pushButton_calc_var_list_hide->setMaximumSize(QSize(350, 16777215));

        horizontalLayout_4->addWidget(pushButton_calc_var_list_hide);

        horizontalSpacer_5 = new QSpacerItem(350, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_4->addWidget(widget_calc_head);

        widget_calc = new QWidget(tab_calc);
        widget_calc->setObjectName(QString::fromUtf8("widget_calc"));
        horizontalLayout = new QHBoxLayout(widget_calc);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_calc_vars = new QWidget(widget_calc);
        widget_calc_vars->setObjectName(QString::fromUtf8("widget_calc_vars"));
        widget_calc_vars->setMinimumSize(QSize(400, 0));
        widget_calc_vars->setMaximumSize(QSize(400, 16777215));
        widget_calc_vars->setStyleSheet(QString::fromUtf8(""));
        formLayout = new QFormLayout(widget_calc_vars);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        scrollArea_calc_vars = new QScrollArea(widget_calc_vars);
        scrollArea_calc_vars->setObjectName(QString::fromUtf8("scrollArea_calc_vars"));
        scrollArea_calc_vars->setMinimumSize(QSize(370, 0));
        scrollArea_calc_vars->setMaximumSize(QSize(370, 16777215));
        scrollArea_calc_vars->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 550, 491));
        scrollAreaWidgetContents->setMinimumSize(QSize(550, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(550, 16777215));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea_calc_vars->setWidget(scrollAreaWidgetContents);

        formLayout->setWidget(0, QFormLayout::LabelRole, scrollArea_calc_vars);


        horizontalLayout->addWidget(widget_calc_vars);

        widget_calc_2 = new QWidget(widget_calc);
        widget_calc_2->setObjectName(QString::fromUtf8("widget_calc_2"));
        widget_calc_2->setMinimumSize(QSize(705, 387));
        widget_calc_2->setMaximumSize(QSize(705, 9999999));
        widget_calc_2->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_6 = new QVBoxLayout(widget_calc_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        widget_calc_3 = new QWidget(widget_calc_2);
        widget_calc_3->setObjectName(QString::fromUtf8("widget_calc_3"));
        widget_calc_3->setMinimumSize(QSize(685, 340));
        widget_calc_3->setMaximumSize(QSize(685, 340));
        widget_calc_3->setStyleSheet(QString::fromUtf8(""));
        pushButton_acos = new QPushButton(widget_calc_3);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setGeometry(QRect(5, 120, 91, 37));
        pushButton_acos->setMinimumSize(QSize(91, 37));
        pushButton_acos->setMaximumSize(QSize(91, 37));
        pushButton_tan = new QPushButton(widget_calc_3);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        pushButton_tan->setGeometry(QRect(102, 206, 91, 37));
        pushButton_tan->setMinimumSize(QSize(91, 37));
        pushButton_tan->setMaximumSize(QSize(91, 37));
        pushButton_eq = new QPushButton(widget_calc_3);
        pushButton_eq->setObjectName(QString::fromUtf8("pushButton_eq"));
        pushButton_eq->setGeometry(QRect(490, 292, 91, 37));
        pushButton_eq->setMinimumSize(QSize(91, 37));
        pushButton_eq->setMaximumSize(QSize(91, 37));
        pushButton_eq->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(117, 148, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(165, 174, 201);\n"
"}"));
        pushButton_bracket_open = new QPushButton(widget_calc_3);
        pushButton_bracket_open->setObjectName(QString::fromUtf8("pushButton_bracket_open"));
        pushButton_bracket_open->setGeometry(QRect(296, 120, 91, 37));
        pushButton_bracket_open->setMinimumSize(QSize(91, 37));
        pushButton_bracket_open->setMaximumSize(QSize(91, 37));
        pushButton_bracket_close = new QPushButton(widget_calc_3);
        pushButton_bracket_close->setObjectName(QString::fromUtf8("pushButton_bracket_close"));
        pushButton_bracket_close->setGeometry(QRect(393, 120, 91, 37));
        pushButton_bracket_close->setMinimumSize(QSize(91, 37));
        pushButton_bracket_close->setMaximumSize(QSize(91, 37));
        pushButton_num2 = new QPushButton(widget_calc_3);
        pushButton_num2->setObjectName(QString::fromUtf8("pushButton_num2"));
        pushButton_num2->setGeometry(QRect(393, 249, 91, 37));
        pushButton_num2->setMinimumSize(QSize(91, 37));
        pushButton_num2->setMaximumSize(QSize(91, 37));
        pushButton_num2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(75, 79, 84);\n"
"	color: white;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(85, 89,94);\n"
"	color: white;\n"
"}\n"
"\n"
"QLabel {\n"
"	background-color: rgb(52, 53, 56);\n"
"	color: white;\n"
"}"));
        pushButton_sqrt = new QPushButton(widget_calc_3);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setGeometry(QRect(102, 292, 91, 37));
        pushButton_sqrt->setMinimumSize(QSize(91, 37));
        pushButton_sqrt->setMaximumSize(QSize(91, 37));
        pushButton_asin = new QPushButton(widget_calc_3);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setGeometry(QRect(5, 163, 91, 37));
        pushButton_asin->setMinimumSize(QSize(91, 37));
        pushButton_asin->setMaximumSize(QSize(91, 37));
        pushButton_fact = new QPushButton(widget_calc_3);
        pushButton_fact->setObjectName(QString::fromUtf8("pushButton_fact"));
        pushButton_fact->setGeometry(QRect(199, 249, 91, 37));
        pushButton_fact->setMinimumSize(QSize(91, 37));
        pushButton_fact->setMaximumSize(QSize(91, 37));
        pushButton_comma = new QPushButton(widget_calc_3);
        pushButton_comma->setObjectName(QString::fromUtf8("pushButton_comma"));
        pushButton_comma->setGeometry(QRect(199, 292, 91, 37));
        pushButton_comma->setMinimumSize(QSize(91, 37));
        pushButton_comma->setMaximumSize(QSize(91, 37));
        pushButton_comma->setStyleSheet(QString::fromUtf8(""));
        pushButton_dot = new QPushButton(widget_calc_3);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(393, 292, 91, 37));
        pushButton_dot->setMinimumSize(QSize(91, 37));
        pushButton_dot->setMaximumSize(QSize(91, 37));
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(75, 79, 84);\n"
"	color: white;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(85, 89,94);\n"
"	color: white;\n"
"}\n"
"\n"
"QLabel {\n"
"	background-color: rgb(52, 53, 56);\n"
"	color: white;\n"
"}"));
        pushButton_num3 = new QPushButton(widget_calc_3);
        pushButton_num3->setObjectName(QString::fromUtf8("pushButton_num3"));
        pushButton_num3->setGeometry(QRect(490, 249, 91, 37));
        pushButton_num3->setMinimumSize(QSize(91, 37));
        pushButton_num3->setMaximumSize(QSize(91, 37));
        pushButton_num3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(75, 79, 84);\n"
"	color: white;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(85, 89,94);\n"
"	color: white;\n"
"}\n"
"\n"
"QLabel {\n"
"	background-color: rgb(52, 53, 56);\n"
"	color: white;\n"
"}"));
        pushButton_clear_all = new QPushButton(widget_calc_3);
        pushButton_clear_all->setObjectName(QString::fromUtf8("pushButton_clear_all"));
        pushButton_clear_all->setGeometry(QRect(490, 120, 91, 37));
        pushButton_clear_all->setMinimumSize(QSize(91, 37));
        pushButton_clear_all->setMaximumSize(QSize(91, 37));
        pushButton_cos = new QPushButton(widget_calc_3);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(102, 120, 91, 37));
        pushButton_cos->setMinimumSize(QSize(91, 37));
        pushButton_cos->setMaximumSize(QSize(91, 37));
        pushButton_mul = new QPushButton(widget_calc_3);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
        pushButton_mul->setGeometry(QRect(587, 206, 91, 37));
        pushButton_mul->setMinimumSize(QSize(91, 37));
        pushButton_mul->setMaximumSize(QSize(91, 37));
        pushButton_minus = new QPushButton(widget_calc_3);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setGeometry(QRect(587, 249, 91, 37));
        pushButton_minus->setMinimumSize(QSize(91, 37));
        pushButton_minus->setMaximumSize(QSize(91, 37));
        pushButton_pow = new QPushButton(widget_calc_3);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
        pushButton_pow->setGeometry(QRect(199, 206, 91, 37));
        pushButton_pow->setMinimumSize(QSize(91, 37));
        pushButton_pow->setMaximumSize(QSize(91, 37));
        pushButton_atan = new QPushButton(widget_calc_3);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setGeometry(QRect(5, 206, 91, 37));
        pushButton_atan->setMinimumSize(QSize(91, 37));
        pushButton_atan->setMaximumSize(QSize(91, 37));
        pushButton_div = new QPushButton(widget_calc_3);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(587, 163, 91, 37));
        pushButton_div->setMinimumSize(QSize(91, 37));
        pushButton_div->setMaximumSize(QSize(91, 37));
        pushButton_num8 = new QPushButton(widget_calc_3);
        pushButton_num8->setObjectName(QString::fromUtf8("pushButton_num8"));
        pushButton_num8->setGeometry(QRect(393, 163, 91, 37));
        pushButton_num8->setMinimumSize(QSize(91, 37));
        pushButton_num8->setMaximumSize(QSize(91, 37));
        pushButton_num8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(75, 79, 84);\n"
"	color: white;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(85, 89,94);\n"
"	color: white;\n"
"}\n"
"\n"
"QLabel {\n"
"	background-color: rgb(52, 53, 56);\n"
"	color: white;\n"
"}"));
        pushButton_num5 = new QPushButton(widget_calc_3);
        pushButton_num5->setObjectName(QString::fromUtf8("pushButton_num5"));
        pushButton_num5->setGeometry(QRect(393, 206, 91, 37));
        pushButton_num5->setMinimumSize(QSize(91, 37));
        pushButton_num5->setMaximumSize(QSize(91, 37));
        pushButton_num5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(75, 79, 84);\n"
"	color: white;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(85, 89,94);\n"
"	color: white;\n"
"}\n"
"\n"
"QLabel {\n"
"	background-color: rgb(52, 53, 56);\n"
"	color: white;\n"
"}"));
        pushButton_num9 = new QPushButton(widget_calc_3);
        pushButton_num9->setObjectName(QString::fromUtf8("pushButton_num9"));
        pushButton_num9->setGeometry(QRect(490, 163, 91, 37));
        pushButton_num9->setMinimumSize(QSize(91, 37));
        pushButton_num9->setMaximumSize(QSize(91, 37));
        pushButton_num9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(75, 79, 84);\n"
"	color: white;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(85, 89,94);\n"
"	color: white;\n"
"}\n"
"\n"
"QLabel {\n"
"	background-color: rgb(52, 53, 56);\n"
"	color: white;\n"
"}"));
        pushButton_ln = new QPushButton(widget_calc_3);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setGeometry(QRect(5, 249, 91, 37));
        pushButton_ln->setMinimumSize(QSize(91, 37));
        pushButton_ln->setMaximumSize(QSize(91, 37));
        pushButton_sin = new QPushButton(widget_calc_3);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(102, 163, 91, 37));
        pushButton_sin->setMinimumSize(QSize(91, 37));
        pushButton_sin->setMaximumSize(QSize(91, 37));
        pushButton_num0 = new QPushButton(widget_calc_3);
        pushButton_num0->setObjectName(QString::fromUtf8("pushButton_num0"));
        pushButton_num0->setGeometry(QRect(296, 292, 91, 37));
        pushButton_num0->setMinimumSize(QSize(91, 37));
        pushButton_num0->setMaximumSize(QSize(91, 37));
        pushButton_num0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(75, 79, 84);\n"
"	color: white;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(85, 89,94);\n"
"	color: white;\n"
"}\n"
"\n"
"QLabel {\n"
"	background-color: rgb(52, 53, 56);\n"
"	color: white;\n"
"}"));
        pushButton_clear = new QPushButton(widget_calc_3);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(587, 120, 91, 37));
        pushButton_clear->setMinimumSize(QSize(91, 37));
        pushButton_clear->setMaximumSize(QSize(91, 37));
        pushButton_num1 = new QPushButton(widget_calc_3);
        pushButton_num1->setObjectName(QString::fromUtf8("pushButton_num1"));
        pushButton_num1->setGeometry(QRect(296, 249, 91, 37));
        pushButton_num1->setMinimumSize(QSize(91, 37));
        pushButton_num1->setMaximumSize(QSize(91, 37));
        pushButton_num1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(75, 79, 84);\n"
"	color: white;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(85, 89,94);\n"
"	color: white;\n"
"}\n"
"\n"
"QLabel {\n"
"	background-color: rgb(52, 53, 56);\n"
"	color: white;\n"
"}"));
        pushButton_mod = new QPushButton(widget_calc_3);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(5, 292, 91, 37));
        pushButton_mod->setMinimumSize(QSize(91, 37));
        pushButton_mod->setMaximumSize(QSize(91, 37));
        pushButton_num6 = new QPushButton(widget_calc_3);
        pushButton_num6->setObjectName(QString::fromUtf8("pushButton_num6"));
        pushButton_num6->setGeometry(QRect(490, 206, 91, 37));
        pushButton_num6->setMinimumSize(QSize(91, 37));
        pushButton_num6->setMaximumSize(QSize(91, 37));
        pushButton_num6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(75, 79, 84);\n"
"	color: white;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(85, 89,94);\n"
"	color: white;\n"
"}\n"
"\n"
"QLabel {\n"
"	background-color: rgb(52, 53, 56);\n"
"	color: white;\n"
"}"));
        pushButton_e = new QPushButton(widget_calc_3);
        pushButton_e->setObjectName(QString::fromUtf8("pushButton_e"));
        pushButton_e->setGeometry(QRect(199, 120, 91, 37));
        pushButton_e->setMinimumSize(QSize(91, 37));
        pushButton_e->setMaximumSize(QSize(91, 37));
        pushButton_num4 = new QPushButton(widget_calc_3);
        pushButton_num4->setObjectName(QString::fromUtf8("pushButton_num4"));
        pushButton_num4->setGeometry(QRect(296, 206, 91, 37));
        pushButton_num4->setMinimumSize(QSize(91, 37));
        pushButton_num4->setMaximumSize(QSize(91, 37));
        pushButton_num4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(75, 79, 84);\n"
"	color: white;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(85, 89,94);\n"
"	color: white;\n"
"}\n"
"\n"
"QLabel {\n"
"	background-color: rgb(52, 53, 56);\n"
"	color: white;\n"
"}"));
        pushButton_sqr = new QPushButton(widget_calc_3);
        pushButton_sqr->setObjectName(QString::fromUtf8("pushButton_sqr"));
        pushButton_sqr->setGeometry(QRect(199, 163, 91, 37));
        pushButton_sqr->setMinimumSize(QSize(91, 37));
        pushButton_sqr->setMaximumSize(QSize(91, 37));
        pushButton_plus = new QPushButton(widget_calc_3);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(587, 292, 91, 37));
        pushButton_plus->setMinimumSize(QSize(91, 37));
        pushButton_plus->setMaximumSize(QSize(91, 37));
        pushButton_plus->setStyleSheet(QString::fromUtf8(""));
        pushButton_log = new QPushButton(widget_calc_3);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(102, 249, 91, 37));
        pushButton_log->setMinimumSize(QSize(91, 37));
        pushButton_log->setMaximumSize(QSize(91, 37));
        pushButton_num7 = new QPushButton(widget_calc_3);
        pushButton_num7->setObjectName(QString::fromUtf8("pushButton_num7"));
        pushButton_num7->setGeometry(QRect(296, 163, 91, 37));
        pushButton_num7->setMinimumSize(QSize(91, 37));
        pushButton_num7->setMaximumSize(QSize(91, 37));
        pushButton_num7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(75, 79, 84);\n"
"	color: white;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(85, 89,94);\n"
"	color: white;\n"
"}\n"
"\n"
"QLabel {\n"
"	background-color: rgb(52, 53, 56);\n"
"	color: white;\n"
"}"));
        label_calc_info = new QLabel(widget_calc_3);
        label_calc_info->setObjectName(QString::fromUtf8("label_calc_info"));
        label_calc_info->setGeometry(QRect(5, 83, 673, 30));
        label_calc_info->setMinimumSize(QSize(1, 30));
        label_calc_info->setMaximumSize(QSize(16777215, 30));
        label_calc_info->setStyleSheet(QString::fromUtf8(""));
        label_calc_info->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_calc = new QLineEdit(widget_calc_3);
        lineEdit_calc->setObjectName(QString::fromUtf8("lineEdit_calc"));
        lineEdit_calc->setGeometry(QRect(5, 10, 673, 70));
        lineEdit_calc->setMinimumSize(QSize(1, 70));
        lineEdit_calc->setStyleSheet(QString::fromUtf8(""));
        lineEdit_calc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_6->addWidget(widget_calc_3);


        horizontalLayout->addWidget(widget_calc_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_4->addWidget(widget_calc);

        tabWidget->addTab(tab_calc, QString());
        tab_graph = new QWidget();
        tab_graph->setObjectName(QString::fromUtf8("tab_graph"));
        verticalLayout_5 = new QVBoxLayout(tab_graph);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget_graph_head = new QWidget(tab_graph);
        widget_graph_head->setObjectName(QString::fromUtf8("widget_graph_head"));
        widget_graph_head->setMinimumSize(QSize(0, 50));
        widget_graph_head->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_7 = new QHBoxLayout(widget_graph_head);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);

        pushButton_graph_vars_hide = new QPushButton(widget_graph_head);
        pushButton_graph_vars_hide->setObjectName(QString::fromUtf8("pushButton_graph_vars_hide"));
        pushButton_graph_vars_hide->setMinimumSize(QSize(345, 30));
        pushButton_graph_vars_hide->setMaximumSize(QSize(345, 30));

        horizontalLayout_7->addWidget(pushButton_graph_vars_hide);

        pushButton_graph_menu_hide = new QPushButton(widget_graph_head);
        pushButton_graph_menu_hide->setObjectName(QString::fromUtf8("pushButton_graph_menu_hide"));
        pushButton_graph_menu_hide->setMinimumSize(QSize(345, 30));
        pushButton_graph_menu_hide->setMaximumSize(QSize(345, 30));

        horizontalLayout_7->addWidget(pushButton_graph_menu_hide);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);


        verticalLayout_5->addWidget(widget_graph_head);

        widget_graph = new QWidget(tab_graph);
        widget_graph->setObjectName(QString::fromUtf8("widget_graph"));
        horizontalLayout_3 = new QHBoxLayout(widget_graph);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        scrollArea_graph_vars = new QScrollArea(widget_graph);
        scrollArea_graph_vars->setObjectName(QString::fromUtf8("scrollArea_graph_vars"));
        scrollArea_graph_vars->setMinimumSize(QSize(370, 0));
        scrollArea_graph_vars->setMaximumSize(QSize(370, 16777215));
        scrollArea_graph_vars->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 276, 523));
        scrollAreaWidgetContents_2->setMinimumSize(QSize(276, 0));
        scrollAreaWidgetContents_2->setMaximumSize(QSize(276, 16777215));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        scrollArea_graph_vars->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_3->addWidget(scrollArea_graph_vars);

        widget_graph_graph = new s21::WidgetGraph(widget_graph);
        widget_graph_graph->setObjectName(QString::fromUtf8("widget_graph_graph"));
        widget_graph_graph->setMinimumSize(QSize(705, 387));
        widget_graph_graph->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(0, 0, 0);\n"
"}"));

        horizontalLayout_3->addWidget(widget_graph_graph);

        widget_graph_menu = new QWidget(widget_graph);
        widget_graph_menu->setObjectName(QString::fromUtf8("widget_graph_menu"));
        widget_graph_menu->setMinimumSize(QSize(370, 0));
        widget_graph_menu->setMaximumSize(QSize(370, 16777215));
        checkBox_graph_menu_axis_x = new QCheckBox(widget_graph_menu);
        checkBox_graph_menu_axis_x->setObjectName(QString::fromUtf8("checkBox_graph_menu_axis_x"));
        checkBox_graph_menu_axis_x->setGeometry(QRect(5, 120, 361, 41));
        lineEdit_graph_menu_min_x = new QLineEdit(widget_graph_menu);
        lineEdit_graph_menu_min_x->setObjectName(QString::fromUtf8("lineEdit_graph_menu_min_x"));
        lineEdit_graph_menu_min_x->setGeometry(QRect(5, 165, 151, 41));
        label_graph_menu_axis_x_info = new QLabel(widget_graph_menu);
        label_graph_menu_axis_x_info->setObjectName(QString::fromUtf8("label_graph_menu_axis_x_info"));
        label_graph_menu_axis_x_info->setGeometry(QRect(155, 165, 61, 41));
        lineEdit_graph_menu_max_x = new QLineEdit(widget_graph_menu);
        lineEdit_graph_menu_max_x->setObjectName(QString::fromUtf8("lineEdit_graph_menu_max_x"));
        lineEdit_graph_menu_max_x->setGeometry(QRect(215, 165, 151, 41));
        label_graph_menu_step_x_info = new QLabel(widget_graph_menu);
        label_graph_menu_step_x_info->setObjectName(QString::fromUtf8("label_graph_menu_step_x_info"));
        label_graph_menu_step_x_info->setGeometry(QRect(10, 210, 61, 41));
        lineEdit_graph_menu_step_x = new QLineEdit(widget_graph_menu);
        lineEdit_graph_menu_step_x->setObjectName(QString::fromUtf8("lineEdit_graph_menu_step_x"));
        lineEdit_graph_menu_step_x->setGeometry(QRect(70, 210, 61, 41));
        checkBox_graph_menu_grid = new QCheckBox(widget_graph_menu);
        checkBox_graph_menu_grid->setObjectName(QString::fromUtf8("checkBox_graph_menu_grid"));
        checkBox_graph_menu_grid->setGeometry(QRect(5, 10, 175, 41));
        checkBox_graph_menu_small_grid = new QCheckBox(widget_graph_menu);
        checkBox_graph_menu_small_grid->setObjectName(QString::fromUtf8("checkBox_graph_menu_small_grid"));
        checkBox_graph_menu_small_grid->setGeometry(QRect(190, 10, 175, 41));
        checkBox_graph_menu_nums_on_axis = new QCheckBox(widget_graph_menu);
        checkBox_graph_menu_nums_on_axis->setObjectName(QString::fromUtf8("checkBox_graph_menu_nums_on_axis"));
        checkBox_graph_menu_nums_on_axis->setGeometry(QRect(5, 60, 175, 41));
        lineEdit_graph_menu_max_y = new QLineEdit(widget_graph_menu);
        lineEdit_graph_menu_max_y->setObjectName(QString::fromUtf8("lineEdit_graph_menu_max_y"));
        lineEdit_graph_menu_max_y->setGeometry(QRect(215, 310, 151, 41));
        lineEdit_graph_menu_min_y = new QLineEdit(widget_graph_menu);
        lineEdit_graph_menu_min_y->setObjectName(QString::fromUtf8("lineEdit_graph_menu_min_y"));
        lineEdit_graph_menu_min_y->setGeometry(QRect(5, 310, 151, 41));
        label_graph_menu_step_y_info = new QLabel(widget_graph_menu);
        label_graph_menu_step_y_info->setObjectName(QString::fromUtf8("label_graph_menu_step_y_info"));
        label_graph_menu_step_y_info->setGeometry(QRect(10, 355, 61, 41));
        lineEdit_graph_menu_step_y = new QLineEdit(widget_graph_menu);
        lineEdit_graph_menu_step_y->setObjectName(QString::fromUtf8("lineEdit_graph_menu_step_y"));
        lineEdit_graph_menu_step_y->setGeometry(QRect(70, 355, 61, 41));
        checkBox_graph_menu_axis_y = new QCheckBox(widget_graph_menu);
        checkBox_graph_menu_axis_y->setObjectName(QString::fromUtf8("checkBox_graph_menu_axis_y"));
        checkBox_graph_menu_axis_y->setGeometry(QRect(5, 265, 361, 41));
        label_graph_menu_axis_y_info = new QLabel(widget_graph_menu);
        label_graph_menu_axis_y_info->setObjectName(QString::fromUtf8("label_graph_menu_axis_y_info"));
        label_graph_menu_axis_y_info->setGeometry(QRect(155, 310, 61, 41));
        pushButton_graph_menu_restore = new QPushButton(widget_graph_menu);
        pushButton_graph_menu_restore->setObjectName(QString::fromUtf8("pushButton_graph_menu_restore"));
        pushButton_graph_menu_restore->setGeometry(QRect(10, 410, 351, 41));
        pushButton_graph_menu_restore->setMinimumSize(QSize(0, 0));
        pushButton_graph_menu_restore->setMaximumSize(QSize(999, 9999));

        horizontalLayout_3->addWidget(widget_graph_menu);


        verticalLayout_5->addWidget(widget_graph);

        tabWidget->addTab(tab_graph, QString());
        tab_credit = new QWidget();
        tab_credit->setObjectName(QString::fromUtf8("tab_credit"));
        verticalLayout_10 = new QVBoxLayout(tab_credit);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        widget_credit_head = new QWidget(tab_credit);
        widget_credit_head->setObjectName(QString::fromUtf8("widget_credit_head"));
        widget_credit_head->setMinimumSize(QSize(0, 50));
        widget_credit_head->setMaximumSize(QSize(16777215, 50));

        verticalLayout_10->addWidget(widget_credit_head);

        widget_credit = new QWidget(tab_credit);
        widget_credit->setObjectName(QString::fromUtf8("widget_credit"));
        horizontalLayout_5 = new QHBoxLayout(widget_credit);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        widget_credit_2 = new QWidget(widget_credit);
        widget_credit_2->setObjectName(QString::fromUtf8("widget_credit_2"));
        widget_credit_2->setMinimumSize(QSize(705, 470));
        widget_credit_2->setMaximumSize(QSize(705, 16777215));
        widget_credit_2->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(42, 43, 46);\n"
"}\n"
"\n"
"QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(95, 99, 104);\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(115, 119, 124);\n"
"}\n"
"\n"
"QLineEdit {\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(52, 53, 56);\n"
"}\n"
"\n"
"QLabel {\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(52, 53, 56);\n"
"}\n"
"\n"
""));
        verticalLayout_8 = new QVBoxLayout(widget_credit_2);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_8);

        verticalSpacer_9 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_8->addItem(verticalSpacer_9);

        widget_credit_3 = new QWidget(widget_credit_2);
        widget_credit_3->setObjectName(QString::fromUtf8("widget_credit_3"));
        widget_credit_3->setMinimumSize(QSize(685, 387));
        widget_credit_3->setMaximumSize(QSize(685, 387));
        widget_credit_3->setStyleSheet(QString::fromUtf8(""));
        widget_credit_answer = new QWidget(widget_credit_3);
        widget_credit_answer->setObjectName(QString::fromUtf8("widget_credit_answer"));
        widget_credit_answer->setGeometry(QRect(373, 14, 300, 359));
        widget_credit_answer->setMinimumSize(QSize(300, 359));
        widget_credit_answer->setMaximumSize(QSize(16777215, 359));
        verticalLayout_16 = new QVBoxLayout(widget_credit_answer);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_10);

        label_credit_answer_month_pay_info = new QLabel(widget_credit_answer);
        label_credit_answer_month_pay_info->setObjectName(QString::fromUtf8("label_credit_answer_month_pay_info"));
        label_credit_answer_month_pay_info->setMinimumSize(QSize(0, 21));
        label_credit_answer_month_pay_info->setMaximumSize(QSize(16777215, 21));
        label_credit_answer_month_pay_info->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_credit_answer_month_pay_info);

        label_credit_answer_month_pay = new QLabel(widget_credit_answer);
        label_credit_answer_month_pay->setObjectName(QString::fromUtf8("label_credit_answer_month_pay"));
        label_credit_answer_month_pay->setMinimumSize(QSize(0, 41));
        label_credit_answer_month_pay->setMaximumSize(QSize(16777215, 41));
        label_credit_answer_month_pay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_16->addWidget(label_credit_answer_month_pay);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_11);

        label_credit_answer_over_pay_info = new QLabel(widget_credit_answer);
        label_credit_answer_over_pay_info->setObjectName(QString::fromUtf8("label_credit_answer_over_pay_info"));
        label_credit_answer_over_pay_info->setMinimumSize(QSize(0, 21));
        label_credit_answer_over_pay_info->setMaximumSize(QSize(16777215, 21));
        label_credit_answer_over_pay_info->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_credit_answer_over_pay_info);

        label_credit_answer_over_pay = new QLabel(widget_credit_answer);
        label_credit_answer_over_pay->setObjectName(QString::fromUtf8("label_credit_answer_over_pay"));
        label_credit_answer_over_pay->setMinimumSize(QSize(0, 41));
        label_credit_answer_over_pay->setMaximumSize(QSize(16777215, 41));
        label_credit_answer_over_pay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_16->addWidget(label_credit_answer_over_pay);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_12);

        label_credit_answer_total_pay_info = new QLabel(widget_credit_answer);
        label_credit_answer_total_pay_info->setObjectName(QString::fromUtf8("label_credit_answer_total_pay_info"));
        label_credit_answer_total_pay_info->setMinimumSize(QSize(0, 21));
        label_credit_answer_total_pay_info->setMaximumSize(QSize(16777215, 21));
        label_credit_answer_total_pay_info->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_credit_answer_total_pay_info);

        label_credit_answer_total_pay = new QLabel(widget_credit_answer);
        label_credit_answer_total_pay->setObjectName(QString::fromUtf8("label_credit_answer_total_pay"));
        label_credit_answer_total_pay->setMinimumSize(QSize(0, 41));
        label_credit_answer_total_pay->setMaximumSize(QSize(16777215, 41));
        label_credit_answer_total_pay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_16->addWidget(label_credit_answer_total_pay);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_13);

        pushButton_credit_start = new QPushButton(widget_credit_answer);
        pushButton_credit_start->setObjectName(QString::fromUtf8("pushButton_credit_start"));
        pushButton_credit_start->setMinimumSize(QSize(0, 21));
        pushButton_credit_start->setMaximumSize(QSize(9999999, 21));
        pushButton_credit_start->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(117, 148, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(165, 174, 201);\n"
"}"));

        verticalLayout_16->addWidget(pushButton_credit_start);

        lineEdit_credit_input_sum = new QLineEdit(widget_credit_3);
        lineEdit_credit_input_sum->setObjectName(QString::fromUtf8("lineEdit_credit_input_sum"));
        lineEdit_credit_input_sum->setGeometry(QRect(180, 14, 151, 41));
        lineEdit_credit_input_sum->setMinimumSize(QSize(0, 41));
        lineEdit_credit_input_sum->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_credit_input_time = new QLineEdit(widget_credit_3);
        lineEdit_credit_input_time->setObjectName(QString::fromUtf8("lineEdit_credit_input_time"));
        lineEdit_credit_input_time->setGeometry(QRect(180, 67, 83, 41));
        lineEdit_credit_input_time->setMinimumSize(QSize(0, 41));
        lineEdit_credit_input_time->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_credit_input_sum = new QLabel(widget_credit_3);
        label_credit_input_sum->setObjectName(QString::fromUtf8("label_credit_input_sum"));
        label_credit_input_sum->setGeometry(QRect(10, 14, 161, 41));
        label_credit_input_sum->setAlignment(Qt::AlignCenter);
        label_credit_input_time = new QLabel(widget_credit_3);
        label_credit_input_time->setObjectName(QString::fromUtf8("label_credit_input_time"));
        label_credit_input_time->setGeometry(QRect(10, 67, 161, 41));
        label_credit_input_time->setAlignment(Qt::AlignCenter);
        label_credit_input_type = new QLabel(widget_credit_3);
        label_credit_input_type->setObjectName(QString::fromUtf8("label_credit_input_type"));
        label_credit_input_type->setGeometry(QRect(10, 173, 161, 41));
        label_credit_input_type->setAlignment(Qt::AlignCenter);
        label_credit_input_sum_unit = new QLabel(widget_credit_3);
        label_credit_input_sum_unit->setObjectName(QString::fromUtf8("label_credit_input_sum_unit"));
        label_credit_input_sum_unit->setGeometry(QRect(330, 14, 31, 41));
        label_credit_input_sum_unit->setAlignment(Qt::AlignCenter);
        comboBox_credit_input_time_unit = new QComboBox(widget_credit_3);
        comboBox_credit_input_time_unit->addItem(QString());
        comboBox_credit_input_time_unit->addItem(QString());
        comboBox_credit_input_time_unit->setObjectName(QString::fromUtf8("comboBox_credit_input_time_unit"));
        comboBox_credit_input_time_unit->setGeometry(QRect(262, 67, 101, 41));
        comboBox_credit_input_time_unit->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 53, 56);"));
        comboBox_credit_input_type = new QComboBox(widget_credit_3);
        comboBox_credit_input_type->addItem(QString());
        comboBox_credit_input_type->addItem(QString());
        comboBox_credit_input_type->setObjectName(QString::fromUtf8("comboBox_credit_input_type"));
        comboBox_credit_input_type->setGeometry(QRect(180, 173, 181, 41));
        comboBox_credit_input_type->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 53, 56);"));
        lineEdit_credit_input_rate = new QLineEdit(widget_credit_3);
        lineEdit_credit_input_rate->setObjectName(QString::fromUtf8("lineEdit_credit_input_rate"));
        lineEdit_credit_input_rate->setGeometry(QRect(180, 120, 151, 41));
        lineEdit_credit_input_rate->setMinimumSize(QSize(0, 41));
        lineEdit_credit_input_rate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_credit_input_rate_unit = new QLabel(widget_credit_3);
        label_credit_input_rate_unit->setObjectName(QString::fromUtf8("label_credit_input_rate_unit"));
        label_credit_input_rate_unit->setGeometry(QRect(330, 120, 31, 41));
        label_credit_input_rate_unit->setAlignment(Qt::AlignCenter);
        label_credit_input_rate = new QLabel(widget_credit_3);
        label_credit_input_rate->setObjectName(QString::fromUtf8("label_credit_input_rate"));
        label_credit_input_rate->setGeometry(QRect(10, 120, 161, 41));
        label_credit_input_rate->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(widget_credit_3);

        label_credit_info = new QLabel(widget_credit_2);
        label_credit_info->setObjectName(QString::fromUtf8("label_credit_info"));
        label_credit_info->setMinimumSize(QSize(1, 30));
        label_credit_info->setMaximumSize(QSize(16777215, 30));
        label_credit_info->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 53, 56);"));
        label_credit_info->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_8->addWidget(label_credit_info);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_14);


        horizontalLayout_5->addWidget(widget_credit_2);


        verticalLayout_10->addWidget(widget_credit);

        tabWidget->addTab(tab_credit, QString());
        tab_deposit = new QWidget();
        tab_deposit->setObjectName(QString::fromUtf8("tab_deposit"));
        verticalLayout_9 = new QVBoxLayout(tab_deposit);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        widget_deposit_head = new QWidget(tab_deposit);
        widget_deposit_head->setObjectName(QString::fromUtf8("widget_deposit_head"));
        widget_deposit_head->setMinimumSize(QSize(0, 50));
        widget_deposit_head->setMaximumSize(QSize(16777215, 50));
        widget_deposit_head->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(42, 43, 46);\n"
"}\n"
"\n"
"QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(95, 99, 104);\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(115, 119, 124);\n"
"}"));
        horizontalLayout_6 = new QHBoxLayout(widget_deposit_head);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_deposit_head_left = new QSpacerItem(393, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_deposit_head_left);

        pushButton_deposit_list_out_hide = new QPushButton(widget_deposit_head);
        pushButton_deposit_list_out_hide->setObjectName(QString::fromUtf8("pushButton_deposit_list_out_hide"));
        pushButton_deposit_list_out_hide->setMinimumSize(QSize(345, 30));
        pushButton_deposit_list_out_hide->setMaximumSize(QSize(345, 16777215));

        horizontalLayout_6->addWidget(pushButton_deposit_list_out_hide);

        pushButton_deposit_list_in_hide = new QPushButton(widget_deposit_head);
        pushButton_deposit_list_in_hide->setObjectName(QString::fromUtf8("pushButton_deposit_list_in_hide"));
        pushButton_deposit_list_in_hide->setMinimumSize(QSize(345, 30));
        pushButton_deposit_list_in_hide->setMaximumSize(QSize(345, 16777215));

        horizontalLayout_6->addWidget(pushButton_deposit_list_in_hide);

        pushButton_deposit_list_out_hide_2 = new QSpacerItem(392, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(pushButton_deposit_list_out_hide_2);


        verticalLayout_9->addWidget(widget_deposit_head);

        widget_deposit = new QWidget(tab_deposit);
        widget_deposit->setObjectName(QString::fromUtf8("widget_deposit"));
        widget_deposit->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(42, 43, 46);\n"
"}\n"
"\n"
"QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(95, 99, 104);\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(115, 119, 124);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widget_deposit);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_deposit_left = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_deposit_left);

        scrollArea_widget_deposit_list_out = new QScrollArea(widget_deposit);
        scrollArea_widget_deposit_list_out->setObjectName(QString::fromUtf8("scrollArea_widget_deposit_list_out"));
        scrollArea_widget_deposit_list_out->setMinimumSize(QSize(280, 0));
        scrollArea_widget_deposit_list_out->setMaximumSize(QSize(306, 16777215));
        scrollArea_widget_deposit_list_out->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 276, 523));
        scrollAreaWidgetContents_5->setMinimumSize(QSize(276, 0));
        scrollAreaWidgetContents_5->setMaximumSize(QSize(276, 16777215));
        verticalLayout_13 = new QVBoxLayout(scrollAreaWidgetContents_5);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        scrollArea_widget_deposit_list_out->setWidget(scrollAreaWidgetContents_5);

        horizontalLayout_2->addWidget(scrollArea_widget_deposit_list_out);

        widget_deposit_2 = new QWidget(widget_deposit);
        widget_deposit_2->setObjectName(QString::fromUtf8("widget_deposit_2"));
        widget_deposit_2->setMinimumSize(QSize(705, 470));
        widget_deposit_2->setMaximumSize(QSize(705, 16777215));
        widget_deposit_2->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(42, 43, 46);\n"
"}\n"
"\n"
"QPushButton {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(95, 99, 104);\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	border-radius: 5px;\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(115, 119, 124);\n"
"}\n"
"\n"
"QLineEdit {\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(52, 53, 56);\n"
"}\n"
"\n"
"QLabel {\n"
"	border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(52, 53, 56);\n"
"}\n"
"\n"
""));
        verticalLayout_7 = new QVBoxLayout(widget_deposit_2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer_deposit_up = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_deposit_up);

        verticalSpacer_deposit_up_eq_label = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_deposit_up_eq_label);

        widget_deposit_3 = new QWidget(widget_deposit_2);
        widget_deposit_3->setObjectName(QString::fromUtf8("widget_deposit_3"));
        widget_deposit_3->setMinimumSize(QSize(685, 387));
        widget_deposit_3->setMaximumSize(QSize(685, 387));
        widget_deposit_3->setStyleSheet(QString::fromUtf8(""));
        widget_deposit_answer = new QWidget(widget_deposit_3);
        widget_deposit_answer->setObjectName(QString::fromUtf8("widget_deposit_answer"));
        widget_deposit_answer->setGeometry(QRect(373, 14, 300, 359));
        widget_deposit_answer->setMinimumSize(QSize(300, 359));
        widget_deposit_answer->setMaximumSize(QSize(16777215, 359));
        verticalLayout_15 = new QVBoxLayout(widget_deposit_answer);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer);

        label_deposit_answer_rate_info = new QLabel(widget_deposit_answer);
        label_deposit_answer_rate_info->setObjectName(QString::fromUtf8("label_deposit_answer_rate_info"));
        label_deposit_answer_rate_info->setMinimumSize(QSize(0, 21));
        label_deposit_answer_rate_info->setMaximumSize(QSize(16777215, 21));
        label_deposit_answer_rate_info->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_deposit_answer_rate_info);

        label_deposit_answer_rate = new QLabel(widget_deposit_answer);
        label_deposit_answer_rate->setObjectName(QString::fromUtf8("label_deposit_answer_rate"));
        label_deposit_answer_rate->setMinimumSize(QSize(0, 41));
        label_deposit_answer_rate->setMaximumSize(QSize(16777215, 41));
        label_deposit_answer_rate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_15->addWidget(label_deposit_answer_rate);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_2);

        label_deposit_answer_tax_info = new QLabel(widget_deposit_answer);
        label_deposit_answer_tax_info->setObjectName(QString::fromUtf8("label_deposit_answer_tax_info"));
        label_deposit_answer_tax_info->setMinimumSize(QSize(0, 21));
        label_deposit_answer_tax_info->setMaximumSize(QSize(16777215, 21));
        label_deposit_answer_tax_info->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_deposit_answer_tax_info);

        label_deposit_answer_tax = new QLabel(widget_deposit_answer);
        label_deposit_answer_tax->setObjectName(QString::fromUtf8("label_deposit_answer_tax"));
        label_deposit_answer_tax->setMinimumSize(QSize(0, 41));
        label_deposit_answer_tax->setMaximumSize(QSize(16777215, 41));
        label_deposit_answer_tax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_15->addWidget(label_deposit_answer_tax);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_3);

        label_deposit_answer_sum_info = new QLabel(widget_deposit_answer);
        label_deposit_answer_sum_info->setObjectName(QString::fromUtf8("label_deposit_answer_sum_info"));
        label_deposit_answer_sum_info->setMinimumSize(QSize(0, 21));
        label_deposit_answer_sum_info->setMaximumSize(QSize(16777215, 21));
        label_deposit_answer_sum_info->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_deposit_answer_sum_info);

        label_deposit_answer_sum = new QLabel(widget_deposit_answer);
        label_deposit_answer_sum->setObjectName(QString::fromUtf8("label_deposit_answer_sum"));
        label_deposit_answer_sum->setMinimumSize(QSize(0, 41));
        label_deposit_answer_sum->setMaximumSize(QSize(16777215, 41));
        label_deposit_answer_sum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_15->addWidget(label_deposit_answer_sum);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_4);

        pushButton_deposit_start = new QPushButton(widget_deposit_answer);
        pushButton_deposit_start->setObjectName(QString::fromUtf8("pushButton_deposit_start"));
        pushButton_deposit_start->setMinimumSize(QSize(0, 21));
        pushButton_deposit_start->setMaximumSize(QSize(9999999, 21));
        pushButton_deposit_start->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(117, 148, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(165, 174, 201);\n"
"}"));

        verticalLayout_15->addWidget(pushButton_deposit_start);

        lineEdit_deposit_input_sum = new QLineEdit(widget_deposit_3);
        lineEdit_deposit_input_sum->setObjectName(QString::fromUtf8("lineEdit_deposit_input_sum"));
        lineEdit_deposit_input_sum->setGeometry(QRect(180, 14, 151, 41));
        lineEdit_deposit_input_sum->setMinimumSize(QSize(0, 41));
        lineEdit_deposit_input_sum->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_deposit_input_time = new QLineEdit(widget_deposit_3);
        lineEdit_deposit_input_time->setObjectName(QString::fromUtf8("lineEdit_deposit_input_time"));
        lineEdit_deposit_input_time->setGeometry(QRect(180, 67, 83, 41));
        lineEdit_deposit_input_time->setMinimumSize(QSize(0, 41));
        lineEdit_deposit_input_time->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_deposit_input_rate = new QLineEdit(widget_deposit_3);
        lineEdit_deposit_input_rate->setObjectName(QString::fromUtf8("lineEdit_deposit_input_rate"));
        lineEdit_deposit_input_rate->setGeometry(QRect(180, 120, 151, 41));
        lineEdit_deposit_input_rate->setMinimumSize(QSize(0, 41));
        lineEdit_deposit_input_rate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_deposit_input_tax = new QLineEdit(widget_deposit_3);
        lineEdit_deposit_input_tax->setObjectName(QString::fromUtf8("lineEdit_deposit_input_tax"));
        lineEdit_deposit_input_tax->setGeometry(QRect(180, 173, 151, 41));
        lineEdit_deposit_input_tax->setMinimumSize(QSize(0, 41));
        lineEdit_deposit_input_tax->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_deposit_input_sum = new QLabel(widget_deposit_3);
        label_deposit_input_sum->setObjectName(QString::fromUtf8("label_deposit_input_sum"));
        label_deposit_input_sum->setGeometry(QRect(10, 14, 161, 41));
        label_deposit_input_sum->setAlignment(Qt::AlignCenter);
        label_deposit_input_time = new QLabel(widget_deposit_3);
        label_deposit_input_time->setObjectName(QString::fromUtf8("label_deposit_input_time"));
        label_deposit_input_time->setGeometry(QRect(10, 67, 161, 41));
        label_deposit_input_time->setAlignment(Qt::AlignCenter);
        label_deposit_input_rate = new QLabel(widget_deposit_3);
        label_deposit_input_rate->setObjectName(QString::fromUtf8("label_deposit_input_rate"));
        label_deposit_input_rate->setGeometry(QRect(10, 120, 161, 41));
        label_deposit_input_rate->setAlignment(Qt::AlignCenter);
        label_deposit_input_tax = new QLabel(widget_deposit_3);
        label_deposit_input_tax->setObjectName(QString::fromUtf8("label_deposit_input_tax"));
        label_deposit_input_tax->setGeometry(QRect(10, 173, 161, 41));
        label_deposit_input_tax->setAlignment(Qt::AlignCenter);
        label_deposit_input_pay_unit = new QLabel(widget_deposit_3);
        label_deposit_input_pay_unit->setObjectName(QString::fromUtf8("label_deposit_input_pay_unit"));
        label_deposit_input_pay_unit->setGeometry(QRect(10, 279, 161, 41));
        label_deposit_input_pay_unit->setAlignment(Qt::AlignCenter);
        label_deposit_input_capitalisation = new QLabel(widget_deposit_3);
        label_deposit_input_capitalisation->setObjectName(QString::fromUtf8("label_deposit_input_capitalisation"));
        label_deposit_input_capitalisation->setGeometry(QRect(10, 332, 161, 41));
        label_deposit_input_capitalisation->setAlignment(Qt::AlignCenter);
        checkBox_deposit_input_capitalisation = new QCheckBox(widget_deposit_3);
        checkBox_deposit_input_capitalisation->setObjectName(QString::fromUtf8("checkBox_deposit_input_capitalisation"));
        checkBox_deposit_input_capitalisation->setGeometry(QRect(180, 332, 181, 41));
        checkBox_deposit_input_capitalisation->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 53, 56);"));
        label_deposit_input_sum_unit = new QLabel(widget_deposit_3);
        label_deposit_input_sum_unit->setObjectName(QString::fromUtf8("label_deposit_input_sum_unit"));
        label_deposit_input_sum_unit->setGeometry(QRect(330, 14, 31, 41));
        label_deposit_input_sum_unit->setAlignment(Qt::AlignCenter);
        comboBox_deposit_input_time_unit = new QComboBox(widget_deposit_3);
        comboBox_deposit_input_time_unit->addItem(QString());
        comboBox_deposit_input_time_unit->addItem(QString());
        comboBox_deposit_input_time_unit->addItem(QString());
        comboBox_deposit_input_time_unit->setObjectName(QString::fromUtf8("comboBox_deposit_input_time_unit"));
        comboBox_deposit_input_time_unit->setGeometry(QRect(262, 67, 101, 41));
        comboBox_deposit_input_time_unit->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 53, 56);"));
        label_deposit_input_rate_unit = new QLabel(widget_deposit_3);
        label_deposit_input_rate_unit->setObjectName(QString::fromUtf8("label_deposit_input_rate_unit"));
        label_deposit_input_rate_unit->setGeometry(QRect(330, 120, 31, 41));
        label_deposit_input_rate_unit->setAlignment(Qt::AlignCenter);
        label_deposit_input_tax_unit = new QLabel(widget_deposit_3);
        label_deposit_input_tax_unit->setObjectName(QString::fromUtf8("label_deposit_input_tax_unit"));
        label_deposit_input_tax_unit->setGeometry(QRect(330, 173, 31, 41));
        label_deposit_input_tax_unit->setAlignment(Qt::AlignCenter);
        comboBox_deposit_input_pay_unit_unit = new QComboBox(widget_deposit_3);
        comboBox_deposit_input_pay_unit_unit->addItem(QString());
        comboBox_deposit_input_pay_unit_unit->addItem(QString());
        comboBox_deposit_input_pay_unit_unit->addItem(QString());
        comboBox_deposit_input_pay_unit_unit->addItem(QString());
        comboBox_deposit_input_pay_unit_unit->addItem(QString());
        comboBox_deposit_input_pay_unit_unit->addItem(QString());
        comboBox_deposit_input_pay_unit_unit->addItem(QString());
        comboBox_deposit_input_pay_unit_unit->setObjectName(QString::fromUtf8("comboBox_deposit_input_pay_unit_unit"));
        comboBox_deposit_input_pay_unit_unit->setGeometry(QRect(180, 279, 181, 41));
        comboBox_deposit_input_pay_unit_unit->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 53, 56);"));
        label_deposit_input_date_start = new QLabel(widget_deposit_3);
        label_deposit_input_date_start->setObjectName(QString::fromUtf8("label_deposit_input_date_start"));
        label_deposit_input_date_start->setGeometry(QRect(10, 226, 161, 41));
        label_deposit_input_date_start->setAlignment(Qt::AlignCenter);
        dateEdit_deposit_date_start = new QDateEdit(widget_deposit_3);
        dateEdit_deposit_date_start->setObjectName(QString::fromUtf8("dateEdit_deposit_date_start"));
        dateEdit_deposit_date_start->setGeometry(QRect(180, 226, 181, 41));
        dateEdit_deposit_date_start->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 53, 56);"));

        verticalLayout_7->addWidget(widget_deposit_3);

        label_deposit_info = new QLabel(widget_deposit_2);
        label_deposit_info->setObjectName(QString::fromUtf8("label_deposit_info"));
        label_deposit_info->setMinimumSize(QSize(1, 30));
        label_deposit_info->setMaximumSize(QSize(16777215, 30));
        label_deposit_info->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 53, 56);"));
        label_deposit_info->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_7->addWidget(label_deposit_info);

        verticalSpacer_deposit_down = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_deposit_down);


        horizontalLayout_2->addWidget(widget_deposit_2);

        scrollArea_widget_deposit_list_in = new QScrollArea(widget_deposit);
        scrollArea_widget_deposit_list_in->setObjectName(QString::fromUtf8("scrollArea_widget_deposit_list_in"));
        scrollArea_widget_deposit_list_in->setMinimumSize(QSize(280, 0));
        scrollArea_widget_deposit_list_in->setMaximumSize(QSize(306, 16777215));
        scrollArea_widget_deposit_list_in->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 276, 523));
        scrollAreaWidgetContents_6->setMinimumSize(QSize(276, 0));
        scrollAreaWidgetContents_6->setMaximumSize(QSize(276, 16777215));
        verticalLayout_14 = new QVBoxLayout(scrollAreaWidgetContents_6);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        scrollArea_widget_deposit_list_in->setWidget(scrollAreaWidgetContents_6);

        horizontalLayout_2->addWidget(scrollArea_widget_deposit_list_in);

        horizontalSpacer_deposit_right = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_deposit_right);


        verticalLayout_9->addWidget(widget_deposit);

        tabWidget->addTab(tab_deposit, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1517, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_calc_var_list_hide->setText(QCoreApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\320\270 \320\270 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\213\320\265", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_eq->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_bracket_open->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_bracket_close->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_num2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_fact->setText(QCoreApplication::translate("MainWindow", "!", nullptr));
        pushButton_comma->setText(QCoreApplication::translate("MainWindow", ",", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_num3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_clear_all->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_num8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_num5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_num9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_num0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "CE", nullptr));
        pushButton_num1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_num6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_e->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        pushButton_num4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_sqr->setText(QCoreApplication::translate("MainWindow", "x^2", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_num7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        label_calc_info->setText(QString());
        lineEdit_calc->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_calc), QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        pushButton_graph_vars_hide->setText(QCoreApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\320\270 \320\270 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\213\320\265", nullptr));
        pushButton_graph_menu_hide->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
        checkBox_graph_menu_axis_x->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\214 x", nullptr));
        lineEdit_graph_menu_min_x->setText(QCoreApplication::translate("MainWindow", "-10", nullptr));
        label_graph_menu_axis_x_info->setText(QCoreApplication::translate("MainWindow", "<= x <=", nullptr));
        lineEdit_graph_menu_max_x->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        label_graph_menu_step_x_info->setText(QCoreApplication::translate("MainWindow", "\321\210\320\260\320\263", nullptr));
        lineEdit_graph_menu_step_x->setText(QString());
        checkBox_graph_menu_grid->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\321\202\320\272\320\260", nullptr));
        checkBox_graph_menu_small_grid->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\273\320\272\320\260\321\217 \321\201\320\265\321\202\320\272\320\260", nullptr));
        checkBox_graph_menu_nums_on_axis->setText(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\275\320\260 \320\276\321\201\321\217\321\205", nullptr));
        lineEdit_graph_menu_max_y->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        lineEdit_graph_menu_min_y->setText(QCoreApplication::translate("MainWindow", "-10", nullptr));
        label_graph_menu_step_y_info->setText(QCoreApplication::translate("MainWindow", "\321\210\320\260\320\263", nullptr));
        lineEdit_graph_menu_step_y->setText(QString());
        checkBox_graph_menu_axis_y->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\214 y", nullptr));
        label_graph_menu_axis_y_info->setText(QCoreApplication::translate("MainWindow", "<= y <=", nullptr));
        pushButton_graph_menu_restore->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_graph), QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272", nullptr));
        label_credit_answer_month_pay_info->setText(QCoreApplication::translate("MainWindow", "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266", nullptr));
        label_credit_answer_month_pay->setText(QString());
        label_credit_answer_over_pay_info->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\277\320\273\320\260\321\202\320\260", nullptr));
        label_credit_answer_over_pay->setText(QString());
        label_credit_answer_total_pay_info->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\211\320\260\321\217 \320\262\321\213\320\277\320\273\320\260\321\202\320\260", nullptr));
        label_credit_answer_total_pay->setText(QString());
        pushButton_credit_start->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_credit_input_sum->setText(QCoreApplication::translate("MainWindow", "\302\240\320\241\321\203\320\274\320\274\320\260", nullptr));
        label_credit_input_time->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\276\320\272", nullptr));
        label_credit_input_type->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277", nullptr));
        label_credit_input_sum_unit->setText(QCoreApplication::translate("MainWindow", "\321\200\321\203\320\261.", nullptr));
        comboBox_credit_input_time_unit->setItemText(0, QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));
        comboBox_credit_input_time_unit->setItemText(1, QCoreApplication::translate("MainWindow", "\320\233\320\265\321\202", nullptr));

        comboBox_credit_input_type->setItemText(0, QCoreApplication::translate("MainWindow", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\271", nullptr));
        comboBox_credit_input_type->setItemText(1, QCoreApplication::translate("MainWindow", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271", nullptr));

        label_credit_input_rate_unit->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_credit_input_rate->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_credit_info->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_credit), QCoreApplication::translate("MainWindow", "\320\232\321\200\320\265\320\264\320\270\321\202", nullptr));
        pushButton_deposit_list_out_hide->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\201\320\275\321\217\321\202\320\270\320\271", nullptr));
        pushButton_deposit_list_in_hide->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\271", nullptr));
        label_deposit_answer_rate_info->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213", nullptr));
        label_deposit_answer_rate->setText(QString());
        label_deposit_answer_tax_info->setText(QCoreApplication::translate("MainWindow", "\320\241\321\203\320\274\320\274\320\260 \320\275\320\260\320\273\320\276\320\263\320\260", nullptr));
        label_deposit_answer_tax->setText(QString());
        label_deposit_answer_sum_info->setText(QCoreApplication::translate("MainWindow", "\320\241\321\203\320\274\320\274\320\260 \320\275\320\260 \320\262\320\272\320\273\320\260\320\264\320\265", nullptr));
        label_deposit_answer_sum->setText(QString());
        pushButton_deposit_start->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_deposit_input_sum->setText(QCoreApplication::translate("MainWindow", "\302\240\320\241\321\203\320\274\320\274\320\260", nullptr));
        label_deposit_input_time->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\276\320\272", nullptr));
        label_deposit_input_rate->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_deposit_input_tax->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\273\320\276\320\263\320\276\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_deposit_input_pay_unit->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214 \320\262\321\213\320\277\320\273\320\260\321\202", nullptr));
        label_deposit_input_capitalisation->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        checkBox_deposit_input_capitalisation->setText(QCoreApplication::translate("MainWindow", "\320\272\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        label_deposit_input_sum_unit->setText(QCoreApplication::translate("MainWindow", "\321\200\321\203\320\261.", nullptr));
        comboBox_deposit_input_time_unit->setItemText(0, QCoreApplication::translate("MainWindow", "\320\224\320\275\320\265\320\271", nullptr));
        comboBox_deposit_input_time_unit->setItemText(1, QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));
        comboBox_deposit_input_time_unit->setItemText(2, QCoreApplication::translate("MainWindow", "\320\233\320\265\321\202", nullptr));

        label_deposit_input_rate_unit->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_deposit_input_tax_unit->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        comboBox_deposit_input_pay_unit_unit->setItemText(0, QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\264\320\265\320\275\321\214", nullptr));
        comboBox_deposit_input_pay_unit_unit->setItemText(1, QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\275\320\265\320\264\320\265\320\273\321\216", nullptr));
        comboBox_deposit_input_pay_unit_unit->setItemText(2, QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        comboBox_deposit_input_pay_unit_unit->setItemText(3, QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\272\320\262\320\260\321\200\321\202\320\260\320\273", nullptr));
        comboBox_deposit_input_pay_unit_unit->setItemText(4, QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\263\320\276\320\264", nullptr));
        comboBox_deposit_input_pay_unit_unit->setItemText(5, QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267 \320\262 \320\277\320\276\320\273 \320\263\320\276\320\264\320\260", nullptr));
        comboBox_deposit_input_pay_unit_unit->setItemText(6, QCoreApplication::translate("MainWindow", "\320\222 \320\272\320\276\320\275\321\206\320\265 \321\201\321\200\320\276\320\272\320\260", nullptr));

        label_deposit_input_date_start->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\207\320\260\320\273\320\260", nullptr));
        label_deposit_info->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_deposit), QCoreApplication::translate("MainWindow", "\320\224\320\265\320\277\320\276\320\267\320\270\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
