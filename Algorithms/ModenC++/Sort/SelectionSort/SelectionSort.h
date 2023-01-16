/**
 * @file SelectionSort.h
 * @author Carlos Salguero
 * @brief Selection Sort Algorithm with modern C++.
 * @version 0.1
 * @date 2023-01-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <algorithm>  // std::min_element, std::iter_swap, std::is_sorted
#include <cassert>    // assert
#include <functional> // std::less<>
#include <iterator>   // distance, begin, end, next

/**
 * @brief
 * Selection Sort Algorithm.
 * @tparam FwdIt
 * @tparam Compare std::less<>
 * @param first
 * @param second
 * @param cpm
 * @time complexity O(N^2)
 * @space complexity O(1)
 */
template <class FwdIt, class Compare = std::less<>>
void selection_sort(FwdIt first, FwdIt second, Compare cmp = Compare{})
{
    for (auto it{first}; it != last; ++i)
    {
        auto const selection_sort{std::min_element(it, last, cmp)};

        std::iter_swap(selection, it);
        assert(std::is_sorted(first, std::next(it), cmp));
    }
}

#endif //! SELECTION_SORT_H