#pragma once

#include "Round.h"
#include <string>
#include "Vector.h"

class Competition
{
public:
    Competition(const std::string& in_competitionId);
    std::string GetCompetitionId() const;
    void AddRound(const Round& round);
private:
    std::string competitionId;
    my::Vector<Round> rounds;
}; 