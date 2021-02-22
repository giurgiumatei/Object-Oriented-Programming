#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Vegetables.h"
#include "Controller.h"
class Vegetables : public QMainWindow
{
    Q_OBJECT

public:
    Vegetables(Controller& controller,QWidget *parent = Q_NULLPTR);

private:
    Ui::VegetablesClass ui;
    Controller& controller;
    void populate_family_list();
    int index_of_current;
    
    int get_selected_index();
    
public slots:
    void search();
    void select_item();

};
