#include "FileParser.h"
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
}