#pragma once

#include <QWidget>
#include "ui_EditWidget.h"

class EditWidget : public QWidget
{
	Q_OBJECT

public:
	EditWidget(QWidget* parent = Q_NULLPTR);
	~EditWidget();

private:
	Ui::EditWidget ui;
};
