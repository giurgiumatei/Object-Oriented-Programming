#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Bills.h"
#include "Controller.h"
class Bills : public QMainWindow
{
    Q_OBJECT

public:
    Bills(Controller& controller, QWidget* parent = Q_NULLPTR);

private:
    Ui::BillsClass ui;
    Controller& controller;
    void populate_list();
    
public slots:
    void populate_sorted();
    void total();
};
