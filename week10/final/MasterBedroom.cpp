/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: MasterBedroom class file
*******************************************************************************************/

#include "MasterBedroom.hpp"
#include <iostream>

MasterBedroom::MasterBedroom()
{
	North = nullptr;
	East = nullptr;
	South = nullptr;
	West = nullptr;
	Down = nullptr;
	Up = nullptr;

	choice = 0;
	initialVisit = true;
	roomChanged = false;
	gameOver = false;
}

void MasterBedroom::roomDescription()
{
	if (initialVisit == true)
	{
		std::cout << "\nYou awaken in bed, your vision and thoughts blurred.\n"
		<<"You try to move your left arm, only to find it has been bandaged.\n"
		<<"You reach your right arm to your head, feeling the bandages there as well.\n"
		<<"You hear a scratching at the window, only to see a dark figure, perched on the ledge outside of the window.\n"
		<<"You stand to your feet, and look at the figure, noticing that it is, in fact, an abnormally large praying mantis.\n"
		<<"It breaks the window and crawls in the room!\n"
		<<"Your goal is to find your way to safety!\n";

		initialVisit = false;
		
		return;
	}
	if (initialVisit == false)
	{
		std::cout << "\nThe mantis leaps across the room at you, narrowly missing with its claws.\n"
		<<"You must escape this room quickly.\n";
	}

}


void MasterBedroom::setDirections(Room*, Room* e, Room* s, Room*, Room*, Room*)
{
	South = s;
	East = e;
}


void MasterBedroom::use(std::vector<Items>* i)
{
	std::cout << "You have nothing in your pocket to use.\n";
}

void MasterBedroom::examine(std::vector<Items>* i)
{
	std::cout << "The room is unfamiliar to you. You are not sure whom this room belongs to.\n";
}

Room* MasterBedroom::go()
{
	choice = MasterBedroomMenu.menuDisplay(directions);
	if (choice == 1)
	{
		return East;
	}
		return South;
}

void MasterBedroom::changeStatus()
{
	
}


void MasterBedroom::displayRoom()
{
	std::cout << "\nLEVEL TWO : MASTER BEDROOM\n"
		<< "xxx=====xxxxxxxxx==xxx=xxx\n"
		<< "x         x    x         x\n"
		<< "[  @      x    x         ]\n"
		<< "[         x    x         ]\n"
		<< "[         I    I         ]\n"
		<< "x         I    I         x\n"
		<< "xx--xxx--xxx--xx--xxxxxxxx\n"
		<< "     I    x    I         x\n"
		<< "     I    x    I         ]\n"
		<< "     x    xx--xx         ]\n"
		<< "     x    x    x         ]\n"
		<< "     x    x    x         x\n"
		<< "     xxxxxxxxxxxx==xxx==xx\n";
}

void MasterBedroom::setGameOver()
{
	
}

