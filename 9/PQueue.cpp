/* 
 * PQueue.cpp
 *
 * Description: Min binary heap-based implementation of data collection Priority Queue ADT.
 *
 * Author:
 *
 * Date: July 2016
 *
 */

#include "PQueue.h"  // Header file


// Default Constructor
PQueue::PQueue() {
	elementCount = 0;
} // end of default constructor


// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool PQueue::isEmpty() const {
	return ( elementCount == 0 );
}  // end isEmpty


// Description: Inserts newElement.
//              It returns "true" if successful, otherwise "false".
// Time Efficiency: O(log n)
bool PQueue::enqueue(const Event& newElement) {
	// This is the insert operation into a min binary heap
	
	bool ableToEnqueue = false;
	
	// If there is space ...
	if (elementCount < CAPACITY) {
		
		// Insert newElement at end of array.
		elements[elementCount] = newElement;
		
		elementCount++;
		
		// Recursively put the array back into a heap
		reHeapUp(elementCount-1);
		
		ableToEnqueue = true;
	}
	
	return ableToEnqueue;
	
} // end enqueue

// Utility method - Recursively put the array back into a heap
void PQueue::reHeapUp(int indexOfBottom) {
	
	// To do
	if(indexOfBottom <= 0) //base case
	{
		return;
	}
	
	int parentIndex = (indexOfBottom - 1)/2;
	if(elements[indexOfBottom] < elements[parentIndex])//compare against parent
	{
		//if less, then swap with parent
		Event temp = elements[parentIndex];
		elements[parentIndex] = elements[indexOfBottom];
		elements[indexOfBottom] = temp;
		
		reHeapUp(parentIndex); //call reHeapUp on new parent
	}
	
	return;
}


// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(log n)
bool PQueue::dequeue() {
	// This is the delete operation
	
	bool ableToDequeue = false;
	
	// To do
	// This version of dequeue does not retrieve.
	
	if(elementCount > 0)
	{
		//overwrite root with last leaf
		elements[0] = elements[elementCount-1];
		
		reHeapDown(0); //reheapify
		elementCount--;
		ableToDequeue = true;
	}
	
	return ableToDequeue;
}  // end remove


// Utility method - Recursively put the array back into a heap
void PQueue::reHeapDown(int indexOfRoot) {
	
	int indexOfMinChild = indexOfRoot;
	
	// Find indices of children.
	int indexOfLeftChild = 2*indexOfRoot+1;
	int indexOfRightChild = 2*indexOfRoot+2;
	
	// Base case: elements[indexOfRoot] is a leaf as it has no children
	if (indexOfLeftChild > elementCount-1) return;
	
	// If we need to swap, select the smallest child
	if (elements[indexOfRoot] > elements[indexOfLeftChild])
		indexOfMinChild = indexOfLeftChild;
	
	// Check if there is a right child, is it the smallest?
	if (indexOfRightChild < elementCount) {
		if (elements[indexOfMinChild] > elements[indexOfRightChild])
			indexOfMinChild = indexOfRightChild;
	}
	
	// Swap parent with smallest of children.
	if (indexOfMinChild != indexOfRoot) {
		
		Event temp = elements[indexOfRoot];
		elements[indexOfRoot] = elements[indexOfMinChild];
		elements[indexOfMinChild]  = temp;
		
		// Recursively put the array back into a heap
		reHeapDown(indexOfMinChild);
	}
	
	return;
}

// Description: Retrieves (but does not remove) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
Event PQueue::peek() const throw(EmptyDataCollectionException) {
	// This is the retrieve operation
	
	// Enforce precondition
	if ( !isEmpty() )
		return elements[0];
	else
		throw(EmptyDataCollectionException("peek() called with an empty PQueue."));
	
}  // end peek


// For Testing Purposes - See Labs 3 and 4.
// Description: Prints the content of "rhs".
ostream& operator<<(ostream & os, const PQueue& rhs) {
	
	for ( unsigned int index = 0; index < rhs.elementCount; index++ )
		cout << rhs.elements[index]; // Print data
	
	return os;
} // end of operator <<

//  End of implementation file.