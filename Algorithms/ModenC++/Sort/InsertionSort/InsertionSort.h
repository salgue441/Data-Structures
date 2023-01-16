/**
 * @file InsertionSort.h
 * @author Carlos Salguero
 * @brief Insertion Sort Algorithm with Modern C++
 * @version 0.1
 * @date 2023-01-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <algorithm>  // std::upper_bound(), std::rotate(), std::is_sorted()
#include <cassert>    // assert
#include <functional> // std::less<>
#include <iterator>   // std::next()

/**
 * @brief
 *
 * @tparam FwdIt
 * @tparam Compare
 * @param first
 * @param second
 * @param cmp
 * @time complexity O(N^2)
 * @space complexity O(1)
 */
template <class FwdIt, class Compare = std::less<>>
void insertion_sort(FwdIt first, FwdIt second, Compare cmp = Compare{})
{
    for (auto it{first}; it != last; ++i)
    {
        auto const insertion{std::upper_bound(first, it, *it, cmp)};

        std::rotate(insertion, it, std::next(it));
        assert(std::is_sorted(first, std::next(it), cmp));
    }
}

#endif //! INSERTION_SORT_H