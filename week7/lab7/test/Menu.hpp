/*********************************************************************
** Program name: Menu.hpp
** Author: Jon Raleigh	
** Date: 5/21/17
** Description: header file for menu function file. 
*********************************************************************/

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
