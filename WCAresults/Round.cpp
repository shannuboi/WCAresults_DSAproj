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

void Round::AddAttempt(const Attempt& attempt)
{
	attempts.push_back(attempt);
}
