// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "LinkedList.h"
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
class DoubleLinkedList : public LinkedList
{
	public:
		DoubleLinkedList();
		virtual ~DoubleLinkedList() {}
		virtual bool isEmtpy();
		virtual int getLength();
		virtual void insert(int element);
		virtual void printList();
		virtual void insertLinkedNode(LinkedNode * node, int data);
		void insertAfter(LinkedNode * node, int data);
		void insertBefore(LinkedNode * node, int data);
};
#endif