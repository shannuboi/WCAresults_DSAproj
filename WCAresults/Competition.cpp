#include "Competition.h"

Competition::Competition(const std::string& in_competitionId,const std::string& in_country)
	:
	competitionId(in_competitionId),
	country(in_country)
{
}

std::string Competition::GetCompetitionId() const
{
	return competitionId;
}

std::string Competition::GetCountry() const
{
	return country;
}