/* 
 * Queue.h
 *
 * Description: Array-based implementation of data collection Queue ADT.
 * 
 * Class invariants: FIFO or LILO
 * 
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 *
 * Date: June 2016
 */

#pragma once

#include <iostream>
#include "Event.h"
#include "EmptyDataCollectionException.h"

using namespace std;


class Queue {

private:
   static const int MAX_CAPACITY = 100;  // Stated in our Assignment 2
   
   Event elements[MAX_CAPACITY]; // Array of queue items
   int front;                 // Index to front of queue
   int back;                  // Index to back of queue
   int elementCount;          // Number of elements currently in the queue
   
public:
   // Constructor
   Queue();
   // Copy constructor and destructor supplied by compiler
        
   // Description: Returns "true" is this queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;
   
   // Description: Adds newElement to the "back" of this queue and 
   //              returns "true" if successful, otherwise "false".
   // Time Efficiency: O(1)
   bool enqueue(const Event& newElement);
   
   // Description: Removes the element at the "front" of this queue and 
   //              returns "true" if successful, otherwise "false".
   // Precondition: This queue is not empty.
   // Time Efficiency: O(1)
   bool dequeue();

   // Description: Retrieves (but does not remove) the element at the  
   //              "front" of this queue and returns it.
   // Precondition: This queue is not empty.
   // Postcondition: This queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this queue is empty.
   // Time Efficiency: O(1)
   Event peek() const throw(EmptyDataCollectionException);  
  
   // For Testing Purposes - See Labs 3 and 4.
   // Description: Prints the content of "this". 
   friend ostream & operator<<(ostream & os, const Queue& rhs);
      
}; // end Queue

// #include "Queue.cpp"