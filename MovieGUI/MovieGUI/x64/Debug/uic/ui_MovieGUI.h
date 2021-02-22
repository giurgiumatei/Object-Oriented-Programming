/********************************************************************************
** Form generated from reading UI file 'MovieGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIEGUI_H
#define UI_MOVIEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MovieGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MovieGUIClass)
    {
        if (MovieGUIClass->objectName().isEmpty())
            MovieGUIClass->setObjectName(QString::fromUtf8("MovieGUIClass"));
        MovieGUIClass->resize(600, 400);
        menuBar = new QMenuBar(MovieGUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MovieGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MovieGUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MovieGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MovieGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MovieGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MovieGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MovieGUIClass->setStatusBar(statusBar);

        retranslateUi(MovieGUIClass);

        QMetaObject::connectSlotsByName(MovieGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *MovieGUIClass)
    {
        MovieGUIClass->setWindowTitle(QCoreApplication::translate("MovieGUIClass", "MovieGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MovieGUIClass: public Ui_MovieGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIEGUI_H
