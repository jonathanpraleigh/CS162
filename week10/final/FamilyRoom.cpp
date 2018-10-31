/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: FamilyRoom class file
*******************************************************************************************/

#include "FamilyRoom.hpp"
#include "iostream"

FamilyRoom::FamilyRoom()
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

void FamilyRoom::roomDescription()
{
	std::cout << "\nA few suitcases and duffle bags litter the floor along with sleeping bags.\n"
		<< "A laptop sits on the floor.\n";
}


void FamilyRoom::setDirections(Room*, Room* e, Room* s, Room*, Room*, Room*)
{
	South = s;
	East = e;
}


void FamilyRoom::use(std::vector<Items>* i)
{
	std::cout << "What would you like to use?\n";
	itemSelection = FamilyRoomMenu.menuItemsDisplay(*i);
	if (itemSelection == adaptor)
	{
		if (roomChanged == false)
		{
			std::cout << "You plug the adaptor into the wall. Surprisingly, the power is on and it turns on.\n"
				<< "You search through the laptop, finding a text file called PASSWORDS.\n"
				<< "A safe combination is on the top of the list. 9-9-9-9. You commit it the COMBINATION to memory and shut off the laptop.\n";
			i->push_back(combination);
			roomChanged = true;
			return;
		}
		if (roomChanged == true)
		{
			std::cout << "The laptop shows nothing new.\n";
			return;
		}
	}
	std::cout << "That does nothing.\n";

}

void FamilyRoom::examine(std::vector<Items>* i)
{
	std::cout << "A few suitcases and duffle bags litter the floor along with sleeping bags.\n"
		<<"The dog lays down on one and watches you as he pants.\n"
		<< "A laptop sits on the floor.\n";
}

Room* FamilyRoom::go()
{
	choice = FamilyRoomMenu.menuDisplay(directions);
	if (choice == 1)
	{
		return East;
	}
		return South;
}

void FamilyRoom::changeStatus()
{

}


void FamilyRoom::displayRoom()
{
	std::cout << "\nLEVEL ONE : FAMILY ROOM\n"
		<< "xxx=====xxxxxxxxxx=====xxx\n"
		<< "x         x    x         x\n"
		<< "[         x    x         ]\n"
		<< "[  @      x    x         ]\n"
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

void FamilyRoom::setGameOver()
{
	
}
