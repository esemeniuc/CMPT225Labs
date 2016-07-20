all: td

td: TestDriver.o ListADT.o Profile.o
	g++ -Wall -o td TestDriver.o ListADT.o Profile.o

TestDriver.o: TestDriver.cpp ListADT.o Profile.h
	g++ -Wall -c TestDriver.cpp

ListADT.o: ListADT.h ListADT.cpp
	g++ -Wall -c ListADT.cpp

Profile.o: Profile.h Profile.cpp
	g++ -Wall -c Profile.cpp

clean:
	rm -f td *.o