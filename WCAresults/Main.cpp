#include "FileParser.h"
#include <iostream>

int main()
{
	FileParser fp;
	for (int i = 0; i < 65; i++)
	{
		fp.NextLine();
		std::cout << fp.GetCompetitionId() << ", " << fp.GetPersonName() << ", " << fp.GetRegionalAverageRecord() << "\n";
	}

}