/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: header file
*******************************************************************************************/
#ifndef UPSTAIRSBATHROOM_HPP
#define UPSTAIRSBATHROOM_HPP

#include "Room.hpp"
#include "Enums.hpp"
#include "Menu.hpp"

class UpstairsBathroom : public Room
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
	Menu UpstairsBathroomMenu;
	std::vector <std::string >direction = {"North"};
	Items itemSelection;

public:
	UpstairsBathroom();
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