/*********************************************************************
** Program name: OSU Information System (People.hpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: Header file for People class. 
*********************************************************************/#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include <string>

class People
{
protected:
	int age;
	std::string name;
	int work;
public:
	virtual void do_work(int);
	People();
	People(std::string name, int age);
	std::string get_name();
	int get_age();
};

#endif