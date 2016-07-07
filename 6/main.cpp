#include <iostream>
#include "merge_sort.h"

using namespace std;

// A driver program to test mergeSort.
// Reads in a number of integers (number, then sequence of values).
// Sorts using mergeSort.
// Prints the values in sorted order.
int main (void) {
	int n;
	
	// Get the number of values.
	//	cout << "Enter the number of values to be sorted:" << endl;
	cin >> n;
	
	// Create array in dynamic memory.
	int *values;
	values = new int[n];
	
	for (int i=0; i<n; i++) {
		// cout << "Enter a number:" << endl;
		cin >> values[i];
	}
	
	// Call mergeSort to sort entire array.
	mergeSort(values,0,n-1);
	
	// Print values, should be sorted.
	for (int i=0; i<n; i++) {
		cout << values[i] << " ";
	}
	cout << endl;
	
	
	// Free up memory.  Note use of delete [], since this is an array.
	delete [] values;
	
	return 0;
}
