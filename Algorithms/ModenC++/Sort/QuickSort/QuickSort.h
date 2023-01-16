/**
 * @file QuickSort.h
 * @author Carlos Salguero
 * @brief Quick sort algorithm implemented with Modern C++
 * @version 0.1
 * @date 2023-01-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <algorithm>  // std::partition()
#include <functional> // std::less<>
#include <iterator>   // std::next(), std::distance()

/**
 * @brief
 *
 * @tparam FwdIt
 * @tparam Compare
 * @param first
 * @param second
 * @param cmp
 * @time complexity O(N log(N))
 * @space complexity O(N)
 */
template <class FwdIt, class Compare = std::less<>>
void quick_sort(FwdIt first, FwdIt second, Compare cmp = Compare{})
{
    auto const N{std::distance(first, last)};

    if (N <= 1)
        return;

    auto const pivot{*std::next(first, N / 2)};

    auto const middle_left{
        std::partition(
            first, last, [=](auto const &elem)
            { return cmp(elem, pivot); })};

    auto const middle_right{
        std::partition(
            middle_left, last, [=](auto const &elem)
            { return !cmp(pivot, elem); })};

    quick_sort(first, middle_left, cmp);
    quick_sort(middle_right, last, cmp);
}

#endif //! QUICK_SORT_H