/*********************************************************************
** Program name: OSU Information System (Buildings.hpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: Header file for Buildings class.
*********************************************************************/#ifndef BUILDINGS_HPP
#define BUILDINGS_HPP

#include <string>

class Buildings
{
private:
	std::string building_name;
	std::string building_address;
	int building_size;

public:
	Buildings(std::string, std::string, int);
	std::string get_building_name();
	std::string get_building_address();
	int get_building_size();

};

#endif