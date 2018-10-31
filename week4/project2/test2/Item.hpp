/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>


class Item
{
private:
	std::string item_name;
	std::string unit;
	int quantity_to_buy;
	int unit_price;
public:
	Item();
	Item(std::string, std::string, int, int);
	std::string get_item_name();
	std::string get_item_unit();
	int get_quantity_to_buy();
	int get_unit_price();
};
#endif
