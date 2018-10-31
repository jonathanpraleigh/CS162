/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: UpstairsHallway class file
*******************************************************************************************/
#include "UpstairsHallway.hpp"
#include <iostream>

UpstairsHallway::UpstairsHallway()
{
	North = nullptr;
	East = nullptr;
	South = nullptr;
	West = nullptr;
	Down = nullptr;
	Up = nullptr;

	initialVisit = true;
	roomChanged = false;
	gameOver = false;

	choice = 0;
}

void UpstairsHallway::setDirections(Room* n, Room* e, Room* s, Room*, Room*, Room*)
{
	North = n;
	East = e;
	South = s;
	
}

void UpstairsHallway::roomDescription()
{
	std::cout << "\nThis is a small hallway between rooms. It is empty and needs a coat of paint.\n";
}


void UpstairsHallway::use(std::vector<Items>* i)
{
	std::cout << "There is nothing to do in this room.\n";
}

void UpstairsHallway::examine(std::vector<Items>* i)
{
	std::cout << "There is nothing worth mentioning about this hallway.\n";
}

Room* UpstairsHallway::go()
{
	choice = UpstairsHallwayMenu.menuDisplay(direction);
	if (choice == 1)
	{
		return North;
	}

	if (choice == 2)
	{
		return East;
	}

	if (choice == 3)
	{
		return South;
	}
}

void UpstairsHallway::changeStatus()
{
	
}


void UpstairsHallway::displayRoom()
{
	std::cout << "\nLEVEL TWO : HALLWAY\n"
		<< "xxx=====xxxxxxxxx==xxx=xxx\n"
		<< "x         x    x         x\n"
		<< "[         x    x         ]\n"
		<< "[         x    x         ]\n"
		<< "[         I    I         ]\n"
		<< "x         I    I         x\n"
		<< "xx--xxx--xxx--xx--xxxxxxxx\n"
		<< "     I    x  @ I         x\n"
		<< "     I    x    I         ]\n"
		<< "     x    xx--xx         ]\n"
		<< "     x    x    x         ]\n"
		<< "     x    x    x         x\n"
		<< "     xxxxxxxxxxxx==xxx==xx\n";
}

void UpstairsHallway::setGameOver()
{
	
}

