/*********************************************************************
** Program name: Grocery Shopping List (List.cpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: List Class file.
*********************************************************************/
#include "List.hpp"
#include "Item.hpp"
#include "inputValidator.hpp"
#include <string>
#include <iostream>

List::List()
{
	list_size = 0;

	ptr_item_array = new Item[STARTING_VALUE];
	ptr_item_array_swapper = new Item[STARTING_VALUE];
	
	for (int i = 0; i < 4; i++)
		{
			ptr_item_array[i] = Item();
			ptr_item_array_swapper[i] = Item();
		}
	item_name_to_pass = "";
	unit_label_to_pass = "";
	unit_price_to_pass = 0;
	quantity_to_buy_to_pass = 0;
	new_list_size = 0;
	duplicate_test = false;
	unit_price_to_display = 0;
	quantity_to_buy_to_display = 0;
	extended_price = 0;
	total = 0;
	pass = false;
	y_or_n = 'y';
	location_to_insert = 0;

}

/*************************************************************** 
** Function: add_item_to_list
** Description: resizes arrays if larger than 4 and adds a new item
** object to the list.
******************************************************************/


void List::add_item_to_list()
{
	do
	{
		std::cout <<"\nPlease enter the item name.\n";
		getline (std::cin, item_name_to_pass);
		pass = testString(item_name_to_pass);

	} while (pass == false);

	duplicate_test = this->is_it_a_duplicate(item_name_to_pass);

	if (duplicate_test == -2)
	{
		return;
	}

	if (duplicate_test == -1)
	{

		do
		{
			std::cout << "\nPlease enter the unit of measurement.\n";
			getline(std::cin, unit_label_to_pass);

			pass = testString(unit_label_to_pass);

		} while (pass == false);


		do
		{
			std::cout << "\nEnter the unit price (no cents).\n";
			std::cin >> unit_price_to_pass;

			pass = testInteger(unit_price_to_pass, 1, 0, true, false);

		} while (pass == false);


		do
		{
			std::cout << "\nEnter the quantity to buy.\n";
			std::cin >> quantity_to_buy_to_pass;

			pass = testInteger(quantity_to_buy_to_pass, 1, 0, true, false);

		} while (pass == false);


		//Adds the items to the list based on current list size. 	

		if (list_size < 4)
		{

		ptr_item_array[list_size] = Item(item_name_to_pass, unit_label_to_pass,
			unit_price_to_pass, quantity_to_buy_to_pass);
		}
		else
		{

			//delete[] ptr_item_array_swapper; //setting up swapper array for new size and use.

			new_list_size = list_size + 1;

			ptr_item_array_swapper = new Item[new_list_size];

			for (int i = 0; i < list_size; i++)  //populating swapper array
			{
				ptr_item_array_swapper[i] = ptr_item_array[i];

			}

			

			ptr_item_array_swapper[list_size] = Item(item_name_to_pass, unit_label_to_pass,
				unit_price_to_pass, quantity_to_buy_to_pass);

			delete[] ptr_item_array;  //clearing list array up
	
			ptr_item_array = new Item[new_list_size];  //resizing list array
	
			for (int i = 0; i < new_list_size; i++)  //copying contents back
			{
				ptr_item_array[i] = ptr_item_array_swapper[i];
			}

			delete[] ptr_item_array_swapper;  //clearing swapper up

		}

	list_size += 1;
	
	return;
}
	if (duplicate_test >= 0)
	{
		item_overwriter(duplicate_test, item_name_to_pass);
	
	}

}

/***************************************************************
** Function: is_it_a_duplicate
** Description: Tests the name of Item members of the List Class 
** against the return of the get_item_name function and prints a 
** message if duplicate. Returns true or false for loop in the 
** add_item_to_list function. 
******************************************************************/

int List::is_it_a_duplicate(std::string duplicate_checker)
{
	for (int i=0; i<list_size; i++)
	{
		item_name_tester = ptr_item_array[i].get_item_name();
		if (duplicate_checker == item_name_tester)
		{
			char y_or_n_passer;

			std::cout << "Item is already in the list, do you want to update it?";
			//std::cin.ignore();
			std::cin >> y_or_n_passer;

			y_or_n = y_or_n_testChar(y_or_n_passer);

			if (y_or_n == 'Y' || y_or_n == 'y')
			{
				return i;
			}
			if (y_or_n == 'N' || y_or_n == 'n')
			{
				return -2;
			}
			
		}
		
	}
	return -1;
	
}

