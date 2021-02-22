#include "SearchWindow.h"
#include "algorithm"
SearchWindow::SearchWindow(Service& service,QWidget *parent)
	: service(service),QWidget(parent)
{
	ui.setupUi(this);
}

SearchWindow::~SearchWindow()
{
}

void SearchWindow::update()
{
	this->update_results();
}

void SearchWindow::update_results()
{
	this->ui.answers_list_widget->clear();
	this->ui.matching_question_line_edit->clear();
	string text = this->ui.search_line_edit->text().toStdString();
	if(text!="")
	{
	vector<Question> questions = this->service.get_questions();
	vector<Answer> answers = this->service.get_answers();
	Question matching_question;
	for (Question question : questions)
	{
		if (question.getText().find(text) != string::npos)
		{
			this->ui.matching_question_line_edit->setText(QString::fromStdString(question.getText()));
			matching_question = question;
			break;
		}
	}
	vector<Answer> related;
	for (auto respond : answers)
	{
		if (respond.getQuestionid() == matching_question.getId())
		{
			related.push_back(respond);
		}
	}

	sort(related.begin(), related.end(), [](Answer first, Answer second)
		{
			

			return first.getVotes() > second.getVotes();


		}

	);
	int i = 0;
	for (auto respond : related)
	{
		if (i == 3)
		{
			break;
		}

		this->ui.answers_list_widget->addItem(QString::fromStdString(respond.getText()));
	}
	}

}
