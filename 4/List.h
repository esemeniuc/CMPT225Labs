/*
 * List.h - Header of the List class
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
#include <cstdlib>
#include <iostream> 
#include "Node.h"

template <class Type>

class List
{
private:
	Node<Type> *head; //Pointer to the first node in the list
	int size; //Records the number of nodes in the list

public:
	// Constructors and Destructors
	/* Generally every class should have at least two construtors, a
	 * default constructor and a copy constructor that creates a copy
	 * of the given object*/
	List(); //default constructor
	List(const List& lst); //copy constructor
	/* Every class should have a destructor, which is responsible for
	 * cleaning  up any dynamic memory allocation performed by the class.
	 * Note the special syntax for the destructor */
	~List();//destructor
	
	// PRE:
	// POST: A new node containing the given data is inserted at the front
	//       of the list
	// PARAM: data is the data to be stored
	void add(Type data);

	// PRE:
	// POST: A new node containing the given data is inserted at the given
	//       position in the list
	// PARAM: pos specifies the (index) position to insert the new node
	//        data is the data to be stored
	void insertAt(int pos, Type data);
	
	// PRE:
	// POST: The first incidence of the given data is removed from the list.
	//       Returns true if data is found (and removed), false otherwise
	// PARAM: data specifies the data to be removed from the list
	bool remove(Type data );
	
	// PRE:
	// POST: Empties the list, freeing up dynamically allocated memory
	// PARAM: 
	void removeAll();

	/* For Testing Purposes - see note in List.cpp */
	// PRE:
	// POST: Prints the contents of the list to the screen, in order
	// PARAM:
	void printList();

};

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

//#include "List.h"
#include <string>
#include <iostream>

using namespace std; //needed for cout, cin to be recognised

// Default constructor
template <class Type>
List<Type>::List()
{
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
template <class Type>
List<Type>::List(const List& lst)
{
	if (lst.head == NULL)
	{
		head = NULL;
		size = 0;
	}
	else
	{
		// Copy first node and assign head
		/* OK, what's with the '->'?  The -> operator accesses the attribute
		 * or method of the object (or struct) that is refererred to by a
		 * pointer.  So "head -> data" is the contents of the data variable
		 * of the object that head points to.  Note that this is synonomous
		 * with "(*head).data" but the latter syntax is ugly and confusing and
		 * is therefore rarely used. */
		head = new Node<Type>;
		head->data = lst.head->data;
		/* Now copy the rest of the list.  To do this we'll need to create two
		 * temporary pointers, one to go through the old list, one node at a
		 * time, and one to keep pace in the new list, creating new nodes. */
		Node<Type> *pNewNode = head;
		Node<Type> *pOldNode = lst.head->next;
		// Repeat until the entire list is copied
		while (pOldNode != NULL)
		{
			pNewNode->next = new Node<Type>;
			pNewNode = pNewNode->next;
			pNewNode->data = pOldNode->data;;
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
template <class Type>
List<Type>::~List()
{
	removeAll();
}

/**************************************************************************/
// List Operations

// Adds a node to the start of the list, making it the new head
template <class Type>
void List<Type>::add(Type x)
{
	Node<Type> *p = new Node<Type>; //temporary node
	// Assign appropriate values to the new node
	p -> data = x;
	p -> next = head;
	// Make the head point to the new node
	head = p;
	size++;
}

// Inserts a new node at the given position (or index) in the list
template <class Type>
void List<Type>::insertAt(int pos, Type x)
{
	Node<Type> *p;
	Node<Type> *newNode;

	// Check that pos is a valid index
	if (pos <= size)
	{
		newNode = new Node<Type>; //new node
		newNode->data = x;

		// Deal with case when item is to be inserted at the head of the list
		if (pos == 0)
		{
			newNode->next = head;
			head = newNode;
		}// if(pos == 0)
		else
		{
			p = head;
			// Move to position BEFORE insertion point
			for(Type i = 0; i < pos-1; i++)
			{
				// Check that p points to a node
				// Note using exception handling should throw an exception here
				if(p == NULL)
				{
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
template <class Type>
bool List<Type>::remove(Type x)
{
	Node<Type> *p = head;
	Node<Type> *temp;
	// Check to see if the list exists
	if (head == NULL)
	{
		return false;
	}
		// Check to see if target is at the head of the list
	else if (head->data == x)
	{
		head = head->next;
		delete p; //currently assigned head
		size--;
		return true;
	}
		// Otherwise iterate through list
	else
	{
		while(p->next != NULL)
		{
			// Check next node for target
			if(p->next->data == x)
			{
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

template <class Type>
// Empties the list by deleting each node, starting at the head
void List<Type>::removeAll()
{
	Node<Type> *p = head;
	// Traverse the list deleting nodes
	while (p!= NULL)
	{
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
 * and prType the retrieved element according to the IO environment
 * Note that the client code could delegate this IO responsibility
 * to a better suited class in the application (which would not be List). */
template <class Type>
void List<Type>::printList()
{
	Node<Type> *p = head;
	cout << "["; //Nice format!
	// Traverse the list
	while (p != NULL)
	{
		cout << p -> data; // Print data
		p = p -> next; // Go to next node
		if (p != NULL)
		{
			cout << ","; // Print a comma unless at the end of the list
		}
	}
	cout << "]"; // Don't print a newline - it might not be wanted
}
