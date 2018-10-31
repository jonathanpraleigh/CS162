/*********************************************************************
** Program name: Grocery Shopping List (Main.cpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: Main file for Grocery Shopping List program
*********************************************************************/

#include "List.hpp"
#include "menu.hpp"
#include <vector>

int selection;
int exit_value;

int main()
{
	List grocery_shopping_list;
	
	std::vector<std::string>menu_options = { "1. Add Item", "2. Remove Last Item", "3. Display the Shopping List", "4. Quit" };

	for ( ; ; )
	{

		selection = menu(menu_options);

		if (selection == 1)
		{
			grocery_shopping_list.add_item_to_list();
		}
		else if (selection == 2)
		{
			grocery_shopping_list.remove_item();
		}
		else if (selection == 3)
		{
			grocery_shopping_list.display_the_shopping_list();
		}
		else if (selection == 4)
		{
			grocery_shopping_list.clear_lists();
			return 0;
		}

	}


	
}
