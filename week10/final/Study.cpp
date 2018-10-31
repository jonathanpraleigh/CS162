/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: Study class file
*******************************************************************************************/

#include "Study.hpp"
#include <iostream>

Study::Study()
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

void Study::roomDescription()
{
	std::cout << "\nThe study has bare walls and no carpet. The only thing of note is a wallsafe that has been mounted the wall.\n";
}


void Study::setDirections(Room* n, Room* e, Room*, Room*, Room*, Room*)
{
	North = n;
	East = e;
}


void Study::use(std::vector<Items>* i)
{
	std::cout << "What would you like to use?\n";
	itemSelection = StudyMenu.menuItemsDisplay(*i);
	if (itemSelection == combination)
	{
		
		if (roomChanged == true)
		{
			std::cout << "The safe is already opened.\n";
		}
		if (roomChanged == false)
		{
			std::cout << "You use the code to open the safe. Inside are a few personal photos and a KEYCARD marked SAFE ROOM.\n"
			<< "You take the KEYCARD.\n";
			i->push_back(keycard);
			roomChanged = true;
		}

	}
	std::cout << "That does nothing.\n";
}

void Study::examine(std::vector<Items>* i)
{
	std::cout << "The study has bare walls and no carpet. The only thing of note is a wallsafe that has been mounted the wall.\n";
}

Room* Study::go()
{
	choice = StudyMenu.menuDisplay(directions);
	if (choice == 1)
	{
		return North;
	}
	return East;
}

void Study::changeStatus()
{
	
}


void Study::displayRoom()
{
	std::cout << "\nLEVEL ONE : STUDY\n"
		<< "xxx=====xxxxxxxxxx=====xxx\n"
		<< "x         x    x         x\n"
		<< "[         x    x         ]\n"
		<< "[         x    x         ]\n"
		<< "[         I    I         ]\n"
		<< "x         I    I         x\n"
		<< "xx--xxxxxxxx--xx--xxxxxxxx\n"
		<< "x    I    I    I         x\n"
		<< "[  @ I    I    I         ]\n"
		<< "[    xx--xx    x         ]\n"
		<< "[    x    x    x         ]\n"
		<< "x    x    x    x         x\n"
		<< "xx==xxxxxxxxxxxxx==xxx==xx\n";
}

void Study::setGameOver()
{
	
}


