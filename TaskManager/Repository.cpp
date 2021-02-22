#include "Repository.h"

vector<Task> Repository::read_from_file()
{
    ifstream file_reader(this->file_location);

    Task new_task;

    vector<Task> items_list;

    while (file_reader >> new_task)
    {
        items_list.push_back(new_task);

    }

    file_reader.close();

    return items_list;
}

void Repository::write_to_file(vector<Task> task_list)
{
    ofstream file_writer(this->file_location);



    for (auto task : task_list)
    {
        file_writer << task;
    }

    file_writer.close();
}

bool sorting_criteria(Task first_task, Task second_task)
{
    return first_task.get_priority() < second_task.get_priority();
}
vector<Task> Repository::get_data()
{
    vector<Task> task_list = this->read_from_file();
    sort(task_list.begin(), task_list.end(), sorting_criteria);

    return task_list;
}
