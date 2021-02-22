/********************************************************************************
** Form generated from reading UI file 'ShoppingList.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGLIST_H
#define UI_SHOPPINGLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
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

class Ui_ShoppingListClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QListWidget *item_list_widget;
    QFormLayout *formLayout_2;
    QLineEdit *filter_line_edit;
    QPushButton *filter_button;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *add_button;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *category_line_edit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *name_line_edit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *quantity_line_edit;
    QPushButton *delete_button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ShoppingListClass)
    {
        if (ShoppingListClass->objectName().isEmpty())
            ShoppingListClass->setObjectName(QString::fromUtf8("ShoppingListClass"));
        ShoppingListClass->resize(1099, 1016);
        centralWidget = new QWidget(ShoppingListClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        item_list_widget = new QListWidget(centralWidget);
        item_list_widget->setObjectName(QString::fromUtf8("item_list_widget"));

        gridLayout_3->addWidget(item_list_widget, 0, 0, 1, 2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        filter_line_edit = new QLineEdit(centralWidget);
        filter_line_edit->setObjectName(QString::fromUtf8("filter_line_edit"));

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, filter_line_edit);

        filter_button = new QPushButton(centralWidget);
        filter_button->setObjectName(QString::fromUtf8("filter_button"));

        formLayout_2->setWidget(1, QFormLayout::SpanningRole, filter_button);


        gridLayout_3->addLayout(formLayout_2, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout_2->addLayout(horizontalLayout, 3, 1, 1, 1);

        add_button = new QPushButton(centralWidget);
        add_button->setObjectName(QString::fromUtf8("add_button"));

        gridLayout_2->addWidget(add_button, 3, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        category_line_edit = new QLineEdit(centralWidget);
        category_line_edit->setObjectName(QString::fromUtf8("category_line_edit"));

        horizontalLayout_2->addWidget(category_line_edit);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        name_line_edit = new QLineEdit(centralWidget);
        name_line_edit->setObjectName(QString::fromUtf8("name_line_edit"));

        horizontalLayout_3->addWidget(name_line_edit);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        quantity_line_edit = new QLineEdit(centralWidget);
        quantity_line_edit->setObjectName(QString::fromUtf8("quantity_line_edit"));

        horizontalLayout_4->addWidget(quantity_line_edit);


        gridLayout->addLayout(horizontalLayout_4, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        delete_button = new QPushButton(centralWidget);
        delete_button->setObjectName(QString::fromUtf8("delete_button"));

        gridLayout_2->addWidget(delete_button, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 2, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        ShoppingListClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ShoppingListClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1099, 26));
        ShoppingListClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ShoppingListClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ShoppingListClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ShoppingListClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ShoppingListClass->setStatusBar(statusBar);

        retranslateUi(ShoppingListClass);
        QObject::connect(filter_button, SIGNAL(clicked()), ShoppingListClass, SLOT(filter()));
        QObject::connect(add_button, SIGNAL(clicked()), ShoppingListClass, SLOT(add()));
        QObject::connect(item_list_widget, SIGNAL(itemSelectionChanged()), ShoppingListClass, SLOT(select_item()));
        QObject::connect(delete_button, SIGNAL(clicked()), ShoppingListClass, SLOT(remove()));

        QMetaObject::connectSlotsByName(ShoppingListClass);
    } // setupUi

    void retranslateUi(QMainWindow *ShoppingListClass)
    {
        ShoppingListClass->setWindowTitle(QCoreApplication::translate("ShoppingListClass", "ShoppingList", nullptr));
        filter_button->setText(QCoreApplication::translate("ShoppingListClass", "filter", nullptr));
        add_button->setText(QCoreApplication::translate("ShoppingListClass", "add", nullptr));
        label->setText(QCoreApplication::translate("ShoppingListClass", "category", nullptr));
        label_2->setText(QCoreApplication::translate("ShoppingListClass", "name", nullptr));
        label_3->setText(QCoreApplication::translate("ShoppingListClass", "quantity", nullptr));
        delete_button->setText(QCoreApplication::translate("ShoppingListClass", "delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShoppingListClass: public Ui_ShoppingListClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGLIST_H
