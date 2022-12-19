/**
 * @file header.cpp
 * @author Carlos Salguero
 * @brief Implementation of the Header.h file
 * @version 0.1
 * @date 2022-12-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "header.h"

/* ---- Chronometer Class  ---- */
Chronometer::Chronometer()
{
    start_time = {};
    has_started = false;
}

/**
 * @brief
 * Starts the chronometer by setting the start_time to the current time
 * and setting the has_started flag to true.
 * @time Complexity: O(1)
 * @space Complexity: O(1)
 * @return void
 */
void Chronometer::start()
{
    gettimeofday(&start_time, nullptr);
    has_started = true;
}

/**
 * @brief
 * Stops the chronometer by calculating the difference between the current time
 * and the start_time. It also sets the has_started flag to false.
 * @time Complexity: O(1)
 * @space Complexity: O(1)
 * @return double The duration of the chronometer in milliseconds
 */
double Chronometer::stop()
{
    timeval end_time{};
    long seconds{}, useconds{};
    double duration{-1};

    if (has_started)
    {
        gettimeofday(&end_time, nullptr);

        seconds = end_time.tv_sec - start_time.tv_sec;
        useconds = end_time.tv_usec - start_time.tv_usec;

        duration = (seconds * 1000.0) + (useconds / 1000.0);
        has_started = false;
    }

    return duration;
}