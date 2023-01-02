#include "Person.h"

Person::Person(const std::string& in_name, const std::string& in_country, const std::string& in_personId)
	:
	country(in_country),
	name(in_name),
	personId(in_personId)
{
}

std::string Person::GetName() const
{
	return name;
}

std::string Person::GetCountry() const
{
	return country;
}

std::string Person::GetPersonId() const
{
	return personId;
}

void Person::AddCompetion(const std::string& compID)
{
	competitionIds.PushFront(compID);
}

const my::LinkedList<std::string>& Person::GetCompIds() const
{
	return competitionIds;
}

void Person::AddSolve(const std::string& solve)
{
	int time = std::stoi(solve);
	if (time > 0)
	{
		all3x3Solves.Insert(time);
	}
}

const my::AVLtree<int>& Person::GetAll3x3Solves() const
{
	return all3x3Solves;
}

void Person::Print(int nComps, int nSolves) const
{
	std::cout << "Name: " << name << ",  Country: " << country << std::endl;
	int i = 0;

	std::cout << "\tVisited comps:\n\t";
	for (const std::string& c : competitionIds)
	{
		std::cout << c << ", ";
		if (i++ >= nComps) break;
	}

	i = 0;
	std::cout << "\n\n\tSolves:\n\t";
	my::InOrderTriversal(all3x3Solves.begin(), all3x3Solves.end(),
		[=, &i](int solve) { // lambda function that prints solves
			if (i++ < nSolves)
			{
				auto time = std::to_string(solve);
				if (time.length() >= 2)
					std::cout << time.substr(0, time.length() - 2) << "." << time.substr(time.length() - 2);
				else
					std::cout << time;
				std::cout << "  ";
			}
		});
	std::cout << std::endl;
	std::cout << std::endl;
}
