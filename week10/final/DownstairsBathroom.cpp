/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: DownstairsBathroom class file
*******************************************************************************************/

#include "DownstairsBathroom.hpp"
#include <iostream>


DownstairsBathroom::DownstairsBathroom()
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

void DownstairsBathroom::roomDescription()
{
	std::cout << "\nThe bathroom is empty and window is boarded over. A swarm of softball size ticks start to crawl towards you.\n"
		<< "The dog growls as you back away.\n";
}


void DownstairsBathroom::setDirections(Room* n, Room*, Room*, Room*, Room*, Room*)
{
	North = n;
}


void DownstairsBathroom::use(std::vector<Items>* i)
{
	std::cout << "There is nothing that can be used here. You should probably leave.\n";
}

void DownstairsBathroom::examine(std::vector<Items>* i)
{
	std::cout << "The bathroom is empty and window is boarded over. A swarm of softball size ticks start to crawl towards you.\n"
		<< "The dog growls as you back away.\n";
}

Room* DownstairsBathroom::go()
{
	std::cout << "The only direction possible is north.\n";
	return North;
}

void DownstairsBathroom::changeStatus()
{
	
}


void DownstairsBathroom::displayRoom()
{
	std::cout << "\nLEVEL ONE : BATHROOM\n"
		<< "xxx=====xxxxxxxxxx=====xxx\n"
		<< "x         x    x         x\n"
		<< "[         x    x         ]\n"
		<< "[         x    x         ]\n"
		<< "[         I    I         ]\n"
		<< "x         I    I         x\n"
		<< "xx--xxxxxxxx--xx--xxxxxxxx\n"
		<< "x    I    I    I         x\n"
		<< "[    I    I    I         ]\n"
		<< "[    xx--xx    x         ]\n"
		<< "[    x @  x    x         ]\n"
		<< "x    x    x    x         x\n"
		<< "xx==xxxxxxxxxxxxx==xxx==xx\n";
}

void DownstairsBathroom::setGameOver()
{
	
}
