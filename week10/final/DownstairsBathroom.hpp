/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: header file
*******************************************************************************************/
#ifndef DOWNSTAIRSBATHROOM_HPP
#define DOWNSTAIRSBATHROOM_HPP

#include "Room.hpp"
#include "Enums.hpp"
#include "Menu.hpp"


class DownstairsBathroom : public Room
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
	Items itemSelection;
	Menu DownstairsBathroomMenu;
	std::vector<std::string>directions = { "North" };

public:
	DownstairsBathroom();
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