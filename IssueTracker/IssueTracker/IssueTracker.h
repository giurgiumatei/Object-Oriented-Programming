#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_IssueTracker.h"
#include "Service.h"
class IssueTracker : public QMainWindow,public Observer
{
    Q_OBJECT

public:
    IssueTracker(User user,Service& service,QWidget *parent = Q_NULLPTR);
    void update() override;
    void populate_list();
    void enable_button();
    
    

private:
    Ui::IssueTrackerClass ui;
    Service& service;
    User user;
public slots:
    void add();
    void remove();
    void resolve();
    void enable_resolve();

};
