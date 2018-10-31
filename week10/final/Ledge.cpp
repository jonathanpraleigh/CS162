/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: Ledge class file
*******************************************************************************************/

#include "Ledge.hpp"
#include <iostream>

Ledge::Ledge()
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

void Ledge::roomDescription()
{
	std::cout << "\nYou are on a narrow ledge outside of the house. Another window is several steps ahead.\n";
}


void Ledge::setDirections(Room* n, Room*, Room* s, Room*, Room*, Room*)
{
	North = n;
	South = s;
}


void Ledge::use(std::vector<Items>* i)
{
	std::cout << "That does nothing.\n";
}

void Ledge::examine(std::vector<Items>* i)
{
	std::cout << "The house is surrounded by woods. You hear the buzzing of insects in the air and see fires in the distance.\n";
}

Room* Ledge::go()
{
	choice = LedgeMenu.menuDisplay(direction);

	if (choice == 1)
	{
		return North;
	}
	if (choice == 2)
	{
		return South;
	}
}

void Ledge::changeStatus()
{
	
}

void Ledge::displayRoom()
{
	std::cout << "OUTSIDE LEDGE\n";
	std::cout
		<< "x_\n"
		<< "x |\n"
		<< "] |\n"
		<< "x |\n"
		<< "] |\n"
		<< "x |\n"
		<< "x |\n"
		<< "x |\n"
		<< "] |\n"
		<< "x |\n"
		<< "] |\n"
		<< "x_|\n"
		<< "x\n";
}

void Ledge::setGameOver()
{
	
}


