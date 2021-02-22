#pragma once
#include "Subject.h"
#include "Repository.h"


class Service :public Subject
{

private:
	Repository<Question>& questions;
	Repository<Participant>& participants;
	vector<int> answered_questions;
public:
	Service(Repository<Question>& questions, Repository<Participant>& participants):
		questions{ questions }, participants{ participants }{}

	vector<Question> get_questions();
	vector<Participant> get_participants();
	vector<Question> get_questions_presenter();
	void add_question(int id, string text, string answer);
	int check_answer(string answer, int id);
	bool was_answered(int id);
	void add_answered(int id);

};

