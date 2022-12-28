#include "Program.h"
#include "Pair.h"

Program::Program()
{
	FileParser fp;
	fp.NextLine();

	bool endOfFile = false;
	while (!endOfFile)
	{
		const auto compId = fp.GetCompetitionId();
		comps.insert({ compId, Competition(compId) });
		while (!endOfFile && compId == fp.GetCompetitionId())
		{
			Round round(fp.GetEventId(), fp.GetRoundTypeId());
			
			endOfFile = !FillRound(fp, round);
			// Fill round returning false indicates endOfFile hit

			comps.find(compId)->second.AddRound(round);
		}
	}
}

bool Program::FillRound(FileParser& fp, Round& round)
{
	const auto compId = fp.GetCompetitionId();
	my::Pair<std::string, std::string> newRound = { fp.GetEventId(), fp.GetRoundTypeId() };
	my::Pair<std::string, std::string> curRound = newRound;

	while (fp.GetCompetitionId() == compId && curRound == newRound) //while different round hasnt come
	{
		Attempt attempt(std::stoi(fp.GetBest()), std::stoi(fp.GetAverage()), fp.GetPersonId(),
			std::stoi(fp.GetValue1()),
			std::stoi(fp.GetValue2()),
			std::stoi(fp.GetValue3()),
			std::stoi(fp.GetValue4()),
			std::stoi(fp.GetValue5()));

		FillCompetatorTable(fp);

		round.AddAttempt(attempt);
		if (!fp.NextLine()) return false; // exit if endoffile
		curRound = { fp.GetEventId(), fp.GetRoundTypeId() };
	}
	return true;
}

void Program::FillCompetatorTable(const FileParser & fp)
{
	competators.insert({ fp.GetPersonId(),
		Person(fp.GetPersonName(), fp.GetPersonCountryId(), fp.GetPersonId()) }); // only inserts new competators

	competators.find(fp.GetPersonId())->second.AddCompetion(fp.GetCompetitionId());
}


