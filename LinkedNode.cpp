// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "LinkedNode.h"

LinkedNode::LinkedNode(int data) : Node(data)
{
	prevNode_ = nullptr;
	nextNode_ = nullptr;
}

LinkedNode::LinkedNode() : Node()
{
	prevNode_ = nullptr;
	nextNode_ = nullptr;
}

LinkedNode::~LinkedNode()
{
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