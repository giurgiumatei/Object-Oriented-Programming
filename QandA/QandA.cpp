#include "QandA.h"
#include "algorithm"
#include <qmessagebox.h>
#include <qdebug.h>
QandA::QandA(Service& service,string user,QWidget *parent)
    : service(service),user(user),QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(user));
    this->populate_questions_table();
}



void QandA::populate_questions_table()
{
    this->ui.questions_list_widget->clear();
    vector<Question> questions = this->service.get_questions();
  //  vector<Answer> answers = this->service.get_answers();
    

    for (auto question : questions)
    {
        this->ui.questions_list_widget->addItem(QString::fromStdString(question.getText()));
    }
}

void QandA::populate_answers_table(int q_id)
{
    vector<Answer> answers = this->service.get_answers();

    this->ui.answers_list_widget->clear();

    for (Answer respond : answers)
    {
        if (respond.getQuestionid() == q_id)
        {
            QListWidgetItem* dataline = new QListWidgetItem();
            dataline->setText(QString::fromStdString(respond.getText()));
            if (respond.getName() == user)
            {
                dataline->setBackground(QBrush(QColor(Qt::GlobalColor::yellow)));
            }
            this->ui.answers_list_widget->addItem(dataline);
        }
    }
}

void QandA::update()
{
   
    this->populate_questions_table();
  //  this->question_selected();
    
}

void QandA::question_selected()
{

    int selected_index = this->ui.questions_list_widget->selectionModel()->selectedIndexes().at(0).row();
    Question question = this->service.get_questions()[selected_index];
    vector<Answer> answers = this->service.get_answers();

    this->ui.answers_list_widget->clear();

    for (Answer respond : answers)
    {
        if (respond.getQuestionid() == question.getId())
        {
            QListWidgetItem* dataline = new QListWidgetItem();
            dataline->setText(QString::fromStdString(respond.getText()));
            if (respond.getName() == user)
            {
                dataline->setBackground(QBrush(QColor(Qt::GlobalColor::yellow)));
            }
           this->ui.answers_list_widget->addItem(dataline);
        }

    }
}

void QandA::answer()
{
    try {


        string text = this->ui.respond_line_edit->text().toStdString();
        
       
        if (text == "")
        {
            throw exception();
        }
        string questionstring = ui.questions_list_widget->currentItem()->text().toStdString();
        qDebug() << QString::fromStdString(questionstring);
        vector<Question> questions = this->service.get_questions();
        int q_id=0;
        for (auto question : questions)
        {
            if (question.getText() == questionstring)
            {
                q_id = question.getId();
            }
        }
        this->service.add_answer(this->service.get_answers().size(),q_id, 0, this->user, text);
        this->populate_answers_table(q_id);
      //  this->service.notify();
    }
    catch (const std::exception&)
    {
        QMessageBox::critical(this, "Error", "Empty Answer!");
        return;
    }
}

void QandA::ask()
{
    try {


        string description = this->ui.ask_question_line_edit->text().toStdString();

        if (description == "")
        {
            throw exception();
        }

        this->service.add_question(this->service.get_questions().size(), user, description);
        this->service.notify();
    }
    catch (const std::exception&)
    {
        QMessageBox::critical(this, "Error", "Empty Question!" );
        return;
    }



}
