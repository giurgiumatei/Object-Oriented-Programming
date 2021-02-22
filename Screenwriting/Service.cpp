#include "Service.h"

vector<Idea> Service::get_ideas()
{
    vector<Idea> ideas_list = this->ideas.get_items();
    sort(ideas_list.begin(), ideas_list.end(), [](Idea first, Idea second)
        {

            return first.getAct() < second.getAct();


        }

    );
	return ideas_list;
}

vector<Screenwriter> Service::get_screenwriters()
{
	return this->screenwriters.get_items();
}

void Service::add_idea(Idea idea)
{
    this->ideas.add_element(idea);
}

void Service::update_idea(Idea idea)
{
    vector<Idea> ideas_list = this->ideas.get_items();
    int i = 0;

    for (auto idea_iter : ideas_list)
    {
        if (idea_iter.getDescription() == idea.getDescription())
        {
            this->ideas.update_element(i, idea);
        }
        i++;
    }
}

string Service::get_user_status(string name)
{
    for (auto writer : this->get_screenwriters())
    {
        if (writer.getName() == name)
        {
            return writer.getExpertize();
        }
    }

    return "";
}

bool Service::has_accepted_ideas(string name)
{
    for (auto idea : this->ideas.get_items())
    {
        if (idea.getCreator() == name && idea.getStatus() == "accepted")
            return true;
    }
    return false;
}

void Service::save_plot_to_file(string idea_description, string text)
{
    ofstream fileOut(idea_description+".txt");
   
    
        fileOut << text;
  

    fileOut.close();
}

void Service::save_plot(string writer)
{
    ofstream fout(writer + "-Plot.txt");
    vector<Idea> ideas = this->get_ideas();
    for (auto idea : ideas)
    {
        if (idea.getStatus() == "accepted")
        {
            string line = idea.getDescription() + "  {" + idea.getCreator() + "}  " + to_string(idea.getAct());
            fout << line<<endl;
           
        }
    }
}


