/*
 * List.cpp - Implementation of the List class
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

#include "List.h"
#include <string>
#include <iostream>

using namespace std; //needed for cout, cin to be recognised

// Default constructor
List::List(){
	head = NULL;
	size = 0; //Don't forget to do this!!!
}

/* Copy constructor to copy an existing list.  Note that the compile
 * will generate a copy constructor automatically.  However, this
 * constructor only creates a SHALLOW COPY (so would only copy the
 * size and head variables).  In this case this would NOT CREATE A
 * NEW LIST, just a new reference to one list.  It is therefore
 * necessary to write a constructor that makes a DEEP COPY.*/

/* Also note the parameter.  C++ functions use pass-by-value by
 * default.  This means that the functions make copies of the given
 * arguments.  This is inefficient (particularly for large objects).
 * Therefore it is normal to pass the address (using &) of the parameter,
 * but, if the parameter should not be changed, it is good practice to 
 * make it const, which prevents it from being changed.*/
List::List(const List& lst){
	if (lst.head == NULL){
		head = NULL;
		size = 0;
	}
	else{
		// Copy first node and assign head
		/* OK, what's with the '->'?  The -> operator accesses the attribute
		 * or method of the object (or struct) that is refererred to by a
		 * pointer.  So "head -> data" is the contents of the data variable
		 * of the object that head points to.  Note that this is synonomous
		 * with "(*head).data" but the latter syntax is ugly and confusing and
		 * is therefore rarely used. */
		head = new Node;
		head->data = lst.head->data;
		/* Now copy the rest of the list.  To do this we'll need to create two
		 * temporary pointers, one to go through the old list, one node at a
		 * time, and one to keep pace in the new list, creating new nodes. */
		Node *pNewNode = head;
		Node *pOldNode = lst.head->next;
		// Repeat until the entire list is copied
		while (pOldNode != NULL){
			pNewNode->next = new Node;
			pNewNode = pNewNode->next;
			pNewNode->data = pOldNode->data;
			pOldNode = pOldNode->next;
		}
		pNewNode->next = NULL;
		size = lst.size;
	}
}

/* The destructor is responsible for deleting any memory that was dynamically
 * allocated by an object.  If there is no such memory no destructor needs to
 * be created (the compiler automatically creates one).  Because this class
 * uses pointers to create new Nodes it is necessary to write a destructor.
 * Destructors are identified by the '~' preceding the class name.  There can
 * be only one destructor for a class, and it cannot have parameters. */
List::~List(){
	removeAll();
}

/**************************************************************************/
// List Operations

// Adds a node to the start of the list, making it the new head
void List::add(int x){
	Node *p = new Node; //temporary node
	// Assign appropriate values to the new node
	p -> data = x;
	p -> next = head;
	// Make the head point to the new node
	head = p;	
	size++;
}

// Inserts a new node at the given position (or index) in the list
void List::insertAt(int pos, int x){
	Node *p;
	Node *newNode;
		
	// Check that pos is a valid index
	if (pos <= size){
		newNode = new Node; //new node
		newNode->data = x;

		// Deal with case when item is to be inserted at the head of the list
		if (pos == 0){
			newNode->next = head;
			head = newNode;
		}// if(pos == 0)
		else{
			p = head;
			// Move to position BEFORE insertion point
			for(int i = 0; i < pos-1; i++){
				// Check that p points to a node
				// Note using exception handling should throw an exception here
				if(p == NULL){
					return;
				}
				p = p->next;
			}//for
			// Insert node
			newNode->next = p->next;
			p->next = newNode;
		}//else (pos != 0)
		size++;
	}//else (pos >= size) do nothing
}

// Removes the first node containing the given data, returns true
// iff data is found (and deleted).
bool List::remove(int x){
	Node *p = head;
	Node *temp;
	// Check to see if the list exists
	if (head == NULL){
		return false;
	}
	// Check to see if target is at the head of the list
	else if (head->data == x){
		head = head->next;
		delete p; //currently assigned head
		size--;
		return true;
	}
	// Otherwise iterate through list
	else{
		while(p->next != NULL){
			// Check next node for target
			if(p->next->data == x){
				temp = p->next;
				p->next = p->next->next;
				size--;
				delete temp;
				return true;
			}
			p = p->next;
		}
	}
	return false;
}

// Empties the list by deleting each node, starting at the head
void List::removeAll(){
	Node *p = head;
	// Traverse the list deleting nodes
	while (p!= NULL){
		head = head->next; // Mustn't "lose" the next node
		delete p; // De-allocate memory
		p = head; // Go to next node
	}
	head = NULL;
	size = 0;
}

// Prints the entire list (head first) to the screen - FOR TESTING PURPOSES!
/* Note that there is some debate about whether or not this type of
 * method belongs in a class.  The argument (briefly) is that a class
 * shouldn't be responsible for its own display as it cannot foresee
 * how it is to be displayed, for example, in a GUI or TUI environment. 
 * The IO responsibility should be left to the client code which
 * would "get" each element via a retrieve() public method of List 
 * and print the retrieved element according to the IO environment
 * Note that the client code could delegate this IO responsibility
 * to a better suited class in the application (which would not be List). */
void List::printList(){
	Node *p = head;
	cout << "["; //Nice format!
	// Traverse the list
	while (p != NULL){
		cout << p -> data; // Print data
		p = p -> next; // Go to next node
		if (p != NULL){
			cout << ","; // Print a comma unless at the end of the list
		}
	}
	cout << "]"; // Don't print a newline - it might not be wanted
}
