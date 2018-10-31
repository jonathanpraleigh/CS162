/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: header file
*******************************************************************************************/
#ifndef UPSTAIRSHALLWAY_HPP
#define UPSTAIRSHALLWAY_HPP

#include "Room.hpp"
#include "Menu.hpp"
#include "Enums.hpp"

class UpstairsHallway : public Room
{
protected:
	Room * North;
	Room * East;
	Room * South;
	Room * West;
	Room * Down;
	Room * Up;
	bool initialVisit;
	bool roomChanged;
	int choice;
	Menu UpstairsHallwayMenu;
	std::vector <std::string >direction = { "North", "East", "South" };
	Items itemSelection;

public:
	UpstairsHallway();
	void setDirections(Room*, Room*, Room*, Room*, Room*, Room*) override;
	void use(std::vector<Items>*) override;
	void examine(std::vector<Items>*) override;
	void roomDescription() override;
	Room* go() override;
	void displayRoom() override;
	void changeStatus() override;
	void setGameOver();
	bool gameOver;

};

#endif