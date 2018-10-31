/*********************************************************************
** Program name: NumberList.cpp used for LinkedList project
** Author: Jon Raleigh
** Date: 5/14/17
** Description: class holds the struct and the functions to 
**				allow for creation, display, and deletion of
**				linked list memebers. 
*********************************************************************/

#include "NumberList.hpp"
#include<iostream>

NumberList::NumberList()
{
	head = nullptr;
	tail = nullptr;
}

void NumberList::addToTail(int number)
{

	if (head == nullptr)
	{
		head = new ListNode(number);
		tail = head;
	}
	else
	{
		ListNode *nodePtr = head;

		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}

//passing the address to the newly created node for the previous
//value.
		nodePtr->next = new ListNode(number, nodePtr);
		
//repeating the same process to go through the list again 
//and assign the tail pointer to the recently added node.

		nodePtr = head;
		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}
		tail = nodePtr;
	}
	
}

void NumberList::addToHead(int number)
{
//sets tail and head pointers to new object if none exists (aka points to nullptr)
//or creates a new node and reassigns head pointer after making a previous pointer. 
	if (head == nullptr)
	{
		head = new ListNode(number);
		tail = head;
	}
	else
	{
		head->previous = new ListNode(number,nullptr,head);
		head = head->previous;
	}

}

void NumberList::deleteFromHead()
{

//tests for empty list soasnotto create crashes.
	if (head == nullptr || tail == nullptr)
	{
		std::cout << "\nThe list is already empty\n";
	}
	else
	{
		ListNode *nodePtr = head->next;
		delete head; //deletes and reassigns head pointer.
		head = nodePtr;
		if (head != nullptr)
		{
			head->previous = nullptr;
		}
//had to put this in here to keep from trying to assign a non-existent pointer to something. 
	}
}

void NumberList::deleteFromTail()
{
	if (tail == nullptr || head == nullptr)
	{
		std::cout << "\nThe list is already empty.\n";
	}
	else
	{
		ListNode *nodePtr = tail->previous;
		delete tail;
		tail = nodePtr;
		if (tail != nullptr)
		{
			tail->next = nullptr;
		}
	}
}


void NumberList::displayList() const
{
	ListNode *nodePtr = tail;

	if (tail == nullptr || head == nullptr)
	{
		std::cout << "The list is empty.\n";
		return;
	}
//redundant to include both, but in the early stages this kept things from crashing and it doesn't hurt to keep it.
	while(nodePtr)
	{
		std::cout << nodePtr->value << " ";
		nodePtr = nodePtr->previous;
	}
	std::cout << "\n";
}

void NumberList::displayHead() const
{
//fairly self-explanatory.
	if (head == nullptr)
	{
		std::cout << "\nThe list is empty.\n";
	}
	else
	{
		std::cout << "\n" << head->value << "\n";
	}
}

void NumberList::displayTail() const
{
//also self-explanatory.
	if (tail == nullptr)
	{
		std::cout << "\nThe list is empty.\n";
	}
	else
	{
		std::cout << "\n" << tail->value << "\n";
	}
}

NumberList::~NumberList()
{
	ListNode *nodePtr = head; 
	while (nodePtr != nullptr)
	{
		ListNode *garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
//nice trick swiped from the book. 
	}
}


