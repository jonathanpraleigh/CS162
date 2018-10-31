/*********************************************************************
** Program name: Queue.hpp
** Author: Jon Raleigh
** Date: 5/21/17
** Description: header file for Queue class file.
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
public:

	struct QueueNode
	{
		int integer_value = 0;
		QueueNode * nextQueueNode;
		QueueNode * prevQueueNode;
	};
	QueueNode * front;
	QueueNode * back;
	Queue();
	~Queue();
	void addBack(int);
	int getFront();
	void removeFront();
	void displayQueue();
	
};

#endif