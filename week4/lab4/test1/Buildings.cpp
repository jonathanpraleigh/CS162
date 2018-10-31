/*********************************************************************
** Program name: OSU Information system (Buildings.cpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: Building class object. Holds details about buildings
*********************************************************************/

#include "Buildings.hpp"
#include <string>

Buildings::Buildings(std::string set_name, std::string set_address, int set_building_size)
{
	building_name = set_name;
	building_address = set_address;
	building_size = set_building_size; //in sq ft
}

std::string Buildings::get_building_name()
{
	return building_name;
}

std::string Buildings::get_building_address()
{
	return building_address;
}

int Buildings::get_building_size()
{
	return building_size;
}
