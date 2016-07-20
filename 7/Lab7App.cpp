#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <sstream>
#include "Queue.h"
#include "Event.h"
#include "EmptyDataCollectionException.h"


using namespace std;


int main(void)
{
	
	// Create an empty queue bankQueue
	Queue* anEventQueue = new Queue();
	
	string aLine = "";
	int time = 0;
	int length = 0;
	Event* newArrivalEvent = NULL;
	try
	{
		cout << "Peeking before enqueuing:" << endl;
		Event peekedEvent = anEventQueue->peek();
		cout << "Now, let's have a look at the peeked event:" << endl;
		cout << peekedEvent.getTime() << endl;
	}
	catch ( EmptyDataCollectionException& anException ) {
		cout << "peeking() unsuccessful because " << anException.what() << endl;
		// Place recovery code here!
	}
	
	//Create and add arrival events to aEventQueue
	while(getline(cin, aLine)) {   // while (there is data)
		stringstream ss(aLine);
		ss >> time >> length;      // Get next arrival time (time) and transaction time (length)
		cout << "Read: " << time << " " << length << endl;
		newArrivalEvent = new Event('A', time, length);
		if ( !anEventQueue->enqueue(*newArrivalEvent) ) return 1;
	}
	
	cout << *anEventQueue << endl;
	
	
	try {
		cout << "Peeking after enqueuing:" << endl;
		Event peekedEvent = anEventQueue->peek();
		cout << "Now, let's have a look at this peeked event:" << endl;
		cout << peekedEvent.getTime() << endl;
	}
	catch ( EmptyDataCollectionException& e ) {
		cout << "peeking() unsuccessful because " << e.what() << endl;
		// Place recovery code here!
	}
	
	
	return 0;
	
}