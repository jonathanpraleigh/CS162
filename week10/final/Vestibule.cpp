/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: Vestibule class file
*******************************************************************************************/
#include "Vestibule.hpp"
#include <iostream>

Vestibule::Vestibule()
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

void Vestibule::roomDescription()
{
	if (initialVisit == true)
	{
		std::cout << "\nYou enter the vestibule. You see a man laying dead on the floor, a massive bee's stinger still in his chest.\n"
			<< "The dog sniffs at him and whimpers.\n"
			<< "The man had nearly finished boarding up the door before he was attacked.\n"
			<< "You won't be leaving through the front door.\n";
	}
	if (initialVisit == false)
	{
		std::cout << "\nYou enter the vestibule. A disturbing scene is before you.\n";
	}
}


void Vestibule::setDirections(Room* n, Room* e, Room*, Room* w, Room*, Room*)
{
	North = n;
	East = e;
	West = w;
}


void Vestibule::use(std::vector<Items>* i)
{
	std::cout << "There is nothing to do here.\n";
}

void Vestibule::examine(std::vector<Items>* i)
{
	std::cout << "You see a man laying dead on the floor, a massive bee's stinger still in his chest.\n"
		<< "The dog sniffs at him and whimpers.\n"
		<< "The man had nearly finished boarding up the door before he was attacked.\n"
		<< "You won't be leaving through the front door.\n";
}

Room* Vestibule::go()
{
	choice = VestibuleMenu.menuDisplay(directions);
	if (choice == 1)
	{
		return North;
	}
	if (choice == 2)
	{
		return East;
	}
	return West;
}

void Vestibule::changeStatus()
{
	
}


void Vestibule::displayRoom()
{
	std::cout << "\nLEVEL ONE : VESTIBULE\n"
		<< "xxx=====xxxxxxxxxx=====xxx\n"
		<< "x         x    x         x\n"
		<< "[         x    x         ]\n"
		<< "[         x    x         ]\n"
		<< "[         I    I         ]\n"
		<< "x         I    I         x\n"
		<< "xx--xxxxxxxx--xx--xxxxxxxx\n"
		<< "x    I    I    I         x\n"
		<< "[    I    I  @ I         ]\n"
		<< "[    xx--xx    x         ]\n"
		<< "[    x    x    x         ]\n"
		<< "x    x    x    x         x\n"
		<< "xx==xxxxxxxxxxxxx==xxx==xx\n";
}

void Vestibule::setGameOver()
{
	
}

