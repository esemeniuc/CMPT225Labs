all: lab7

lab7: Lab7App.o Queue.o Event.o EmptyDataCollectionException.o
	g++ -o lab7 Lab7App.o Queue.o Event.o EmptyDataCollectionException.o

# Note, this makefile is very strong in terms of dependencies.
# It assumes most classes can depend on others, just to be safe.
# This results in much redundant compilation, and one could remove some of these dependencies.

Lab7App.o: Lab7App.cpp Queue.h Event.h EmptyDataCollectionException.h
	g++ -c Lab7App.cpp
	
Queue.o: Queue.cpp Queue.h Event.h EmptyDataCollectionException.h
	g++ -c Queue.cpp

Event.o: Event.cpp Event.h
	g++ -c Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c EmptyDataCollectionException.cpp

clean:
	rm -f lab7 *.o