#include "MovieGUI.h"
#include <qmessagebox.h>
#include <qdebug.h>
#include <qshortcut.h>
using namespace std;

MovieGUI::MovieGUI(Controller& controller, MyListWidget& mylist_widget, QWidget* parent)
	: QMainWindow(parent), controller{ controller },mylist_widget{mylist_widget}
{
	ui.setupUi(this);
	this->populate_list();
	this->populate_mylist();
	this->connect_signals_and_slots();
	this->index_of_current = 0;
	this->current();
	this->mode = "A";
	this->mode_line_edit();
}

void MovieGUI::connect_signals_and_slots()
{
	QObject::connect(this->ui.delete_button, &QPushButton::clicked, this, &MovieGUI::delete_movie);
	QShortcut* undo_shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
	QShortcut* redo_shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this);
	QObject::connect(undo_shortcut, &QShortcut::activated, this, &MovieGUI::undo);
	QObject::connect(redo_shortcut, &QShortcut::activated, this, &MovieGUI::redo);
}

void MovieGUI::populate_list()
{

	this->ui.movie_list_widget->clear();

	vector<Movie> movies = this->controller.get_data_controller();

	for (Movie& movie : movies)
	{
		this->ui.movie_list_widget->addItem(QString::fromStdString(movie.get_title() + " - " + std::to_string(movie.get_year_of_release())));
	}
}

void MovieGUI::populate_mylist()
{
	//this->mylist_widget.clear();
	vector<Movie> mylist_movies = this->controller.get_data_watchlist();

	for (Movie& movie : mylist_movies)
	{

		//	this->ui.mylist_list_widget->addItem(QString::fromStdString(movie.get_title() + " - " + std::to_string(movie.get_year_of_release())));
	}
}

void MovieGUI::current()
{
	vector<Movie> mylist_movies = this->controller.get_data_controller();
	if (mylist_movies.size() == 0)
	{
		return;
	}
	this->ui.current_line_edit->setText(QString::fromStdString(mylist_movies[this->index_of_current].get_title()));
}




int MovieGUI::get_selected_index()
{
	QModelIndexList selected_indexes = this->ui.movie_list_widget->selectionModel()->selectedIndexes();
	if (selected_indexes.size() == 0)
	{
		this->ui.genre_line_edit->clear();
		this->ui.title_line_edit->clear();
		this->ui.trailer_line_edit->clear();
		this->ui.year_line_edit->clear();
		this->ui.likes_line_edit->clear();
		return -1;
	}

	int selected_index = selected_indexes.at(0).row();

	return selected_index;
}

void MovieGUI::change_selection_mode()
{

	if (this->mode == "A")
	{
		this->mode = "B";
		qDebug() << QString::fromStdString("DA");
	}

	else
	{
		this->mode = "A";
	}
	this->mode_line_edit();

}

void MovieGUI::mode_line_edit()
{

	this->ui.mode_line_edit->setText(QString::fromStdString("Mode " + this->mode));
}

void MovieGUI::add_movie()
{

	try
	{
		if (this->mode == "B")
		{
			throw std::exception();
		}
	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "Must be in Administrator Mode! ");
		return;
	}
	string genre = this->ui.genre_line_edit->text().toStdString();
	string title = this->ui.title_line_edit->text().toStdString();
	string trailer = this->ui.trailer_line_edit->text().toStdString();
	string likes = this->ui.likes_line_edit->text().toStdString();
	string year = this->ui.year_line_edit->text().toStdString();
	unsigned int number_of_likes;
	unsigned int year_of_release;
	try
	{
		number_of_likes = stoul(likes);
		year_of_release = stoul(year);

	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "Invalid Arguments! ");
		return;
	}


	try
	{
		this->controller.add_movie_controller(title, genre, year_of_release, number_of_likes, trailer);

	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "Movie already in the list! ");
		return;

	}


	this->populate_list();

	int last_element = this->controller.get_data_controller().size() - 1;
	this->ui.movie_list_widget->setCurrentRow(last_element);


}







void MovieGUI::delete_movie()
{

	try
	{
		if (this->mode == "B")
		{
			throw std::exception();
		}
	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "Must be in Administrator Mode! ");
		return;
	}
	int selected_index = this->get_selected_index();

	if (selected_index < 0)
	{
		QMessageBox::critical(this, "Error", "No movie was selected! ");
		return;
	}

	string title = this->controller.get_data_controller()[selected_index].get_title();


	try
	{
		this->controller.remove_movie_controller(title);
	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "Movie not in the list! ");
		return;
	}



	this->populate_list();


}

void MovieGUI::open_watchlist_in_new_window()
{
	mylist_widget.show();
}

