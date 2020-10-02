// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "LinkedNode.h"

LinkedNode::LinkedNode(int data) : Node(data)
{
	// Ryan: We should really put these in our initialization list.
	prevNode_ = nullptr;
	nextNode_ = nullptr;
}

LinkedNode::LinkedNode() : Node()
{
	// Ryan: We should really put these in our initialization list.
	prevNode_ = nullptr;
	nextNode_ = nullptr;
}

LinkedNode::~LinkedNode()
{
	// Ryan: We need to check to ensure this is not nullptr
	//		 otherwise we could try and delete something that
	//		 that is already null, which would cause a problem.
	delete nextNode_;
}

void LinkedNode::setNextNode(LinkedNode * node)
{
	nextNode_ = node;
}

void LinkedNode::setPrevNode(LinkedNode * node)
{
	prevNode_ = node;
}

LinkedNode * LinkedNode::getNextNode()
{
	return nextNode_;
}

LinkedNode * LinkedNode::getPrevNode()
{
	return prevNode_;
}