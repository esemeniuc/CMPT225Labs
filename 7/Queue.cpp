/* 
 * Queue.cpp
 *
 * Description: Array-based implementation of data collection Queue ADT.
 * 
 * Class invariants: FIFO or LILO
 * 
 * Inspired from the code in our textbook (Frank M. Carrano and Tim Henry)
 *
 * Date: June 2016
 */

#include "Queue.h"  // Header file

        
// Constructor
Queue::Queue() : front(0), back(CAPACITY - 1), elementCount(0)
{
} // end default constructor


// Copy constructor and destructor supplied by compiler


// Description: Returns "true" is this queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool Queue::isEmpty() const
{
   return elementCount == 0;
} // end isEmpty

// Description: Adds newElement to the "back" of this queue and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
bool Queue::enqueue(const Event& newElement)
{
   bool queuedOK = false;
   if (elementCount < CAPACITY)
   {
      // Queue has room for another item
      back = (back + 1) % CAPACITY;
      elements[back] = newElement;
      elementCount++;
      queuedOK = true;
   } // end if
   
   return queuedOK;
} // end enqueue


// Description: Removes the element at the "front" of this queue and 
//              returns "true" if successful, otherwise "false".
// Precondition: This queue is not empty.
// Time Efficiency: O(1)
bool Queue::dequeue()
{
   bool dequeuedOK = false;
   if (!isEmpty())
   {
      front = (front + 1) % CAPACITY;
      elementCount--;
      dequeuedOK = true;
   } // end if
   
   return dequeuedOK;
} // end dequeue


// Description: Retrieves (but does not remove) the element at the  
//              "front" of this queue and returns it.
// Precondition: This queue is not empty.
// Postcondition: This queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this queue is empty.
// Time Efficiency: O(1)
Event Queue::peek() const throw(EmptyDataCollectionException)
{
   // Enforce precondition
   if (isEmpty())
      throw EmptyDataCollectionException("peek() called with empty queue.");

   // Queue is not empty; return front
   return elements[front];
} // end peek

// For Testing Purposes - See Labs 3 and 4.
// Description: Prints the content of "this". 
ostream & operator<<(ostream & os, const Queue& rhs) {
   int index = rhs.front;
   int count = 0;
    
   while ( count < rhs.elementCount ) {
      cout << rhs.elements[index];
      index = (index + 1) % rhs.CAPACITY;
      count++;
   }
  
   return os;
} // end of operator <<

// End of implementation file.