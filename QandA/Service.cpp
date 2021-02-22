#include "Service.h"
#include <algorithm>
vector<Answer> Service::get_answers()
{
	return this->answers.get_items();
}

vector<Question> Service::get_questions()
{
    vector<Question> questions_list = this->questions.get_items();
    vector<Answer> answers_list = this->get_answers();
    sort(questions_list.begin(), questions_list.end(), [answers_list](Question first, Question second)
        {
            int first_question_answers = 0, second_question_answers = 0;

            for (auto respond : answers_list)
            {
                if (respond.getQuestionid() == first.getId())
                {
                    first_question_answers++;
                }
                else if (respond.getQuestionid() == second.getId())
                {
                    second_question_answers++;
                }
            }

            return first_question_answers > second_question_answers;


        }

    );
	return questions_list;
}

vector<string> Service::get_users()
{
	return this->users;
}

void Service::add_question(int id, string name, string text)
{
	Question new_question = Question(id, text, name);
	this->questions.add_element(new_question);
}

void Service::add_answer(int id, int question_id, int votes, string name, string text)
{
	Answer new_answer = Answer(id, question_id, votes, name, text);
	this->answers.add_element(new_answer);
}
