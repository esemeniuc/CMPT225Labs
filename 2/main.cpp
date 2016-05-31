#include <iostream>
#include "sum_array.h"

using namespace std;

int main()
{
	//find how large to make array
	cout << "Please enter number of values to be summed: ";

	//take input
	int numbersToSum;
	cin >> numbersToSum;


	//make array
	int* numbersArr = new int[numbersToSum];

	//loop until all numbers have been inputted
	for(int i = 0; i < numbersToSum; i++)
	{
		cin >> numbersArr[i];
	}

	//sum up numbers
	int result = sumArray(numbersArr, numbersToSum);

	//cleanup array
	delete[] numbersArr;

	return result;
}