#include "QandA.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "SearchWindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository<Question> questions_repository("questions.txt");
    Repository<Answer> answers_repository("answers.txt");
    Service service(questions_repository, answers_repository);
    

    vector<QandA*> windows;
    int i=0;
    for (auto user : service.get_users())
    {
        QandA* observer = new QandA(service, user);
        windows.push_back(observer);
        service.add(observer);
        windows[i]->show();
        i++;
    }

    SearchWindow* search_window=new SearchWindow{ service };
    service.add(search_window);
    search_window->show();
    
    return a.exec();
}
