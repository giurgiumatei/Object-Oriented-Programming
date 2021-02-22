#pragma once
#include "Repository.h"
#include "Student.h"
#include "Teacher.h"

class Service
{
private:
	Repository<Teacher> teachers_list;
	Repository<Student> students_list;


public:

	Service(Repository<Teacher> teachers_list, Repository<Student> students_list) :teachers_list{ teachers_list }, students_list{ students_list } {};
	

    Repository<Teacher> get_teacher_data();
    void set_teachers_data(Repository<Teacher> teachers_list);

    Repository<Student> get_student_data();
    void set_students_data(Repository<Student> students_data);

};

