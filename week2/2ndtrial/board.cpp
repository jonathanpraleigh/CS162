/*********************************************************************
** Program name: board class for langtom program 
** Author: Jon Raleigh
** Date: 4/16/17
** Description: Creates board array and holds the values. Also 
**		displays the board and clears the memory used for
**		the array when it's no longer in use.
*********************************************************************/

#include <iostream>
#include <string>
#include "board.hpp"

Board::Board(int b_dimensions)
{
	b_array = new bool*[b_dimensions];
	
	for (int i = 0; i < b_dimensions; i++)
	{
		b_array[i] = new bool[b_dimensions];
	}

	
	for (int row = 0; row < b_dimensions; row++)
	{
		for (int column = 0; column < b_dimensions; column++)
		{
			b_array[row][column] = false;
		}
	}
	
	b_size = b_dimensions;
	b_color = false;
}

// creates dynamic array based on dimensions paramater. Decided
// to go with bool instead of enums for the colors for simplicity's
// sake, as there are only two possible values.  	

void Board::setColor(int b_set_row, int b_set_column, bool b_c)
{
	b_array[b_set_row][b_set_column] = b_c;
}

//sets the "color" of the square to true or false.

bool Board::getColor(int b_row, int b_column)
{
	b_color = b_array[b_row][b_column];
	return b_color;
}

// gets current value of array location 

/*******************************************************************
** displayBoard() is used once the values for the array have been 
** established within langton. Iterates through the array and displays
** hashtag if true and empty space if false.
******************************************************************/ 
 

void Board::displayBoard()
{
	for (int row = 0; row <b_size; row++ )
	{
		for (int column = 0; column < b_size; column++)
		{
			bool filled;
			std::string output;

			filled = getColor(row, column);

			if (filled == true)
			{
				output = "#";
			}
			else if (filled == false)
			{
				output = " ";
			};

			std::cout << output;
		}

		std::cout << "\n";
	}
}

/**************************************************************	
** clearBoard() is my memory clearing function. recycled from
** the first lab.
***************************************************************/

void Board::clearBoard()
{
	for (int i = 0; i < b_size; i++ )
	{
		delete[] b_array[i];
	}

	delete[] b_array;
}
	
