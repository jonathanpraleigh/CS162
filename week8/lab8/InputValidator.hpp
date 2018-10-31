/********************************************************************************************
** Program name: SearchAndSort
** Author: Jon Raleigh
** Date: 5/28/17
** Description: Uses XXXX search method, XXXX sort method, and Binary Search to locate
**				values within four text files.
*******************************************************************************************/

#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

class InputValidator
{
private:
	int integer_test;

public:
	InputValidator();
	int testInteger(int, int, bool, bool, bool);
	//char testChar(char, std::vector<char>);
	//char y_or_n_testChar(char);
	void integerFail();
};


#endif
