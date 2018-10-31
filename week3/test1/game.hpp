/*********************************************************************
** Program name: game header file
** Author: Jon Raleigh
** Date: 4/23/17
** Description: header file for game class file.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "die.hpp"
#include "loadedDie.hpp"

class Game
{
private:
	int player_one_sides;
	int *p_player_one_sides;
	char y_or_n_player_one_loaded;
	char *p_y_or_n_player_one_loaded;
	bool player_one_loaded;
	int player_two_sides;
	int *p_player_two_sides;
	char y_or_n_player_two_loaded;
	char *p_y_or_n_player_two_loaded;
	bool player_two_loaded;
	bool pass;
	int rounds;
	std::vector<int> results_player_one;
	std::vector<int> results_player_two;
	int player_one_score;
	int player_two_score;
	Die playerOneDie;
	Die playerTwoDie;
	LoadedDie playerOneLoadedDie;
	LoadedDie playerTwoLoadedDie;
	int player_one_total_score;
	int player_two_total_score;

public:
	Game();
	void roll_dice();
	void results();
};

#endif
