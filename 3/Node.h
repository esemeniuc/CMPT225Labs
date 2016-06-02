/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *
 * Created on: 
 * Author: 
 */
 
// #pragma once is shorthand for the 2 #include guards we've seen before:
// #ifndef _NODE and #define _NODE
#pragma once

class Node
{
public:
	// Public attributes - Why are the attributes public?
	int data;     // The data in the node
	Node* next;   // Pointer to next node
	
	// Constructors and destructor
	Node();
	Node(int theData);
	Node(int theData, Node* theNextNode);
	~Node();

}; // end Node