#pragma once
#include "Repository.h"
#include "Subject.h"
class Service:public Subject
{
private:
	Repository<Question>& questions;
	Repository<Answer>& answers;
	vector<string> users;
public:

	Service(Repository<Question>& questions, Repository<Answer>& answers) :questions{ questions }, answers{ answers }
	{
		string line;
		ifstream users_file{ "users.txt" };
		while ((getline(users_file,line)))
		{
			this->users.push_back(line);
		}
	}

	vector<Answer> get_answers();
	vector<Question> get_questions();
	vector<string> get_users();
	void add_question(int id,string name,string text);
	void add_answer(int id, int question_id, int votes, string name, string text);
};

