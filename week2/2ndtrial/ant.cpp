/*********************************************************************
** Program name: ant class for langton program
** Author: Jon Raleigh
** Date: 4/16/17
** Description: creates ant object which stores data such as 
		location and orientation of the ant.
*********************************************************************/

#include "ant.hpp"
#include "orientation.hpp"

Ant::Ant(int r, int c, orientation o, int d)
{
	setLocation(r, c, d);
	setOrientation(o);
}

//I included the dimensions "d" so that I could deal with situations
//where the ant leaves the board. 

/******************************************************************
** setLocation() sets the location of the ant, but also allows for  
** instances where the ant would leave the board.
******************************************************************/

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

int Ant::getLocationColumn()
{
	return a_column;
}

//I went with enums here, which is why I included the orientation
//header file, since that holds the enums I'm using for orienation. 

void Ant::setOrientation(orientation set_o)
{
	a_orientation = set_o;
}

orientation Ant::getOrientation()
{
	return a_orientation;
}
