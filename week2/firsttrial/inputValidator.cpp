/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/
#include "inputValidator.hpp"
#include <vector>

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
	
	// test to make sure character
	// return false if not. true if it is.

// bool testDouble(double, double, double)
	// implemented in later projects as needed.

// bool testString(str)
	// implemented in later projects as needed. 