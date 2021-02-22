#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManager.h"
#include "Controller.h"
class TaskManager : public QMainWindow
{
    Q_OBJECT

public:
    TaskManager(Controller& controller,QWidget *parent = Q_NULLPTR);
    

private:
    Controller& controller;
    Ui::TaskManagerClass ui;
    int get_selected_index();
    void populate_list();
  

 public slots:
    void show_total_duration();

};
