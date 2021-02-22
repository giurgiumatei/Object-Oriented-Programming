#include "Exam.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	Repository repository("C:\\Users\\giurg\\OneDrive\\Facultate\\OOP\\Exam\\Exam\\test.txt");
	Controller controller(repository);
	Exam gui(controller);
	gui.show();
	return a.exec();
}
