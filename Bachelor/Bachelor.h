#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Bachelor.h"
#include "Service.h"
class Bachelor : public QMainWindow
{
    Q_OBJECT

public:
    Bachelor(Teacher& teacher,Service& service,QWidget *parent = Q_NULLPTR);

private:
    Ui::BachelorClass ui;
    Service& service;
    Teacher& teacher;
};
