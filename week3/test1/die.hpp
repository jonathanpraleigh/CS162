/*********************************************************************
** Program name: die header file
** Author: Jon Raleigh
** Date: 4/23/17
** Description: header file for die class file.
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
private:
	int die_faces;
	int roll_result;
public:
	Die();
	Die(int);
	int roll();
};

#endif