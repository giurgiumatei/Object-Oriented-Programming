#include "Model.h"

Model::Model(Service& service) : service(service)
{
}

int Model::columnCount(const QModelIndex& parent) const
{
	return 6;
}

int Model::rowCount(const QModelIndex& parent) const
{
	return service.getIdeas().size();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		switch (section) {
		case 0:
			return "Description";
		case 1:
			return "Status";
		case 2:
			return "Creator";
		case 3:
			return "Act";
		default:
			break;
		}
	}
	return QVariant();
}

Qt::ItemFlags Model::flags(const QModelIndex& index) const
{
	return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

bool Model::setData(const QModelIndex& index, const QVariant& value, int role)
{
	int row = index.row();
	int column = index.column();
	Idea& idea = service.getIdeasSorted()[row];
	if (role == Qt::EditRole)
	{
		switch (column) {
		case 0:
			idea.setDescription(value.toString().toStdString());
			break;
		case 1:
			idea.setStatus(value.toString().toStdString());
			break;
		case 2:
			idea.setCreator(value.toString().toStdString());
			break;
		case 3:
			idea.setAct(value.toString().toStdString());
			break;
		default:
			break;
		}
	}
	emit dataChanged(index, index);
	return true;
}

QVariant Model::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();
	Idea idea = service.getIdeasSorted()[row];
	if (role == Qt::DisplayRole)
		switch (column) {
		case 0:
			return idea.getDescription().c_str();
		case 1:
			return idea.getStatus().c_str();
		case 2:
			return idea.getCreator().c_str();
		case 3:
			return idea.getAct().c_str();
		default:
			break;
		}
	return QVariant();
}


void Model::addIdea(string description, string creator, string act)
{
	beginInsertRows(QModelIndex(), 0, 0);
	service.addIdea(description, creator, act);
	endInsertRows();
}

void Model::acceptIdea(QModelIndex index)
{
	beginInsertRows(QModelIndex(), 0, 0);
	service.acceptIdea(index.row());
	endInsertRows();
}

void Model::savePlot()
{
	service.savePlotController();
}

Model::~Model()
{
}