#include "Fraction.h"
#include <iostream>

using namespace std;

int main (void) {
  // Use this driver program to test cout <<.
	Fraction a(2,3);
	Fraction b(1,6);
	Fraction c = a + b;

	// Test addition of fractions.
	cout << "Fraction C" << endl;
	cout << c << endl;

}
