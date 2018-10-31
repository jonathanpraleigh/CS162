/*********************************************************************
** Program name: OSU Information System (inputValidator.hpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: header file for input validation functions.
*********************************************************************/

#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

#include <vector>

bool testInteger(int, int, int, bool, bool);
bool testChar(char, std::vector<char> );
bool y_or_n_testChar(char);

#endif
