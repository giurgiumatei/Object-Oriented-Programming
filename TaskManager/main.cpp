#include "TaskManager.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	Repository repository("C:\\Users\\giurg\\OneDrive\\Facultate\\OOP\\TaskManager\\TaskManager\\test.txt");
	Controller controller(repository);
	TaskManager gui(controller);
	gui.show();
	return a.exec();
}
