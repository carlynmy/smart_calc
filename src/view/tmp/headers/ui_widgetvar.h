/********************************************************************************
** Form generated from reading UI file 'widgetvar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETVAR_H
#define UI_WIDGETVAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetVar
{
public:
    QPushButton *pushButton_var;
    QLineEdit *lineEdit_value;
    QPushButton *pushButton_type;
    QPushButton *pushButton_delete;

    void setupUi(QWidget *WidgetVar)
    {
        if (WidgetVar->objectName().isEmpty())
            WidgetVar->setObjectName(QString::fromUtf8("WidgetVar"));
        WidgetVar->resize(360, 37);
        WidgetVar->setMinimumSize(QSize(360, 37));
        WidgetVar->setMaximumSize(QSize(360, 37));
        WidgetVar->setStyleSheet(QString::fromUtf8(""));
        pushButton_var = new QPushButton(WidgetVar);
        pushButton_var->setObjectName(QString::fromUtf8("pushButton_var"));
        pushButton_var->setGeometry(QRect(272, 0, 86, 37));
        pushButton_var->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_value = new QLineEdit(WidgetVar);
        lineEdit_value->setObjectName(QString::fromUtf8("lineEdit_value"));
        lineEdit_value->setGeometry(QRect(61, 0, 211, 37));
        lineEdit_value->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(52, 53, 56);\n"
"	border-top: 1px  solid rgb(150, 150, 150) ;\n"
"	border-left: 0px  solid rgb(150, 150, 150) ;\n"
"	border-bottom: 1px  solid rgb(150, 150, 150) ;\n"
"	border-right: 1px  solid rgb(150, 150, 150) ;\n"
"}"));
        pushButton_type = new QPushButton(WidgetVar);
        pushButton_type->setObjectName(QString::fromUtf8("pushButton_type"));
        pushButton_type->setGeometry(QRect(0, 0, 31, 37));
        pushButton_type->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_delete = new QPushButton(WidgetVar);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(30, 0, 31, 37));
        pushButton_delete->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 0px;\n"
"	background-color: rgb(52, 53, 56);\n"
"	border-top: 1px  solid rgb(150, 150, 150) ;\n"
"	border-left: 1px  solid rgb(150, 150, 150) ;\n"
"	border-bottom: 1px  solid rgb(150, 150, 150) ;\n"
"	border-right: 0px  solid rgb(150, 150, 150) ;\n"
"}\n"
""));

        retranslateUi(WidgetVar);

        QMetaObject::connectSlotsByName(WidgetVar);
    } // setupUi

    void retranslateUi(QWidget *WidgetVar)
    {
        WidgetVar->setWindowTitle(QCoreApplication::translate("WidgetVar", "Form", nullptr));
        pushButton_var->setText(QString());
        lineEdit_value->setText(QCoreApplication::translate("WidgetVar", "pi = 3.1415 \321\213\321\213\321\213\321\213\321\213", nullptr));
        pushButton_type->setText(QString());
        pushButton_delete->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WidgetVar: public Ui_WidgetVar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETVAR_H
