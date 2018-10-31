/*********************************************************************
** Program name: OSU Information System (Student.hpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: Header file for student class. 
*********************************************************************/#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "People.hpp"
#include <string>

class Student : public People
{
private:
	double gpa;
	int hours_of_homework;
public:
	Student();
	Student(std::string, int);
	double get_gpa();
	void roll_gpa();
	void do_work(int);
};


#endif