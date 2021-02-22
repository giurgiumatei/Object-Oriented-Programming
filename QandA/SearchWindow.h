#pragma once

#include <QWidget>
#include "ui_SearchWindow.h"
#include "Service.h"
#include "Subject.h"
class SearchWindow : public QWidget,public Observer
{
	Q_OBJECT

public:
	SearchWindow(Service& service,QWidget *parent = Q_NULLPTR);
	~SearchWindow();
	void update() override;
private:
	Ui::SearchWindow ui;
	Service& service;
	
public slots:

	void update_results();
};
