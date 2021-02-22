/********************************************************************************
** Form generated from reading UI file 'Presenter.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESENTER_H
#define UI_PRESENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Presenter
{
public:
    QListWidget *questions_list_widget;
    QPushButton *add_button;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *id_line_edit;
    QLineEdit *text_line_edit;
    QLineEdit *answer_line_edit;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *Presenter)
    {
        if (Presenter->objectName().isEmpty())
            Presenter->setObjectName(QString::fromUtf8("Presenter"));
        Presenter->resize(921, 704);
        questions_list_widget = new QListWidget(Presenter);
        questions_list_widget->setObjectName(QString::fromUtf8("questions_list_widget"));
        questions_list_widget->setGeometry(QRect(190, 120, 531, 371));
        add_button = new QPushButton(Presenter);
        add_button->setObjectName(QString::fromUtf8("add_button"));
        add_button->setGeometry(QRect(670, 590, 93, 28));
        layoutWidget = new QWidget(Presenter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(330, 510, 291, 181));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        id_line_edit = new QLineEdit(layoutWidget);
        id_line_edit->setObjectName(QString::fromUtf8("id_line_edit"));

        gridLayout->addWidget(id_line_edit, 0, 0, 1, 1);

        text_line_edit = new QLineEdit(layoutWidget);
        text_line_edit->setObjectName(QString::fromUtf8("text_line_edit"));

        gridLayout->addWidget(text_line_edit, 1, 0, 1, 1);

        answer_line_edit = new QLineEdit(layoutWidget);
        answer_line_edit->setObjectName(QString::fromUtf8("answer_line_edit"));

        gridLayout->addWidget(answer_line_edit, 2, 0, 1, 1);

        layoutWidget1 = new QWidget(Presenter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(210, 530, 111, 141));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);


        retranslateUi(Presenter);
        QObject::connect(add_button, SIGNAL(clicked()), Presenter, SLOT(add_question()));

        QMetaObject::connectSlotsByName(Presenter);
    } // setupUi

    void retranslateUi(QWidget *Presenter)
    {
        Presenter->setWindowTitle(QCoreApplication::translate("Presenter", "Presenter", nullptr));
        add_button->setText(QCoreApplication::translate("Presenter", "Add", nullptr));
        label->setText(QCoreApplication::translate("Presenter", "Id", nullptr));
        label_2->setText(QCoreApplication::translate("Presenter", "Text", nullptr));
        label_3->setText(QCoreApplication::translate("Presenter", "Answer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Presenter: public Ui_Presenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESENTER_H
