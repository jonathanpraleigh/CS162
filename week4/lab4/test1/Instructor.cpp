/*********************************************************************
** Program name: OSU Information System (Instructor.cpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: Instructor class. Inherits from people. contains name 
**		age, and rating. Also randomly generates rating. 
*********************************************************************/#include "Instructor.hpp"
#include "People.hpp"
#include <random>
#include <iostream>


Instructor::Instructor()
{
	name = "none";
	age = 1;
	instructor_rating = 0.0;
}

Instructor::Instructor(std::string n, int a)
{
	name = n;
	age = a;
	this->roll_instructor_rating();
	this->get_instructor_rating();
}

double Instructor::get_instructor_rating()
{
	return instructor_rating;
}

void Instructor::roll_instructor_rating()
{
	int roll = rand() % 501;
	instructor_rating = roll / 100.00;	
}

void Instructor::do_work(int do_work)
{
	hours_of_grading = rand() % 12;
	hours_of_grading += do_work;

	std::cout << this->get_name()
		<< " graded papers for "
		<< hours_of_grading
		<< " hours.\n";
}
