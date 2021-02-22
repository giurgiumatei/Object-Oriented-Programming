#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QandA.h"
#include "Service.h"
class QandA : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    QandA(Service& service,string user,QWidget *parent = Q_NULLPTR);
    void populate_questions_table();
    void populate_answers_table(int q_id);
    void update() override;
    int selected_index = 0;

private:
    Ui::QandAClass ui;
    Service& service;
    string user;
    
public slots:
    void ask();
    void question_selected();
    void answer();
};
