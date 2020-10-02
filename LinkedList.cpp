// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "LinkedList.h"

LinkedList::LinkedList()
{
	head_ = nullptr;
	tail_ = nullptr;
}

LinkedList::~LinkedList()
{
	delete head_;
}