/**
 * @file MergeSort.h
 * @author Carlos Salguero
 * @brief Merge Sort Algorithm implemented with Modern C++
 * @version 0.1
 * @date 2023-01-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <algorithm>  // std::inplace_merge()
#include <iterator>   // std::next(), std::distance()
#include <functional> // std::less<>

/**
 * @brief
 *
 * @tparam BiDirIt
 * @tparam Compare
 * @param first
 * @param second
 * @param cmp
 * @time complexity O(N log(N))
 * @space complexity O(N)
 */
template <class BiDirIt, class Compare = std::less<>>
void merge_sort(BiDirIt first, BiDirIt second, Compare cmp = Compare{})
{
    auto const N{std::distance(first, last)};

    if (N <= 1)
        return;

    auto const middle{std::next(first, N / 2)};

    merge_sort(first, middle, cmp);
    merge_sort(middle, last, cmp);

    std::inplace_merge(first, middle, last, cmp);
}

#endif //! MERGE_SORT_H