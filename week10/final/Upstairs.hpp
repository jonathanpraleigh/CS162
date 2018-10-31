/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: header file
*******************************************************************************************/
#ifndef UPSTAIRS_HPP
#define UPSTAIRS_HPP

#include "Room.hpp"
#include "Menu.hpp"
#include "Enums.hpp"

class Upstairs : public Room
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
	Menu UpstairsMenu;
	std::vector <std::string >direction = { "East", "South", "Down" };
	Items itemSelection;

public:
	Upstairs();
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