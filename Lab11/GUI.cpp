#include "GUI.h"
#include <qlayout.h>
#include <qformlayout.h>
#include <qgridlayout.h>
#include <qmessagebox.h>
#include <qdebug.h>
#include <qtabbar.h>

GUI::GUI(Controller& controller): controller{controller}
{
	this->initialise_GUI();
	this->populate_list();
	this->connect_signals_and_slots();
}

void GUI::initialise_GUI()
{
	this->movies_list_widget = new QListWidget{};
	this->genre_line_edit = new QLineEdit{};
	this->title_line_edit = new QLineEdit{};
	this->year_line_edit=new QLineEdit{};
	this->likes_line_edit = new QLineEdit{};
	this->trailer_line_edit = new QLineEdit{};
	this->add_button = new QPushButton{"Add"};
	this->delete_button = new QPushButton{"Delete"};
	this->update_button = new QPushButton{ "Update" };

	QVBoxLayout* main_layout = new QVBoxLayout{this};
	QTabWidget* main_tab = new QTabWidget{ this };
	
	
	main_layout->addWidget(this->movies_list_widget);

	QFormLayout* movie_details_layout = new QFormLayout{};
	movie_details_layout->addRow("Title", this->title_line_edit);
	movie_details_layout->addRow("Genre", this->genre_line_edit);
	movie_details_layout->addRow("Year of Release", this->year_line_edit);
	movie_details_layout->addRow("Number of Likes", this->likes_line_edit);
	movie_details_layout->addRow("Trailer", this->trailer_line_edit);

	main_layout->addLayout(movie_details_layout);

	QGridLayout* buttons_layout = new QGridLayout{};
	buttons_layout->addWidget(this->add_button, 0, 0);//add button on row 0 column 0
	buttons_layout->addWidget(this->delete_button, 0, 1);
	buttons_layout->addWidget(this->update_button, 0, 2);

	main_layout->addLayout(buttons_layout);
}

void GUI::populate_list()
{
	
	this->movies_list_widget->clear();
	vector<Movie> movies = this->controller.get_data_controller();

	for (Movie& movie : movies)
	{
		this->movies_list_widget->addItem(QString::fromStdString(movie.get_title() + " - " + std::to_string(movie.get_year_of_release())));
	}


}

void GUI::connect_signals_and_slots()
{
	QObject::connect(this->movies_list_widget, &QListWidget::itemSelectionChanged, [this]() {
		int selected_index = this->get_selected_index();
		if (selected_index < 0)
		{
			return;
		}
		Movie movie = this->controller.get_data_controller()[selected_index];
		this->genre_line_edit->setText(QString::fromStdString(movie.get_genre()));
		this->title_line_edit->setText(QString::fromStdString(movie.get_title()));
		this->year_line_edit->setText(QString::fromStdString(std::to_string(movie.get_year_of_release())));
		this->likes_line_edit->setText(QString::fromStdString(std::to_string(movie.get_likes())));
		this->trailer_line_edit->setText(QString::fromStdString(movie.get_trailer()));
		});

	QObject::connect(this->add_button, &QPushButton::clicked,this, &GUI::add_movie);//connection
	QObject::connect(this->delete_button, &QPushButton::clicked, this, &GUI::delete_movie);//connection
	QObject::connect(this->update_button, &QPushButton::clicked, this, &GUI::update_movie);//connection
}


int GUI::get_selected_index()
{
	QModelIndexList selected_indexes = this->movies_list_widget->selectionModel()->selectedIndexes();
	if (selected_indexes.size() == 0)
	{
		this->genre_line_edit->clear();
		this->title_line_edit->clear();
		this->trailer_line_edit->clear();
		this->year_line_edit->clear();
		this->likes_line_edit->clear();
		return -1;
	}

	int selected_index = selected_indexes.at(0).row();

	return selected_index;
}

void GUI::add_movie()
{
	string genre = this->genre_line_edit->text().toStdString();
	string title = this->title_line_edit->text().toStdString();
	string trailer = this->trailer_line_edit->text().toStdString();
	string likes = this->likes_line_edit->text().toStdString();
	string year = this->year_line_edit->text().toStdString();
	unsigned int number_of_likes = stoul(likes);
	unsigned int year_of_release = stoul(year);

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
	this->movies_list_widget->setCurrentRow(last_element);


}

void GUI::delete_movie()
{
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

void GUI::update_movie()
{

	int selected_index = this->get_selected_index();

	if (selected_index < 0)
	{
		QMessageBox::critical(this, "Error", "No movie was selected! ");
		return;
	}

	string genre = this->genre_line_edit->text().toStdString();
	string title = this->title_line_edit->text().toStdString();
	//qDebug() << QString::fromStdString(title);
	string trailer = this->trailer_line_edit->text().toStdString();
	string likes = this->likes_line_edit->text().toStdString();
	string year = this->year_line_edit->text().toStdString();
	unsigned int number_of_likes = stoul(likes);
	unsigned int year_of_release = stoul(year);

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
