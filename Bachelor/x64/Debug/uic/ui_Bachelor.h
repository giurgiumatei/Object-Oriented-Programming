/********************************************************************************
** Form generated from reading UI file 'Bachelor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACHELOR_H
#define UI_BACHELOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BachelorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BachelorClass)
    {
        if (BachelorClass->objectName().isEmpty())
            BachelorClass->setObjectName(QString::fromUtf8("BachelorClass"));
        BachelorClass->resize(600, 400);
        menuBar = new QMenuBar(BachelorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        BachelorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BachelorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        BachelorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(BachelorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        BachelorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(BachelorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        BachelorClass->setStatusBar(statusBar);

        retranslateUi(BachelorClass);

        QMetaObject::connectSlotsByName(BachelorClass);
    } // setupUi

    void retranslateUi(QMainWindow *BachelorClass)
    {
        BachelorClass->setWindowTitle(QCoreApplication::translate("BachelorClass", "Bachelor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BachelorClass: public Ui_BachelorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACHELOR_H
