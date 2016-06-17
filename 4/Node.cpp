/*
 * Node.cpp
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *
 * Created on: 
 * Author: 
 */

#include <cstdio>
#include "Node.h"

Node::Node()
{
	data = 0;
	next = NULL;
}

Node::Node(int theData)
{
	data = theData;
	next = NULL;
}

Node::Node(int theData, Node* theNextNode)
{
	data = theData;
	next = theNextNode;
}

Node::~Node()
{
}

// end Node.cpp