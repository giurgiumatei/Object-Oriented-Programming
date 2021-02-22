#pragma once
#include "Service.h"
#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"
#include "Model.h"
class GUI : public QMainWindow,public Observer
{
    Q_OBJECT

public:
    GUI(Model* idea_model, Service& service, Astronomer astronomer, QWidget* parent = Q_NULLPTR);
    void update() override;
   
private:
    Ui::GUIClass ui;
    Service& service;
    Astronomer astronomer;
    Model* idea_model;
    
   
public slots:
    void add_star();
    void search_star();
    void filter(int is_checked);

};
