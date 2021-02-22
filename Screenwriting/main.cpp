#include "Screenwriting.h"
#include <QtWidgets/QApplication>
#include "Model.h"
#include "Service.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    Repository<Idea> ideas{ "ideas.txt" };
    Repository<Screenwriter> screenwriters{ "screenwriters.txt" };
    Service service(ideas, screenwriters);

    vector<Screenwriting*> windows;
    int i = 0;
    Model* idea_model = new Model(service);
    for (auto screenwriter : service.get_screenwriters())
    {
        Screenwriting* observer = new Screenwriting( idea_model,service, screenwriter);
        windows.push_back(observer);
        service.add(observer);
        windows[i]->show();
        i++;

    }


    return a.exec();
}