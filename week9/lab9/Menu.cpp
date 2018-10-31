/********************************************************************************************
** Program name: Lab 9
** Author: Jon Raleigh
** Date: 6/04/17
** Description: menu functions for program.
*******************************************************************************************/

#include <vector>
#include <string>
#include <iostream>
#include "Menu.hpp"
#include "InputValidator.hpp"

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




