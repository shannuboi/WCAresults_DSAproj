#include "Round.h"
#include <string>
#include <vector>

class Competition
{
public:
    Competition(const std::string& in_competitionId, const std::string& in_year);
    std::string GetCompetitionId() const;
    std::string GetCountry() const;
    void AddRound(const Round& round);
private:
    std::string competitionId;
    std::string country;
    std::vector<Round> rounds;
}; 