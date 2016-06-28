all: test_add test_sub test_mult test_div test_cout

test_cout: test_cout.o Fraction.o
	g++ -Wall -o test_cout test_cout.o Fraction.o

test_cout.o: test_cout.cpp Fraction.h
	g++ -Wall -c test_cout.cpp

test_add: test_add.o Fraction.o
	g++ -Wall -o test_add test_add.o Fraction.o

test_add.o: test_add.cpp Fraction.h
	g++ -Wall -c test_add.cpp

test_mult: test_mult.o Fraction.o
	g++ -Wall -o test_mult test_mult.o Fraction.o

test_mult.o: test_mult.cpp Fraction.h
	g++ -Wall -c test_mult.cpp

test_sub: test_sub.o Fraction.o
	g++ -Wall -o test_sub test_sub.o Fraction.o

test_sub.o: test_sub.cpp Fraction.h
	g++ -Wall -c test_sub.cpp

test_div: test_div.o Fraction.o
	g++ -Wall -o test_div test_div.o Fraction.o

test_div.o: test_div.cpp Fraction.h
	g++ -Wall -c test_div.cpp

Fraction.o: Fraction.h Fraction.cpp
	g++ -Wall -c Fraction.cpp


clean:
	rm -f test_add test_sub test_mult test_div test_cout *.o