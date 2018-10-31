/*********************************************************************
** Program name: Grocery Shopping List (inputValidator.cpp)
** Author: Jon Raleigh 
** Date: 4/30/17
** Description: file holds functions that validate input based on 
**		type and parameters passed to the function. Will be
**		expanded based on need for future assignments. 
*********************************************************************/

#include "inputValidator.hpp"
#include <iostream>

/***********************************************************
** testInteger() tests min and max or both  
************************************************************/

bool testInteger(int test, int iv_min, int iv_max, bool iv_min_used, bool iv_max_used)
{
	if (iv_min_used == true && iv_max_used == true)
	{
		if (test >= iv_min && test <= iv_max)
		{
			return true;
		}
		std::cout << "\nPlease enter a valid number.\n";
		return false;
	}

	if (iv_min_used == true && iv_max_used == false)
	{
		if (test >= iv_min)
		{
			return true;
		}
		std::cout << "\nPlease enter a valid number.\n";
		return false;
	}

	if (iv_min_used == false && iv_max_used == true)
	{
		if (test <= iv_max)
		{
			return true;
		}
		std::cout << "\nPlease enter a valid number.\n";
		return false;
	}
	return false;
}

/* Vectors not allowed for this project

/**************************************************************
** testChar tests the character against a list of possibilities
** stored in a vector passed as well. 
*****************************************************************

bool testChar(char iv_char, std::vector<char> iv_char_options)
{
	int iv_char_size;

	iv_char_size = iv_char_options.size();
	
	for (int i = 0; i < iv_char_size; i++)
	{
		if (iv_char == iv_char_options[i])
		{
			return true;
		}

	}

	return false;

}

*/

/**************************************************************
** y_or_n_testChar tests the character against a list of 4 possibilities
** sans vector. Made specifically since YyNn are common inputs.
*****************************************************************/

char y_or_n_testChar(char iv_char)
{
	do
	{
		if (iv_char == 'Y' || iv_char == 'y' || iv_char == 'N' || iv_char == 'n')
		{
			return iv_char;
		}
		std::cout << "/nPlease enter Y or N./n";
		std::cin.ignore();
		std::cin >> iv_char;
	} while (iv_char != 'Y' || iv_char != 'y' || iv_char != 'N' || iv_char != 'n');
	
	return iv_char;
	
}
	

// bool testDouble(double, double, double)
	// implemented in later projects as needed.

bool testString(std::string string_to_test)
{
	// Did not want to exclude names of products including numerals (such as 7*UP). So very simple test here
	// to catch empty strings.
	std::string string_checker = string_to_test;

	int length = string_checker.length();

	if (length > 0)
	{
		return true;
	}
	std::cout << "\nPlease enter a valid name or unit of measurement.\n";
	return false;
}
