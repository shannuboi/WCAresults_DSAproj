#include "Round.h"
#include <assert.h>

Round::Round(int in_number,const std::string& in_eventId)
	:
	number(in_number),
	totalrounds(-1),
	eventId(in_eventId)
{
}

// Returns pair { curRoundNum, TotalRounds }
my::Pair<int, int> Round::GetRoundNum() const
{
	return { number, totalrounds };
}

std::string Round::GetType() const
{
	return eventId;
}

void Round::AddAttempt(const Attempt& attempt)
{
	attempts.push_back(attempt);
}

void Round::SetTotalRounds(int totrounds)
{
	assert(totrounds > 0);
	totalrounds = totalrounds;
}
