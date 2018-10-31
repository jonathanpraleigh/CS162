/*********************************************************************
** Program name: Dice.cpp (used for project 3)
** Author: Jon Raleigh
** Date: 5/14/2017
** Description: Rolls dice
*********************************************************************/

#include "Dice.hpp"
#include <random>

Dice::Dice()
{
	total = 0;
};

int Dice::roll_dice(int n, int f)
{
	for (int i = 0; i < n; i++)
	{
		total = rand() % f + 1;

	}
	return total;
}