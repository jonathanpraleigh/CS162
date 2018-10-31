/*********************************************************************
** Program name: Queue.cpp (used for Lab 7)
** Author: Jon Raleigh
** Date: 5/21/2017
** Description: Queue Class file. Holds functions and structs used
*				for the program
*********************************************************************/

#include "Queue.hpp"
#include <iostream>

Queue::Queue()
{
	front = nullptr;
	back = nullptr;
}

Queue::~Queue()
{
	if (front != nullptr)
	{
		delete front;
	}
	if (back != nullptr)
	{
		delete back;
	}

}

void Queue::addBack(int val)
{
/*****************************************************
* Adds value to back and reassigns front and back 
* pointers. 
*****************************************************/
	if (front == nullptr)
	{
		front = new QueueNode;
		back = front;
//		front = back;
		front->integer_value = val;
		front->nextQueueNode = back;
		front->prevQueueNode = back;
	}
	else
	{
		QueueNode *nodeptr = new QueueNode;
		nodeptr->integer_value = val;
		nodeptr->prevQueueNode = back;
		nodeptr->nextQueueNode = front;
		back->nextQueueNode = nodeptr;
		back = nodeptr;
		front->prevQueueNode = back;
	}
}

int Queue::getFront()
{
/*****************************************************
* Returns the value of the front node.
*****************************************************/
	if (front == nullptr)
	{
		std::cout << "\nThe queue is empty. Value will be displayed as zero.\n";
		return 0;
	}
	return front->integer_value;
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
		delete front;
		front = nullptr;
		back = nullptr;		
		std::cout << "\nThe queue is now empty.\n";
		return;
	}


	//struct QueueNode *nodeptr = front->nextQueueNode;
	
	QueueNode *nodeptr = front->nextQueueNode;

	//front = front->nextQueueNode;

	nodeptr->prevQueueNode = back;

	back->nextQueueNode = nodeptr;

	/*back->nextQueueNode = nodeptr;

	nodeptr->prevQueueNode = back;*/

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
			<< front->integer_value;

		if (front != back)
		{
			struct QueueNode * listptr = front->nextQueueNode;

			while (listptr != front)
			{
				std::cout << " "
					<< listptr->integer_value;

				listptr = listptr->nextQueueNode;
			}

			std::cout << "\n";
		}
	}
}


