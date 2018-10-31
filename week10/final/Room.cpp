/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: Room class file
*******************************************************************************************/
#include "Room.hpp"

Room::Room()
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

void Room::roomDescription()
{
	//description loaded up for each room. some of the rooms change according to
	//whether they've been visited or not.
}


void Room::setDirections(Room*, Room*, Room*, Room*, Room*, Room*)
{
	//pointers to the other adjacent rooms, if available. 
}


void Room::use(std::vector<Items>* i)
{
	//menu that draws from inventory, set inventory as parameter.
}

void Room::examine(std::vector<Items>* i)
{
	//deeper examination of room. sometimes involves picking up an item. 
}

Room* Room::go()
{
	//If it's possible to leave the room, returns the room, if not, it says:
	return this;
}

void Room::changeStatus()
{
	//going into one room changes the upstairs area. I created this function to be able to change a value in another room.
}

void Room::displayRoom()
{
	//displays the map of the house for that floor.
}

void Room::setGameOver()
{
	//function that I created, but it didn't work. 
}


