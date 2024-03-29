/*
 * Profile.h
 * 
 * Class Description: Models the profile of a social network member.
 * Class Invariant: The name of the member (and friends) is a valid string (it is not an empty string)
 *                  and it starts with a letter (a or A to z or Z). 
 *                  The name of a member uniquely identifies her/him.
 *
 * Created on: May 10, 2016
 * Author: AL
 */

#pragma once
#include <string>
using namespace std;

class Profile
{
private:
	static const int ARRAY_SIZE = 10; // size of array
	string name;                      // name
	string image;                     // image filename (optional)
	string status;                    // current status
	int numberOfFriends;              // current number of friends
	string friends[ARRAY_SIZE];       // list of friends
	
public:

	// Default Constructor
	// Description: Create an blank social network member. 
	// Postcondition: name set to "To_Be_Named", image set to "No image yet", current status set to "Just joined", 
	//                numberOfFriends set to 0.        
	Profile();

	// Constructor
	// Description: Create a social network member with a name.
	// Postcondition: If aName is not an empty string and it starts with a letter, 
	//                 name set to aName, otherwise name set to "To_Be_Named".
	//                image set to "No image yet", current status set to "Just joined" and numberOfFriends set to 0.
	Profile(string aName);

	// Getters and setters
	// Description: Returns social network member's name.
	string getName() const;

	// Description: Returns social network member's image filename.
	string getImage() const;

	// Description: Returns social network member's status.
	string getStatus() const;

	// Description: Returns social network member's number of friends.
	int getNumberOfFriends() const;

	// Description: Sets the social network member's name.
	// Precondition: aName must be a valid string (it is not an empty string) and starts with a letter.  
	// Postcondition: name is set to aName, if aName is valid, otherwise name is unchanged.
	void setName(const string aName);

	// Description: Sets the social network member's image filename.
	void setImage(const string anImage);

	// Description: Sets the social network member's status.
	void setStatus(const string aStatus);

	// Utilities
	// Description: Adds a friend to the social network member's list of friends.
	// Precondition: aName must be a valid string (it is not an empty string) and starts with a letter.  
	// Postcondition: If aFriend is valid, numberOfFriends incremented and aFriend added to list of friends.
	//                Otherwise, numberOfFriends and list of friends unchanged.
	void addFriend(const string aFriend);

    // Overloaded Operators
	// Description: Comparison operator. Compares "this" Profile object with "rhs" Profile object.
	//              Returns true if both Profile objects have the same name.
	bool operator==(const Profile & rhs) const;
	
	// Description: Prints the content of "this".
	friend ostream & operator<<(ostream & os, const Profile & p);

};
// end of Profile.h