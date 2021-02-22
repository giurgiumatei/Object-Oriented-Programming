/********************************************************************************
** Form generated from reading UI file 'Exam.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAM_H
#define UI_EXAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamClass
{
public:
    QWidget *centralWidget;
    QListWidget *entity_list_widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ExamClass)
    {
        if (ExamClass->objectName().isEmpty())
            ExamClass->setObjectName(QString::fromUtf8("ExamClass"));
        ExamClass->resize(1403, 1018);
        centralWidget = new QWidget(ExamClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        entity_list_widget = new QListWidget(centralWidget);
        entity_list_widget->setObjectName(QString::fromUtf8("entity_list_widget"));
        entity_list_widget->setGeometry(QRect(360, 110, 661, 531));
        ExamClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ExamClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1403, 26));
        ExamClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExamClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ExamClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ExamClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ExamClass->setStatusBar(statusBar);

        retranslateUi(ExamClass);

        QMetaObject::connectSlotsByName(ExamClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExamClass)
    {
        ExamClass->setWindowTitle(QCoreApplication::translate("ExamClass", "Exam", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamClass: public Ui_ExamClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAM_H
