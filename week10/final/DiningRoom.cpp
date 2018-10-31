/********************************************************************************************
** Program name: Final Project 
** Author: Jon Raleigh
** Date: 6/13/17
** Description: DiningRoom class file
*******************************************************************************************/

#include "DiningRoom.hpp"
#include <iostream>

DiningRoom::DiningRoom()
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

void DiningRoom::roomDescription()
{
	if (initialVisit == true)
	{
		std::cout << "\nThe dining room was once beautiful and is in the process of being restored.\n"
			<< "A plump centipede, about 10 feet long and a foot wide, is curled around a backpack.\n"
			<< "The dog barks at it, but it doesn't stir.\n";
		initialVisit = false;
		return;
	}
	std::cout << "\nThe dining room was once beautiful and is in the process of being restored.\n"
	<<"A plump centipede, about 10 feet long and a foot wide, is curled in the center of the room.\n";

}


void DiningRoom::setDirections(Room* n, Room* e, Room* s, Room* w, Room* u, Room* d)
{
	South = s;
	West = w;
}


void DiningRoom::use(std::vector<Items>* i)
{
	std::cout << "What would you like to use?\n";
	itemSelection = DiningRoomMenu.menuItemsDisplay(*i);
	if (itemSelection == broom)
	{
		if (roomChanged == false)
		{
			std::cout << "You use the broom handle to carefully pull the backpack from inside the centipedes legs.\n"
				<< "The legs move as you pull it away. You pull out the ADAPTOR and put it in your pocket.\n";
			i->push_back(adaptor);
			roomChanged = true;
			return;
		}
		std::cout << "You poke the centipede with your broom. It isn't very active.\n";
		return;
	}
	if (itemSelection != broom)
	{
		std::cout << "That does nothing.\n";
	}
}
	
void DiningRoom::examine(std::vector<Items>* i)
{
	std::cout << "The centipede is curled in the center of the room. It seems to be alive upon closer inspection.\n";
}

Room* DiningRoom::go()
{
	choice = DiningRoomMenu.menuDisplay(directions);
	if (choice == 1)
	{
		return South;
	}
	return West;
}

void DiningRoom::changeStatus()
{
	
}

void DiningRoom::displayRoom()
{
	std::cout <<"\nLEVEL ONE : DINING ROOM\n"
		<< "xxx=====xxxxxxxxxx=====xxx\n"
		<< "x         x    x         x\n"
		<< "[         x    x         ]\n"
		<< "[         x    x  @      ]\n"
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

void DiningRoom::setGameOver()
{
	
}



