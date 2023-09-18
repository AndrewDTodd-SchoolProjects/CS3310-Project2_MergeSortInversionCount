#include "InversionCounter.h"

uint64_t CountInversions(const int const* array, const uint32_t& arrayLength)
{
	uint64_t inversions = 0;
	for (uint32_t i = 0; i < arrayLength - 1; i++)
	{
		for (uint32_t j = i + 1; j < arrayLength; j++)
		{
			if (array[i] > array[j])
				inversions++;
		}
	}

	return inversions;
}