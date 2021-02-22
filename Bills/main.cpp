#include "Bills.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	Repository repository("C:\\Users\\giurg\\OneDrive\\Facultate\\OOP\\Bills\\Bills\\test.txt");
	Controller controller(repository);
	Bills gui(controller);
	gui.show();
	return a.exec();
}
