// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "DoubleLinkedList.h"
#include <iostream>
DoubleLinkedList::DoubleLinkedList() : LinkedList()
{
	
}

bool DoubleLinkedList::isEmtpy()
{
	if(head_==nullptr)
		return true;
	else
		return false;
}

int DoubleLinkedList::getLength()
{
	int count(0);
	LinkedNode * temp = head_;
	while(temp->getNextNode() != nullptr)
	{
		temp = temp->getNextNode();
		count++;
	}
	count++;
	return count;
}

void DoubleLinkedList::insert(int element)
{
	LinkedNode * newNode = new LinkedNode(element);
	insertLinkedNode(newNode, element);
}

void DoubleLinkedList::printList()
{
	LinkedNode * ptr = head_;
	while(ptr->getNextNode() != nullptr)
	{
		std::cout<<ptr->getData()<<" ";
		ptr = ptr->getNextNode();
	}
	std::cout<<tail_->getData()<<std::endl;
}

void DoubleLinkedList::insertLinkedNode(LinkedNode * node, int data)
{
	if(head_ == nullptr)
	{
		head_=node;
		tail_=node;
	}
	else
	{
		tail_->setNextNode(node);
		node->setPrevNode(tail_);
		tail_=node;
	}
}

void DoubleLinkedList::insertAfter(LinkedNode * node, int data)
{
	LinkedNode * newNode = new LinkedNode(data);
	if(node->getNextNode() == nullptr)
	{
		insertLinkedNode(newNode, data);
	}
	else
	{
		newNode->setNextNode(node->getNextNode());
		newNode->setPrevNode(node);
		node->getNextNode()->setPrevNode(newNode);
		node->setNextNode(newNode);
	}
}

void DoubleLinkedList::insertBefore(LinkedNode * node, int data)
{
	LinkedNode * newNode = new LinkedNode(data);
	if(node->getPrevNode() == nullptr)
	{
		node->setPrevNode(newNode);
		newNode->setNextNode(node);
		head_=newNode;
	}
	else
	{
		newNode->setNextNode(node);
		newNode->setPrevNode(node->getPrevNode());
		node->getPrevNode()->setNextNode(newNode);
		node->setPrevNode(newNode);
	}
}