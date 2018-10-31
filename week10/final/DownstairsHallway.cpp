/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: DownstairsHallway class file
*******************************************************************************************/
#include "DownstairsHallway.hpp"
#include <iostream>

DownstairsHallway::DownstairsHallway()
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

void DownstairsHallway::roomDescription()
{
	std::cout << "\nYou enter the hallway. It is unremarkable. There are doors to your east, south, and west.\n";
}


void DownstairsHallway::setDirections(Room*, Room* e, Room* s, Room* w, Room*, Room*)
{
	East = e;
	South = s;
	West = w;
}


void DownstairsHallway::use(std::vector<Items>* i)
{
	std::cout << "There is nothing to do here.\n";
}

void DownstairsHallway::examine(std::vector<Items>* i)
{
	std::cout << "You enter the hallway. It is unremarkable. There are doors to your east, south, and west.";
}

Room* DownstairsHallway::go()
{
	choice = DownstairsHallwayMenu.menuDisplay(directions);
	if (choice == 1)
	{
		return East;
	}
	if (choice == 2)
	{
		return South;
	}
	return West;
}

void DownstairsHallway::changeStatus()
{
	
}


void DownstairsHallway::displayRoom()
{
	std::cout << "\nLEVEL ONE : HALLWAY\n"
		<< "xxx=====xxxxxxxxxx=====xxx\n"
		<< "x         x    x         x\n"
		<< "[         x    x         ]\n"
		<< "[         x    x         ]\n"
		<< "[         I    I         ]\n"
		<< "x         I    I         x\n"
		<< "xx--xxxxxxxx--xx--xxxxxxxx\n"
		<< "x    I  @ I    I         x\n"
		<< "[    I    I    I         ]\n"
		<< "[    xx--xx    x         ]\n"
		<< "[    x    x    x         ]\n"
		<< "x    x    x    x         x\n"
		<< "xx==xxxxxxxxxxxxx==xxx==xx\n";
}

void DownstairsHallway::setGameOver()
{
	
}
