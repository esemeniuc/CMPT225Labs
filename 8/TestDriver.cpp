/*
 * Test Driver
 *
 * Author:
 * Date:
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Profile.h"
#include "ListADT.h"

using namespace std;

//	+ join(newProfile : Profile ) : void
//	+ leave( profile : Profile ) : void
//	+ modify( profile : Profile ) : void
//	+ search( target : Profile ) : void

int getIndex(ListADT* inputListADT, Profile* inputProfile)
{
	int index = 0;
	int elementCount = inputListADT->getElementCount();
	while(!(*inputProfile == inputListADT->getElement(index)) && index < elementCount) //linear search of all profiles until match
	{
		index++;
	}
	
	if(*inputProfile == inputListADT->getElement(index-1))
	{
		return index;
	}
	else
	{
		return -1; //bad
	}
	
}

void join(ListADT* inputListADT)
{
	Profile tempProfile;
	string inputName;
	string inputImage;
	string inputStatus;
	string inputFriend;
	
	cout << "Joining FB" << endl;
	cout << "Please input the following:" << endl;
	
	cout << "Name: ";
	cin >> inputName;
	tempProfile.setName(inputName);
	
	cout << "Image: ";
	cin >> inputImage;
	tempProfile.setName(inputImage);
	
	cout << "Status: ";
	cin >> inputStatus;
	tempProfile.setName(inputStatus);
//
//	uint8_t friendCount = 0;
//	do
//	{
//		cout << "Friend #" << (unsigned int)friendCount+1 << ": ";
//		getline(cin, inputFriend);

//		cout << "result: " << inputFriend << endl;
//		if(!inputFriend.empty())
//		{
//			tempProfile.addFriend(inputFriend);
//			friendCount++;
//		}
//	} while(!inputFriend.empty());
	
	
	cout << "Friend: ";
	cin >> inputFriend;
	tempProfile.addFriend(inputFriend);
	
	inputListADT->insert(inputListADT->getElementCount(), tempProfile); //input our profile
}

void leave(ListADT* inputListADT)
{
	string inputName;
	cout << "Input member's name who wants to leave: ";
	cin >> inputName;
	
	//create a temp profile
	Profile tempProfile(inputName);
	int index = getIndex(inputListADT, &tempProfile); //get index of person who should leave
	
	//call leave on their index
	if(inputListADT->remove(index))//delete the profile
	{
		cout << "Removed " << inputName << endl;
	}
	else
	{
		cout << "Could not find " << inputName << endl;
	}
}

void modify(ListADT* inputListADT)
{
	string inputName;
	cout << "Input member's name who wants to updated: ";
	cin >> inputName;
	
	//create a temp profile
	Profile shellProfile(inputName);
	
	int index = getIndex(inputListADT, &shellProfile); //get index of person who should leave
	
	if(index < 0)
	{
		cout << "not found" << endl;
		return;
	}
	
	Profile tempProfile = inputListADT->getElement(index);
	
	//modify profile
	string inputImage;
	cout << "Image: ";
	cin >> inputImage;
	tempProfile.setName(inputImage);
	
	string inputStatus;
	cout << "Status: ";
	cin >> inputStatus;
	tempProfile.setName(inputStatus);
	
	string inputFriend;
	uint8_t friendCount = 1;
	cout << "Friend #1: ";
	while(cin >> inputFriend)
	{
		if(inputFriend.empty())
		{
			break;
		}
		tempProfile.addFriend(inputFriend);
		friendCount++;
		cout << "Friend #" << (unsigned int)friendCount << ": ";
	}
	
	inputListADT->setElement(index, tempProfile); //input our profile back into inputListADT
}

void search(ListADT* inputListADT)
{
	string inputName;
	cout << "Input member's name who wants to be found: ";
	cin >> inputName;
	
	//create a temp profile
	Profile shellProfile(inputName);
	
	int index = getIndex(inputListADT, &shellProfile);
	
	if(index < 0)
	{
		cout << "not found" << endl;
		return;
	}
	
	Profile tempProfile = inputListADT->getElement(index);
	
	cout << tempProfile << endl;
}

char userMenu(void)
{
	char userSelection;
	cout << "Welcome to FB, please choose from the following selection" << endl;
	cout << "j - join" << endl;
	cout << "l - leave" << endl;
	cout << "m - modify" << endl;
	cout << "s - search" << endl;
	cout << "q - quit" << endl;
	cout << "Please enter a choice: ";
	
	cin >> userSelection;
	
	return userSelection;
}

int main() {
	
	// Variables declaration
	// ListADT* members = new ListADT();
	
	ListADT members;
	int userStatus = 1;
	
	
//	while(userStatus)
//	{
//		char userSelection = userMenu();
//		switch (userSelection)
//		{
//			case 'j':
//				join(&members);
//				break;
//			case 'l':
//				leave(&members);
//				break;
//			case 'm':
//				modify(&members);
//				break;
//			case 's':
//				search(&members);
//				break;
//			case 'q':
//				userStatus = 0;
//				break;
//			default:
//				cout << "Invalid selection, please try again" << endl;
//				break;
//		}
//	}
	
	Profile testProfile1 = Profile("bob");
	Profile testProfile2 = Profile("tom");
	Profile testProfile3 = Profile("scott");
	
	members.insert(1, testProfile1);
	members.insert(2, testProfile2);
	members.insert(3, testProfile3);
	members.remove(2);
	
	cout << members.getPosition(testProfile3) << endl;
	
	return 0;
}