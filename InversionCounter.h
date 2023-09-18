#ifndef INVERSIONCOUNTER_H
#define INVERSIONCOUNTER_H

#include <cstdint>

/// <summary>
/// Function that will return the number of inversions in the array of integers it is provided with
/// </summary>
/// <param name="array">Address (pointer) of the array to count inversions on</param>
/// <param name="arrayLength">The length of the array to count inversions on</param>
/// <returns>The number of inversions in the provided array</returns>
uint64_t CountInversions(const int* const array, const uint32_t& arrayLength);

#endif // !INVERSIONCOUNTER_H

