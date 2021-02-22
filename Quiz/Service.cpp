#include "Service.h"

vector<Question> Service::get_questions()
{
    vector<Question> questions_list = this->questions.get_items();

    sort(questions_list.begin(), questions_list.end(), [](Question first, Question second)
        {
            
            return first.getScore() > second.getScore();

        }

    );

    return questions_list;
}

vector<Participant> Service::get_participants()
{
	return this->participants.get_items();
}

vector<Question> Service::get_questions_presenter()
{
    vector<Question> questions_list = this->questions.get_items();

    sort(questions_list.begin(), questions_list.end(), [](Question first, Question second)
        {

            return first.getId() < second.getId();

        }

    );

    return questions_list;
}

void Service::add_question(int id, string text, string answer)
{
    vector<Question> questions = this->questions.get_items();

    for (auto question : questions)
    {
        if (question.getId() == id)
        {
            throw exception();
        }
    }

    Question new_question(id, text, answer, 10);
    this->questions.add_element(new_question);
    this->notify();
}

int Service::check_answer(string answer, int id)
{
    vector<Question> questions = this->questions.get_items();

    for (auto question : questions)
    {
        if (question.getId() == id)
        {
            if (question.getCorrectanswer() == answer)
            {
                return question.getScore();
            }
        }
    }

    return 0;
}

bool Service::was_answered(int id)
{
    vector<int> questions = this->answered_questions;

    for (auto question : questions)
    {
        if (question == id)
        {
            return true;
        }
    }

    return false;
}

void Service::add_answered(int id)
{
    this->answered_questions.push_back(id);

}
