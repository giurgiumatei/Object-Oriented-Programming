#include "Service.h"
#include <algorithm>
#include <qdebug.h>
vector<Programmer> Service::get_programmers()
{
	return this->programmers.get_items();
}

vector<Task> Service::get_tasks()
{
	vector<Task> tasks_list = this->tasks.get_items();
    qDebug() << tasks_list.size();
    sort(tasks_list.begin(), tasks_list.end(), [](Task first, Task second)
        {

            return first.getStatus() > second.getStatus();


        }

    );

    return tasks_list;
}

void Service::add_task(string description, string status, int id)
{
    Task new_task(description, status, id);

    this->tasks.add_element(new_task);

}

void Service::delete_task(string description)
{
    vector<Task> tasks_list = this->tasks.get_items();
    int i = 0;
    for (auto task : tasks_list)
    {
        if (task.getDescription() == description)
        {
            this->tasks.delete_element(i);
            break;
        }
        i++;
    }
}

void Service::update_task(string description)
{
    vector<Task> tasks_list = this->tasks.get_items();
    int i = 0;

    for (auto task : tasks_list)
    {
        if (task.getDescription().find(description) != string::npos)
        {
            task.setStatus("closed");
            task.setDescription(description);
            this->tasks.update_element(i, task);
            break;
        }
       
        if (description.find(task.getDescription())!= string::npos)
        {
            task.setStatus("progress");
            task.setDescription(description);
            this->tasks.update_element(i,task);
            break;
        }
        i++;
    }
}
