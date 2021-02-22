#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Cars.h"
#include "Controller.h"
class Cars : public QMainWindow
{
    Q_OBJECT

public:
    Cars(Controller& controller,QWidget *parent = Q_NULLPTR);

private:
    Ui::CarsClass ui;
    Controller& controller;
    void populate_list();
    
public slots:
    void filter();
};  
