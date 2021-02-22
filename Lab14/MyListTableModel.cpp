#include "MyListTableModel.h"
#include <iostream>
void MyListTableModel::add_in_MyList(string title)
{
	controller.add_movie_watchlist_by_title(title);
	insertRows(controller.get_data_watchlist().size(), 1);

}





bool MyListTableModel::insertRows(int position, int rows, const QModelIndex& index)
{
	beginInsertRows(QModelIndex(), position, position + rows - 1);
	endInsertRows();
	return true;
}

bool MyListTableModel::removeRows(int position, int rows, const QModelIndex& index)
{

	beginRemoveRows(QModelIndex(), position, position + rows - 1);
	endRemoveRows();
	return true;
}

int MyListTableModel::rowCount(const QModelIndex& parent) const
{
	return controller.get_data_watchlist().size();
}

int MyListTableModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant MyListTableModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int col = index.column();
	Movie movie = controller.get_data_watchlist()[row];
	int likes = movie.get_likes();
	int year = movie.get_year_of_release();
	string likes_string = std::to_string(likes);
	string year_string = std::to_string(year);
	if (role == Qt::DisplayRole)
	{
		switch (col)
		{
		case 0:
			return QString::fromStdString(movie.get_title());
		case 1:
			return QString::fromStdString(movie.get_genre());
		case 2:
			return QString::fromStdString(year_string);
		case 3:
			return QString::fromStdString(likes_string);
		case 4:
			return QString::fromStdString(movie.get_trailer());
		default:
			break;
		}
	}
	return QVariant();
}

QVariant MyListTableModel::header_data(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section) {
			case 0:
				return QString("Title");
			case 1:
				return QString("Genre");
			case 2:
				return QString("Year of Release");
			case 3:
				return QString("No. of Likes");
			case 4:
				return QString("Trailer");
			default:
				break;
			}
		}
	}
	return QVariant();
}