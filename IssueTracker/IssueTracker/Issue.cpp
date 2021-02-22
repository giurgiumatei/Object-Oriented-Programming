#include "Issue.h"

string Issue::getDescription() const
{
    return description;
}

void Issue::setDescription(string description)
{
    this->description = description;
}

string Issue::getStatus() const
{
    return status;
}

void Issue::setStatus(string status)
{
    this->status = status;
}

string Issue::getReporter() const
{
    return reporter;
}

void Issue::setReporter(string reporter)
{
    this->reporter = reporter;
}

string Issue::getSolver() const
{
    return solver;
}

void Issue::setSolver(string solver)
{
    this->solver = solver;
}

ifstream& operator>>(ifstream& input, Issue& issue)
{
    string line;
    Utilities utilities;



    if (getline(input, line))
    {
        vector<string> parameters = utilities.split_parameters(line, '|');
        issue.description = parameters[0];
        issue.status = parameters[1];
        issue.reporter = parameters[2];
        issue.solver = parameters[3];

        return input;
    }
    else return input;
}

ofstream& operator<<(ofstream& output, Issue& issue)
{
    output << issue.getDescription() << "|" << issue.getStatus() << "|" << issue.getReporter() << "|" << issue.getSolver() << "\n";
    return output;
}
