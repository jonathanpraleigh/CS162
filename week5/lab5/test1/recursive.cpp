/*********************************************************************
** Program name: 
** Author: Jon Raleigh
** Date: 
** Description:
*********************************************************************/

#include <iostream>
#include <string>
#include "menu.hpp"
#include "inputValidator.hpp"
#include "recursive.hpp"

int main()
{
	Menu Recursion;
	
	for (; ;)
	{
		program_choice = Recursion.menuDisplay(recursion_menu);

		if (program_choice == 1)
		{
			std::cout << "\nPlease enter a string of letters or numbers to be reversed.\n";
			std::cin.ignore(1000, '\n'); 
			std::getline(std::cin, string_to_be_reversed);
			string_reverser(string_to_be_reversed);
			
		}
		else if ( program_choice == 2)
		{
			InputValidator ArraySizeTester;
			std::cout << "\nPlease enter the size of your array.\n";
			array_size = ArraySizeTester.testInteger(1, 0, true, false, false);
			i_cant_wait_to_ditch_arrays_for_vectors = new int[array_size];
			
			std::cout << "\nPlease enter your array values\n";

			for (int i=0; i <array_size; i++)
			{
				array_input = ArraySizeTester.testInteger(1, 0, true, false, false);
				i_cant_wait_to_ditch_arrays_for_vectors[i] = array_input;
			}

			array_sum(i_cant_wait_to_ditch_arrays_for_vectors, array_size);
			
			delete[] i_cant_wait_to_ditch_arrays_for_vectors;

			i_cant_wait_to_ditch_arrays_for_vectors = NULL;

		
		}
		else if (program_choice == 3)
		{
			std::cout << "\nPlease enter the number of rows in your triangle.\n";
			std::cin >> rows_to_be_passed;
			triangle_calculator(rows_to_be_passed);
			
		}
		else if (program_choice == 4)
		{
			return 0;
		}

	}
}

void string_reverser(std::string reverse)
{
	if (reverse.size() == 0)
	{
		std::cout << "\n";
		return;
	}
	std::cout << reverse.back();
	reverse.pop_back();
	string_reverser(reverse);
}

void array_sum(int a[], int s)
{
	s -= 1;

	if (s < 0)
	{
		std::cout << sum;
		return;
	}

	sum += a[s];

	array_sum(a, s);
}

void triangle_calculator(int n)
{
	if (n == 0)
	{
		std::cout << total_rows;
		return;
	}

	rows += 1;
	total_rows += rows;
	n -= 1;

	triangle_calculator(n);
}
