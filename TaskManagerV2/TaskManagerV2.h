#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_TaskManagerV2.h"
#include "Service.h"
class TaskManagerV2 : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    TaskManagerV2(Service& service, string name, QWidget* parent = Q_NULLPTR);
    void update() override;
    void populate_list();
private:
    Ui::TaskManagerV2Class ui;
    Service& service;
    string name;
    
public slots:
    void add();
    void remove();
    void start();
    void done();

};
