#pragma once
#include "Repository.h"
#include <vector>
#include "Subject.h"

class Service :public Subject
{

private:
	Repository<Idea>& ideas;
	Repository<Screenwriter>& screenwriters;


public:
	Service(Repository<Idea>& ideas, Repository<Screenwriter>& screenwriters) :
		ideas{ ideas }, screenwriters{ screenwriters }{}

	vector<Idea> get_ideas();
	vector<Screenwriter> get_screenwriters();
	void add_idea(Idea idea);
	void update_idea(Idea idea);
	string get_user_status(string name);
	bool has_accepted_ideas(string name);
	void save_plot_to_file(string idea_description, string text);
	void save_plot(string writer);



};