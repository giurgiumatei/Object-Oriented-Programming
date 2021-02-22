/********************************************************************************
** Form generated from reading UI file 'Bills.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILLS_H
#define UI_BILLS_H

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

class Ui_BillsClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QListWidget *bills_list_widget;
    QPushButton *sort_button;
    QHBoxLayout *horizontalLayout;
    QPushButton *total_button;
    QLineEdit *total_line_edit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BillsClass)
    {
        if (BillsClass->objectName().isEmpty())
            BillsClass->setObjectName(QString::fromUtf8("BillsClass"));
        BillsClass->resize(1526, 1082);
        centralWidget = new QWidget(BillsClass);
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
        bills_list_widget = new QListWidget(centralWidget);
        bills_list_widget->setObjectName(QString::fromUtf8("bills_list_widget"));
        QFont font;
        font.setPointSize(12);
        bills_list_widget->setFont(font);

        gridLayout->addWidget(bills_list_widget, 0, 0, 1, 1);

        sort_button = new QPushButton(centralWidget);
        sort_button->setObjectName(QString::fromUtf8("sort_button"));

        gridLayout->addWidget(sort_button, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        total_button = new QPushButton(centralWidget);
        total_button->setObjectName(QString::fromUtf8("total_button"));

        horizontalLayout->addWidget(total_button);

        total_line_edit = new QLineEdit(centralWidget);
        total_line_edit->setObjectName(QString::fromUtf8("total_line_edit"));

        horizontalLayout->addWidget(total_line_edit);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        BillsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BillsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1526, 26));
        BillsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BillsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        BillsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BillsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        BillsClass->setStatusBar(statusBar);

        retranslateUi(BillsClass);
        QObject::connect(sort_button, SIGNAL(clicked()), BillsClass, SLOT(populate_sorted()));
        QObject::connect(total_button, SIGNAL(clicked()), BillsClass, SLOT(total()));

        QMetaObject::connectSlotsByName(BillsClass);
    } // setupUi

    void retranslateUi(QMainWindow *BillsClass)
    {
        BillsClass->setWindowTitle(QCoreApplication::translate("BillsClass", "Bills", nullptr));
        sort_button->setText(QCoreApplication::translate("BillsClass", "Sort", nullptr));
        total_button->setText(QCoreApplication::translate("BillsClass", "Calculate Total", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BillsClass: public Ui_BillsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILLS_H
