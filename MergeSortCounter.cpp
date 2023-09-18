#include <chrono>
#include <limits>
#include <iostream>

#include "Project2_InversionsCountConstDeff.h"

#include "MergeSortCount.h"
#include "ArrayGen.h"
#include "ArrayFromFile.h"

int main(int argc, char* argv[])
{
	int* array = nullptr;
	uint32_t arraySize = 0;
	
	if (argc != 2)
	{
		array = new int[ARRAY_SIZE];
		arraySize = ARRAY_SIZE;

		GenerateRandomArray(array, ARRAY_SIZE, 1, std::numeric_limits<int>::max());
	}
	else
	{
		try
		{
			array = ArrayFromFile(argv[1], &arraySize);
		}
		catch (std::invalid_argument argEx)
		{
			std::cerr << argEx.what() << std::endl;

			return 1;
		}
	}

	//Testing block to read a specified file with number list while in debug
	/*
	try
	{
		array = ArrayFromFile("../../LotsOfNum.txt", &arraySize);
	}
	catch (std::invalid_argument argEx)
	{
		std::cerr << argEx.what() << std::endl;

		return 1;
	}
	*/

	//can be used for testing
	//int array[] = { 54044, 14108, 79294, 29649, 25260, 60660, 2995, 53777, 49689, 9083 };

#ifdef PRINT_DEBUG_INFO
	std::cout << "Array pre sort:" << std::endl;
	std::cout << "[ ";
	for (uint32_t i = 0; i < arraySize; i++)
	{
		std::cout << array[i] << ", ";
	}
	std::cout << " ]" << std::endl;
#endif // PRINT_DEBUG_INFO

	auto startTime = std::chrono::high_resolution_clock::now();
	uint64_t inversionCount = 0;
	SortNCountInversions(array, 0, arraySize - 1, inversionCount);
	auto endTime = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

#ifdef PRINT_DEBUG_INFO
	std::cout << "Array post sort:" << std::endl;
	std::cout << "[ ";
	for (uint32_t i = 0; i < arraySize; i++)
	{
		std::cout << array[i] << ", ";
	}
	std::cout << " ]" << std::endl;
#endif // PRINT_DEBUG_INFO

	std::cout << "MergeSort inversion count execution time: " << duration.count() << " milliseconds" << std::endl;
	std::cout << "MergeSort inversion count inversions count: " << inversionCount << std::endl;

	delete[] array;

	return 0;
}
