#ifndef MERGE_SORT_COUNT_H
#define MERGE_SORT_COUNT_H

#include<cstdint>

/// <summary>
/// Will count the inversions and sort the array by means of MergSort
/// </summary>
/// <param name="array">The array to sort and count upon</param>
/// <param name="left">The index to consider the far left for the sort</param>
/// <param name="right">The index to consider as the far right for the sort</param>
/// <param name="countIttr">A reference to the inversions counter that will be itterated and contain the total number of inversions counted after execution</param>
/// <returns>The final sorted and merged array</returns>
uint64_t& SortNCountInversions(int* array, const uint32_t& left, const uint32_t& right, uint64_t& countIttr);

#endif //!MERGE_SORT_COUNT_H
