/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: SouthBedroom class file
*******************************************************************************************/
#include "SouthBedroom.hpp"
#include <iostream>

SouthBedroom::SouthBedroom()
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

void SouthBedroom::roomDescription()
{
	if (roomChanged == false)
	{
		std::cout << "\nThe room is mostly bare. A radio on the floor blares an emergency broadcast. A window is across the way with a large ledge beneath. It appears to be painted shut.\n";
		return;
	}
	std::cout << "\nA radio on the floor blares an emergency broadcast. A window is across the way with a large ledge beneath. The window has been broken.\n";
}


void SouthBedroom::setDirections(Room*, Room* e, Room*, Room* w, Room*, Room*)
{
	East = e;
	West = w;
}


void SouthBedroom::use(std::vector<Items>* i)
{
	std::cout << "What would you like to use?\n";
	itemSelection = SouthBedroomMenu.menuItemsDisplay(*i);
	if (itemSelection == hammer)
	{
		if (roomChanged == false)
		{
			std::cout << "You smash the window and now have access to the ledge below.\n"
			<<"You should hurry before any insects come and swarm your location.\n";
			roomChanged = true;
			return;
		}
		std::cout << "That does nothing.\n";
	}
	std::cout << "That does nothing.\n";
		

}

void SouthBedroom::examine(std::vector<Items>* i)
{
	std::cout << "The room has a mattress on the floor. A radio is on the floor, playing an emergency broadcast.\n"
	<<"The announcer is talking about a new bacteria-based pesticide that was supposed to kill insects, arachnids, and arthropods.\n"
	<<"A rogue biohacker at the company instead increased its virulence and spliced in explosive growth. Thousands have died so far.\n";
}

Room* SouthBedroom::go()
{
	choice = SouthBedroomMenu.menuDisplay(direction);
	if (choice == 1)
	{
		if (roomChanged == false)
		{
			std::cout << "The window blocks your way.\n";
			return this;
		}
		return East;
	}
	if (choice == 2)
	{
		return West;
	}
}

void SouthBedroom::changeStatus()
{
	
}


void SouthBedroom::displayRoom()
{
	std::cout << "\nLEVEL TWO : SOUTH BEDROOM\n"
		<< "xxx=====xxxxxxxxx==xxx=xxx\n"
		<< "x         x    x         x\n"
		<< "[         x    x         ]\n"
		<< "[         x    x         ]\n"
		<< "[         I    I         ]\n"
		<< "x         I    I         x\n"
		<< "xx--xxx--xxx--xx--xxxxxxxx\n"
		<< "     I    x    I         x\n"
		<< "     I    x    I   @     ]\n"
		<< "     x    xx--xx         ]\n"
		<< "     x    x    x         ]\n"
		<< "     x    x    x         x\n"
		<< "     xxxxxxxxxxxx==xxx==xx\n";
}

void SouthBedroom::setGameOver()
{
	
}
