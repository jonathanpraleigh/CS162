/*********************************************************************
** Program name: loadedDie.cpp (used for dice game program)
** Author: Jon Raleigh
** Date: 04/23/2017
** Description: 
*********************************************************************/

#include "loadedDie.hpp"
#include <cstdlib>

LoadedDie::LoadedDie()
{
	die_faces = 0;
	roll_result = 0;
}

LoadedDie::LoadedDie(int faces)
{
	die_faces = faces;
	roll_result = 0;
};

//roll() creates two random numbers and returns the higher, thus 
//biasing the die towards higher numbers. 

int LoadedDie::roll()
{
	int temp;
	int temp2;

	temp = rand() % die_faces + 1;
	temp2 = rand() % die_faces + 1;

	if (temp > temp2)
	{
		roll_result = temp;
	}
	else { roll_result = temp2;};

	return roll_result;
};

