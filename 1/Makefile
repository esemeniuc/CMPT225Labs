all: testcirc1 testcirc2

testcirc1: testcirc1.o circle.o
	g++ -Wall testcirc1.o circle.o -o testcirc1

testcirc2: testcirc2.o circle.o
	g++ -Wall testcirc2.o circle.o -o testcirc2

circle.o: circle.h circle.cpp
	g++ -Wall -c circle.cpp

testcirc1.o: testcirc1.cpp circle.h
	g++ -Wall -c testcirc1.cpp

testcirc2.o: testcirc2.cpp circle.h
	g++ -Wall -c testcirc2.cpp

clean:
	rm -f testcirc1 testcirc2 *.o