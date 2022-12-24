#include "FileParser.h"
#include "Pair.h"
#include <iostream>

int main()
{
	FileParser fp;
	fp.GoToLine(1);
	std::cout << fp.Line() << fp.GetCompetitionId() << ", " << fp.GetPersonName() << ", " << fp.GetValue1()
		<< "\n";
	for (int i = 2; i <= 5; i++)
	{
		fp.NextLine();
		std::cout << fp.Line() << fp.GetCompetitionId() << ", " << fp.GetPersonName() << ", " << fp.GetValue1()
			<< "\n";
	}
	fp.GoToLine(7);
	std::cout << fp.Line() << fp.GetCompetitionId() << ", " << fp.GetPersonName() << ", " << fp.GetValue1()
		<< "\n";

	my::Pair<int, std::string> lol = { fp.Line(), fp.GetPersonName() };
	my::Pair<int, std::string> lol1 = { 2, fp.GetPersonName() };
	my::Pair<int, std::string> lol2 = { fp.Line(), fp.GetPersonName() };
	if (lol == lol1) std::cout << "OH NOOOO!";
	if (lol == lol2) std::cout << lol.first << " " << lol.second;
}