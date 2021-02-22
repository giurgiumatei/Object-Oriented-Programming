#include "TaskManager.h"
#include <qdebug.h>
#include <qmessagebox.h>
TaskManager::TaskManager(Controller& controller,QWidget *parent)
    : controller{ controller }, QMainWindow(parent)
{
    ui.setupUi(this);
    this->populate_list();
    
}



void TaskManager::populate_list()
{
    //QString information;
    this->ui.tasks_list_widget->clear();
    vector<Task> task_list = this->controller.get_data();
   
    /*for (Task& task : task_list)
    {
        qDebug() << QString::fromStdString(task.get_description() + " | " + to_string(task.get_priority()));
    }
   */
    for (Task& task : task_list)
    {

      QString information = QString::fromStdString(task.get_description() + " | " + to_string(task.get_priority()));
      QListWidgetItem* dataline = new QListWidgetItem();
       if (task.get_priority() == 1)
       {
          dataline->setText(information);
            dataline->setFont(QFont("Segoe UI", 12, QFont::Bold, true));
            this->ui.tasks_list_widget->addItem(dataline);
        }
        else
        {
            dataline->setText(information);
            this->ui.tasks_list_widget->addItem(dataline);
       }
        dataline->setText(information);
       this->ui.tasks_list_widget->addItem(dataline);
    }
   
}

void TaskManager::show_total_duration()
{
    string priority = this->ui.priority_line_edit->text().toStdString();
    qDebug() << QString::fromStdString(priority);
    try
    {
        int priority_integer = stoi(priority);
        int total_duration = this->controller.show_total_duration_by_priority(priority_integer);

        QMessageBox::information(this, QString::fromStdString("Total Duration"), QString::fromStdString(to_string(total_duration)));
    }
    catch (const std::exception&)
    {
        QMessageBox::critical(this, "Error", "Invalid priority! ");
        return;
    }
   

    
}

int TaskManager::get_selected_index()
{
    return 0;
}


