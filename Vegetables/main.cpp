#include "Vegetables.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repository("C:\\Users\\giurg\\OneDrive\\Facultate\\OOP\\Vegetables\\Vegetables\\test.txt");
    Controller controller(repository);
    Vegetables gui(controller);
    gui.show();
    return a.exec();
}
