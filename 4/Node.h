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
#include <cstdlib>
#include <iostream>

template <class Type>

class Node
{
public:
	// Public attributes - Why are the attributes public?
	Type data;     // The data in the node
	Node* next;   // Pointer to next node
	
	// Constructors and destructor
	Node();
	Node(Type theData);
	Node(Type theData, Node* theNextNode);
	~Node();

}; // end Node

/*
 * Node.cpp
 *
 * Class Definition: Node of a singly linked list
 *                   in which the data is of "int" data type.
 *
 * Created on:
 * Author:
 */

template <class Type>
Node<Type>::Node()
{
	//data = 0; //disable because we can't know if its an int
	next = NULL;
}

template <class Type>
Node<Type>::Node(Type theData)
{
	data = theData;
	next = NULL;
}

template <class Type>
Node<Type>::Node(Type theData, Node* theNextNode)
{
	data = theData;
	next = theNextNode;
}

template <class Type>
Node<Type>::~Node()
{
}

// end Node.cpp