/*********************************************************************
** Program name: Grocery Shopping List (Item.cpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: Item Class file
*********************************************************************/#include "Item.hpp"
#include <string>

Item::Item()
{
	item_name = "";
	unit = "";
	unit_price = 0;
	quantity_to_buy = 0;
}

Item::Item(std::string set_item_name, std::string set_item_unit, int set_unit_price, int set_quantity_to_buy)
{
	item_name = set_item_name;
	unit = set_item_unit;
	unit_price = set_unit_price;
	quantity_to_buy = set_quantity_to_buy;
}

std::string Item::get_item_name()
{
	return item_name;
}

std::string Item::get_item_unit()
{
	return unit;
}

int Item::get_unit_price()
{
	return unit_price;
}

int Item::get_quantity_to_buy()
{
	return quantity_to_buy;
}