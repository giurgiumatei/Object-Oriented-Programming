#include "TaskManagerV2.h"
#include "qdebug.h"
#include <qmessagebox.h>
#include "Utilities.h"
TaskManagerV2::TaskManagerV2(Service& service,string name,QWidget *parent)
    :service{ service }, name{ name }, QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(name));
    this->populate_list();
}

void TaskManagerV2::update()
{
    this->populate_list();
}

void TaskManagerV2::populate_list()
{
    this->ui.tasks_list_widget->clear();
    vector<Task> tasks = this->service.get_tasks();

    for (auto task : tasks)
    {
        qDebug() << QString::fromStdString(task.getDescription() + " " + task.getStatus());
        this->ui.tasks_list_widget->addItem(QString::fromStdString(task.getDescription()+ "-" +task.getStatus()));
    }
}

void TaskManagerV2::remove()
{
    try {


        string description = this->ui.tasks_line_edit->text().toStdString();

        if (description == "")
        {
            throw exception();
        }
       
        this->service.delete_task(description);
        this->service.notify();
    }
    catch (const std::exception&)
    {
        QMessageBox::critical(this, "Error", "Empty Description!");
        return;
    }
}

void TaskManagerV2::start()
{
    string line = this->ui.tasks_list_widget->currentItem()->text().toStdString();

    vector<string> splitted = Utilities::split_parameters(line, '-');
    string description = splitted[0];
    string status = splitted[1];

    try
    {
        if (status != "open")
        {
            throw exception();
        }
    }
    catch (const std::exception&)
    {
        QMessageBox::critical(this, "Error", "Task is not open!");
        return;
    }
    description = this->name + "-" + description;
    this->service.update_task(description);
    this->service.notify();
}

void TaskManagerV2::done()
{
    string line = this->ui.tasks_list_widget->currentItem()->text().toStdString();

    vector<string> splitted = Utilities::split_parameters(line, '-');
    string name = splitted[0];
    string description = splitted[1];
    try
    {
        if (splitted.size() != 3)
        {
            throw exception();
        }

    }
    catch (const std::exception&)
    {
        QMessageBox::critical(this, "Error", "Task was not open by this programmer!");
        return;
    }
    string status = splitted[2];
    try
    {
        if (name != this->name)
        {
            throw exception();
        }
    }
    catch (const std::exception&)
    {
        QMessageBox::critical(this, "Error", "Task was not open by this programmer!");
        return;
    }

    try
    {
        if (status != "progress")
        {
            throw exception();
        }
    }
    catch (const std::exception&)
    {
        QMessageBox::critical(this, "Error", "Task is not in progress!");
        return;
    }
    
    this->service.update_task(description);
    this->service.notify();
}

void TaskManagerV2::add()
{
    try {


        string description = this->ui.tasks_line_edit->text().toStdString();

        if (description == "")
        {
            throw exception();
        }
        vector<Programmer> programmers_list=this->service.get_programmers();
        int p_id=-1;
        for (auto programmer : programmers_list)
        {
            if (programmer.getName() == this->name)
            {
                p_id = programmer.getId();
            }
        }
        this->service.add_task(description, "open", p_id);
        this->service.notify();
    }
    catch (const std::exception&)
    {
        QMessageBox::critical(this, "Error", "Empty Description!");
        return;
    }

}
