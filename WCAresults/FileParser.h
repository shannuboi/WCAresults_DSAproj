#pragma once

#include <string>
#include <fstream>

class FileParser
{
public:
	FileParser(const std::string& fileName = "WCA_Results.txt");
	void NextLine();
private:
	std::ifstream file;

public:
	std::string GetCompetitionId() const;
	std::string GetEventId() const;
	std::string GetRoundTypeId() const;
	std::string GetPos() const;
	std::string GetBest() const;
	std::string GetAverage() const;
	std::string GetPersonName() const;
	std::string GetPersonId() const;
	std::string GetPersonCountryId() const;
	std::string GetFormatId() const;
	std::string GetValue1() const;
	std::string GetValue2() const;
	std::string GetValue3() const;
	std::string GetValue4() const;
	std::string GetValue5() const;
	std::string GetRegionalSingleRecord() const;
	std::string GetRegionalAverageRecord() const;
private:
	std::string competitionId;
	std::string eventId;
	std::string roundTypeId;
	std::string pos;
	std::string best;
	std::string average;
	std::string personName;
	std::string personId;
	std::string personCountryId;
	std::string formatId;
	std::string value1;
	std::string value2;
	std::string value3;
	std::string value4;
	std::string value5;
	std::string regionalSingleRecord;
	std::string regionalAverageRecord;
};