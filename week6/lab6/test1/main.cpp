/*********************************************************************
** Program name: main.cpp used for Linked List project
** Author: Jon Raleigh
** Date: 5/14/17
** Description: Implementation file for NumberList.	
*********************************************************************/

#include "main.hpp"
#include "menu.hpp"
#include "inputValidator.hpp"
#include<vector>

int main()
{
	menu_options = { "Add a new node to the head", "Add a new node to the tail", "Delete from head", "Delete from tail", "Traverse the list reversely", "Print the head value", "Print the tail value", "Exit" };

	for (;;)
	{
		selection = LinkedListMenu.menuDisplay(menu_options);

		if (selection == 1 )
		{
			// "Add a new node to the head"
			input = linkedListInput.testInteger(0, 0, true, false, false);
			Node.addToHead(input);

		}
		if (selection == 2 )
		{
			//"Add a new node to the tail" Asks for number and then passes to addToTail function to add it to end of list. 
			input = linkedListInput.testInteger(0, 0, true, false, false);
			Node.addToTail(input);
		}
		if (selection == 3 )
		{
			Node.deleteFromHead();
		}
		if (selection == 4 )
		{
			//"Delete from tail",
			Node.deleteFromTail();
		}
		if (selection == 5 )
		{
			//"Traverse the list reversely" Needs to start with last element on the list and go previous from there. 
			Node.displayList();
		}
		if (selection == 6)
		{
			//"Print the head value", 
			Node.displayHead();
		}
		if (selection == 7)
		{
			//"Print the tail value"
			Node.displayTail();
		}
		if (selection == 8 )
		{
			// Exit
			return 0;
		}

	}
}
