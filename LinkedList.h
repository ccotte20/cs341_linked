// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "List.h"
#include "LinkedNode.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class LinkedList : public List
{
	public:
		LinkedList();
		virtual ~LinkedList();
		// Ryan: We should always make our attributes private
		//		 to prevent unwanted access externally.
		LinkedNode * head_;
		LinkedNode * tail_;
};
#endif