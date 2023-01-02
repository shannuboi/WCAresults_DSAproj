#include "Competition.h"
#include <iostream>

Competition::Competition(const std::string& in_competitionId)
	:
	competitionId(in_competitionId)
{
}

std::string Competition::GetCompetitionId() const
{
	return competitionId;
}

const my::Vector<Round>& Competition::GetRounds() const
{
	return rounds;
}

void Competition::AddRound(const Round& round)
{
	rounds.Pushback(round);
}

void Competition::Print(int n) const
{
	std::cout << "Competition: " << competitionId << std::endl;
	int i = 0;
	for (const Round& r : rounds)
	{
		std::cout << "\t";
		r.Print(3);
		if (++i >= n) break;
	}
	std::cout << std::endl;
}
