/*********************************************************************
** Program name: OSU Information System ( People.cpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: People class file. members inherited by Instructor
** and Student classes. 
*********************************************************************/
#include <string>
#include <iostream>
#include "People.hpp"

People::People()
{
	name = "";
	age = 0;
}

People::People(std::string set_name, int set_age)
{
	name = set_name;
	age = set_age;
}

void People::do_work(int do_work)
{

	std::cout << "Error.";
}

std::string People::get_name()
{
	return name;
}

int People::get_age()
{
	return age;
}
