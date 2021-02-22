/********************************************************************************
** Form generated from reading UI file 'QandA.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QANDA_H
#define UI_QANDA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_QandAClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QListWidget *questions_list_widget;
    QLineEdit *ask_question_line_edit;
    QPushButton *ask_question_button;
    QListWidget *answers_list_widget;
    QLabel *label_2;
    QLineEdit *respond_line_edit;
    QPushButton *respond_question_button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QandAClass)
    {
        if (QandAClass->objectName().isEmpty())
            QandAClass->setObjectName(QString::fromUtf8("QandAClass"));
        QandAClass->resize(1213, 870);
        centralWidget = new QWidget(QandAClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 80, 81, 51));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        questions_list_widget = new QListWidget(centralWidget);
        questions_list_widget->setObjectName(QString::fromUtf8("questions_list_widget"));
        questions_list_widget->setGeometry(QRect(120, 150, 256, 192));
        ask_question_line_edit = new QLineEdit(centralWidget);
        ask_question_line_edit->setObjectName(QString::fromUtf8("ask_question_line_edit"));
        ask_question_line_edit->setGeometry(QRect(130, 380, 241, 31));
        ask_question_button = new QPushButton(centralWidget);
        ask_question_button->setObjectName(QString::fromUtf8("ask_question_button"));
        ask_question_button->setGeometry(QRect(420, 380, 93, 28));
        answers_list_widget = new QListWidget(centralWidget);
        answers_list_widget->setObjectName(QString::fromUtf8("answers_list_widget"));
        answers_list_widget->setGeometry(QRect(700, 170, 256, 192));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(790, 90, 71, 41));
        label_2->setFont(font);
        respond_line_edit = new QLineEdit(centralWidget);
        respond_line_edit->setObjectName(QString::fromUtf8("respond_line_edit"));
        respond_line_edit->setGeometry(QRect(700, 390, 201, 31));
        respond_question_button = new QPushButton(centralWidget);
        respond_question_button->setObjectName(QString::fromUtf8("respond_question_button"));
        respond_question_button->setGeometry(QRect(940, 390, 93, 28));
        QandAClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QandAClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1213, 26));
        QandAClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QandAClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QandAClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QandAClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QandAClass->setStatusBar(statusBar);

        retranslateUi(QandAClass);
        QObject::connect(ask_question_button, SIGNAL(clicked()), QandAClass, SLOT(ask()));
        QObject::connect(questions_list_widget, SIGNAL(itemSelectionChanged()), QandAClass, SLOT(question_selected()));
        QObject::connect(respond_question_button, SIGNAL(clicked()), QandAClass, SLOT(answer()));

        QMetaObject::connectSlotsByName(QandAClass);
    } // setupUi

    void retranslateUi(QMainWindow *QandAClass)
    {
        QandAClass->setWindowTitle(QCoreApplication::translate("QandAClass", "QandA", nullptr));
        label->setText(QCoreApplication::translate("QandAClass", "Questions", nullptr));
        ask_question_button->setText(QCoreApplication::translate("QandAClass", "Ask", nullptr));
        label_2->setText(QCoreApplication::translate("QandAClass", "Answers", nullptr));
        respond_question_button->setText(QCoreApplication::translate("QandAClass", "Answer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QandAClass: public Ui_QandAClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QANDA_H
