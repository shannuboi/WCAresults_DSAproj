#include "FileParser.h"
#include <iostream>

int main()
{
	FileParser fp;
	for (int i = 2; i <= 65; i++)
	{
		fp.NextLine();
		std::cout << fp.GetCompetitionId() << ", " << fp.GetPersonName() << ", " << fp.GetRegionalAverageRecord() << "\n";
	}
	int lno = fp.LineNo();
	fp.GoToLine(7);
	std::cout << lno;
	std::cout << fp.GetCompetitionId() << ", " << fp.GetPersonName() << ", " << fp.GetRegionalAverageRecord() << "\n";
}