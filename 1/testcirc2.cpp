// Driver program 2 for testing the circle class.
// Tests intersection method.
#include <iostream> // As we need to print data
#include <stdio.h> // For using printf, formatted output
#include "circle.h"

using namespace std;

int main() {
  Circle c1 = Circle();
  Circle c2 = Circle(0,4,10);
  Circle c3 = Circle(0,4,14.1);
  Circle c4 = Circle(0,11,0.2);

  if (c1.intersect(c2))
    cout << "c1 intersects c2" << endl;
  else
    cout << "c1 does not intersect c2" << endl;

  if (c1.intersect(c3))
    cout << "c1 intersects c3" << endl;
  else
    cout << "c1 does not intersect c3" << endl;

  if (c1.intersect(c4))
    cout << "c1 intersects c4" << endl;
  else
    cout << "c1 does not intersect c4" << endl;

	

	return 0;
}
