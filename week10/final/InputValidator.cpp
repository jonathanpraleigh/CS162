/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: InputValidator class file
*******************************************************************************************/

#include "InputValidator.hpp"
#include <iostream>

InputValidator::InputValidator()
{
	integer_test = 0;
}

/***********************************************************
** testInteger tests min and max or both
************************************************************/

int InputValidator::testInteger(int iv_min, int iv_max, bool iv_min_used, bool iv_max_used, bool is_it_a_menu)
{

//Constructs a request for an integer based on min and max values passed. 

	if (is_it_a_menu != true)
	{
		std::cout << "Please enter an integer ";
		if (iv_min_used == true)
		{
			std::cout << "over " << iv_min;
		}
		if (iv_min_used == true && iv_max_used == true)
		{
			std::cout << " and ";
		}
		if (iv_max_used == true)
		{
			std::cout << "under " << iv_max << ".\n";
		}
	}

	std::cin >> integer_test;

//Tests to make sure input is an integer and makes the user input the value again. 
	
	while(!std::cin)
	{
		this->integerFail();
		std::cin >> integer_test;
	}

//First test case with min and max number range.

	if (iv_min_used == true && iv_max_used == true)
	{
		for ( ; ; )
		{
			if (integer_test >= iv_min && integer_test <= iv_max)
			{
				return integer_test;
			}

			this->integerFail();

			std::cin >> integer_test;
		}
	}

//Second test case with only minimum value set

	if (iv_min_used == true && iv_max_used == false)
	{
		for (; ; )
		{
			if (integer_test >= iv_min)
			{
				return integer_test;
			}

			this->integerFail();

			std::cin >> integer_test;
		}
	}

//Third test case with only maximum value set.

	if (iv_min_used == false && iv_max_used == true)
	{
		for (; ; )
		{
			if (integer_test <= iv_max)
			{
				return integer_test;
			}

			this->integerFail();

			std::cin >> integer_test;
		}
	}

	if (iv_min_used == false && iv_max_used == false)
	{
		return integer_test;
	}

}

void InputValidator::integerFail()
{
	std::cout << "\nInvalid input. Please try again.\n";
	std::cin.clear();
	std::cin.ignore();
}

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

} */

/**************************************************************
** y_or_n_testChar tests the character against a list of 4 possibilities
** sans vector. Made specifically since YyNn are common inputs.
*****************************************************************

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
	// implemented in later projects as needed. */
