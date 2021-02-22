#pragma once
#include "Service.h"
#include "Subject.h"
#include <QWidget>
#include "ui_Presenter.h"

class Presenter : public QWidget,public Observer
{
	Q_OBJECT

public:
	Presenter(Service& service,QWidget *parent = Q_NULLPTR);
	~Presenter();
	void update() override;
	
	void populate_list();
private:
	Ui::Presenter ui;
	Service& service;
public slots:
	void add_question();
};
