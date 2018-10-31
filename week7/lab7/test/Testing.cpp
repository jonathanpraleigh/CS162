/*********************************************************************
** Program name: Testing.cpp (used for Lab 7)
** Author: Jon Raleigh
** Date: 5/21/2017
** Description: Implementation and testing file for the lab.
*********************************************************************/

#include "Testing.hpp"
#include "Queue.hpp"
#include "InputValidator.hpp"
#include <iostream>

//#include "Menu.hpp"

int main()
{
	Queue TestQueue;
	menu_options = { "Enter a value to be added to the queue", "Display first node (front) value", "Remove first node (front) value", "Display the queue contents", "Exit" };
	InputValidator InputTester;

	for (;;)
	{
		selection = testing_menu.menuDisplay(menu_options);

		if (selection == 1)
		{
			std::cout << "\nPlease enter a value to be added.\n";
			
			value_to_be_added = InputTester.testInteger(0, 0, false, false, true);

			TestQueue.addBack(value_to_be_added);
		}

		if (selection == 2)
		{
			std::cout << "\n"
				<< TestQueue.getFront()
				<< "\n";
		}

		if (selection == 3)
		{
			TestQueue.removeFront();
		}

		if (selection == 4)
		{
			TestQueue.displayQueue();
		}

		if (selection == 5)
		{
			return 0;
		}
	}
}
