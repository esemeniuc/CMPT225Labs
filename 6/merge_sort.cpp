#include <iostream>
#include "merge_sort.h"

using namespace std;

// Perform mergeSort to sort an array of integers.
// Inputs:
//   arr is the input array of arrSize integers.
//   low and high are the indices to sort to/from, e.g. 0 arrSize-1 to sort entire array
// Postcondition:
//   arr[low] ... arr[high] will contain the original values, sorted in increasing order.
void mergeSort(int arr[], int low, int high)
{
	//big idea: split in to 2 until we reach the base case where we have a size of 1
	if(high <= low) 	//base case, recurse back up when bounds touch
	{
		return;
	}

	//split into 2 smaller subarrays
	int mid = (high + low)/ 2; //find mid
	//cout << "mid: " << mid << endl;

	//split into to chunks, first piece is floor(size/2), second piece is remainder
	mergeSort(arr, low, mid);
//	cout << "Current array contents" << endl;
//	cout << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ", " << arr[4] << endl;
	mergeSort(arr, mid+1, high);
	merge(arr, low, mid, mid+1, high);

}


// Perform a merge of two sorted sub-arrays.
// Inputs:
//   arr is the input array on which to perform a merge.
//   low-mid and mid1-high are the two sub-arrays to merge.
// Precondition:
//   arr[low]...arr[mid] is sorted in increasing order.
//   arr[mid1]...arr[high] is sorted in increasing order.
//   These should be disjoint, contiguous sub-arrays too.
// Postcondition:
//   arr[low]...arr[high] is sorted in increasing.
void merge(int arr[], int low, int leftmid, int rightmid, int high)
{

	int arraySize = high - low + 1; //add 1 because high and low use array indexing
	int tempArray[arraySize];
//	cout << "high: " << high << " low: " << low << " size: " << arraySize << endl;

	//loop and compare first element of each array, inserting the lowest one into a temp array
	//have a counter for left and a counter for right, making sure we don't double copy
	//if we reach the end of one subarray, then blindly copy the rest verbatim
	int leftPos = low; //get rid of later
	int rightPos = rightmid;
	int arrayPos = 0; //starting position on our temporary array
	while(leftPos <= leftmid && rightPos <= high)
	{
		if(arr[leftPos] < arr[rightPos])
		{
			tempArray[arrayPos] = arr[leftPos];
			leftPos++;
		}
		else
		{
			tempArray[arrayPos] = arr[rightPos];
			rightPos++;
		}

		arrayPos++; //increment our tracker
	}

	while(leftPos <= leftmid) //merge remaining left stuff
	{
		tempArray[arrayPos] = arr[leftPos];
		leftPos++;
		arrayPos++; //increment our tracker
	}

	while(rightPos <= high) //merge remaining right stuff
	{
		tempArray[arrayPos] = arr[rightPos];
		rightPos++;
		arrayPos++; //increment our tracker
	}

	//copy temp array over to main array
	for(int i = 0; i < arraySize; i++) //note: offset between arr and tempArray is low
	{
		arr[i+low] = tempArray[i];
	}

}


