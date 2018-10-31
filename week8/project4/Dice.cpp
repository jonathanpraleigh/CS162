/*********************************************************************
** Program name: Project 4
** Author: Jon Raleigh
** Date: 5/28/2017
** Description: XXX
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