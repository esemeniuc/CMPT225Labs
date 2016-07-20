/*
 * BankSimApp.cpp
 *
 * Class Description: Simulation of waiting customers (1-line-up) in a 1-teller bank.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *
 * Date: June 2016
 *
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include "PQueue.h"
#include "Queue.h"
#include "Event.h"

using namespace std;

void printResult(PQueue* aPQ, Queue* aQ) {
  cout << "The PQueue\n" << endl; 
  cout << *aPQ << endl;

  cout << "The Queue\n" << endl;  
  cout << *aQ << endl;  

  return;
}

void printStats( int peopleCount, int waitingTime ) {
  float avg = (float)waitingTime/(float)peopleCount;

  cout << "\nFinal Statistics:  " << endl;  
  cout << "\tTotal number of people processed:  " << peopleCount << endl;
  cout << "\tAverage amount of time spent waiting: " 
       << setprecision(3) << avg;
}


// Performs the simulation.
int main () {
  string aLine = "";
  int time = 0;
  int length = 0;
  bool tellerAvailable = true;
  Event currentEvent;
  Event customer;
  Event newDepartureEvent;
  int currentTime = 0;
  int departureTime = 0;
  int peopleCount = 0;
  int waitingTime = 0;

  // Create an empty queue bankQueue to represent the bank waiting line-up
  Queue* bankQueue = new Queue();

  // Create an empty priority queue eventListPQueue for the events
  PQueue* eventListPQueue = new PQueue();

  // Create and add arrival events to eventListPQueue
	while(getline(cin, aLine)) {   // while (there is data)
    stringstream ss(aLine);
    ss >> time >> length;      // Get next arrival time (time) and transaction time (length)  
cout << "Read: " << time << " " << length << endl;  // For debugging purposes
    Event newArrivalEvent(Event::ARRIVAL, time, length);
    
 	eventListPQueue->enqueue(newArrivalEvent);
  }
 
printResult( eventListPQueue, bankQueue );  // For debugging purposes

  cout << "Simulation Begins" << endl;

  // Event loop
  while ( !eventListPQueue->isEmpty() ) {
    try {
      // Get the current event
      currentEvent = eventListPQueue->peek();
    }
    catch ( EmptyDataCollectionException& anException ) {
      cout << "main:eventListPQueue->peek(): " << anException.what() << endl;
    }

    // Get current time
    currentTime = currentEvent.getTime();

    // Processes an arrival event
    if ( currentEvent.isArrival() ) {        
       cout << "Processing an arrival event at time:";
       cout.width(5); cout << right << currentTime << endl;
       peopleCount++;

      // Remove this event from the eventListPQueue
      if ( eventListPQueue->dequeue() ) {
        // if no customer is waiting and the teller is available
        // then this customer (represented by currentEvent) is now reaching the teller
        if ( bankQueue->isEmpty() && tellerAvailable ) {
          // Create a departure event for this customer 
          departureTime = currentTime + currentEvent.getLength();
          newDepartureEvent = Event(Event::DEPARTURE, departureTime);
          eventListPQueue->enqueue(newDepartureEvent);
          tellerAvailable = false;
        }
        else
          // If the teller is busy, next customer line-up
          bankQueue->enqueue(currentEvent);
      }
    }
    else {  // Processes a departure event -> customer leaving the teller and the bank
      cout << "Processing a departure event at time:";
      cout.width(4); cout << right << currentTime << endl;

      // Remove this event from the eventListPQueue
      if ( eventListPQueue->dequeue() ) {
        if ( !bankQueue->isEmpty() ) {   
          // Customer at front of line-up now reaching the teller and begins transaction
          try { 
            customer = bankQueue->peek();
          }
          catch ( EmptyDataCollectionException& anException ) {
            cout << "main:eventListPQueue->peek(): " << anException.what() << endl;
          }
          if ( bankQueue->dequeue() ) {
            // Create a departure event for this customer
            departureTime = currentTime + customer.getLength();
        	  newDepartureEvent = Event(Event::DEPARTURE, departureTime);
         	  eventListPQueue->enqueue(newDepartureEvent);
            waitingTime += ( currentTime - customer.getTime() );
        	}
        }
        else
          // If no customer waiting in line-up, teller now available
       	  tellerAvailable = true;
      }
    }
  //printResult( eventListPQueue, bankQueue );  // For debugging purposes
  }

  cout << "Simulation Ends" << endl;
  printStats( peopleCount, waitingTime );
  return 0;
}