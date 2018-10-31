/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: NorthBedroom class file
*******************************************************************************************/

#include "NorthBedroom.hpp"
#include <iostream>

NorthBedroom::NorthBedroom()
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

void NorthBedroom::roomDescription()
{
	if (initialVisit == true)
	{
		std::cout << "\nYou enter through the window, avoiding the broken glass.\n"
			<< "The dog leaps up and starts to lick your face, happy to have found someone.\n"
			<< "A bag of dog food had been knocked over and a large bucket of water wast left.\n"
			<< "Someone left the dog here in the room with enough supplied for a couple of weeks.\n"
			<< "Otherwise, the room is bare. There is a door to the west.\n";
		initialVisit = false;
		return;
	}
	std::cout << "\nYou enter the room with the dog. You notice now that it really, really smells of dog.\n";
}


void NorthBedroom::setDirections(Room*, Room* e, Room*, Room* w, Room*, Room*)
{
	West = w;
	East = e;
}


void NorthBedroom::use(std::vector<Items>* i)
{
	std::cout << "That does nothing.\n";
}

void NorthBedroom::examine(std::vector<Items>* i)
{
	std::cout << "Though you don't remember much, you don't believe that this had been your dog.\n"
	<< "It seems extremely friendly and well socialized and has taken to you right away.\n"; 
}

Room* NorthBedroom::go()
{
	choice = NorthBedroomMenu.menuDisplay(direction);
	if (choice == 1)
	{
		return East;
	}
	if (choice == 2)
	{
		West->changeStatus();
		return West;
	}
}

void NorthBedroom::changeStatus()
{
	
}


void NorthBedroom::displayRoom()
{
	std::cout << "\nLEVEL TWO : NORTH BEDROOM\n"
		<< "xxx=====xxxxxxxxx==xxx=xxx\n"
		<< "x         x    x         x\n"
		<< "[         x    x         ]\n"
		<< "[         x    x   @     ]\n"
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

void NorthBedroom::setGameOver()
{
	
}
