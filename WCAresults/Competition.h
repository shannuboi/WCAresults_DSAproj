#pragma once

#include "Round.h"
#include <string>
#include "Vector.h"

class Competition
{
public:
    Competition() = default;
    Competition(const std::string& in_competitionId);
    std::string GetCompetitionId() const;
    const my::Vector<Round>& GetRounds() const;
    void AddRound(const Round& round);
    void Print(int n) const;
private:
    std::string competitionId;
    my::Vector<Round> rounds;
}; 