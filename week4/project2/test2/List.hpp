/*********************************************************************
** Program name: Grocery Shopping List (List.hpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: Header file for List class
*********************************************************************/

#ifndef LIST_HPP

#define LIST_HPP


#include "Item.hpp"

class List
{
private:
	int list_size;
	Item *ptr_item_array;
	Item *ptr_item_array_swapper;
	std::string item_name_to_pass;
	std::string unit_label_to_pass;
	int unit_price_to_pass;
	int quantity_to_buy_to_pass;
	int new_list_size;
	int duplicate_test;
	std::string item_name_tester;
	std::string item_name_to_display;
	std::string unit_label_to_display;
	int unit_price_to_display;
	int quantity_to_buy_to_display;
	int extended_price;
	int total;
	bool pass;
	char y_or_n;
	const int STARTING_VALUE = 4;
	int location_to_insert;



public:
	List();
	void add_item_to_list();
	void remove_item();
	void display_the_shopping_list();
	int is_it_a_duplicate(std::string);
	void item_overwriter(int, std::string);
	int get_list_size();
	void clear_lists();
	


};

#endif