void MovieGUI::undo()
{
	try
	{
		this->controller.undo();
	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "No more undos! ");
		return;
	}

	this->populate_list();

}

void MovieGUI::redo()
{
	try
	{
		this->controller.redo();
	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "No more redos! ");
		return;
	}

	this->populate_list();
}

void MovieGUI::update_movie()
{

	try
	{
		if (this->mode == "B")
		{
			throw std::exception();
		}
	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "Must be in Administrator Mode! ");
		return;
	}

	int selected_index = this->get_selected_index();

	if (selected_index < 0)
	{
		QMessageBox::critical(this, "Error", "No movie was selected! ");
		return;
	}

	string genre = this->ui.genre_line_edit->text().toStdString();
	string title = this->ui.title_line_edit->text().toStdString();
	//qDebug() << QString::fromStdString(title);
	string trailer = this->ui.trailer_line_edit->text().toStdString();
	string likes = this->ui.likes_line_edit->text().toStdString();
	string year = this->ui.year_line_edit->text().toStdString();
	unsigned int number_of_likes;
	unsigned int year_of_release;
	try
	{
		number_of_likes = stoul(likes);
		year_of_release = stoul(year);

	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "Invalid Arguments! ");
		return;
	}

	try
	{
		this->controller.update_movie_controller(title, genre, year_of_release, number_of_likes, trailer);

	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "Movie not in the list! ");
		return;

	}



	this->populate_list();



}

void MovieGUI::select_movie()
{
	int selected_index = this->get_selected_index();
	if (selected_index < 0)
	{
		return;
	}
	Movie movie = this->controller.get_data_controller()[selected_index];
	this->ui.genre_line_edit->setText(QString::fromStdString(movie.get_genre()));
	this->ui.title_line_edit->setText(QString::fromStdString(movie.get_title()));
	this->ui.year_line_edit->setText(QString::fromStdString(std::to_string(movie.get_year_of_release())));
	this->ui.likes_line_edit->setText(QString::fromStdString(std::to_string(movie.get_likes())));
	this->ui.trailer_line_edit->setText(QString::fromStdString(movie.get_trailer()));


}

void MovieGUI::open_watchlist()
{
	try
	{
		if (this->mode == "A")
		{
			throw std::exception();
		}
	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "Must be in User Mode! ");
		return;
	}
	this->controller.open_watchlist();
}

void MovieGUI::next()
{

	try
	{
		if (this->mode == "A")
		{
			throw std::exception();
		}
	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "Must be in User Mode! ");
		return;
	}
	this->index_of_current++;
	if (this->index_of_current == this->controller.get_length_of_data())
	{
		this->index_of_current = 0;
	}

	this->current();


}

void MovieGUI::save()
{

	try
	{
		if (this->mode == "A")
		{
			throw std::exception();
		}
	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "Must be in User Mode! ");
		return;
	}
	Movie new_movie = this->controller.get_data_controller()[this->index_of_current];
	string genre = new_movie.get_genre();
	string title = new_movie.get_title();
	string trailer = new_movie.get_trailer();
	unsigned int number_of_likes = new_movie.get_likes();
	unsigned int year_of_release = new_movie.get_year_of_release();



	try
	{
		//this->controller.add_movie_watchlist(title, genre, year_of_release, number_of_likes, trailer);
		this->mylist_widget.add_in_MyList(title);

	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "Movie already in the list! ");
		return;

	}


	this->populate_mylist();

	int last_element = this->controller.get_data_watchlist().size() - 1;
	//this->ui.mylist_list_widget->setCurrentRow(last_element);
}

void MovieGUI::list_by_filter()
{

	try
	{
		if (this->mode == "A")
		{
			throw std::exception();
		}
	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "Must be in User Mode! ");
		return;
	}
	string genre = this->ui.mylist_genre_line_edit->text().toStdString();
	string likes = this->ui.mylist_likes_line_edit->text().toStdString();
	unsigned int number_of_likes;

	try
	{
		number_of_likes = stoul(likes);


	}
	catch (const std::exception&)
	{
		QMessageBox::critical(this, "Error", "Invalid Arguments! ");
		return;
	}



	if (genre == "")
	{
		this->populate_list();
	}
	else
	{

		vector<Movie> movies = this->controller.get_data_controller();
		vector<Movie> filtered_list;
		for (auto movie : movies)
		{
			if (movie.get_genre() == genre && movie.get_likes() >= number_of_likes)
			{
				filtered_list.push_back(movie);

			}

		}

		this->ui.movie_list_widget->clear();


		for (auto movie : filtered_list)
		{

			this->ui.movie_list_widget->addItem(QString::fromStdString(movie.get_title() + " - " + std::to_string(movie.get_year_of_release())));
		}

	}

}
