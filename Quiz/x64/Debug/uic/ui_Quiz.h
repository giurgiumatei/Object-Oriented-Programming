/********************************************************************************
** Form generated from reading UI file 'Quiz.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUIZ_H
#define UI_QUIZ_H

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

class Ui_QuizClass
{
public:
    QWidget *centralWidget;
    QListWidget *questions_list_widget;
    QLineEdit *answer_line_edit;
    QPushButton *answer_button;
    QLineEdit *score_line_edit;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QuizClass)
    {
        if (QuizClass->objectName().isEmpty())
            QuizClass->setObjectName(QString::fromUtf8("QuizClass"));
        QuizClass->resize(1358, 859);
        centralWidget = new QWidget(QuizClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        questions_list_widget = new QListWidget(centralWidget);
        questions_list_widget->setObjectName(QString::fromUtf8("questions_list_widget"));
        questions_list_widget->setGeometry(QRect(300, 70, 741, 531));
        answer_line_edit = new QLineEdit(centralWidget);
        answer_line_edit->setObjectName(QString::fromUtf8("answer_line_edit"));
        answer_line_edit->setGeometry(QRect(450, 660, 113, 22));
        answer_button = new QPushButton(centralWidget);
        answer_button->setObjectName(QString::fromUtf8("answer_button"));
        answer_button->setEnabled(false);
        answer_button->setGeometry(QRect(630, 660, 93, 28));
        score_line_edit = new QLineEdit(centralWidget);
        score_line_edit->setObjectName(QString::fromUtf8("score_line_edit"));
        score_line_edit->setGeometry(QRect(1130, 350, 113, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1160, 300, 81, 41));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        QuizClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QuizClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1358, 26));
        QuizClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QuizClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QuizClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QuizClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QuizClass->setStatusBar(statusBar);

        retranslateUi(QuizClass);
        QObject::connect(answer_button, SIGNAL(clicked()), QuizClass, SLOT(answer()));
        QObject::connect(questions_list_widget, SIGNAL(itemSelectionChanged()), QuizClass, SLOT(enable_answer()));

        QMetaObject::connectSlotsByName(QuizClass);
    } // setupUi

    void retranslateUi(QMainWindow *QuizClass)
    {
        QuizClass->setWindowTitle(QCoreApplication::translate("QuizClass", "Quiz", nullptr));
        answer_button->setText(QCoreApplication::translate("QuizClass", "Answer", nullptr));
        label->setText(QCoreApplication::translate("QuizClass", "Score", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuizClass: public Ui_QuizClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUIZ_H
