// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "Node.h"
#ifndef LINKEDNODE_H
#define LINKEDNODE_H
class LinkedNode : public Node
{
	public:
		LinkedNode(int data);
		virtual ~LinkedNode();
		void setNextNode(LinkedNode * node);
		void setPrevNode(LinkedNode * node);
		LinkedNode * getNextNode();
		LinkedNode * getPrevNode();
	private:
		LinkedNode * prevNode_;
		LinkedNode * nextNode_;
	protected:
		LinkedNode();
};
#endif