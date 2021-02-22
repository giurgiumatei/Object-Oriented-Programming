#pragma once
#pragma once
#include "Repository.h"
#include <vector>
#include "Subject.h"

class Service:public Subject
{
private:

	Repository<User>& users;
	Repository<Issue>& issues;

public:
	Service(Repository<User>& users,Repository<Issue>& issues):
		users{ users }, issues{ issues }{}
	vector<User> get_users();
	vector<Issue> get_issues();
	void add_issue(string description, string status, string reporter, string solver);
	void remove_issue(string description);
	void update_issue(string description, string status, string resolver);
};

