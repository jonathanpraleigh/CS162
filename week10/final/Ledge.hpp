/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: header file
*******************************************************************************************/
#ifndef LEDGE_HPP
#define LEDGE_HPP

#include "Room.hpp"
#include "Menu.hpp"
#include "Enums.hpp"

class Ledge : public Room
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
	Menu LedgeMenu;
	std::vector <std::string >direction = { "North", "South" };
	Items itemSelection;


public:
	Ledge();
	void setDirections(Room*, Room*, Room*, Room*, Room*, Room*) override;
	void use(std::vector<Items>*) override;
	void examine(std::vector<Items>*) override;
	void roomDescription() override;
	Room* go() override;
	void displayRoom() override ;
	void changeStatus() override;
	void setGameOver();
	bool gameOver;

};

#endif