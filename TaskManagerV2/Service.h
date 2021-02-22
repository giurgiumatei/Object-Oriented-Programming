#pragma once
#include "Repository.h"
#include <vector>
#include "Subject.h"

class Service:public Subject
{

private:
	Repository<Task>& tasks;
	Repository<Programmer>& programmers;


public:
	Service(Repository<Programmer>& programmers, Repository<Task>& tasks) :
		programmers{ programmers }, tasks{ tasks }{}

	vector<Programmer> get_programmers();
	vector<Task> get_tasks();
	void add_task(string description, string status, int id);
	void delete_task(string description);
	void update_task(string description);



};

