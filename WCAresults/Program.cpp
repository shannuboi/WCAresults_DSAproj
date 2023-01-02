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
		AlphabeticalComps.Insert(compId);
		DateWiseComps.PushFront(compId);

		while (!endOfFile && compId == fp.GetCompetitionId())
		{
			Round round(fp.GetEventId(), fp.GetRoundTypeId());
			
			endOfFile = !FillRound(fp, round);
			// Fill round returning false indicates endOfFile hit

			comps.find(compId)->second.AddRound(round);
		}
	}
}

void Program::Execute()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\t\t\t                   ____        ___   ____                    ____    " << std::endl;
	std::cout << "\t\t\t \\      /\\      / |     |     |     |    |    /\\      /\\    |    " << std::endl;
	std::cout << "\t\t\t  \\    /  \\    /  |---- |     |     |    |   /  \\    /  \\   |____" << std::endl;
	std::cout << "\t\t\t   \\  /    \\  /   |     |     |     |    |  /    \\  /    \\  |    " << std::endl;
	std::cout << "\t\t\t    \\/      \\/    |____ |____ |___  |____| /      \\/      \\ |____" << std::endl;
	std::cout << std::endl;
	std::cout << "\t\t\t\t     _____   ___      ___         ___  " << std::endl;
	std::cout << "\t\t\t\t       |    |   |    |   | |   | |___| " << std::endl;
	std::cout << "\t\t\t\t       |    |___|    |___| |___| |   \\" << std::endl;
	std::cout << std::endl;
	std::cout << "\t\t\t     _____    _____     ______     _____    _____    _____   _______" << std::endl;
	std::cout << "\t\t\t    |     |  |     |   |      |      |     |        |           |   " << std::endl;
	std::cout << "\t\t\t    |_____|  |_____|   |      |      |     |_____   |           |   " << std::endl;
	std::cout << "\t\t\t    |        |     \\   |      |      |     |        |           |  " << std::endl;
	std::cout << "\t\t\t    |        |      \\  |______|   ___|     |_____   |_____      |  " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	bool running = true;
	while (running)
	{
		std::cout << "Here are all the Functions you can run" << std::endl;
		std::cout << "1. Print 10 competitions" << std::endl;
		std::cout << "2. Print 10 competators" << std::endl;
		std::cout << "3. Print 10 players that won more then one comp" << std::endl;
		std::cout << "4. one function goes here" << std::endl;
		std::cout << "5. one function goes here" << std::endl;

		char choice = '0';

		std::cout << "Please enter a number to run respective function (q to exit)" << std::endl;
		std::cin.get(choice);
		std::cin.get();

		switch (choice)
		{
		case '1':
			PrintTenComps();
			break;
		case '2':
			PrintTenPlayers();
			break;
		case '3':
			PrintTenPlayersThatWonMoreThenOneComp();
			break;
		case 'q':
			running = false;
			break;
		default:
			std::cout << "\nNot a valid input\n\n";
		}
	}
}

void Program::PrintTenComps()
{
	int i = 0;
	for (const std::string& compID : DateWiseComps)
	{
		comps[compID].Print(5);
		if (++i >= 10) break;
	}
}

void Program::PrintTenPlayers()
{
	int i = 0;
	my::InOrderTriversal(AllCompetators.begin(), AllCompetators.end(),
		[this, &i](const std::string& id) { // lambda function that prints players
			if (i++ < 10)
			competators[id].Print(5, 10);
		});
}

void Program::PrintTenPlayersThatWonMoreThenOneComp()
{
	int i = 0;
	my::InOrderTriversal(AllCompetators.begin(), AllCompetators.end(),
		[this, &i](const std::string& id) { // lambda function
			if (i < 10)
			{
				const Person& player = competators[id];
				int count = 0;
				for (const std::string& compId : player.GetCompIds())
				{
					for (const Round& round : comps[compId].GetRounds())
					{
						if (round.GetAttempts()[0].GetPersonId() == id)
							count++;
					}
				}

				if (count >= 2)
				{
					player.Print();
					i++;
				}					
			}
		});
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
	else
	{
		AllCompetators.Insert(fp.GetPersonId());
	}

	if(newcomp) 
		competators.find(fp.GetPersonId())->second.AddCompetion(fp.GetCompetitionId());

	if (fp.GetEventId() == "333")
	{
		competators.find(fp.GetPersonId())->second.AddSolve(fp.GetValue1());
		competators.find(fp.GetPersonId())->second.AddSolve(fp.GetValue2());
		competators.find(fp.GetPersonId())->second.AddSolve(fp.GetValue3());
		competators.find(fp.GetPersonId())->second.AddSolve(fp.GetValue4());
		competators.find(fp.GetPersonId())->second.AddSolve(fp.GetValue5());
	}
}


