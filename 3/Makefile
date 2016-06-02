all: test

test: test.o ListADT.o Node.o
	g++ -Wall test.o ListADT.o Node.o -o test

test.o: test.cpp ListADT.h
	g++ -Wall -c test.cpp

ListADT.o: ListADT.h ListADT.cpp Node.h
	g++ -Wall -c ListADT.cpp

Node.o: Node.h Node.cpp
	g++ -Wall -c Node.cpp

clean:
	rm -f test *.o