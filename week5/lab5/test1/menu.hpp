/*********************************************************************
** Program name: OSU Information System (menu.hpp)
** Author: Jon Raleigh	
** Date: 5/07/17
** Description: header file for menu function file. 
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include "inputValidator.hpp"

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
