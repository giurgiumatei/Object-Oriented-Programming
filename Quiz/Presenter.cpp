#include "Presenter.h"
#include "qmessagebox.h"
Presenter::Presenter(Service& service, QWidget* parent)
	: service{ service },QWidget(parent)
{
	ui.setupUi(this);
	this->populate_list();
}

Presenter::~Presenter()
{
}

void Presenter::update()
{
    this->populate_list();
}

void Presenter::populate_list()
{
	this->ui.questions_list_widget->clear();
	vector<Question> questions = this->service.get_questions_presenter();

	for (auto question : questions)
	{

		this->ui.questions_list_widget->addItem(QString::fromStdString(to_string(question.getId()) + "-" + question.getText() + "-"+question.getCorrectanswer()+"-" + to_string(question.getScore())));
	}
}

void Presenter::add_question()
{
    try {


        int id = stoi(this->ui.id_line_edit->text().toStdString());

        string text = this->ui.text_line_edit->text().toStdString();
        if (text == "")
        {
            throw exception();
        }

        string answer = this->ui.answer_line_edit->text().toStdString();
       
        
        this->service.add_question(id, text, answer);
        this->service.notify();
    }
    catch (const std::exception&)
    {
        QMessageBox::critical(this, "Error", "Invalid Parameters!");
        return;
    }
}
