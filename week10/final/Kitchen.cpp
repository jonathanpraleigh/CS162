/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: Kitchen class file
*******************************************************************************************/

#include "Kitchen.hpp"
#include <iostream>

Kitchen::Kitchen()
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

void Kitchen::roomDescription()
{
	std::cout << "\nThe kitchen seems more finished than the rest of the house. The floor hasn't been laid, but everything else seems done.\n"
		<< "Cleaning supplies were left scattered about.\n"
		<< "The dog growls towards the northern door.\n";
}


void Kitchen::setDirections(Room* n, Room*, Room*, Room* w, Room*, Room*)
{
	North = n;
	West = w;
}


void Kitchen::use(std::vector<Items>* i)
{
	std::cout << "There is nothing you can use here.";
}

void Kitchen::examine(std::vector<Items>* i)
{
	if (roomChanged == false)
	{
		std::cout << "You pick up a BROOM. Perhaps you can use it to strike at anything that attacks you.\n";
		roomChanged = true;
		i->push_back(broom);
		return;
	}
	std::cout << "The kitchen seems more finished than the rest of the house. The floor hasn't been laid, but everything else seems done.\n"
		<< "Cleaning supplies were left scattered about.\n"
		<< "The dog growls towards the northern door.\n";
}

Room* Kitchen::go()
{
	choice = KitchenMenu.menuDisplay(directions);
	if (choice == 1)
	{
		return North;
	}
	return West;
}

void Kitchen::changeStatus()
{
	
}


void Kitchen::displayRoom()
{
	std::cout << "\nLEVEL ONE : KITCHEN\n"
		<< "xxx=====xxxxxxxxxx=====xxx\n"
		<< "x         x    x         x\n"
		<< "[         x    x         ]\n"
		<< "[         x    x         ]\n"
		<< "[         I    I         ]\n"
		<< "x         I    I         x\n"
		<< "xx--xxxxxxxx--xx--xxxxxxxx\n"
		<< "x    I    I    I         x\n"
		<< "[    I    I    I    @    ]\n"
		<< "[    xx--xx    x         ]\n"
		<< "[    x    x    x         ]\n"
		<< "x    x    x    x         x\n"
		<< "xx==xxxxxxxxxxxxx==xxx==xx\n";
}

void Kitchen::setGameOver()
{
	
}
