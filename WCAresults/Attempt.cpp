#include "Attempt.h"

Attempt::Attempt()
	:
	solves(5)
{
}

Attempt::Attempt(int in_best, int in_average, const std::string& in_personId,
	int val1, int val2, int val3, int val4, int val5)
	:
	best(in_best),
	average(in_average),
	personID(in_personId),
	solves(5)
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

const my::Array<int>& Attempt::GetSolves() const
{
	return solves;
}

void Attempt::Print() const
{
	std::cout << "Player: " << personID << ",  AVG: " << average << ",  BEST: " << best << std::endl;
	std::cout << "\t\t\t";
	for (int i = 0; i < solves.GetLength(); i++)
	{
		auto time = std::to_string(solves[i]);
		if (time.length() >= 2)
			std::cout << time.substr(0, time.length() - 2) << "." << time.substr(time.length() - 2);
		else
			std::cout << time;
		std::cout << "  ";
	}
	std::cout << std::endl;
}
