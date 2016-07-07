#include "List.h"
#include <iostream>

using namespace std;

int main()
{

	List<int> testlist; //make list of ints
	List<string> testlist2; //make list of strings

	// An empty int List has already been instantiated in another test case which tested the default constructor.
	cout << "The int List is empty: " << endl;
	// Confirm this by printing the List (and testing the method printList() in doing so.
	testlist.printList();
	cout << "\n\nTesting add method: Adding the element 3 to the empty int List." << endl;
	testlist.add( 3 );
	// Confirm add(...) was successful by printing the List.
	testlist.printList();
	cout << "\n\nTesting add method: Adding the element 7 to the empty int List." << endl;
	testlist.add( 7 );
	// Confirm add(...) was successful by printing the List.
	testlist.printList();
	cout << "\n\nTesting add method: Adding the element 9 to the empty int List." << endl;
	testlist.add( 9 );
	// Confirm add(...) was successful by printing the List.
	testlist.printList();
	cout << "\n\nTesting add method: Removing the element 9 to the empty int List." << endl;
	testlist.remove( 9 );
	// Confirm add(...) was successful by printing the List.
	testlist.printList();


	// An empty int List has already been instantiated in another test case which tested the default constructor.
	cout << "\n\nThe string List is empty: " << endl;
	// Confirm this by printing the List (and testing the method printList() in doing so.
	testlist2.printList();
	cout << "\n\nTesting add method: Adding the string \"oyo\" to the empty int List." << endl;
	testlist2.add("oyo");
	// Confirm add(...) was successful by printing the List.
	testlist2.printList();
	cout << "\n\nTesting add method: Adding the string \"oyo2\" to the empty int List." << endl;
	testlist2.add("oyo2");
	// Confirm add(...) was successful by printing the List.
	testlist2.printList();

	return 0;
}