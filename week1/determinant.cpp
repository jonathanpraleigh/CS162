/*******************************************************
* Program Name : determinant.hpp (function file) 
* Author : Jon Raleigh
* Date : 4/9/17
* Description : Returns the determinant from a 2d dynamic array
* 		provided a matrix pointer and size.   
* ******************************************************/
#include "determinant.hpp"

int determinant(int** dMatrix, int dSize)
{
	//I terminated the program in main if any size that wasn't 2 or 3 was provided
	//so I only used 2 and else for the possibilities below. 

	if (dSize == 2)
	 {
		deter = (dMatrix[0][0] * dMatrix[1][1]) - (dMatrix[0][1] * dMatrix[1][0]);
		return deter;
	 }
	else
	 {
		deter = ( dMatrix[0][0] * ( ( dMatrix[1][1] * dMatrix[2][2] ) - ( dMatrix[1][2] * dMatrix[2][1] ) ) ) -
				( dMatrix[0][1] * ( ( dMatrix[1][0] * dMatrix[2][2] ) - ( dMatrix[1][2] * dMatrix[2][0] ) ) ) +
				( dMatrix[0][2] * ( ( dMatrix[1][0] * dMatrix[2][1] ) - ( dMatrix[1][1] * dMatrix[2][0] ) ) );
		return deter;
	 }
	
}


