#pragma once
#include "Repository.h"
#include <qabstractitemmodel.h>


class MyListGUI:public QAbstractListModel
{
private:

	Repository& repository;


public:

	MyListGUI(Repository& repository) :repository{ repository } {}

	int rowCount(const QModelIndex& parent = QModelIndex())const;
	//QVariant data

};

