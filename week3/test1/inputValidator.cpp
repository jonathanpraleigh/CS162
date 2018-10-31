/*********************************************************************
** Program name: inputValidator.cpp used for dice game program.
** Author: Jon Raleigh 
** Date: 4/23/17
** Description: file holds functions that validate input based on 
**		type and parameters passed to the function. Will be
**		expanded based on need for future assignments. 
*********************************************************************/

#include "inputValidator.hpp"
#include <vector>

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
		return false;
	}

	if (iv_min_used == true && iv_max_used == false)
	{
		if (test >= iv_min)
		{
			return true;
		}
		return false;
	}

	if (iv_min_used == false && iv_max_used == true)
	{
		if (test <= iv_max)
		{
			return true;
		}
		return false;
	}
	return false;
}



/**************************************************************
** testChar tests the character against a list of possibilities
** stored in a vector passed as well. 
*****************************************************************/

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

/**************************************************************
** y_or_n_testChar tests the character against a list of 4 possibilities
** sans vector. Made specifically since YyNn are common inputs.
*****************************************************************/

bool y_or_n_testChar(char iv_char)
{

	if (iv_char == 'Y'|| iv_char == 'y'|| iv_char == 'N'|| iv_char == 'n')
	{
		return true;
	}
	return false;
}
	

// bool testDouble(double, double, double)
	// implemented in later projects as needed.

// bool testString(str)
	// implemented in later projects as needed. 
