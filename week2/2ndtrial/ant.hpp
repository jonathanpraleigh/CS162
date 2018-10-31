/*********************************************************************
** Program name: ant header file.
** Author: Jon Raleigh
** Date: 4/16/17
** Description: header file. 
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "orientation.hpp"

class Ant
{
private:
	int a_row;
	int a_column;
	orientation a_orientation;
public:
	Ant(int row, int column, orientation a_orientation, int);
	void setLocation(int row, int column, int dim);
	int getLocationRow();
	int getLocationColumn();
	void setOrientation(enum orientation);
	orientation getOrientation();
};


#endif
