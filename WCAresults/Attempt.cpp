#include "Attempt.h"

Attempt::Attempt(int in_best, int in_average, const std::string& in_personId, int val1, int val2, int val3, int val4, int val5)
	:
	best(in_best),
	average(in_average),
	personID(in_personId)
{
	solves[0] = val1;
	solves[1] = val2;
	solves[2] = val3;
	solves[3] = val4;
	solves[4] = val5;

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