#include "Service.h"



vector<Star> Service::get_stars()
{
    this->sort_stars();
    return this->stars.get_items();
}

vector<Astronomer> Service::get_astronomers()
{
    return this->astronomers.get_items();
}

void Service::add_star(Star star) //checks if the star is in the list and if not then adds it to the list and call sort_stars() to update the file
{
    vector<Star> stars = this->stars.get_items();
    for (auto s : stars)
    {
        if (s.getName() == star.getName())
        {
            throw exception();
        }
    }
    this->stars.add_element(star);
    this->sort_stars();
}

void Service::sort_stars()
{
   
    sort(this->stars_list.begin(), this->stars_list.end(), [](Star first, Star second)
        {

            return first.getConstelation() < second.getConstelation();

        }

    );
    this->stars.write_to_file(stars_list);
}
