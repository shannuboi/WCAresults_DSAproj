#pragma once

#include <unordered_map>
#include "Competition.h"
#include "Person.h"
#include "FileParser.h"

class Program
{
public:
	Program();
private:
	bool FillRound(FileParser& fp, Round& round);
	void FillCompetatorTable(const FileParser& fp);
private:
	int compcount = 0;
	int playercount = 0;
	std::unordered_map<std::string, Competition> comps;
	std::unordered_map<std::string, Person> competators;
};