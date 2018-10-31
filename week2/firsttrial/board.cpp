/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
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

	// creates dynamic array based on dimensions paramater	

void Board::setColor(int b_set_row, int b_set_column, bool b_c)
{
	b_array[b_set_row][b_set_column] = b_c;
}

	// sets specific array value to true of false

bool Board::getColor(int b_row, int b_column)
{
	b_color = b_array[b_row][b_column];
	return b_color;
}

	// gets current value of array location 

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

			std::cout << " " << output << " ";
		}

		std::cout << "\n";
	}
}
	

void Board::clearBoard()
{
	for (int i = 0; i < b_size; i++ )
	{
		delete[] b_array[i];
	}

	delete[] b_array;
}
	
