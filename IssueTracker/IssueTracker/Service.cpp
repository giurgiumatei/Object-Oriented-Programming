#include "Service.h"

vector<User> Service::get_users()
{
	return this->users.get_items();
}

vector<Issue> Service::get_issues()
{
	vector<Issue> issues_list = this->issues.get_items();

    sort(issues_list.begin(), issues_list.end(), [](Issue first, Issue second)
        {
            if(first.getStatus()==second.getStatus())
            { 
                return first.getDescription() < second.getDescription();
            }
            return first.getStatus() > second.getStatus();

        }

    );

    return issues_list;
}

void Service::add_issue(string description, string status, string reporter, string solver)
{
    Issue issue(description, status, reporter, solver);
    this->issues.add_element(issue);
}

void Service::remove_issue(string description)
{
    vector<Issue> issues_list = this->issues.get_items();
    int i = 0;
    for (auto issue : issues_list)
    {
        if (issue.getDescription() == description)
        {
            if (issue.getStatus() == "open")
            {
                throw std::exception();
            }
            this->issues.delete_element(i);
            break;
        }
        i++;
    }
}

void Service::update_issue(string description, string status, string resolver)
{
    vector<Issue> issues_list = this->issues.get_items();

    int i = 0;

    for (auto issue : issues_list)
    {
        if (issue.getDescription() == description)
        {
            Issue new_issue(description, status, issue.getReporter(), resolver);
            this->issues.update_element(i, new_issue);
            break;
        }
        i++;
    }

}
