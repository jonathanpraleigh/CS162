/*********************************************************************
** Program name: loadedDie header file
** Author: Jon Raleigh
** Date: 4/23/17
** Description: header file for loadedDie class file.
*********************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

class LoadedDie

{
private:
	int die_faces;
	int roll_result;
public:
	LoadedDie();
	LoadedDie(int);
	int roll();
};

#endif