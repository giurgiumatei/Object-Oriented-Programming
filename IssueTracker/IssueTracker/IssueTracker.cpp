#include "IssueTracker.h"
#include <qdebug.h>
#include <qmessagebox.h>
IssueTracker::IssueTracker(User user,Service& service,QWidget *parent)
    : user{ user }, service{ service },QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(user.getName()+" - "+user.getType()));
    this->populate_list();
    this->enable_button();
}

void IssueTracker::update()
{
    this->populate_list();
}

void IssueTracker::populate_list()
{
    this->ui.issues_list_widget->clear();
    vector<Issue> issues = this->service.get_issues();

    for (auto issue : issues)
    {
        
        this->ui.issues_list_widget->addItem(QString::fromStdString(issue.getDescription() + "-" + issue.getStatus()+ "-"+issue.getReporter()+"-"+issue.getSolver()));
    }
}

void IssueTracker::enable_button()
{
   // qDebug() << QString::fromStdString(user.getType());
    if (user.getType() == "tester")
    {
        this->ui.add_issue_button->setEnabled(true);
    }

}

void IssueTracker::enable_resolve()
{
    string line = this->ui.issues_list_widget->currentItem()->text().toStdString();

    vector<string> splitted = Utilities::split_parameters(line, '-');
   
    string status = splitted[1];

    if (status == "open")
    {
        this->ui.resolve_button->setEnabled(true);
    }
    else
    {
        this->ui.add_issue_button->setEnabled(false);
    }
}

void IssueTracker::remove()
{
    try {


        string description = this->ui.remove_issue_line_edit->text().toStdString();

     

        this->service.remove_issue(description);
        this->service.notify();
    }
    catch (const std::exception&)
    {
        QMessageBox::critical(this, "Error", "Status is open!");
        return;
    }
}

void IssueTracker::resolve()
{
    try
    {
        if (this->user.getType() != "programmer")
        {
            throw exception();
        }

    }
    catch (const std::exception&)
    {
        QMessageBox::critical(this, "Error", "Not a programmer!");
        return;
    }
    string line = this->ui.issues_list_widget->currentItem()->text().toStdString();

    vector<string> splitted = Utilities::split_parameters(line, '-');
    string description = splitted[0];
   
    this->service.update_issue(description,"closed",user.getName());
    this->service.notify();
}

void IssueTracker::add()
{

    try {


        string description = this->ui.add_issue_line_edit->text().toStdString();

        if (description == "")
        {
            throw exception();
        }
        vector<Issue> issues_list = this->service.get_issues();
        
        for (auto issue : issues_list)
        {
            if (issue.getDescription() == description)
            {
                throw exception();
            }
        }
        this->service.add_issue(description, "open", this->user.getName(),"No Solver Yet");
        this->service.notify();
    }
    catch (const std::exception&)
    {
        QMessageBox::critical(this, "Error", "Invalid Description!");
        return;
    }

}
