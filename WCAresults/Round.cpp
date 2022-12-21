#include "Round.h"

Round::Round(int in_number,const std::string& in_eventId)
	:
	number(in_number),
	eventId(in_eventId)
{
}

int Round::GetNumber() const
{
	return number;
}

std::string Round::GetType() const
{
	return eventId;
}