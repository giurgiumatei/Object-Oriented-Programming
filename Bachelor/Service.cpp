#include "Service.h"

Repository<Teacher> Service::get_teacher_data()
{
    return this->teachers_list;
}

void Service::set_teachers_data(Repository<Teacher> teachers_list)
{
    this->teachers_list = teachers_list;
}

Repository<Student> Service::get_student_data() 
{
    return this->students_list;
}

void Service::set_students_data(Repository<Student> students_list)
{
    this->students_list = students_list;
}

