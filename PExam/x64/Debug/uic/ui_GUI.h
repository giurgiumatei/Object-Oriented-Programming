/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QWidget *centralWidget;
    QTableView *tableView;
    QPushButton *add_button;
    QListWidget *search_list_widget;
    QLabel *label_5;
    QCheckBox *checkBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *name_line_edit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *ra_line_edit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *dec_line_edit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *diameter_line_edit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *search_line_edit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QString::fromUtf8("GUIClass"));
        GUIClass->resize(1065, 835);
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(130, 20, 661, 321));
        add_button = new QPushButton(centralWidget);
        add_button->setObjectName(QString::fromUtf8("add_button"));
        add_button->setGeometry(QRect(650, 410, 111, 51));
        search_list_widget = new QListWidget(centralWidget);
        search_list_widget->setObjectName(QString::fromUtf8("search_list_widget"));
        search_list_widget->setGeometry(QRect(400, 540, 256, 192));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(389, 740, 51, 21));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(800, 180, 151, 91));
        QFont font;
        font.setPointSize(11);
        checkBox->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(420, 370, 200, 127));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        name_line_edit = new QLineEdit(layoutWidget);
        name_line_edit->setObjectName(QString::fromUtf8("name_line_edit"));

        horizontalLayout->addWidget(name_line_edit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        ra_line_edit = new QLineEdit(layoutWidget);
        ra_line_edit->setObjectName(QString::fromUtf8("ra_line_edit"));

        horizontalLayout_2->addWidget(ra_line_edit);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        dec_line_edit = new QLineEdit(layoutWidget);
        dec_line_edit->setObjectName(QString::fromUtf8("dec_line_edit"));

        horizontalLayout_3->addWidget(dec_line_edit);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        diameter_line_edit = new QLineEdit(layoutWidget);
        diameter_line_edit->setObjectName(QString::fromUtf8("diameter_line_edit"));

        horizontalLayout_4->addWidget(diameter_line_edit);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(440, 740, 176, 26));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        search_line_edit = new QLineEdit(layoutWidget1);
        search_line_edit->setObjectName(QString::fromUtf8("search_line_edit"));

        horizontalLayout_5->addWidget(search_line_edit);

        GUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1065, 26));
        GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GUIClass->setStatusBar(statusBar);

        retranslateUi(GUIClass);
        QObject::connect(add_button, SIGNAL(clicked()), GUIClass, SLOT(add_star()));
        QObject::connect(search_line_edit, SIGNAL(textChanged(QString)), GUIClass, SLOT(search_star()));
        QObject::connect(checkBox, SIGNAL(stateChanged(int)), GUIClass, SLOT(filter(int)));

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QCoreApplication::translate("GUIClass", "GUI", nullptr));
        add_button->setText(QCoreApplication::translate("GUIClass", "Add", nullptr));
        label_5->setText(QCoreApplication::translate("GUIClass", "Search", nullptr));
        checkBox->setText(QCoreApplication::translate("GUIClass", "Your Stars", nullptr));
        label->setText(QCoreApplication::translate("GUIClass", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("GUIClass", "Ra", nullptr));
        label_3->setText(QCoreApplication::translate("GUIClass", "Dec", nullptr));
        label_4->setText(QCoreApplication::translate("GUIClass", "Diameter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
