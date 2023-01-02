#pragma once

#include <unordered_map>
#include "StringHasher.h"
#include "Competition.h"
#include "Person.h"
#include "FileParser.h"
#include "AVLtree.h"

class Program
{
public:
	Program();
	void Execute();
private:
	void PrintTenComps();
	void PrintTenPlayers();
	void PrintTenPlayersThatWonMoreThenOneComp();
	void PrintTenPlayersThatBeatFeliksZemdegs();
	void Print10CompsWithSub53x3Solve();

	bool FillRound(FileParser& fp, Round& round);
	void FillCompetatorTable(const FileParser& fp);
private:
	std::unordered_map<std::string, Competition, my::StringHasher> comps;
	std::unordered_map<std::string, Person, my::StringHasher> competators;

	my::AVLtree<std::string> AlphabeticalComps;

	my::AVLtree<std::string> AllCompetators;
};