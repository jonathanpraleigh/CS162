/********************************************************************************************
** Program name: SearchAndSort
** Author: Jon Raleigh
** Date: 5/28/17
** Description: Uses XXXX search method, XXXX sort method, and Binary Search to locate
**				values within four text files.
*******************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>

class Menu
{
private:
	int menu_selection;
	int menu_total_options;
public:
	int menuDisplay(std::vector<std::string>);
	Menu();
};


#endif
