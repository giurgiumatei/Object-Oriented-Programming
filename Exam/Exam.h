#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Exam.h"
#include "Controller.h"
class Exam : public QMainWindow
{
    Q_OBJECT

public:
    Exam(Controller& controller, QWidget* parent = Q_NULLPTR);

private:
    Ui::ExamClass ui;
    Controller& controller;
    void populate_list();

public slots:

};
