/* 
 * PQueue.h
 *
 * Description: Min binary heap-based implementation of data collection Priority Queue ADT.
 *
 * Author:
 *
 * Date: July 2016
 *
 */
#pragma once

#include <iostream>
#include "Event.h"
#include "EmptyDataCollectionException.h"

using namespace std;
const int CAPACITY = 100;

class PQueue {

private:
    // To do: Add the attributes here!
    int elementCount;
    Event elements[CAPACITY];
    
    // Utility method - Recursively put the array back into a heap
    void reHeapUp(int indexOfBottom);
    
    // Utility method - Recursively put the array back into a heap
    void reHeapDown(int indexOfRoot);


public:
    // Default Constructor
    PQueue();
    
    // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;
    
    // Description: Inserts newElement.
    //              It returns "true" if successful, otherwise "false".
    // Time Efficiency: O(log n)
    bool enqueue(const Event& newElement);
    
    // Description: Removes the element with the "highest" priority.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is not empty.
    // Time Efficiency: O(log n)
    bool dequeue();
    
    // Description: Retrieves (but does not remove) the element with the "highest" priority.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    Event peek() const throw(EmptyDataCollectionException);
    
    // For Testing Purposes - See Labs 3 and 4.
    // Description: Prints the content of "this".
    friend ostream & operator<<(ostream & os, const PQueue& rhs);
   
}; // end PQueue