#include "Domain.h"
Task::Task(string description, int duration, int priority)
{

	this->description = description;
	this->duration = duration;
	this->priority = priority;
}
string Task::get_description() const
{
    return description;
}

void Task::set_description(string description)
{
    this->description = description;
}

int Task::get_duration() const
{
    return duration;
}

void Task::set_duration(int duration)
{
    this->duration = duration;
}

int Task::get_priority() const
{
    return priority;
}

void Task::set_priority(int priority)
{
    this->priority = priority;
}

istream& operator>>(istream& input, Task& task)
{
	string line;
	getline(input, line);

	if (line.size() == 0)
	{
		return input;
	}

	int position = line.find(" | ");
	string description = line.substr(0, position);
	line.erase(0, position + 3);
	position = line.find(" | ");
	string duration_string = line.substr(0, position);
	int duration = stoi(duration_string);
	line.erase(0, position + 3);
	string priority_string = line;
	int priority = stoi(priority_string);

	task = Task(description, duration, priority);

	return input;
}

ostream& operator<<(ostream& output, Task& task)
{
	output << task.get_description ()<< " | " << task.get_duration() << " | " << task.get_priority() << "\n";
	return output;
}
