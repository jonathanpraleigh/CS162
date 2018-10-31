/********************************************************************************************
** Program name: Lab 9
** Author: Jon Raleigh
** Date: 6/04/17
** Description: header for Menu class
*******************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>

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
