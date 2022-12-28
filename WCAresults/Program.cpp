#include "Program.h"
#include "Pair.h"

// Reads data from FileParser and fills up data structures
Program::Program()
{
	FileParser fp;
	fp.NextLine(); // start at first comp

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

// Takes a round by refference and adds all attempts of that round into round
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

// If competator is new it is added to hash map
void Program::FillCompetatorTable(const FileParser & fp)
{
	bool newcomp = true;
	if (!competators.insert({ fp.GetPersonId(),
		Person(fp.GetPersonName(), fp.GetPersonCountryId(), fp.GetPersonId()) }).second) // if not new competators
	{
		auto latestCompId = competators.find(fp.GetPersonId())->second.GetCompIds().begin();
		newcomp = *latestCompId != fp.GetCompetitionId();
	}
	if(newcomp) 
		competators.find(fp.GetPersonId())->second.AddCompetion(fp.GetCompetitionId());
}


