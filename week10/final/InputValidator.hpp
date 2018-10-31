/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: header file
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
