#include "Quiz.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "Presenter.h"
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    Repository<Question> questions{ "questions.txt" };
    Repository<Participant> participants{ "participants.txt" };
    Service service(questions, participants);

    vector<Quiz*> windows;
    int i = 0;
    for (auto participant : service.get_participants())
    {
        Quiz* observer = new Quiz(participant, service);
        windows.push_back(observer);
        service.add(observer);
        windows[i]->show();
        i++;

    }

    Presenter* presenter = new Presenter{ service };
    service.add(presenter);
    presenter->show();


    return a.exec();
}