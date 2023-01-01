#include "Round.h"
#include <assert.h>

Round::Round(const std::string& in_eventId, const std::string& in_roundType)
	:
	eventId(in_eventId),
	roundType(in_roundType)
{
}

std::string Round::GetEventType() const
{
	return eventId;
}

std::string Round::GetRoundType() const
{
	return roundType;
}

const my::Vector<Attempt>& Round::GetAttempts() const
{
	return attempts;
}

void Round::AddAttempt(const Attempt& attempt)
{
	attempts.Pushback(attempt);
}

void Round::Print(int n) const
{
	std::cout << "Round :" << eventId << ", number: " << roundType << std::endl;
	int i = 0;
	for (const Attempt& a : attempts)
	{
		std::cout << "\t\t";
		a.Print();
		if (++i >= n) break;
	}
	std::cout << std::endl;
}
