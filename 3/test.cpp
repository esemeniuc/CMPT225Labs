// test.cpp
// Driver program for testing linked list copies and destructor.
#include "ListADT.h"
#include <iostream>

using namespace std;
void listTest(){
	ListADT ls1;

	//ListADT ls2(ls1); //copy?

	cout << "Adding 1,2,3 to the first list." << endl;
	ls1.add(1);
	ls1.add(2);
	ls1.add(3);
	cout << "Printing the first list." << endl;
	ls1.printList();
	cout << endl << "Does it contain {1,2,3}?" << endl;

	cout << endl << "Make a copy of the list." << endl;
	ListADT ls2(ls1);
	cout << "Print second list." << endl;
	ls2.printList();
	cout << endl << "Does it contain {1,2,3}?" << endl;

	cout << endl << "Add 4,5,6 to the first list." << endl;
	ls1.add(4);
	ls1.add(5);
	ls1.add(6);

	cout << endl << "Print first list." << endl;
	ls1.printList();
	cout << endl << "Does it contain {1,2,3,4,5,6}?" << endl;

	cout << endl << "Print second list: (what does it contain?)." << endl;
	ls2.printList();
	cout << endl << "If it was shallow copied, it should contain: {1,2,3,4,5,6}.";
	cout << endl << "If it was deep copied, it should contain: {1,2,3}." << endl;
	cout << endl;

	return;
}

int main (void)
{
	listTest();
	return 0;
}
