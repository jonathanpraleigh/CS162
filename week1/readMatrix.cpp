/************************************************************
** Program Name : readMatrix.hpp
** Author : Jon Raleigh
** Date : 4/9/17
** Description : After taking a pointer to a 2d array and
**		the size of the array as parameters, prompts
**		the user to enter the values of the array.	 
************************************************************/

#include "readMatrix.hpp"
#include <iostream>

void readMatrix(int** rMatrix, int rSize)
 {
	for (rRow = 0; rRow < rSize; rRow++)
	{
		for (rColumn = 0; rColumn < rSize; rColumn++)
		{
			std::cout << "Please enter the value for array location "
				<< rRow
				<< " , "
				<< rColumn
				<< std::endl;

			std::cin >> input;
			
			rMatrix[rRow][rColumn] = input;
		}
	}	
 }

