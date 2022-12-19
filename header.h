/**
 * @file header.h
 * @author Carlos Salguero
 * @brief Contains auxiliary functions for the Data Structures
 * @version 0.1
 * @date 2022-12-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <sys/time.h>

/* ---- Chronometer Class  ---- */
class Chronometer
{
public:
    // Constructor
    Chronometer();

    // Destructor
    ~Chronometer() = default;

    // Functions
    void start();
    double stop();

private:
    timeval start_time{};
    bool has_started{0};
};

/* ---- Auxiliary Functions ---- */
template <class T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

#endif // HEADER_H