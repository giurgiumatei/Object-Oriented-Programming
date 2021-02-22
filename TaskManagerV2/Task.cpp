#include "Task.h"

string Task::getDescription() const
{
    return description;
}

void Task::setDescription(string description)
{
    this->description = description;
}

string Task::getStatus() const
{
    return status;
}

void Task::setStatus(string status)
{
    this->status = status;
}

int Task::getId() const
{
    return id;
}

void Task::setId(int id)
{
    this->id = id;
}

ifstream& operator>>(ifstream& input, Task& task)
{
    string line;
    Utilities utilities;



    if (getline(input, line))
    {
        vector<string> parameters = utilities.split_parameters(line, '|');
        task.description = parameters[0];
        task.status = parameters[1];
        task.id = stoi(parameters[2]);

        return input;
    }
    else return input;
}

ofstream& operator<<(ofstream& output, Task& task)
{
    vector<string> parameters = Utilities::split_parameters(task.getDescription(), '-');
    if(parameters.size()==1)
    {
    output << task.getDescription() << "|" << task.getStatus() << "|" << task.getId() << "\n";
    return output;
    }
    else
    {
        output << parameters[1] << "|" << task.getStatus() << "|" << task.getId() << "\n";
        return output;

    }
    
}