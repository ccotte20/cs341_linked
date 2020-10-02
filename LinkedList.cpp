// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "LinkedList.h"

LinkedList::LinkedList()
{
	// Ryan: We should really include these as part of our 
	//		 intialization list.
	head_ = nullptr;
	tail_ = nullptr;
}

LinkedList::~LinkedList()
{
	// Ryan: We need to check first if this is the nullptr
	//		 otherwise we could end up trying to delete a 
	//		 null item.
	delete head_;
}