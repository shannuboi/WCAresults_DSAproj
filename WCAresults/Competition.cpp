#include "Competition.h"

Competition::Competition(const std::string& in_competitionId)
	:
	competitionId(in_competitionId)
{
}

std::string Competition::GetCompetitionId() const
{
	return competitionId;
}

void Competition::AddRound(const Round& round)
{
	rounds.push_back(round);
}
