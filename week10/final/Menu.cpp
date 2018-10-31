/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: Menu class file
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

Items Menu::menuItemsDisplay(std::vector<Items>itemMenuOptions)
{
	for (; ; )
	{
		std::cout << "==============================\n\n\n";

		menu_total_options = itemMenuOptions.size();

		for (int count = 0; count < menu_total_options; count++)
		{

			std::cout << count + 1
				<< ". ";
			if( itemMenuOptions[count] == hammer)
				{
					std::cout << "hammer"; 
				}
			if (itemMenuOptions[count] == adaptor)
			{
				std::cout << "adaptor";
			}
			if (itemMenuOptions[count] == broom)
			{
				std::cout << "broom";
			}
			if (itemMenuOptions[count] == combination)
			{
				std::cout << "combination";
			}
			if (itemMenuOptions[count] == keycard)
			{
				std::cout << "keycard";
			}
				std::cout << "\n";
		}

		std::cout << "\n\n==============================\n"
			<< "Select an option\n";

		InputValidator MenuTest;

		menu_selection = MenuTest.testInteger(1, menu_total_options, true, true, true);
		return itemMenuOptions[menu_selection - 1];
	}
}




