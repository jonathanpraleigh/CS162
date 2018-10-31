/*********************************************************************
** Program name: OSU Information System (Instructor.hpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: header file for Instructor class. 
*********************************************************************/#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "People.hpp"

class Instructor: public People
{
private:
	double instructor_rating;
	int hours_of_grading;
public:
	Instructor();
	Instructor(std::string, int);
	void roll_instructor_rating();
	double get_instructor_rating();
	void do_work(int);
};

#endif