#pragma once

#include <string>
#include "Array.h"

class Attempt
{
public:
    Attempt();
    Attempt(int in_best, int in_average, const std::string& in_personId,
        int val1, int val2, int val3, int val4, int val5 );
    int GetBest() const;
    int GetAverage() const;
    std::string GetPersonId() const;
private:
    int best;
    int average;
    std::string personID;
    my::Array<int> solves;
};