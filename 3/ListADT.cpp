/*
 * ListADT.cpp - Implementation of the ListADT class
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

#include "ListADT.h"
#include <string>
#include <iostream>

using namespace std; //needed for cout, cin to be recognized

// Default constructor
ListADT::ListADT(){
	elementCount = 0;
	head = NULL;
}

/* Copy constructor to copy an existing list.  Note that the compiler
 * will generate a copy constructor automatically.  However, this
 * constructor only creates a SHALLOW COPY (so would only copy the
 * elementCount and head variables).  In this case this would NOT CREATE A
 * NEW LIST, just a new reference to one list.  It is therefore
 * necessary to write a constructor that makes a DEEP COPY.*/

/* Also note the parameter.  C++ functions use pass-by-value by
 * default.  This means that the functions make copies of the given
 * arguments.  This is inefficient (particularly for large objects).
 * Therefore it is normal to pass the address, also called the reference,
 * (using &) of the parameter. Also, if the parameter must not be changed,
 * it is good practice to make it const, which prevents it from being changed.*/
ListADT::ListADT(const ListADT& lst){
	elementCount = lst.elementCount;
	head = NULL; //shallow copy - you need to fix this!

	Node* currentNode = lst.head;
	while(currentNode != NULL) //loop until end
	{
		add(currentNode->data); //add new data elements and copy over data elements
		currentNode = currentNode->next; //allows us to move forward
	}
}

/* The destructor is responsible for deleting any memory that was dynamically
 * allocated by an object.  If there is no such memory, no destructor needs to
 * be created (the compiler automatically creates one). Because this class
 * uses pointers when new Node objects are instantiated, it is necessary to write 
 * a destructor. Destructors are identified by the '~' preceding the class name.
 * There can be only one destructor for a class, and it cannot have parameters. */
ListADT::~ListADT(){
	// You need to write this!
	cout << "Destructor called!" << endl;
	Node* previousNode = head;
	Node* currentNode = head;

	while(currentNode != NULL)
	{
		currentNode = currentNode->next;
		delete previousNode;
		previousNode = currentNode;

	}
	//delete previousNode;

}

/**************************************************************************/
// ListADT Operations
// 
// Description: Add an element (newData) to the list
// ***Note that the new Node containing the given data is 
//    inserted at the end of the list.***
// PARAM: newData is the data to be stored
void ListADT::add(int newData){
	Node *newNode = new Node(newData); //new Node with x

	// Check to see if list is empty
	if (head == NULL){
		// Make new Node the new head
		head = newNode;
	}else{
		// Move to the end of the list
		Node* p = head;
		while (p->next != NULL){
			p = p->next;
		}
		p->next = newNode;
	}	
	elementCount++;
}

// Description: Prints the contents of the list to the screen, in order.
/* Note that there is some debate about whether or not this type of
 * method belongs in a class. The argument (briefly) is that a class
 * shouldn't be responsible for I/O by "displaying" itself as it cannot 
 * foresee how it is to be displayed (in a TUI or GUI environment?).
 * However, such method eases testing.
 */
void ListADT::printList(){
	Node *p = head;
	cout << "{"; //Nice format!
	// Traverse the list
	while (p != NULL){
		cout << p -> data; // Print data
		p = p -> next; // Go to next Node
		if (p != NULL){
			cout << ","; // Print a comma unless at the end of the list
		}
	}
	cout << "}"; // Don't print a newline - it might not be wanted
}
// end of implementation file of ListADT class