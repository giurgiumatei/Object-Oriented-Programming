#include "Quiz.h"
#include <qdebug.h>
Quiz::Quiz(Participant participant, Service& service, QWidget *parent)
    :participant{ participant }, service{ service }, QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(participant.getName()));
    this->populate_list();
    this->ui.score_line_edit->setText(QString::fromStdString(to_string(this->participant.getScore())));
}

void Quiz::update()
{
    this->populate_list();
    this->ui.score_line_edit->setText(QString::fromStdString(to_string(this->participant.getScore())));
}

void Quiz::populate_list()
{
    this->ui.questions_list_widget->clear();
    vector<Question> questions = this->service.get_questions();

    for (auto question : questions)
    {
        if (this->service.was_answered(question.getId()) == false)
        {
            this->ui.questions_list_widget->addItem(QString::fromStdString(to_string(question.getId()) + "-" + question.getText() + "-" + to_string(question.getScore())));
        }
        else
        {
            QString information = QString::fromStdString(to_string(question.getId()) + "-" + question.getText() + "-" + to_string(question.getScore()));
            QListWidgetItem* dataline = new QListWidgetItem();
            dataline->setText(information);
           
            dataline->setBackground(QBrush(QColor(Qt::GlobalColor::green)));
            this->ui.questions_list_widget->addItem(dataline);
            
        }
    }
}

void Quiz::enable_answer()
{
   
    
    string line = this->ui.questions_list_widget->currentItem()->text().toStdString();

    vector<string> splitted = Utilities::split_parameters(line, '-');
    int id = stoi(splitted[0]);

        if (this->service.was_answered(id)==false)
        {
          //  qDebug() << "da";
            this->ui.answer_button->setEnabled(true);
        }
        else
        {
            this->ui.answer_button->setEnabled(false);
        }
 }


void Quiz::answer()
{ 
    string line = this->ui.questions_list_widget->currentItem()->text().toStdString();

    vector<string> splitted = Utilities::split_parameters(line, '-');
    int id  = stoi(splitted[0]);
    string answer = this->ui.answer_line_edit->text().toStdString();

    this->participant.setScore(service.check_answer(answer, id) + this->participant.getScore());

    this->service.add_answered(id);
   
    this->service.notify();
    

}
