// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "DoubleLinkedList.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
int main()
{
	// Get the file name for input
	std::string inputFile;
	std::cout<<"Enter input file name"<<std::endl;
	std::cin>>inputFile;
	
	//open file, check for errors
	std::ifstream inStream;
	inStream.open(inputFile.c_str());
	if(inStream.fail())
	{
		std::cout<<"Input file opening failed" << std::endl;
		exit(1);
	}
	
	//fill Doubly linked list
	int inputInt(0);
	DoubleLinkedList * dll = new DoubleLinkedList();
	while(inStream>>inputInt)
	{
		dll->insert(inputInt);
	}
	inStream.close();
	
	//open inserts file, check for errors
	inStream.open("inserts.txt");
	if(inStream.fail())
	{
		std::cout<<"Input file opening failed" << std::endl;
		exit(1);
	}
	
	//initialize hopCount to store count from inserts
	int hopCount(0);
	//get inserts integers
	while(inStream>>inputInt)
	{
		//count number of hops from head
		int headHops(0);
		LinkedNode * headPtr = dll->head_;
		while(headPtr->getData()<inputInt)
		{
			headPtr = headPtr->getNextNode();
			headHops++;
			//check if tail, if so exit to avoid setting pointer to nothing
			if(headPtr->getNextNode() == nullptr)
				break;
		}
		
		//count number of hops from tail
		int tailHops(0);
		LinkedNode * tailPtr = dll->tail_;
		while(tailPtr->getData()>inputInt)
		{
			tailPtr = tailPtr->getPrevNode();
			tailHops++;
			//check if head, if so exit to avoid setting pointer to nothing
			if(tailPtr->getPrevNode() == nullptr)
				break;
		}
		
		//compare number of hops from head to number of hops from tail and do appropriate insert
		if(headHops<tailHops)
		{
			if(headPtr->getData()==inputInt)
				dll->insertAfter(headPtr, inputInt);
			else
				dll->insertBefore(headPtr, inputInt);
			hopCount += headHops;
		}
		else
		{
			dll->insertAfter(tailPtr, inputInt);
			hopCount += tailHops;
		}
	}
	inStream.close();
	
	std::ofstream outStream;
	// Get file name for output
	std::string outputFile;
	std::cout<<"Enter output file name"<<std::endl;
	std::cin>>outputFile;
	
	// Open file, check for errors
	outStream.open(outputFile.c_str());
	if(outStream.fail())
	{
		std::cout<<"Output file opening failed" << std::endl;
		exit(1);
	}
	
	//print doubly linked list to file
	LinkedNode * ptr = dll->head_;
	while(ptr->getNextNode() != nullptr)
	{
		outStream<<ptr->getData()<<" ";
		ptr = ptr->getNextNode();
	}
	outStream<<dll->tail_->getData();
	outStream.close();
	
	//open file for appending, check for errors
	outStream.open("README.txt", std::ios::app);
	if(outStream.fail())
	{
		std::cout<<"Output file opening failed" << std::endl;
		exit(1);
	}
	//add new hopCount to existing file
	outStream<<"Hop Count: "<<hopCount<<"\n";
	
	//delete dll
	delete dll;
	
	
	return 0;
}