/*
 * Profile.cpp
 * 
 * Class Description: Models the profile of a social network member.
 * Class Invariant: The name of the member (and friends) is a valid string (it is not an empty string)
 *                  and it starts with a letter (a or A to z or Z). 
 *                  The name of a member uniquely identifies her/him.
 *
 * Created on: May 10, 2016
 * Author: AL
 */

#include <iostream>
#include <string>
#include <locale>         // std::locale, std::isalpha
#include "Profile.h"

using namespace std;


// Default Constructor
// Description: Create an blank social network member. 
// Postcondition: name set to "To_Be_Named", image set to "No image yet", current status set to "Just joined", 
//                numberOfFriends set to 0.
Profile::Profile() {
	name = "To_Be_Named";    
	image = "No image yet";              
	status = "Just joined";             
	numberOfFriends = 0;   
}

// Constructor
// Description: Create a social network member with a name.
// Postcondition: If aName is not an empty string and it starts with a letter, 
//                name set to aName, otherwise name set to "To_Be_Named".
//                image set to "No image yet", current status set to "Just joined" and numberOfFriends set to 0.              
Profile::Profile(string aName) {
    this->setName(aName);
	image = "No image yet";              
	status = "Just joined";             
	numberOfFriends = 0;    
}

// Getters and setters
// Description: Returns social network member's name.
string Profile::getName() const {
	return name;
}

// Description: Returns social network member's image filename.
string Profile::getImage() const {
	return image;
}

// Description: Returns social network member's status.
string Profile::getStatus() const {
	return status;
}

// Description: Returns social network member's number of friends.
int Profile::getNumberOfFriends() const {
	return numberOfFriends;
}

// Description: Sets the social network member's name.
// Precondition: aName must be a valid string (it is not an empty string) and starts with a letter.  
// Postcondition: name is set to aName, if aName is valid, otherwise name is unchanged.
void Profile::setName(const string aName) {
    locale loc;
	if ( !aName.empty() && (isalpha(aName[0], loc)) )
		name = aName;
	else
		name = "To_Be_Named";               	
}

// Description: Sets the social network member's image filename.
void Profile::setImage(const string anImage) {
	image = anImage;
}

// Description: Sets the social network member's status.
void Profile::setStatus(const string aStatus) {
	status = aStatus;
}

// Utilities
// Description: Adds a friend to the social network member's list of friends.
// Precondition: aName must be a valid string (it is not an empty string) and starts with a letter.  
// Postcondition: If aFriend is valid, numberOfFriends incremented and aFriend added to list of friends.
//                Otherwise, numberOfFriends and list of friends unchanged.
void Profile::addFriend(const string aFriend) {
    friends[numberOfFriends++] = aFriend;
}

// Overloaded Operators
// Description: Comparison (equality) operator. Compares "this" Profile object with "rhs" Profile object.
//              Returns true if both Profile objects have the same name.
bool Profile::operator==(const Profile& rhs) const {
	
	// Compare both Profile objects
	if (name == rhs.getName() ) 
		return true;
	else 
		return false;
} // end of operator==

// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Profile & p) {

	os << p.name << ", " << p.image << ", " << p.status << ", with " << p.numberOfFriends << " friends:" << endl;	
    for (int index = 0; index < p.numberOfFriends; index++)
    //for (int index = 0; index < Profile::ARRAY_SIZE; index++) // compile!!!
       os << p.friends[index] << endl;
	return os;
} // end of operator<<

// end of Profile.cpp