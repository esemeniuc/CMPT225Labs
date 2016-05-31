// Driver program 1 for testing the circle class.
#include <iostream> // As we need to print data
#include <stdio.h> // For using printf, formatted output
#include "circle.h"

using namespace std;

int main() {

    Circle c1 = Circle(0,0,3);
    Circle c2 = Circle(5,20,10);

	//c1.displayCircle();
	// Apply the setters.
	c1.move(5,2);
	c2.setRadius(5);
	
	// Print the output of the getters
	// Should produce 5
	cout << c1.getX() << endl;
	// Should produce 2
	cout << c1.getY() << endl;
	// Should produce 5
	cout << c2.getRadius() << endl;
	// Should produce 25*PI
	// This statement prints the output as a floating point number with 1 place after the decimal point (%.1f), 
	// followed by a newline character (\n)
	// Should produce 78.5 with decent PI approximation
	printf("%.1f\n", c2.getArea());

	return 0;
}
