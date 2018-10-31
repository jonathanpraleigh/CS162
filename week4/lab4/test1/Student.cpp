/*********************************************************************
** Program name: OSU Information System (Student.cpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: Student class. Holds data for student objects and 
** generates random GPA on creation. 
*********************************************************************/
#include "Student.hpp"
#include "People.hpp"
#include <string>
#include <iostream>

Student::Student()
{
	name = "none";
	age = 1;
	gpa = 0;
}

Student::Student(std::string n, int a) 
{
	name = n;
	age = a;
	this->roll_gpa();
	this->get_gpa();

}

void Student::do_work(int do_work)
{
	hours_of_homework = rand() % 12;
	hours_of_homework += do_work;

	std::cout << this->get_name()
		<< " did "
		<< hours_of_homework
		<< " hours of homework.\n";
}

double Student::get_gpa()
{
	return gpa;
}

void Student::roll_gpa()
{
	int roll = rand() % 401;
	gpa = roll / 100.00;
}

