/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: Upstairs class file
*******************************************************************************************/
#include "Upstairs.hpp"
#include <iostream>

Upstairs::Upstairs()
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

void Upstairs::roomDescription()
{
	if (initialVisit == false)
	{
		if (roomChanged == true)
		{
			std::cout << "\nYou are at the top of the stairs. There is a door to your east and south.\n"
				<< "The dog waits by your side.\n";
		}
		if (roomChanged == false)
		{
			std::cout << "\nYou hear the scratching of dog claws and desperate barks behind the door to the east. It is still locked.\n"
				<< "Another door is to your south.\n";
		}

	}
	if (initialVisit == true)
	{
		std::cout << "\nYou enter the hallway, see a plastic-wrapped dresser next to the door, and instinctively pull the dresser over to block the door.\n"
			<< " You are at the top of stairs, with doors to the east and south of you.\n"
			<< "You hear a dog barking behind the door to your east.\n";
		initialVisit = false;
	}

}


void Upstairs::setDirections(Room*, Room* e, Room* s, Room*, Room*, Room* d)
{
	East = e;
	South = s;
	Down = d;
}


void Upstairs::use(std::vector<Items>* i)
{
	std::cout << "Nothing happens.\n";
}

void Upstairs::examine(std::vector<Items>* i)
{
	std::cout << "There is furniture at the top of the stairs, which appears to have been hastily left.\n"
	<< "There is a staircase going down. You hear the the giant mantis clawing through the room behind you.\n";
}

Room* Upstairs::go()
{
	choice = UpstairsMenu.menuDisplay(direction);
	if (choice == 1)
	{
		if (roomChanged == false)
		{
			std::cout << "The door is locked. You push, but it will not open. You will have to find another way in.\n";
			return this;
		}
		return East;

	}
	if (choice == 2)
	{
		return South;
	}
	if (choice == 3)
	{
		if (roomChanged == false)
		{
			std::cout << "Your conscience will not allow you to leave the dog behind.\n";
			return this;
		}
		return Down;
	}
}

void Upstairs::displayRoom()
{
	std::cout << "\nLEVEL TWO : STAIRS\n"
		<< "xxx=====xxxxxxxxx==xxx=xxx\n"
		<< "x         x    x         x\n"
		<< "[         x @  x         ]\n"
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

void Upstairs::changeStatus()
{
	roomChanged = true;
}

void Upstairs::setGameOver()
{
	
}
