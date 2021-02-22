#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Quiz.h"
#include "Service.h"
class Quiz : public QMainWindow,public Observer
{
    Q_OBJECT

public:
    Quiz(Participant participant, Service& service, QWidget* parent = Q_NULLPTR);
    void update() override;
    void populate_list();

private:
    Ui::QuizClass ui;
    Service& service;
    Participant participant;
    
public slots:
    void answer();
    void enable_answer();
};
