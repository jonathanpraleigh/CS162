/*********************************************************************
** Program name: Menu.cpp (used for Langton Program)
** Author: Jon Raleigh
** Date: 04/16/2017
** Description: Displays a list of menu options and returns an integer
**		corresponding to the option selected. 
*********************************************************************/

#include <vector>
#include <string>
#include <iostream>
#include "menu.hpp"

int menu(std::vector<std::string> f_menu_options)
{
	bool menu_valid;
	int menu_selection;
	int menu_total_options;

	do
	{
		std::cout << "==============================\n\n\n";

		menu_total_options = f_menu_options.size();

		for (int count = 0; count < menu_total_options; count++)
		{
			std::cout << f_menu_options[count]
				<< "\n";
		}

		std::cout << "\n\n==============================\n"
			<< "Select an option\n";
		

		std::cin >> menu_selection;

		menu_valid = testInteger(menu_selection, 1, menu_total_options, true, true);
	} while (menu_valid == false);

	return menu_selection;
}

