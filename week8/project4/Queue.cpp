/*********************************************************************
** Program name: Queue.cpp (used for Lab 7)
** Author: Jon Raleigh
** Date: 5/21/2017
** Description: Queue Class file. Holds functions and structs used
*				for the program
*********************************************************************/

#include "Queue.hpp"
#include "Creature.hpp"
#include <iostream>

Queue::Queue()
{
	front = nullptr;
	back = nullptr;
}

Queue::~Queue()
{
	while(front != nullptr)
	{
		delete front->creaturePtr;
		front->creaturePtr = nullptr;
		removeFront();
	}

	front = nullptr;
	back = nullptr;
	/*
	if (front != nullptr)
	{
		delete front;
	}
	if (back != nullptr)
	{
		delete back;
	}*/

}

void Queue::addBack(Creature *val)
{
/*****************************************************
* Adds value to back and reassigns front and back 
* pointers. 
*****************************************************/
	if (front == nullptr)
	{
		front = new QueueNode;
		back = front;
		front->creaturePtr = val;
		front->nextQueueNode = back;
		front->prevQueueNode = back;
	}
	else
	{
		QueueNode *nodeptr = new QueueNode;
		nodeptr->creaturePtr = val;
		nodeptr->prevQueueNode = back;
		nodeptr->nextQueueNode = front;
		back->nextQueueNode = nodeptr;
		back = nodeptr;
		front->prevQueueNode = back;
	}
}

void Queue::addFront(Creature* val)
{
	if (front == nullptr)
	{
		front = new QueueNode;
		back = front;
		front->creaturePtr = val;
		front->nextQueueNode = back;
		front->prevQueueNode = back;
	}
	else
	{
		QueueNode *nodeptr = new QueueNode;
		nodeptr->creaturePtr = val;
		nodeptr->prevQueueNode = back;
		nodeptr->nextQueueNode = front;
		front->prevQueueNode = nodeptr;
		back->nextQueueNode = nodeptr;
		front = nodeptr;
	}
}


Creature* Queue::getFront()
{
/*****************************************************
* Returns the value of the front node.
*****************************************************/
	if (front == nullptr)
	{
		std::cout << "\nThe queue is empty. Value will be displayed as zero.\n";
		return 0;
	}
	return front->creaturePtr;
}

void Queue::removeFront()
{
/*****************************************************
* Deletes the front node and reassigns pointers. 
*****************************************************/
	if (front == nullptr)
	{
		std::cout << "\nThe queue is empty. Nothing was removed.\n";
		return;
	}
	if (front == back)
	{
		front->creaturePtr = nullptr;
		delete front;
		front = nullptr;
		back = nullptr;		
		//std::cout << "\nThe queue is now empty.\n";
		return;
	}

	QueueNode *nodeptr = front->nextQueueNode;
	nodeptr->prevQueueNode = back;
	back->nextQueueNode = nodeptr;
	front->creaturePtr = nullptr;
	delete front;
	front = nodeptr;
	
}

void Queue::displayQueue()
{
	if (front == nullptr)
	{
		std::cout << "\nThe queue is empty.\n";
	}

	if (front != nullptr)
	{
		std::cout << "\n"
			<< front->creaturePtr->get_character_name();

		if (front != back)
		{
			struct QueueNode * listptr = front->nextQueueNode;

			while (listptr != front)
			{
				std::cout << " "
					<< listptr->creaturePtr->get_character_name();

				listptr = listptr->nextQueueNode;
			}

			std::cout << "\n";
		}
	}

}

bool Queue::isEmpty()
{
	if (front == nullptr)
	{
		return true;
	}
	return false;
}

