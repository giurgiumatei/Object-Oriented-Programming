#pragma once
#include <qabstractitemmodel.h>
#include "Service.h"

class Model :
	public QAbstractTableModel
{
private:
	Service& service;

public:
	Model(Service& service, QObject* parent = NULL) :service{ service } {}
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	void insert_row();



};

