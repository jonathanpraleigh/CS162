/*********************************************************************
** Program name: Queue.hpp
** Author: Jon Raleigh
** Date: 5/21/17
** Description: header file for Queue class file.
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Creature.hpp"

class Queue
{
public:

	struct QueueNode
	{
		Creature * creaturePtr;
		QueueNode * nextQueueNode;
		QueueNode * prevQueueNode;
	};
	QueueNode * front;
	QueueNode * back;
	Queue();
	~Queue();
	void addBack(Creature*);
	void addFront(Creature*);
	Creature* getFront();
	void removeFront();
	void displayQueue();
	bool isEmpty();
	
	//need a garbage queue for losing creatures. 
	
};

#endif