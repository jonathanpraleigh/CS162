/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/

#include "ant.hpp"
#include "orientation.hpp"

Ant::Ant(int r, int c, orientation o, int d)
{
	setLocation(r, c, d);
	setOrientation(o);
}


void Ant::setLocation(int set_r, int set_c, int test_dim)
{
	if (set_r >= 0 && set_r < test_dim)
	{
		a_row = set_r;
	}
	else if (set_r < 0)
	{
		a_row = test_dim - 1;
	}
	else if (set_r >= test_dim)
	{
		a_row = 0;
	}

	if (set_c >= 0 && set_c < test_dim)
	{
		a_column = set_c;
	}
	else if (set_c < 0)
	{
		a_column = test_dim - 1;
	}
	else if (set_c >= test_dim)
	{
		a_column = 0;
	}
}


int Ant::getLocationRow()
{
	return a_row;
}

	// retrieves current row value of the ant

int Ant::getLocationColumn()
{
	return a_column;
}

	// retrieves current column value of the ant

void Ant::setOrientation(orientation set_o)
{
	a_orientation = set_o;
}

	// inputs new orientation value

orientation Ant::getOrientation()
{
	return a_orientation;
}
