/********************************************************************************
** Form generated from reading UI file 'widgetfunc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETFUNC_H
#define UI_WIDGETFUNC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetFunc
{
public:
    QLineEdit *lineEdit_value;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_type;
    QPushButton *pushButton_hide;
    QPushButton *pushButton_color;

    void setupUi(QWidget *WidgetFunc)
    {
        if (WidgetFunc->objectName().isEmpty())
            WidgetFunc->setObjectName(QString::fromUtf8("WidgetFunc"));
        WidgetFunc->resize(360, 37);
        WidgetFunc->setMinimumSize(QSize(360, 37));
        WidgetFunc->setMaximumSize(QSize(360, 37));
        lineEdit_value = new QLineEdit(WidgetFunc);
        lineEdit_value->setObjectName(QString::fromUtf8("lineEdit_value"));
        lineEdit_value->setGeometry(QRect(61, 0, 211, 37));
        lineEdit_value->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(52, 53, 56);\n"
"	border-top: 1px  solid rgb(150, 150, 150) ;\n"
"	border-left: 0px  solid rgb(150, 150, 150) ;\n"
"	border-bottom: 1px  solid rgb(150, 150, 150) ;\n"
"	border-right: 1px  solid rgb(150, 150, 150) ;\n"
"}"));
        pushButton_delete = new QPushButton(WidgetFunc);
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
        pushButton_type = new QPushButton(WidgetFunc);
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
        pushButton_hide = new QPushButton(WidgetFunc);
        pushButton_hide->setObjectName(QString::fromUtf8("pushButton_hide"));
        pushButton_hide->setGeometry(QRect(272, 0, 43, 37));
        pushButton_hide->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_color = new QPushButton(WidgetFunc);
        pushButton_color->setObjectName(QString::fromUtf8("pushButton_color"));
        pushButton_color->setGeometry(QRect(314, 0, 43, 37));
        pushButton_color->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(WidgetFunc);

        QMetaObject::connectSlotsByName(WidgetFunc);
    } // setupUi

    void retranslateUi(QWidget *WidgetFunc)
    {
        WidgetFunc->setWindowTitle(QCoreApplication::translate("WidgetFunc", "Form", nullptr));
        lineEdit_value->setText(QCoreApplication::translate("WidgetFunc", "pi = 3.1415 \321\213\321\213\321\213\321\213\321\213", nullptr));
        pushButton_delete->setText(QString());
        pushButton_type->setText(QString());
        pushButton_hide->setText(QString());
        pushButton_color->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WidgetFunc: public Ui_WidgetFunc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETFUNC_H
