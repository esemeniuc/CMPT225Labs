/*
 * ListADT.h - Header of the ListADT class
 * 
 * Class Description: A data collection List ADT class.
 *                    Note that this is a link-based implementation 
 *                    of a data collection List ADT class 
 *                    as its underlying data structure is
 *                    a singly-headed singly-linked list (SHSL).                  
 *
 * Creation Date: 
 * Author: 
 */

#pragma once
#include "Node.h"



class ListADT{

private:
    int elementCount;  // Number of elements currently stored in the list.
	Node *head;        // Pointer to the first node in the list

public:
	// Constructors and Destructors
	/* Generally every class should have at least two construtors, a
	 * default constructor and a copy constructor that creates a copy
	 * of the given object*/
	ListADT(); //default construtor

	ListADT(const ListADT& lst); //copy constructor

	/* Every class should have a destructor, which is responsible for
	 * cleaning up any dynamic memory allocation performed by the class.
	 * Note the special syntax for the destructor */
	~ListADT();//destructor
	
	// Description: Add an element (data) to the list
	// POST: A new node containing the given data is inserted 
	//       at the front of the list
	// PARAM: data is the data to be stored
	void add(int newData);

	// Description: Prints the contents of the list to the screen, in order.
	//              For testing purpose, unless required by client in problem statement.
	//              Could also overload operator<<.
	void printList();

}; // end of header file of ListADT class