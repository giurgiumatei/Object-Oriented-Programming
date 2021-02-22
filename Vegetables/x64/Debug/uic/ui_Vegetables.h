/********************************************************************************
** Form generated from reading UI file 'Vegetables.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEGETABLES_H
#define UI_VEGETABLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VegetablesClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QListWidget *family_list_widget;
    QListWidget *vegetables_list_widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *vegetable_label;
    QLineEdit *vegetable_line_edit;
    QPushButton *search_button;
    QHBoxLayout *horizontalLayout_2;
    QLabel *parts_label;
    QLineEdit *parts_line_edit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VegetablesClass)
    {
        if (VegetablesClass->objectName().isEmpty())
            VegetablesClass->setObjectName(QString::fromUtf8("VegetablesClass"));
        VegetablesClass->resize(1716, 1207);
        centralWidget = new QWidget(VegetablesClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        family_list_widget = new QListWidget(centralWidget);
        family_list_widget->setObjectName(QString::fromUtf8("family_list_widget"));
        QFont font;
        font.setPointSize(22);
        family_list_widget->setFont(font);

        horizontalLayout->addWidget(family_list_widget);

        vegetables_list_widget = new QListWidget(centralWidget);
        vegetables_list_widget->setObjectName(QString::fromUtf8("vegetables_list_widget"));
        vegetables_list_widget->setFont(font);

        horizontalLayout->addWidget(vegetables_list_widget);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        vegetable_label = new QLabel(centralWidget);
        vegetable_label->setObjectName(QString::fromUtf8("vegetable_label"));
        QFont font1;
        font1.setPointSize(11);
        vegetable_label->setFont(font1);

        horizontalLayout_3->addWidget(vegetable_label);

        vegetable_line_edit = new QLineEdit(centralWidget);
        vegetable_line_edit->setObjectName(QString::fromUtf8("vegetable_line_edit"));

        horizontalLayout_3->addWidget(vegetable_line_edit);

        search_button = new QPushButton(centralWidget);
        search_button->setObjectName(QString::fromUtf8("search_button"));
        QFont font2;
        font2.setPointSize(10);
        search_button->setFont(font2);

        horizontalLayout_3->addWidget(search_button);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        parts_label = new QLabel(centralWidget);
        parts_label->setObjectName(QString::fromUtf8("parts_label"));
        parts_label->setFont(font1);

        horizontalLayout_2->addWidget(parts_label);

        parts_line_edit = new QLineEdit(centralWidget);
        parts_line_edit->setObjectName(QString::fromUtf8("parts_line_edit"));

        horizontalLayout_2->addWidget(parts_line_edit);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        VegetablesClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VegetablesClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1716, 26));
        VegetablesClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VegetablesClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        VegetablesClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VegetablesClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        VegetablesClass->setStatusBar(statusBar);

        retranslateUi(VegetablesClass);
        QObject::connect(family_list_widget, SIGNAL(itemSelectionChanged()), VegetablesClass, SLOT(select_item()));
        QObject::connect(search_button, SIGNAL(clicked()), VegetablesClass, SLOT(search()));

        QMetaObject::connectSlotsByName(VegetablesClass);
    } // setupUi

    void retranslateUi(QMainWindow *VegetablesClass)
    {
        VegetablesClass->setWindowTitle(QCoreApplication::translate("VegetablesClass", "Vegetables", nullptr));
        vegetable_label->setText(QCoreApplication::translate("VegetablesClass", "Vegetable", nullptr));
        search_button->setText(QCoreApplication::translate("VegetablesClass", "Search", nullptr));
        parts_label->setText(QCoreApplication::translate("VegetablesClass", "Parts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VegetablesClass: public Ui_VegetablesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEGETABLES_H
