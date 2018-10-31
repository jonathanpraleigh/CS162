/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: MasterBathroom class file
*******************************************************************************************/

#include "MasterBathroom.hpp"
#include <iostream>

MasterBathroom::MasterBathroom()
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

void MasterBathroom::roomDescription()
{
	std::cout << "\nThe bathroom is in disarray.\n"
	<< "Bare plumbing protrudes from the floor where a toilet and shower should be.\n";
}


void MasterBathroom::setDirections(Room* n, Room*, Room*, Room*, Room*, Room*)
{
	North = n;
}


void MasterBathroom::use(std::vector<Items>* i)
{
	std::cout << "You have nothing in your pockets to use.\n";
}

void MasterBathroom::examine(std::vector<Items>* i)
{
	std::cout << "The bathroom appears to be under construction. You look around desperately for something to wield as a weapon, but there is nothing.\n";
}

Room* MasterBathroom::go()
{
	choice = MasterBathroomMenu.menuDisplay(directions);
	return North;
}

void MasterBathroom::changeStatus()
{
	
}


void MasterBathroom::displayRoom()
{
	std::cout << "\nLEVEL TWO : MASTER BATH\n"
		<< "xxx=====xxxxxxxxx==xxx=xxx\n"
		<< "x         x    x         x\n"
		<< "[         x    x         ]\n"
		<< "[         x    x         ]\n"
		<< "[         I    I         ]\n"
		<< "x         I    I         x\n"
		<< "xx--xxx--xxx--xx--xxxxxxxx\n"
		<< "     I    x    I         x\n"
		<< "     I @  x    I         ]\n"
		<< "     x    xx--xx         ]\n"
		<< "     x    x    x         ]\n"
		<< "     x    x    x         x\n"
		<< "     xxxxxxxxxxxx==xxx==xx\n";
}

void MasterBathroom::setGameOver()
{
	
}
