/*
 * Node.cpp
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of Event class type.
 *
 * Created on: 
 * Author: 
 */

#include "Node.h"

Node::Node()
{
	next = NULL;
}

Node::Node(Event theData)
{
	data = theData;
	next = NULL;
}

Node::Node(Event theData, Node* theNextNode)
{
	data = theData;
	next = theNextNode;
}

Node::~Node()
{
}

// end Node.cpp