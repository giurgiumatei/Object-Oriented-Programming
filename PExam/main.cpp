#include "GUI.h"
#include <QtWidgets/QApplication>
#include "Model.h"
#include "Service.h"
#include "Tests.h"
int main(int argc, char* argv[])
{
    //comment the next line in order to run the tests,carefull since it modifies the input file
   // test_all();
    QApplication a(argc, argv);

    Repository<Astronomer> astronomers{ "astronomers.txt" };
    Repository<Star> stars{ "stars.txt" };
    Service service(astronomers, stars);

    vector<GUI*> windows;
    int i = 0;
    Model* idea_model = new Model(service);
    for (auto astronomer : service.get_astronomers())
    {
        GUI* gui = new GUI(idea_model, service, astronomer);
        windows.push_back(gui);
        service.add(gui);
        windows[i]->show();
        i++;

    }


    return a.exec();
}