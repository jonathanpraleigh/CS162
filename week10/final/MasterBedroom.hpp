/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: header file
*******************************************************************************************/
#ifndef MASTERBEDROOM_HPP
#define MASTERBEDROOM_HPP

#include "Room.hpp"
#include "Menu.hpp"
#include "Enums.hpp"

class MasterBedroom : public Room
{
protected:
	Room * North;
	Room * East;
	Room * South;
	Room * West;
	Room * Down;
	Room * Up;
	int choice;
	bool initialVisit;
	bool roomChanged;
	std::vector<std::string> directions = {"East", "South"};
	Menu MasterBedroomMenu;
	Items itemSelection;

public:
	MasterBedroom();
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