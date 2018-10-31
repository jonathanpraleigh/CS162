/*********************************************************************
** Program name: Main.cpp (used for dice game program)
** Author: Jon Raleigh
** Date: 04/23/2017
** Description: 
*********************************************************************/

#include "game.hpp"
#include "menu.hpp"

//not much going on here.

int main()
{
	int selection;

	std::vector<std::string> game_menu_options = { "1. Play the game again", "2. Exit" };

	selection = menu(game_menu_options);

	if (selection == 2)
	{
		return 0;
	}

	Game diceGame;

	diceGame.roll_dice();

	diceGame.results();

	return 0;
}
