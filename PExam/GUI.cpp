#include "GUI.h"
#include "Model.h"
#include <qmessagebox.h>
#include <qboxlayout.h>
GUI::GUI(Model* idea_model, Service& service, Astronomer astronomer, QWidget* parent )
    : service{ service }, astronomer{ astronomer }, idea_model{ idea_model }, QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(astronomer.getName()));
    this->ui.tableView->setModel(idea_model);
    ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   
}

void GUI::update()
{
}

void GUI::search_star()
{
	this->ui.search_list_widget->clear();
	string name = this->ui.search_line_edit->text().toStdString();

	vector<Star> stars_list = this->service.get_stars();
	for (Star star : stars_list)
	{
		if(star.getName().find(name) != string::npos)

		{ 
		this->ui.search_list_widget->addItem(QString::fromStdString(star.getName()));
		}
	}
}

void GUI::filter(int is_checked)
{
	if (is_checked) 
	{
		int i = 0;
		for (Star stars : this->service.get_stars()) {
			{

				if (stars.getConstelation() != this->astronomer.getConstelation())
					this->ui.tableView->hideRow(i);
				i++;
			}
		}
	}
	else {
		int i = 0;
		for (Star s : this->service.get_stars()) {
			{
				this->ui.tableView->showRow(i);
				i++;
			}
		}
	}
}

void GUI::add_star() //takes what it needs from the window and calls Service::add_star() if no exceptions are thrown
{


	try
	{
		string name = this->ui.name_line_edit->text().toStdString();
		if (name == "")
		{
			throw exception();
		}
		int ra = stoi(this->ui.ra_line_edit->text().toStdString());
		int dec = stoi(this->ui.dec_line_edit->text().toStdString());
		int diameter= stoi(this->ui.diameter_line_edit->text().toStdString());
		if (diameter <= 0)
		{
			throw exception();
		}
		Star new_star(name,this->astronomer.getConstelation(),ra,dec,diameter);
		this->service.add_star(new_star);
		this->idea_model->insert_row();
		emit this->idea_model->dataChanged(this->idea_model->index(0, 0), this->idea_model->index(this->service.get_stars().size() + 1, 4));
	}
	catch (const std::exception& exception)
	{
		QMessageBox::critical(this, "Error", "Invalid Input!");

	}

}
