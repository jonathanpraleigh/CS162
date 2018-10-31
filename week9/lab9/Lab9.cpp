/********************************************************************************************
** Program name: Lab 9
** Author: Jon Raleigh
** Date: 6/04/17
** Description: Implementation of two STL Containers
*******************************************************************************************/

#include "Menu.hpp"
#include "InputValidator.hpp"
#include "Lab9.hpp"
#include <iostream>
#include <string>
#include <stack>
#include <queue>

int main()
{
	

	while (selection != 3)
	{
		selection = MainMenu.menuDisplay(mainMenuOptions);

		if (selection == 1)
		{
			queueDemonstration();
		}
		if (selection == 2)
		{
			stackDemonstration();
		}
		if (selection == 3)
		{
			return 0;
		}

	}
	
}

void queueDemonstration()
{
	std::cout << "\nPlease enter the number of rounds.\n";
	rounds = Inputter.testInteger(1, 20, true, true, false);
	std::cout << "\nPlease enter the percentage to randomly put a number in the buffer\n";
	addChance = Inputter.testInteger(1, 100, true, true, false);
	std::cout << "\nPlease enter the percentage to randomly remove a number from the buffer;\n";
	removeChance = Inputter.testInteger(1, 100, true, true, false);
	
	//for (int i = 0; i < rounds; i++)
	for (roundCounter = 1; roundCounter < rounds + 1; roundCounter++)
	{
		roll = (rand() % 1000 + 1);
		std::cout << "\nYou rolled a " << roll << ".\n";

		rollTemp = roller();
		
		if (addChance > rollTemp)
		{
			intQueue.push(roll);
			std::cout << "\nYour roll " << roll << " was added to the queue.\n";
		}
		else
		{
			std::cout << "\nThe roll was not added to the queue.\n";
		}

		rollTemp = roller();

		if (removeChance > rollTemp)
		{
			if (!intQueue.empty())
			{
				std::cout << "\nThe number " << intQueue.front() << " was removed from the queue.\n";
				intQueue.pop();
			}
			else
			{
				std::cout << "\nThe queue is empty.\n";
			}
		}
		else
		{
			std::cout << "\nNo numbers were removed.\n";
		}

		currentSize = intQueue.size();

		displayQueue(intQueue);

		if (roundCounter == 1)
		{
			std::cout << "\nThe average length of the queue is " << currentSize << ".\n";
			prevAvgLength = currentSize;
		}
		else
		{
			avgLength = (prevAvgLength * (roundCounter - 1) + currentSize) / roundCounter;
			std::cout << "\nThe current average length is " << avgLength << ".\n";
			prevAvgLength = avgLength;
		}

	}

}

int roller ()
{
	return (rand() % 100 + 1);
}

void displayQueue(std::queue<int> x)
{
	std::cout << "\n";

	disposableQueue = x;
	
	iterations = disposableQueue.size();

	for (int i = 0; i < iterations; i++)
	{
		std::cout << disposableQueue.front() << " ";
		disposableQueue.pop();
	}

	std::cout << "\n";
}

void stackDemonstration()
{
	std::cout << "\nPlease enter a string and I will turn it into a palindrome.\n";
	
	std::cin.clear();
	std::cin.ignore(256, '\n');
	getline(std::cin, toPalindrome);


	for (int i = 0; i < toPalindrome.size(); i++)
	{
		palindrome.push(toPalindrome[i]);
	}

	std::cout << "\n" << toPalindrome;

	size = toPalindrome.size();

	for (int i = 0; i<size; i++)
	{
		std::cout << palindrome.top();
		palindrome.pop();
	}

	std::cout << "\n";
}
