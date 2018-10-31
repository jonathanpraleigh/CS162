/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: header file
*******************************************************************************************/

#ifndef VERMIN_HPP
#define VERMIN_HPP

#include <vector>
#include "Menu.hpp"
#include "Enums.hpp"

int choice;
int timer;

bool finished;

std::vector<std::string>openingMenuOptions = { "Play", "Quit" };
std::vector<std::string>playMenuOptions = { "Go", "Examine", "Use", "Quit Game" };
std::vector<Items>inventory;
std::vector<Items> * ptrInventory = &inventory;

Menu GameMenu;
Menu PlayMenu;

void openingGraphics();

#endif

