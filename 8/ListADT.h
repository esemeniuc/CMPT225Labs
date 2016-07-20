/*
 * ListADT.h
 * 
 * Class Description: A List ADT - inspired from ListADT from our textbook.
 * Class Invariant: List position of elements start at 1 (not 0). 
 *
 * Inspired on: May 18, 2016
 * Author: AL
 */

#pragma once
#include <string>
#include "Profile.h"

using namespace std;


class ListADT 
{
private:
	static const int DEFAULT_CAPACITY = 5; // Default capacity of array 
	Profile elements[DEFAULT_CAPACITY];    // Array of elements <- underlying data structure
   int elementCount;                       // Current number of elements in List
   int maxElements;                        // Max number of elements that can be stored in List
   
public:
   // Constructor
   ListADT();

    // Description: Returns the current number of elements in the List.
   int  getElementCount() const;

   // Description: Insert newElement at newPosition in the List. 
   // Postcondition: If 1 <= newPosition <= getElementCount() + 1 and the insertion
   //                is successful, newElement is at newPosition in the List,
   //                other elements, located after newElement, "have moved" 1 position up, 
   //                and the returned value is true. Otherwise, false is returned.
   bool insert(int newPosition, const Profile& newElement);

   // Description: Removes the element at position in the List 
   // Postcondition: If 1 <= position <= getElementCount() and the removal is successful,
   //                the element at position in the List is removed, and
   //                other elements "have moved" 1 position down, 
   //                and the returned value is true. Otherwise, false is returned.
   bool remove(int position);

   // Description: Removes all elements from the List.
   // Postconditions: List contains no elements and the element count is 0.
   void clear();
   
   // Description: Returns the element at position in the List.
   // Precondition: 1 <= position <= getElementCount().
   Profile getElement(int position) const;
   
   // Description: Replaces the element at position by newElement in the List.
   // Precondition: 1 <= position <= getElementCount().
   void setElement(int position, const Profile& newElement);

   // Description: Prints all elements in the List.
   friend ostream & operator<<(ostream & os, const ListADT& rhs);
   
	// Description: Returns the position of a given element within the list.
	//              If the list is empty or the element is not found,
	//              it returns an invalid position, i.e., 0. (Remember position starts at 1).
	int getPositionIT(const Profile& anElement) const;
	
	// Description: Returns the position of a given element within the list.
	//              If the list is empty or the element is not found,
	//              it returns an invalid position, i.e., 0. (Remember position starts at 1).
	int getPosition(const Profile& anElement) const;
	
	// Description: Returns the position of a given element within the list.
	//              If the list is empty or the element is not found,
	//              it returns an invalid position, i.e., 0. (Remember position starts at 1).
	int getPositionR(const Profile& anElement, int currentIndex) const;
	
}; // end header file ListADT