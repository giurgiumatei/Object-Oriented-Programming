/********************************************************************************
** Form generated from reading UI file 'SearchWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHWINDOW_H
#define UI_SEARCHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchWindow
{
public:
    QListWidget *answers_list_widget;
    QLineEdit *search_line_edit;
    QLabel *label;
    QLineEdit *matching_question_line_edit;

    void setupUi(QWidget *SearchWindow)
    {
        if (SearchWindow->objectName().isEmpty())
            SearchWindow->setObjectName(QString::fromUtf8("SearchWindow"));
        SearchWindow->resize(432, 450);
        answers_list_widget = new QListWidget(SearchWindow);
        answers_list_widget->setObjectName(QString::fromUtf8("answers_list_widget"));
        answers_list_widget->setGeometry(QRect(70, 180, 256, 192));
        search_line_edit = new QLineEdit(SearchWindow);
        search_line_edit->setObjectName(QString::fromUtf8("search_line_edit"));
        search_line_edit->setGeometry(QRect(120, 50, 131, 31));
        label = new QLabel(SearchWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 55, 16));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        matching_question_line_edit = new QLineEdit(SearchWindow);
        matching_question_line_edit->setObjectName(QString::fromUtf8("matching_question_line_edit"));
        matching_question_line_edit->setGeometry(QRect(120, 110, 131, 31));

        retranslateUi(SearchWindow);
        QObject::connect(search_line_edit, SIGNAL(textChanged(QString)), SearchWindow, SLOT(update_results()));

        QMetaObject::connectSlotsByName(SearchWindow);
    } // setupUi

    void retranslateUi(QWidget *SearchWindow)
    {
        SearchWindow->setWindowTitle(QCoreApplication::translate("SearchWindow", "SearchWindow", nullptr));
        label->setText(QCoreApplication::translate("SearchWindow", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchWindow: public Ui_SearchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWINDOW_H
