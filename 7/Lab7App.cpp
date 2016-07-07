#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <sstream>
#include "Queue.h"
#include "Event.h"


using namespace std;


int main(void)
{
    
    // Create an empty queue bankQueue
    Queue* anEventQueue = new Queue();
    
    string aLine = "";
    int time = 0;
    int length = 0;
    Event* newArrivalEvent = NULL;
    
    // Create and add arrival events to aEventQueue
    while(getline(cin, aLine)) {   // while (there is data)
        stringstream ss(aLine);
        ss >> time >> length;      // Get next arrival time (time) and transaction time (length)
        cout << "Read: " << time << " " << length << endl;
        newArrivalEvent = new Event('A', time, length);
        if ( !anEventQueue->enqueue(*newArrivalEvent) ) return 1;
    }
    
    cout << *anEventQueue << endl;
    
    return 0;
    
}