/**
 * @file Olympian.cpp
 * @author Daniel O'Neill
 * @date 9/11/2024
 * @section 1003
 *
 * @note I pledge my word of honor that I have abided by the
 * CSN Academic Integrity Policy while completing this assignment.
 *
 * @brief this file is a derived class file from the Athlete.h file
 */

#ifndef OLYMPIAN_H
#define OLYMPIAN_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>

#include "Athlete.h"

class Olympian : public Athlete
{
public:
    Olympian() {}
    Olympian(const std::string& name, int id,const std::string& Cname);

    // new functions
    /**
     * @brief Adds new score to the array
     */
    void push_back(double score_value);

    /**
     * @brief Gets the active first array score
     */
    double front() const;

    /**
     * @brief Gets the active final array score
     */
    double back() const;

    /**
     * @brief  Returns the current size of array
     */
    size_t size() const {return score_count;}

    /**
     * @brief true if the array is empty
     */
    bool empty() const {return score_count == 0;}

    /**
     * @brief max number of scores that can be stored
     */
    size_t capacity() const {return 5;}

    /**
     * @brief Returns the country name
     */
    std::string country() const {return country_name;}

    /**
     * @brief sets the country name
     */
    void country(const std::string& new_country) {country_name = new_country;}

    /**
     * @brief compares the athletes
     */
    bool equal(const Olympian& other_olympian) const;

    // overridden functions
    /**
     * @brief gets the score
     */
    double at(size_t index) const;

    /**
     * @brief sets the score
     */
    void at(size_t index, double value);

    /**
     * @brief finds the lowest score
     */
    double min_score() const;

    /**
     * @brief finds the highest score
     */
    double max_score() const;

    /**
     * @brief gets the average of the scores
     */
    double average_score() const;

private:
    std::string country_name {}; // The athletes country
    int score_count {};      // Active number of scores
};

#endif /* OLYMPIAN_H */
