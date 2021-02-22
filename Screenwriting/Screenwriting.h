#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Screenwriting.h"
#include "Service.h"
#include "Model.h"
class Screenwriting : public QMainWindow,public Observer
{
    Q_OBJECT

public:
   
    Screenwriting(Model* idea_model, Service& service, string name, QWidget* parent = Q_NULLPTR);
    void disable_button();

private:
    Ui::ScreenwritingClass ui;
    Service& service;
    string name;
    Model* idea_model;
    
public slots:
    void propose();
    void idea_selected();
    void accept();
    void open_edit_window();
    void save_plot();
};
