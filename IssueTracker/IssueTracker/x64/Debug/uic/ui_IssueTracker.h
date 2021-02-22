/********************************************************************************
** Form generated from reading UI file 'IssueTracker.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ISSUETRACKER_H
#define UI_ISSUETRACKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IssueTrackerClass
{
public:
    QWidget *centralWidget;
    QListWidget *issues_list_widget;
    QLineEdit *add_issue_line_edit;
    QPushButton *add_issue_button;
    QPushButton *remove_issue_button;
    QLineEdit *remove_issue_line_edit;
    QPushButton *resolve_button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IssueTrackerClass)
    {
        if (IssueTrackerClass->objectName().isEmpty())
            IssueTrackerClass->setObjectName(QString::fromUtf8("IssueTrackerClass"));
        IssueTrackerClass->resize(1623, 934);
        centralWidget = new QWidget(IssueTrackerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        issues_list_widget = new QListWidget(centralWidget);
        issues_list_widget->setObjectName(QString::fromUtf8("issues_list_widget"));
        issues_list_widget->setGeometry(QRect(320, 70, 941, 651));
        add_issue_line_edit = new QLineEdit(centralWidget);
        add_issue_line_edit->setObjectName(QString::fromUtf8("add_issue_line_edit"));
        add_issue_line_edit->setGeometry(QRect(710, 740, 551, 51));
        add_issue_button = new QPushButton(centralWidget);
        add_issue_button->setObjectName(QString::fromUtf8("add_issue_button"));
        add_issue_button->setEnabled(false);
        add_issue_button->setGeometry(QRect(320, 740, 141, 61));
        QFont font;
        font.setPointSize(10);
        add_issue_button->setFont(font);
        remove_issue_button = new QPushButton(centralWidget);
        remove_issue_button->setObjectName(QString::fromUtf8("remove_issue_button"));
        remove_issue_button->setGeometry(QRect(320, 810, 141, 51));
        remove_issue_button->setFont(font);
        remove_issue_line_edit = new QLineEdit(centralWidget);
        remove_issue_line_edit->setObjectName(QString::fromUtf8("remove_issue_line_edit"));
        remove_issue_line_edit->setGeometry(QRect(710, 810, 551, 51));
        resolve_button = new QPushButton(centralWidget);
        resolve_button->setObjectName(QString::fromUtf8("resolve_button"));
        resolve_button->setEnabled(false);
        resolve_button->setGeometry(QRect(710, 20, 111, 41));
        IssueTrackerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(IssueTrackerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1623, 26));
        IssueTrackerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(IssueTrackerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        IssueTrackerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(IssueTrackerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        IssueTrackerClass->setStatusBar(statusBar);

        retranslateUi(IssueTrackerClass);
        QObject::connect(add_issue_button, SIGNAL(clicked()), IssueTrackerClass, SLOT(add()));
        QObject::connect(remove_issue_button, SIGNAL(clicked()), IssueTrackerClass, SLOT(remove()));
        QObject::connect(resolve_button, SIGNAL(clicked()), IssueTrackerClass, SLOT(resolve()));
        QObject::connect(issues_list_widget, SIGNAL(itemSelectionChanged()), IssueTrackerClass, SLOT(enable_resolve()));

        QMetaObject::connectSlotsByName(IssueTrackerClass);
    } // setupUi

    void retranslateUi(QMainWindow *IssueTrackerClass)
    {
        IssueTrackerClass->setWindowTitle(QCoreApplication::translate("IssueTrackerClass", "IssueTracker", nullptr));
        add_issue_button->setText(QCoreApplication::translate("IssueTrackerClass", "Add Issue", nullptr));
        remove_issue_button->setText(QCoreApplication::translate("IssueTrackerClass", "Remove Issue", nullptr));
        resolve_button->setText(QCoreApplication::translate("IssueTrackerClass", "Resolve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IssueTrackerClass: public Ui_IssueTrackerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ISSUETRACKER_H
