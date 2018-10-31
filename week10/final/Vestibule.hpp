/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: header file
*******************************************************************************************/
#ifndef VESTIBULE_HPP
#define VESTIBULE_HPP

#include "Room.hpp"
#include "Enums.hpp"
#include "Menu.hpp"

class Vestibule : public Room
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
	std::vector<std::string>directions = { "North","East","West" };
	Menu VestibuleMenu;

public:
	Vestibule();
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