/*********************************************************************
** Program name: die.cpp (used for dice game program)
** Author: Jon Raleigh
** Date: 04/23/2017
** Description: 
*********************************************************************/

#include "die.hpp"
#include <cstdlib>

Die::Die()
{
	die_faces = 0;
	roll_result = 0;
}

Die::Die(int faces)
{
	die_faces = faces;
	roll_result = 0;
}

//roll() uses rand to determine a random number. 

int Die::roll()
{
	roll_result = rand() % die_faces + 1;

	return roll_result;
}