/***************************************************************
** Function: item_overwriter
** Description: Function for overwriting an existing item on the 
** list. 
******************************************************************/

void List::item_overwriter(int location_to_overwrite, std::string name_to_overwrite)
{
	do
	{
		std::cout << "\nPlease enter the unit of measurement.\n";
		std::cin.ignore();
		getline(std::cin, unit_label_to_pass);

		pass = testString(unit_label_to_display);

	} while (pass == false);


	do
	{
		std::cout << "\nEnter the unit price.\n";
		std::cin.ignore();
		std::cin >> unit_price_to_pass;

		pass = testInteger(unit_price_to_pass, 1, 0, true, false);

	} while (pass == false);


	do
	{
		std::cout << "\nEnter the quantity to buy.\n";
		std::cin.ignore();
		std::cin >> quantity_to_buy_to_pass;

		pass = testInteger(quantity_to_buy_to_pass, 1, 0, true, false);

	} while (pass == false);
	
	ptr_item_array[location_to_overwrite] = Item(name_to_overwrite, unit_label_to_pass,
			unit_price_to_pass, quantity_to_buy_to_pass);
		
}


/***************************************************************
** Function: remove_item
** Description: For lists smaller than 4, copies over a default
** constructed Item to the current item. For lists larger than 4,
** resizes the swapper array, copies the contents over, resizes the
** main array, and copies the contents to the new array. Deletes
** arrays when finished. 
******************************************************************/

void List::remove_item()
{
	
	if (list_size <= 0)
	{
		std::cout << "\nThere are no more items to remove.\n";
		return;
	}
	
	if (list_size > 0 && list_size <= 4)
	{
		new_list_size = list_size - 1;
		
		ptr_item_array[new_list_size] = Item();
	}
	else if (list_size > 4)
	{
		new_list_size = list_size - 1;
		
		delete[] ptr_item_array_swapper;  //setting up swapper array for new size and use.

		ptr_item_array_swapper = new Item[new_list_size];

		for (int i = 0; i < new_list_size; i++)
		{
			ptr_item_array_swapper[i] = ptr_item_array[i];	//populating swapper array	
		}

		delete[] ptr_item_array;  //clearing list array up

		ptr_item_array = new Item[new_list_size];  //resizing list array

		for (int i = 0; i < new_list_size; i++)
		{
			ptr_item_array[i] = ptr_item_array_swapper[i]; //copying contents back
		}

		delete[] ptr_item_array_swapper;

	}


	list_size -= 1;

}

/***************************************************************
** Function: display_the_shopping_list
** Description: pulls get methods for each item in the list array.
** if the item is a default constructed item, does not print. 
** Totals the price
******************************************************************/

void List::display_the_shopping_list()
{
	total = 0;

	std::cout 
		<< "\n==============================\nGrocery List\n==============================\n";

	for (int i=0; i<list_size; i++)
	{
		item_name_to_display = ptr_item_array[i].get_item_name();
		unit_label_to_display = ptr_item_array[i].get_item_unit();
		unit_price_to_display = ptr_item_array[i].get_unit_price();
		quantity_to_buy_to_display = ptr_item_array[i].get_quantity_to_buy();
		
		extended_price = unit_price_to_display * quantity_to_buy_to_display;

		std::cout
			<< item_name_to_display
			<< "\n$ "
			<< unit_price_to_display
			<< " per "
			<< unit_label_to_display
			<< "\n"
			<< "x "
			<< quantity_to_buy_to_display
			<< "\nSubtotal $"
			<< extended_price
			<< "\n";
			
		total += extended_price;

	}
	
	std::cout
		<< "\n--------------------\nTotal : $"
		<< total;
}

int List::get_list_size()
{
	return list_size;
}

void List::clear_lists()
{
	delete[] ptr_item_array;
	//delete[] ptr_item_array_swapper;
}

