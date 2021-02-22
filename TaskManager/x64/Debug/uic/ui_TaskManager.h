/********************************************************************************
** Form generated from reading UI file 'TaskManager.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGER_H
#define UI_TASKMANAGER_H

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

class Ui_TaskManagerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QListWidget *tasks_list_widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *priority_label;
    QLineEdit *priority_line_edit;
    QPushButton *show_total_duration_button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TaskManagerClass)
    {
        if (TaskManagerClass->objectName().isEmpty())
            TaskManagerClass->setObjectName(QString::fromUtf8("TaskManagerClass"));
        TaskManagerClass->resize(1733, 1216);
        centralWidget = new QWidget(TaskManagerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tasks_list_widget = new QListWidget(centralWidget);
        tasks_list_widget->setObjectName(QString::fromUtf8("tasks_list_widget"));
        QFont font;
        font.setPointSize(12);
        tasks_list_widget->setFont(font);

        gridLayout_2->addWidget(tasks_list_widget, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        priority_label = new QLabel(centralWidget);
        priority_label->setObjectName(QString::fromUtf8("priority_label"));

        horizontalLayout->addWidget(priority_label);

        priority_line_edit = new QLineEdit(centralWidget);
        priority_line_edit->setObjectName(QString::fromUtf8("priority_line_edit"));

        horizontalLayout->addWidget(priority_line_edit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        show_total_duration_button = new QPushButton(centralWidget);
        show_total_duration_button->setObjectName(QString::fromUtf8("show_total_duration_button"));

        gridLayout->addWidget(show_total_duration_button, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        TaskManagerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TaskManagerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1733, 26));
        TaskManagerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TaskManagerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TaskManagerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TaskManagerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TaskManagerClass->setStatusBar(statusBar);

        retranslateUi(TaskManagerClass);
        QObject::connect(show_total_duration_button, SIGNAL(clicked()), TaskManagerClass, SLOT(show_total_duration()));

        QMetaObject::connectSlotsByName(TaskManagerClass);
    } // setupUi

    void retranslateUi(QMainWindow *TaskManagerClass)
    {
        TaskManagerClass->setWindowTitle(QCoreApplication::translate("TaskManagerClass", "TaskManager", nullptr));
        priority_label->setText(QCoreApplication::translate("TaskManagerClass", "Priority", nullptr));
        show_total_duration_button->setText(QCoreApplication::translate("TaskManagerClass", "Show Total Duration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskManagerClass: public Ui_TaskManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGER_H
