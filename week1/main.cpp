/*********************************************************
* Program name: main.cpp (main function) 
* Author : Jon Raleigh
* Date : 4/9/17
* Description : Asks user to select 2 or 3 matrix size,
* 		passes creates a pointer to a 2d dynamic  
* 		array based on the size. Then uses two
* 		functions to populate the array and 
* 		provide the determinant. After this, 
* 		displays the contents of the matrix and 
* 		the determinant.
* ********************************************************/


#include <iostream>

void readMatrix(int **, int);
int determinant(int **, int);

int main ()
{
	int size;
	int determ;
	int** pMatrix;
	int row;
	int column;

	std::cout << "Please select a (2)x2 or (3)x3 matrix.";
	std::cin >> size;

	if (size != 2 && size != 3)
	 {
		std::cout << "Please try again.";
		return 0;
	 }

	//Above is some very weak input validation.  

	pMatrix = new int*[size];
	for (int i = 0; i < size; ++i)
	 {
		pMatrix[i] = new int[size];
	 }

	//Above lines create the dynamic array.

	readMatrix(pMatrix, size);
	
	determ = determinant(pMatrix, size);

	//functions above populate the array and finds the determinant. 

	for (row = 0; row < size; row++)
	{
		for (column = 0; column < size; column++)
		{
			std::cout << " "
				<< pMatrix[row][column]
				<< " ";
		}

		std::cout << "\n";
	}

	//Above displays the contents of the array by iterating through rows and columns
	
	std::cout << "The determinant is " << determ << "." << std::endl;

	for (int i = 0; i < size; ++i)
	 {
		delete[] pMatrix[i];
	 }
	delete[] pMatrix;

	//"undoes" the creation of the array and clears the memory.

	return 0;
}

