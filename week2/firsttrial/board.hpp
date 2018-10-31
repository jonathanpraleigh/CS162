/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
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