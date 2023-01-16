/**
 * @file HeapSort.h
 * @author Carlos Salguero
 * @brief Heap Sort Algorithm implemented with Modern C++
 * @version 0.1
 * @date 2023-01-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <algorithm>  // std::is_heap(), std::push_heap()
#include <functional> // std::less<>
#include <iterator>   //
#include <cassert>    // assert

/**
 * @brief 
 * 
 * @tparam RandomIt 
 * @tparam Compare 
 * @param first 
 * @param last 
 * @param cmp 
 */
template <class RandomIt, class Compare = std::less<>>
void heap_sort(RandomIt first, RandomIt last, Compare cmp = Compare{})
{
    custom::make_heap(first, last, cmp);
    custom::sort_heap(first, last, cmp);
}

namespace custom
{
    /**
     * @brief
     *
     * @tparam RandomIt
     * @tparam Compare
     * @param first
     * @param second
     * @param cmp
     */
    template <class RandomIt, class Compare = std::less<>>
    void make_heap(RandomIt first, RandomIt second, Compare cmp = Compare{})
    {
        for (auto it{first}; it != last;)
        {
            std::push_heap(first, ++it, cmp);
            assert(std::is_heap(first, it, cmp));
        }
    }

    /**
     * @brief
     *
     * @tparam RandomIt
     * @tparam Compare
     * @param first
     * @param last
     * @param cmp
     */
    template <class RandomIt, class Compare = std::less<>>
    void sort_heap(RandomIt first, RandomIt last, Compare cmp = Compare{})
    {
        for (auto it{last}; it != first;)
        {
            std::pop_heap(first, it--, cmp);
            assert(std::is_heap(first, it, cmp));
        }
    }
}

#endif //! HEAP_SORT_H