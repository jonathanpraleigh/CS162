/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: Downstairs class file
*******************************************************************************************/

#include "Downstairs.hpp"
#include <iostream>


Downstairs::Downstairs()
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

void Downstairs::roomDescription()
{
	std::cout << "\nYou are at the bottom of the stairs. There are doors to your East, South, and West.\n"
		<< "You see a door leading into a basement which seems to be locked by a complicated electric lock.\n"
		<< "The dog barks at the basement door and tries to scratch at it.\n";
}


void Downstairs::setDirections(Room*, Room* e, Room* s, Room* w, Room* u, Room* d)
{
	East = e;
	South = s;
	West = w;
	Up = u;

}


void Downstairs::use(std::vector<Items>* i)
{
	std::cout << "What would you like to use?\n";
	itemSelection = DownstairsMenu.menuItemsDisplay(*i);
	if (itemSelection == keycard)
	{
		std::cout << "You slide the card and the door unlocks. You step inside with the dog and close it behind you.\n"
			<< "You have found a panic room stocked with a few weeks worth of food. You and the dog are safe for now.\n"
			<< "YOU WIN.\nGAME OVER.\n\nQuit at any time or continue to explore the house.";
		this->setGameOver();
		return;
	}

	if (itemSelection != keycard)
	{
		std::cout << "That does nothing.\n";
	}
}
	
void Downstairs::examine(std::vector<Items>* i)
{
	std::cout << "You look more closely at the basement door.\n"
		<< "It seems to be a sophisticated electronic lock opened with a keycard.\n"
		<< "Who has something like that?\n";
}

Room* Downstairs::go()
{
	choice = DownstairsMenu.menuDisplay(directions);
	if (choice == 1)
	{
		return East;
	}
	if (choice == 2)
	{
		return South;
	}
	if (choice == 3)
	{
		return West;
	}
	return Up;
}

void Downstairs::changeStatus()
{
	
}


void Downstairs::displayRoom()
{
	std::cout << "\nLEVEL ONE : STAIRS\n"
		<< "xxx=====xxxxxxxxxx=====xxx\n"
		<< "x         x    x         x\n"
		<< "[         x    x         ]\n"
		<< "[         x @  x         ]\n"
		<< "[         I    I         ]\n"
		<< "x         I    I         x\n"
		<< "xx--xxxxxxxx--xx--xxxxxxxx\n"
		<< "x    I    I    I         x\n"
		<< "[    I    I    I         ]\n"
		<< "[    xx--xx    x         ]\n"
		<< "[    x    x    x         ]\n"
		<< "x    x    x    x         x\n"
		<< "xx==xxxxxxxxxxxxx==xxx==xx\n";
}

void Downstairs::setGameOver()
{
	gameOver = true;
}
