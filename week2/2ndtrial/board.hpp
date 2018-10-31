/*********************************************************************
** Program name: board header file
** Author: Jon Raleigh
** Date: 4/16/17
** Description: header file.
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
private:
	bool ** b_array;
	bool b_color;
	int b_size;	

public:
	Board(int);
	void setColor(int, int, bool);
	bool getColor(int, int);
	void displayBoard();
	void clearBoard();

};

#endif
