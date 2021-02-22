#include "TaskManagerV2.h"
#include <QtWidgets/QApplication>
#include "Service.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    Repository<Task> tasks{ "tasks.txt" };
    Repository<Programmer> programmers{ "programmers.txt" };
    Service service(programmers, tasks);
   
    vector<TaskManagerV2*> windows;
    int i = 0;
    for (auto programmer : service.get_programmers())
    {
        TaskManagerV2* observer = new TaskManagerV2(service, programmer.getName());
        windows.push_back(observer);
        service.add(observer);
        windows[i]->show();
        i++;

    }

    
    return a.exec();
}
