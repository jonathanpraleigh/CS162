/*********************************************************************
** Program name: langton.cpp
** Author: Jon Raleigh
** Date: 4/16/17
** Description: 
*********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "menu.hpp"
#include "board.hpp"
#include "ant.hpp"
#include "inputValidator.hpp"
#include "orientation.hpp"


int main()
{
	std::vector<std::string> menu_options{ "1. Play the game", "2. Quit" };
	std::vector<char> orientation_options{'N', 'E', 'S', 'W', 'n', 'e', 's', 'w'};
	//int menu(std::vector<std::string>);
	int response;
	int dimensions;
	int starting_row;
	int starting_column;
	int turns;
	int new_row;
	int new_column;
	char starting_orientation;
	bool dimensions_passed;
	bool row_passed;
	bool column_passed;
	bool turns_passed;
	bool orientation_passed;
	bool current_color;
	orientation current_orientation;
	
	response = menu(menu_options);

	if (response == 2)
	{
		return 0;
	}

	std::cout << "Please enter the dimensions of the board (preferably less than 80).\n";
	
	std::cin >> dimensions;

	dimensions_passed = testInteger(dimensions, 0, 0, true, false);

	if (dimensions_passed == false)
	{
		while (dimensions_passed == false)
		{
			std::cout << "Please enter valid dimensions.\n";
			
			std::cin >> dimensions;

			dimensions_passed = testInteger(dimensions, 0, 0, true, false);
		}
	}

	Board langton_board(dimensions);

	std::cout << "Please enter the starting row.\n";
	
	std::cin >> starting_row;

	row_passed = testInteger(starting_row, -1, dimensions, true, true);

	if (row_passed == false)
	{
		while (row_passed == false)
		{
			std::cout << "Please enter a valid starting row.\n";

			std::cin >> starting_row;

			row_passed = testInteger(starting_row, -1, dimensions, true, true);
		}
	}

	std::cout << "Please enter the starting column.\n";

	std::cin >> starting_column;

	column_passed = testInteger(starting_column, -1, dimensions, true, true);

	if (column_passed == false)
	{
		while (column_passed == false)
		{
			std::cout << "Please enter a valid starting column.\n";

			std::cin >> starting_column;

			column_passed = testInteger(starting_column, -1, dimensions, true, true);
		}
	}

	
	std::cout << "Please enter the starting orientation (N, E, S, W).\n";

	std::cin >> starting_orientation;

	orientation_passed = testChar(starting_orientation, orientation_options);

	if (orientation_passed == false)
	{
		while (orientation_passed == false)
		{
			std::cout << "Please enter a valid starting orientation.\n";

			std::cin >> starting_orientation;

			orientation_passed = testChar(starting_orientation, orientation_options);
		}
	}
	
	if (starting_orientation == 'N' || starting_orientation == 'n')
	{
		current_orientation = NORTH;
	}
	else if (starting_orientation == 'E' || starting_orientation == 'e')
	{
		current_orientation = EAST;
	}
	else if (starting_orientation == 'S' || starting_orientation == 's')
	{
		current_orientation = SOUTH;
	}
	else if (starting_orientation == 'W' || starting_orientation == 'w')
	{
		current_orientation = WEST;
	}

	Ant player(starting_row, starting_column, current_orientation, dimensions);

	std::cout << "Please enter the number of turns you would like the ant to take.\n";

	std::cin >> turns;

	turns_passed = testInteger(turns, 0, 0, true, false);

	if (turns_passed == false)
	{
		while (turns_passed == false)
		{
			std::cout << "Please enter a valid number of turns.\n";

			std::cin >> turns;

			turns_passed = testInteger(turns, 0, 0, true, false);
		}
	}

	for (int i = 0; i <= turns; i++)
	{


		int current_row = player.getLocationRow();
		int current_column = player.getLocationColumn();
		current_orientation = player.getOrientation();

		current_color = langton_board.getColor(current_row, current_column);

		if (current_color == false)
		{
			langton_board.setColor(current_row, current_column, true);
			
			if (current_orientation == NORTH)
			{
				new_row = current_row + 1;

				player.setLocation(new_row, current_column, dimensions);
	
				player.setOrientation(EAST);
			}


			if (current_orientation == EAST)
			{
				new_column = current_column + 1;

				player.setLocation(current_row, new_column, dimensions);

				player.setOrientation(SOUTH);
			}

			if (current_orientation == SOUTH)
			{
				new_row = current_row - 1;
				
				player.setLocation(new_row, current_column, dimensions);

				player.setOrientation(WEST);
			}

			if (current_orientation == WEST)
			{
				new_column = current_column - 1;
				
				player.setLocation(current_row, new_column, dimensions);
					
				player.setOrientation(NORTH);
			}

		}
		
		else if (current_color == true)
		{
			langton_board.setColor(current_row, current_column, false);
	
			if (current_orientation == NORTH)
				{
					new_row = current_row + 1;

					player.setLocation(new_row, current_column, dimensions);

					player.setOrientation(WEST);
				}

			if (current_orientation == EAST)
			{
				new_column = current_column - 1;

				player.setLocation(current_row, new_column, dimensions);

				player.setOrientation(NORTH);
			}

			if (current_orientation == SOUTH)
			{
				new_row = current_row + 1;

				player.setLocation(new_row, current_column, dimensions);

				player.setOrientation(EAST);
			}

			if (current_orientation == WEST)
			{
				new_column = current_column + 1;

				player.setLocation(current_row, new_column, dimensions);

				player.setOrientation(SOUTH);
			}

		}

		langton_board.displayBoard();

		langton_board.clearBoard();

		//loops around how?
	}
}



