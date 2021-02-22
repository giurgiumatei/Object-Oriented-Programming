/********************************************************************************
** Form generated from reading UI file 'Cars.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARS_H
#define UI_CARS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarsClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QListWidget *cars_list_widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *filter_button;
    QLineEdit *name_line_edit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CarsClass)
    {
        if (CarsClass->objectName().isEmpty())
            CarsClass->setObjectName(QString::fromUtf8("CarsClass"));
        CarsClass->resize(1239, 911);
        centralWidget = new QWidget(CarsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cars_list_widget = new QListWidget(centralWidget);
        cars_list_widget->setObjectName(QString::fromUtf8("cars_list_widget"));

        gridLayout->addWidget(cars_list_widget, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        filter_button = new QPushButton(centralWidget);
        filter_button->setObjectName(QString::fromUtf8("filter_button"));

        horizontalLayout->addWidget(filter_button);

        name_line_edit = new QLineEdit(centralWidget);
        name_line_edit->setObjectName(QString::fromUtf8("name_line_edit"));

        horizontalLayout->addWidget(name_line_edit);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        CarsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CarsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1239, 26));
        CarsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CarsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CarsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CarsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CarsClass->setStatusBar(statusBar);

        retranslateUi(CarsClass);
        QObject::connect(filter_button, SIGNAL(clicked()), CarsClass, SLOT(filter()));

        QMetaObject::connectSlotsByName(CarsClass);
    } // setupUi

    void retranslateUi(QMainWindow *CarsClass)
    {
        CarsClass->setWindowTitle(QCoreApplication::translate("CarsClass", "Cars", nullptr));
        filter_button->setText(QCoreApplication::translate("CarsClass", "Show Cars", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CarsClass: public Ui_CarsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARS_H
