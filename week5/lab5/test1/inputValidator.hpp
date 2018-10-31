/*********************************************************************
** Program name: OSU Information System (inputValidator.hpp)
** Author: Jon Raleigh
** Date: 5/07/17
** Description: header file for input validation functions.
*********************************************************************/

#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

//#include <vector>

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
