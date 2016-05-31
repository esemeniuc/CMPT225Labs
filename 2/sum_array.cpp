//
// Created by eric on 24/05/16.
//

#include "sum_array.h"

int sumArray(int arr[], int arrSize)
{
	int runningTotal = 0;
	for(int i = 0; i < arrSize; i++)
	{
		runningTotal += arr[i];
	}

	return runningTotal;
}