/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: UpstairsBathroom class file
*******************************************************************************************/
#include "UpstairsBathroom.hpp"
#include <iostream>

UpstairsBathroom::UpstairsBathroom()
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

void UpstairsBathroom::roomDescription()
{
	std::cout << "\nYou are in a bathroom being remodeled. Tools lay on the counter.\n";
}


void UpstairsBathroom::setDirections(Room* n, Room*, Room*, Room*, Room*, Room*)
{
	North = n;
}


void UpstairsBathroom::use(std::vector<Items>* i)
{
	std::cout << "That does nothing.\n";
}

void UpstairsBathroom::examine(std::vector<Items>* i)
{
	if (roomChanged == true)
	{
		std::cout << "The bathroom was in the process of being remodeled. You have already taken the hammer.\n";
	}
	if (roomChanged == false)
	{
		std::cout << "The bathroom was in the process of being remodeled. A HAMMER lies on the counter. You pick it up.\n";
		roomChanged = true;
		i->push_back(hammer);
	}

}

Room* UpstairsBathroom::go()
{
	choice = UpstairsBathroomMenu.menuDisplay(direction);
	return North;
}

void UpstairsBathroom::changeStatus()
{
	
}


void UpstairsBathroom::displayRoom()
{
	std::cout << "\nLEVEL TWO : BATHROOM\n"
		<< "xxx=====xxxxxxxxx==xxx=xxx\n"
		<< "x         x    x         x\n"
		<< "[         x    x         ]\n"
		<< "[         x    x         ]\n"
		<< "[         I    I         ]\n"
		<< "x         I    I         x\n"
		<< "xx--xxx--xxx--xx--xxxxxxxx\n"
		<< "     I    x    I         x\n"
		<< "     I    x    I         ]\n"
		<< "     x    xx--xx         ]\n"
		<< "     x    x @  x         ]\n"
		<< "     x    x    x         x\n"
		<< "     xxxxxxxxxxxx==xxx==xx\n";
}

void UpstairsBathroom::setGameOver()
{
	
}
