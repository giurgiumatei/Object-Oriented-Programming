#include "Controller.h"

vector<Task> Controller::get_data()
{
	return this->repository.get_data();
}

int Controller::show_total_duration_by_priority(int priority)
{
	vector<Task> task_list=this->get_data();

	int total_duration = 0;
	for (auto task : task_list)
	{

		if (task.get_priority()==priority)
		{
			total_duration += task.get_duration();
		}

	}

	return total_duration;
}
