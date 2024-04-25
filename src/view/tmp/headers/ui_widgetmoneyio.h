/********************************************************************************
** Form generated from reading UI file 'widgetmoneyio.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETMONEYIO_H
#define UI_WIDGETMONEYIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetMoneyIO
{
public:
    QLineEdit *lineEdit_value;
    QPushButton *pushButton_delete;
    QDateEdit *dateEdit;
    QLabel *label_unit;

    void setupUi(QWidget *WidgetMoneyIO)
    {
        if (WidgetMoneyIO->objectName().isEmpty())
            WidgetMoneyIO->setObjectName(QString::fromUtf8("WidgetMoneyIO"));
        WidgetMoneyIO->resize(261, 37);
        WidgetMoneyIO->setMinimumSize(QSize(261, 37));
        WidgetMoneyIO->setMaximumSize(QSize(261, 37));
        lineEdit_value = new QLineEdit(WidgetMoneyIO);
        lineEdit_value->setObjectName(QString::fromUtf8("lineEdit_value"));
        lineEdit_value->setGeometry(QRect(100, 0, 101, 37));
        lineEdit_value->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(52, 53, 56);\n"
"	border-top: 1px  solid rgb(150, 150, 150) ;\n"
"	border-left: 0px  solid rgb(150, 150, 150) ;\n"
"	border-bottom: 1px  solid rgb(150, 150, 150) ;\n"
"	border-right: 1px  solid rgb(150, 150, 150) ;\n"
"}"));
        pushButton_delete = new QPushButton(WidgetMoneyIO);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(230, 0, 31, 37));
        pushButton_delete->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 0px;\n"
"	background-color: rgb(52, 53, 56);\n"
"	border-top: 1px  solid rgb(150, 150, 150) ;\n"
"	border-left: 1px  solid rgb(150, 150, 150) ;\n"
"	border-bottom: 1px  solid rgb(150, 150, 150) ;\n"
"	border-right: 1px  solid rgb(150, 150, 150) ;\n"
"}\n"
""));
        dateEdit = new QDateEdit(WidgetMoneyIO);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(0, 0, 101, 37));
        dateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 53, 56);"));
        label_unit = new QLabel(WidgetMoneyIO);
        label_unit->setObjectName(QString::fromUtf8("label_unit"));
        label_unit->setGeometry(QRect(200, 0, 31, 37));
        label_unit->setStyleSheet(QString::fromUtf8("\n"
"	background-color: rgb(52, 53, 56);\n"
"	border-top: 1px  solid rgb(150, 150, 150) ;\n"
"	border-left: 0px  solid rgb(150, 150, 150) ;\n"
"	border-bottom: 1px  solid rgb(150, 150, 150) ;\n"
"	border-right: 1px  solid rgb(150, 150, 150) ;\n"
""));

        retranslateUi(WidgetMoneyIO);

        QMetaObject::connectSlotsByName(WidgetMoneyIO);
    } // setupUi

    void retranslateUi(QWidget *WidgetMoneyIO)
    {
        WidgetMoneyIO->setWindowTitle(QCoreApplication::translate("WidgetMoneyIO", "Form", nullptr));
        lineEdit_value->setText(QCoreApplication::translate("WidgetMoneyIO", "1000", nullptr));
        pushButton_delete->setText(QString());
        label_unit->setText(QCoreApplication::translate("WidgetMoneyIO", "\321\200\321\203\320\261.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetMoneyIO: public Ui_WidgetMoneyIO {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETMONEYIO_H
