/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: header file
*******************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include "Enums.hpp"

class Menu
{
private:
	int menu_selection;
	int menu_total_options;
public:
	int menuDisplay(std::vector<std::string>);
	Items menuItemsDisplay(std::vector<Items>);
	Menu();
};


#endif
