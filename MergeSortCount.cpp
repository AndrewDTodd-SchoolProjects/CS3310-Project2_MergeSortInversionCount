#include "MergeSortCount.h"
#include "InversionCounter.h"

void MergeNCountSplitInversions(int* array, const uint32_t& left, const uint32_t& mid, const uint32_t& right, uint64_t& countIttr)
{
	const uint32_t leftLength = mid - left + 1; //left side length
	const uint32_t rightLength = right - mid; //right side length

	int* leftArray = new int[leftLength];
	for (int leftItr = 0; leftItr < leftLength; leftItr++)
	{
		leftArray[leftItr] = array[leftItr + left];
	}

	int* rightArray = new int[rightLength];
	for (int rightItr = 0; rightItr < rightLength; rightItr++)
	{
		rightArray[rightItr] = array[mid + 1 + rightItr];
	}

	int i = 0, j = 0, k = left;

	while (i < leftLength && j < rightLength)
	{
		if (leftArray[i] <= rightArray[j])
		{
			array[k] = leftArray[i];
			i++;
		}
		else
		{
			array[k] = rightArray[j];
			j++;
			countIttr += leftLength - i;
		}
		k++;
	}

	//copy remaining elements of left side if any
	while(i < leftLength)
	{
		array[k] = leftArray[i];
		i++;
		k++;
	}
	//copy remaining elements of right side if any
	while (j < rightLength)
	{
		array[k] = rightArray[j];
		j++;
		k++;
	}

	//clean up the heap allocated arrays
	delete[] leftArray;
	delete[] rightArray;
}

uint64_t& SortNCountInversions(int* array, const uint32_t& left, const uint32_t& right, uint64_t& countIttr)
{
	/*
	if (right - left == 0 || right - left == 1)
		return countIttr;
	*/

	if (left < right)
	{
		uint32_t mid = left + (right - left) / 2;

		SortNCountInversions(array, left, mid, countIttr);
		SortNCountInversions(array, mid + 1, right, countIttr);
		MergeNCountSplitInversions(array, left, mid, right, countIttr);
	}

	return countIttr;
}