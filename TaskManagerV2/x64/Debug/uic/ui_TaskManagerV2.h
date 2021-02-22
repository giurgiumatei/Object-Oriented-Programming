/********************************************************************************
** Form generated from reading UI file 'TaskManagerV2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGERV2_H
#define UI_TASKMANAGERV2_H

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

class Ui_TaskManagerV2Class
{
public:
    QWidget *centralWidget;
    QListWidget *tasks_list_widget;
    QLineEdit *tasks_line_edit;
    QPushButton *add_button;
    QPushButton *remove_button;
    QPushButton *start_button;
    QPushButton *done_button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TaskManagerV2Class)
    {
        if (TaskManagerV2Class->objectName().isEmpty())
            TaskManagerV2Class->setObjectName(QString::fromUtf8("TaskManagerV2Class"));
        TaskManagerV2Class->resize(1758, 1184);
        centralWidget = new QWidget(TaskManagerV2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tasks_list_widget = new QListWidget(centralWidget);
        tasks_list_widget->setObjectName(QString::fromUtf8("tasks_list_widget"));
        tasks_list_widget->setGeometry(QRect(470, 70, 841, 601));
        tasks_line_edit = new QLineEdit(centralWidget);
        tasks_line_edit->setObjectName(QString::fromUtf8("tasks_line_edit"));
        tasks_line_edit->setGeometry(QRect(480, 730, 791, 61));
        add_button = new QPushButton(centralWidget);
        add_button->setObjectName(QString::fromUtf8("add_button"));
        add_button->setGeometry(QRect(280, 730, 161, 51));
        remove_button = new QPushButton(centralWidget);
        remove_button->setObjectName(QString::fromUtf8("remove_button"));
        remove_button->setGeometry(QRect(1350, 730, 171, 51));
        start_button = new QPushButton(centralWidget);
        start_button->setObjectName(QString::fromUtf8("start_button"));
        start_button->setGeometry(QRect(260, 350, 151, 51));
        done_button = new QPushButton(centralWidget);
        done_button->setObjectName(QString::fromUtf8("done_button"));
        done_button->setGeometry(QRect(1350, 350, 161, 61));
        TaskManagerV2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TaskManagerV2Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1758, 26));
        TaskManagerV2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TaskManagerV2Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TaskManagerV2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TaskManagerV2Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TaskManagerV2Class->setStatusBar(statusBar);

        retranslateUi(TaskManagerV2Class);
        QObject::connect(add_button, SIGNAL(clicked()), TaskManagerV2Class, SLOT(add()));
        QObject::connect(remove_button, SIGNAL(clicked()), TaskManagerV2Class, SLOT(remove()));
        QObject::connect(start_button, SIGNAL(clicked()), TaskManagerV2Class, SLOT(start()));
        QObject::connect(done_button, SIGNAL(clicked()), TaskManagerV2Class, SLOT(done()));

        QMetaObject::connectSlotsByName(TaskManagerV2Class);
    } // setupUi

    void retranslateUi(QMainWindow *TaskManagerV2Class)
    {
        TaskManagerV2Class->setWindowTitle(QCoreApplication::translate("TaskManagerV2Class", "TaskManagerV2", nullptr));
        add_button->setText(QCoreApplication::translate("TaskManagerV2Class", "Add", nullptr));
        remove_button->setText(QCoreApplication::translate("TaskManagerV2Class", "Remove", nullptr));
        start_button->setText(QCoreApplication::translate("TaskManagerV2Class", "Start", nullptr));
        done_button->setText(QCoreApplication::translate("TaskManagerV2Class", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskManagerV2Class: public Ui_TaskManagerV2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGERV2_H
