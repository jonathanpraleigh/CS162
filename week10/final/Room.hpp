/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: header file
*******************************************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP
#include "Enums.hpp"
#include <vector>

class Room
{
protected:
	Room * North;
	Room * East;
	Room * South;
	Room * West;
	Room * Down;
	Room * Up;
	bool initialVisit;
	bool roomChanged;
	int choice;
	Items itemSelection;

public:
	Room();
	virtual void use(std::vector<Items>*) = 0;
	virtual void examine(std::vector<Items>*) = 0;
	virtual Room* go() = 0;
	virtual void setDirections(Room*, Room*, Room*, Room*, Room*, Room*) = 0;
	virtual void roomDescription() = 0;
	virtual void displayRoom() = 0;
	virtual void changeStatus() = 0;
	virtual void setGameOver() = 0;
	bool gameOver;
	
};


#endif
