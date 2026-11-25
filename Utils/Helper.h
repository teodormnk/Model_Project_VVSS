#pragma once

#include "pch.h"

inline double calculateMaxInVector(const std::vector<double>& vector)
{
    // TDD =  Test Driven Development -> se scriu mai intai testele care trebuie sa pice, apoi refactorizam codul astfel incat testele sa treaca
    if(vector.size() <= 0) 
    {
        throw std::invalid_argument("Vector gol!");
    }
    double max = vector[0];
    for(auto number: vector)
    {
        if(number > max)
        {
            max = number;
        }
    }
    return max;
}

inline double calculateAvgInVector(const std::vector<double>& vector)
{
    if(vector.size() <= 0)
        throw std::invalid_argument("Vector gol!");

    double sum = 0.0;

    for(auto number: vector)
    {
        sum += number;
    }
    return sum / vector.size();
}