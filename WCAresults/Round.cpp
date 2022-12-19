#include "Round.h"

Round::Round(int in_number,const std::string& in_EventId)
	:
	number(in_number),
	EventId(in_EventId)
{
}

int Round::GetNumber() const
{
	return number;
}

std::string Round::GetType() const
{
	return EventId;
}