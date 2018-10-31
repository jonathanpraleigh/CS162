/*********************************************************************
** Program name: Numberlist.hpp
** Author: Jon Raleigh
** Date: 5/14/17
** Description: header file for NumberList class.
*********************************************************************/

#ifndef NUMBERLIST_HPP
#define NUMBERLIST_HPP

class NumberList
{
protected:
	struct ListNode
	{
		int value;
		ListNode *previous;
		ListNode *next;
		ListNode (int value1, ListNode *previous1 = nullptr, ListNode *next1 = nullptr)
		{
			value = value1;
			previous = previous1;
			next = next1;
		
		}
	};
	ListNode *head;
	ListNode *tail;
public:
	NumberList();
	~NumberList();
	void addToTail(int number);
	void addToHead(int number);
	void deleteFromHead();
	void deleteFromTail();
	void displayList() const;
	void displayHead() const;
	void displayTail() const;
	
};


#endif
