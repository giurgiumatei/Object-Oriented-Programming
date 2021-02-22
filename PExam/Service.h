#pragma once
#include "Subject.h"
#include "Repository.h"


class Service :public Subject
{

private:
	Repository<Astronomer>& astronomers;
	Repository<Star>& stars;
	vector<Star> stars_list;
	//vector<int> answered_questions;
public:
	Service(Repository<Astronomer>& astronomers , Repository<Star>& stars) :
		astronomers{ astronomers }, stars{ stars }{this->stars_list = this->stars.get_items(); }

	vector<Star> get_stars();
	vector<Astronomer> get_astronomers();
	void add_star(Star star);
	void sort_stars();
	//void add_question(int id, string text, string answer);
	
};
