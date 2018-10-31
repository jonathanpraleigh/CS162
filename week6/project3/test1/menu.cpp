/*********************************************************************
** Program name: menu.cpp (used for project 3)
** Author: Jon Raleigh
** Date: 5/14/2017
** Description: Displays a list of menu options and returns an integer
**		corresponding to the option selected. 
*********************************************************************/

#include <vector>
#include <string>
#include <iostream>
#include "menu.hpp"
#include "inputValidator.hpp"

Menu::Menu()
{
	menu_selection = 0;
	menu_total_options = 0;
}

int Menu::menuDisplay(std::vector<std::string> f_menu_options)
{
	for (; ; )
	{
		std::cout << "==============================\n\n\n";

		menu_total_options = f_menu_options.size();

		for (int count = 0; count < menu_total_options; count++)
		{

			std::cout << count + 1
				<< ". "
				<< f_menu_options[count]
				<< "\n";
		}

		std::cout << "\n\n==============================\n"
			<< "Select an option\n";

		InputValidator MenuTest;

		menu_selection = MenuTest.testInteger(1, menu_total_options, true, true, true);
		return menu_selection;
	} 
}




