#include "IssueTracker.h"
#include <QtWidgets/QApplication>
#include "Service.h"
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    Repository<User> users{ "users.txt" };
    Repository<Issue> issues{ "issues.txt" };
    Service service(users, issues);

    vector<IssueTracker*> windows;
    int i = 0;
    for (auto user : service.get_users())
    {
        IssueTracker* observer = new IssueTracker(user,service);
        windows.push_back(observer);
        service.add(observer);
        windows[i]->show();
        i++;

    }


    return a.exec();
}
