#include "Screenwriting.h"
#include "Model.h"
#include <qmessagebox.h>
#include "EditWidget.h"
#include <qboxlayout.h>
using namespace std;
Screenwriting::Screenwriting(Model* idea_model,Service& service, string name, QWidget* parent )
    : service{ service }, name{ name }, idea_model{ idea_model }, QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(name));
    
    this->ui.tableView->setModel(idea_model);
    ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	this->ui.develop_button->setEnabled(false);
	this->disable_button();

}

void Screenwriting::disable_button()
{
	if (this->service.has_accepted_ideas(this->name))
	{
		this->ui.develop_button->setEnabled(true);
	}
}

void Screenwriting::idea_selected()
{

	int index= this->ui.tableView->currentIndex().row();
	Idea idea = this->service.get_ideas()[index];

	if (idea.getStatus() == "accepted" || this->service.get_user_status(this->name) != "senior")
	{
		this->ui.accept_button->setDisabled(true);
	}
	else
	{
		this->ui.accept_button->setDisabled(false);
	}
}

void Screenwriting::accept()
{

	int index = this->ui.tableView->currentIndex().row();
	Idea idea = this->service.get_ideas()[index];
	idea.setStatus("accepted");
	this->service.update_idea(idea);
	this->disable_button();
	emit this->idea_model->dataChanged(this->idea_model->index(0, 0), this->idea_model->index(this->service.get_ideas().size() + 1, 4));
}

void Screenwriting::open_edit_window()
{

	EditWidget* edit_widget = new EditWidget{};
	QVBoxLayout* layout = new QVBoxLayout{ edit_widget };
	vector<Idea> ideas = this->service.get_ideas();

	for (auto idea : ideas)
	{
		if (idea.getStatus() == "accepted" && idea.getCreator() == this->name)
		{
			QTextEdit* text_edit = new QTextEdit();
			layout->addWidget(text_edit);
			QPushButton* save_button = new QPushButton("Save");
			layout->addWidget(save_button);
			QObject::connect(save_button, &QPushButton::clicked, this, [this, text_edit, idea]() {

				string text = text_edit->toPlainText().toStdString();
				this->service.save_plot_to_file(idea.getDescription(),text); //or does the description have to be changed?

				});
		}
	}

	edit_widget->show();

}

void Screenwriting::save_plot()
{

	this->service.save_plot(this->name);
}

void Screenwriting::propose()
{

	try
	{
		string description = this->ui.description_line_edit->text().toStdString();
		int act = stoi(this->ui.act_line_edit->text().toStdString());
		Idea idea(description, "proposed", this->name, act);
		this->service.add_idea(idea);
		this->idea_model->insert_row();
		emit this->idea_model->dataChanged(this->idea_model->index(0, 0), this->idea_model->index(this->service.get_ideas().size()+1,4));
	}
	catch (const std::exception& exception)
	{
		QMessageBox::critical(this, "Error", exception.what());

	}

}
