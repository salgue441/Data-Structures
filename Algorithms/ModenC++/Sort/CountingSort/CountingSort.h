/**
 * @file CountingSort.h
 * @author Carlos Salguero
 * @brief Counting Sort Algorithm implemented with modern C++
 * @version 0.1
 * @date 2023-01-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include <algorithm>
#include <iterator> // for std::next()
#include <vector>

/**
 * @brief
 *
 * @tparam ForwardIterator
 * @param first
 * @param last
 */
template <typename ForwardIterator>
void counting_sort(ForwardIterator first, ForwardIterator last)
{
    if (first == last || std::next(first) == last)
        return;

    auto minmax{std::minmax_element(first, last)};
    auto min{*minmax.first};
    auto max{*minmax.second};

    if (min == max)
        return;

    using difference_type =
        typename std::iterator_traits<ForwardIterator>::difference_type;

    std::vector<difference_type> counts(max - min + 1, 0);

    for (auto it{first}; it != last; ++it)
        ++counts[*it - min];

    for (auto count : counts)
        first = std::fill_n(first, count, min++);
}

#endif //! COUNTING_SORT_H