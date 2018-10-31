/*********************************************************************
** Program name: game.cpp (used for dice game program)
** Author: Jon Raleigh
** Date: 04/23/2017
** Description: 
*********************************************************************/

#include "game.hpp"
#include "menu.hpp"
#include "die.hpp"
#include "loadedDie.hpp"
#include <iostream>
#include <string>
#include "inputValidator.hpp"
//includes here


Game::Game()
{
//Initiating values for dice objects, and rounds. Data validation.

	std::cout << "Please enter the number of sides for player one's die.\n";
	std::cin >> player_one_sides;

	pass = testInteger(player_one_sides, 1, 0, true, false);	

	while (pass == false)
	{
		pass = testInteger(player_one_sides, 1, 0, true, false);
		
		if (pass == false)
		{	
				
			std::cout << "Please enter a number 1 or above." << std::endl;
			std::cin >> player_one_sides;
			std::cin.clear();		
			std::cin.ignore();		 
		}

	} 
	
	std::cout << "Is player one's die loaded? (Y/N)\n";
	std::cin >> y_or_n_player_one_loaded;

	pass == y_or_n_testChar(y_or_n_player_one_loaded); 
	
	while (pass == false)
	{
		pass = y_or_n_testChar(y_or_n_player_one_loaded);
	
		if (pass == false)
		{
			std::cout << "Please enter Y or N.\n";
			std::cin >> y_or_n_player_one_loaded;
		}

	} 

	if (y_or_n_player_one_loaded == 'Y'|| y_or_n_player_one_loaded == 'y')
	{
		player_one_loaded = true;
	}
	else if (y_or_n_player_one_loaded == 'N' || y_or_n_player_one_loaded == 'n')
	{
		player_one_loaded = false;
	}

	std::cout << "Please enter the number of sides for player two's die.\n";
	std::cin >> player_two_sides;

	pass = testInteger(player_two_sides, 1, 0, true, false);

	while (pass == false)
	{
		pass = testInteger(player_two_sides, 1, 0, true, false);

		if (pass == false)
		{
			std::cout << "Please enter a number 1 or above.\n";
			std::cin >> player_two_sides;
			std::cin.clear();
			std::cin.ignore();
		}

	} 

	std::cout << "Is player two's die loaded? (Y/N)\n";
	std::cin >> y_or_n_player_two_loaded;
	
	pass = y_or_n_testChar(y_or_n_player_two_loaded);

	while (pass == false)
	{
		pass = y_or_n_testChar(y_or_n_player_two_loaded);
		if (pass == false)
		{
			std::cout << "Please enter Y or N.\n";
			std::cin >> y_or_n_player_two_loaded;
			
		}

	} 

	if (y_or_n_player_two_loaded == 'Y' || y_or_n_player_two_loaded == 'y')
	{
		player_two_loaded = true;
	}
	else if (y_or_n_player_two_loaded == 'N' || y_or_n_player_two_loaded == 'n')
	{
		player_two_loaded = false;
	}

	std::cout << "Please enter the number of rounds you would like to play.\n";
	std::cin >> rounds;

	pass = testInteger(rounds, 1, 0, true, false);

	while (pass == false)
	{
		pass = testInteger(rounds, 1, 0, true, false);

		if (pass == false)
		{
			std::cout << "Please enter a number 1 or above.\n";
			std::cin >> rounds;
		}

	} 

	player_one_score = 0;
	player_one_total_score = 0;
	player_two_score = 0;
	player_two_total_score = 0;

}
/*************************************************************************************
** Function : roll_dice()
** Description : creates four dice objects and uses the dice and loaded dice 
** function "roll()" to load scores in a vector.
************************************************************************************/

void Game::roll_dice()
{

	Die playerOneDie(player_one_sides);
	Die playerTwoDie(player_two_sides);
	LoadedDie playerOneLoadedDie(player_one_sides);
	LoadedDie playerTwoLoadedDie(player_two_sides);

	if (player_one_loaded == false)
	{
		for (int i = 0; i < rounds; i++)
		{
			int roll_result;

			roll_result = playerOneDie.roll();

			results_player_one.push_back(roll_result);
		}
	}

	if (player_one_loaded == true)
	{
		for (int i = 0; i < rounds; i++)
		{
			int roll_result;

			roll_result = playerOneLoadedDie.roll();

			results_player_one.push_back(roll_result);
		}
	}

	if (player_two_loaded == false)
	{
		for (int i = 0; i < rounds; i++)
		{
			int roll_result;

			roll_result = playerTwoDie.roll();

			results_player_two.push_back(roll_result);
		}
	}

	if (player_two_loaded == true)
	{
		for (int i = 0; i < rounds; i++)
		{
			int roll_result;

			roll_result = playerTwoLoadedDie.roll();

			results_player_two.push_back(roll_result);
		}
	}
}

/************************************************************************
* Function results()
* Description : displays and formats contents of the results vector above.
* also determines winner of the roll and the entire game.
* ***********************************************************************/
void Game::results()
{
	int score_lines;
	int score_compare_one;
	int score_compare_two;

	score_lines = rounds;

	for (int i = 0; i < score_lines; i++)
	{
		std::cout << "Player 1. d"
			<< player_one_sides
			<< " Loaded? "
			<< y_or_n_player_one_loaded
			<< " Results: "
			<< results_player_one[i]
			<< "\n"
			<< "Player 2. d"
			<< player_two_sides
			<< " Loaded? "
			<< y_or_n_player_two_loaded
			<< " Results: "
			<< results_player_two[i]
			<< "\n\n";

		score_compare_one = results_player_one[i];
		score_compare_two = results_player_two[i];

		if (score_compare_one > score_compare_two)
		{
			std::cout << "Player one wins the round.\n\n";
			player_one_total_score = player_one_total_score + 1;
		}
		else if (score_compare_one < score_compare_two)
		{
			std::cout << "Player two wins the round.\n\n";
			player_two_total_score = player_two_total_score + 1;
		}
	}

	if (player_one_total_score > player_two_total_score)
	{
		std::cout << "\nPlayer one wins the game.\n";
	}

	if (player_one_total_score < player_two_total_score)
	{
		std::cout << "Player two wins the game.\n";
	}
	
	if (player_one_total_score == player_two_total_score)
	{
		std::cout << "It's a draw.\n";
	}  
}

