#include "Attempt.h"

Attempt::Attempt(int in_best, int in_average, const std::string& in_personId,
	int val1, int val2, int val3, int val4, int val5)
	:
	best(in_best),
	average(in_average),
	personID(in_personId),
	solves(5)
{
	solves.Pushback(val1);
	solves.Pushback(val2);
	solves.Pushback(val3);
	solves.Pushback(val4);
	solves.Pushback(val5);
}

int Attempt::GetBest() const
{
	return best;
}

int Attempt::GetAverage() const
{
	return average;
}

std::string Attempt::GetPersonId() const
{
	return personID;
}