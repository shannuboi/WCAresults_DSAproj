#include "Round.h"
#include <string>
#include <vector>

class Competition
{
public:
    Competition(const std::string& in_competitionId);
    std::string GetCompetitionId() const;
    void AddRound(const Round& round);
private:
    std::string competitionId;
    std::vector<Round> rounds;
}; 