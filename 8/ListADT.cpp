/*
 * ListADT.cpp
 * 
 * Class Description: A List ADT - inspired from ListADT from our textbook.
 * Class Invariant: List position of elements start at 1 (not 0).
 *
 * Inspired on: May 18, 2016
 * Author: AL
 */

#include <iostream>
//#include <string>
#include "Profile.h"
#include "ListADT.h"  // Header file


// Constructor
ListADT::ListADT() : elementCount(0), maxElements(ListADT::DEFAULT_CAPACITY) {
} 


// Description: Returns the current number of elements in the List.
int  ListADT::getElementCount() const {
   return elementCount;
} 

// Description: Insert newElement at newPosition in the List. 
// Postcondition: If 1 <= newPosition <= getElementCount() + 1 and the insertion
//                is successful, newElement is at newPosition in the List,
//                other elements, located after newElement, "have moved" 1 position up, 
//                and the returned value is true. Otherwise, false is returned.
bool ListADT::insert(int newPosition, const Profile& newElement) {
   bool ableToInsert = (newPosition >= 1) && (newPosition <= elementCount + 1) &&             
                       (elementCount < maxElements);
   if (ableToInsert)
   {
      // Make room for new Element by shifting all elements at
      // positions >= newPosition toward the end of the array
      // (no shift if newPosition == elementCount + 1)
      for (int pos = elementCount; pos >= newPosition; pos--)
         elements[pos] = elements[pos - 1];
         
      // Insert new Element
      elements[newPosition - 1] = newElement;
      elementCount++;  // Increase count of elements
   }  // end if
   
   return ableToInsert;
}  // end insert


// Description: Removes the element at position in the List 
// Postcondition: If 1 <= position <= getElementCount() and the removal is successful,
//                the element at position in the List is removed, and
//                other elements "have moved" 1 position down, 
//                and the returned value is true. Otherwise, false is returned.
bool ListADT::remove(int position) {
   bool ableToRemove = (position >= 1) && (position <= elementCount);
   if (ableToRemove)
   {
      // Remove Element by shifting all elements after the one at
      // position toward the beginning of the array
      // (no shift if position == elementCount)
      for (int fromIndex = position, toIndex = fromIndex - 1; fromIndex < elementCount;
	        fromIndex++, toIndex++)
         elements[toIndex] = elements[fromIndex];
         
      elementCount--;  // Decrease count of elements
   }  // end if
   
   return ableToRemove;
}  // end remove


// Description: Removes all elements from the List.
// Postconditions: List contains no elements and the element count is 0.
void ListADT::clear() {
   elementCount = 0;
}  // end clear

   
// Description: Returns the element at position in the List.
// Precondition: 1 <= position <= getElementCount().
Profile ListADT::getElement(int position) const {
   Profile toBeReturned;

   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= elementCount);
   if (ableToGet)
      toBeReturned = elements[position - 1];
   else
   {
      string message = "getElement() called with an empty List or an invalid position.";
      cout << message;  // throw exception may be better
   }  // end if

   return toBeReturned;
}  // end getElement

   
// Description: Replaces the element at position by newElement in the List.
// Precondition: 1 <= position <= getElementCount().
void ListADT::setElement(int position, const Profile& newElement) {
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= elementCount);
   if (ableToSet)
      elements[position - 1] = newElement;
   else
   {
      string message = "setElement() called with an empty List or an invalid position.";
      cout << message;  // throw exception may be better
   }  // end if
}  // end setElement

// Description: Prints all elements in the List.
ostream & operator<<(ostream & os, const ListADT& rhs) {
   for (int index = 0; index < rhs.elementCount; index++)
      os << "Element " << index+1 << " is " << rhs.elements[index].getName() << endl;
   
   return os;
} // end of operator << 

// Description: Returns the position of a given element within the list.
//              If the list is empty or the element is not found,
//              it returns an invalid position, i.e., 0. (Remember position starts at 1).
int ListADT::getPositionIT(const Profile& anElement) const
{
	int index = 0;
	while(!(anElement == elements[index]) && index < elementCount) //linear search of all profiles until match
	{
		index++;
	}
	
	if(anElement == elements[index])
	{
		return index + 1;
	}
	else
	{
		return 0; //bad
	}
}

// Description: Returns the position of a given element within the list.
//              If the list is empty or the element is not found,
//              it returns an invalid position, i.e., 0. (Remember position starts at 1).
int ListADT::getPosition(const Profile& anElement) const
{
	int index = getPositionR(anElement, 0); //get position starting at beginning of array
	
	return index + 1;
}

// Description: Returns the position of a given element within the list.
//              If the list is empty or the element is not found,
//              it returns an invalid position, i.e., 0. (Remember position starts at 1).
int ListADT::getPositionR(const Profile& anElement, int currentIndex) const
{
	if(currentIndex >= elementCount) //base case 1 if exceed bound
	{
		return -1;
	}
	else if(anElement == elements[currentIndex]) //base case 2 if found match
	{
		return currentIndex;
	}
	
	return getPositionR(anElement, currentIndex+1);
}

//  End of implementation file