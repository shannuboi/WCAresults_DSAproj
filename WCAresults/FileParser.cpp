#include "FileParser.h"
#include <assert.h>
#include <sstream>

FileParser::FileParser(const std::string& fileName)
	:
	file(fileName),
	lineNo(1)
{
	assert(file); // Will throw exception if file dosn't open
	std::string dump;
	std::getline(file, dump); // First line is column headings
}

// returns true only if next line is read successfully
bool FileParser::NextLine()
{
	std::string input;
	if (std::getline(file, input))
	{
		lineNo++;
		std::stringstream line(input);
		const char delim = '\t';

		std::getline(line, competitionId, delim);
		std::getline(line, eventId, delim);
		std::getline(line, roundTypeId, delim);
		std::getline(line, pos, delim);
		std::getline(line, best, delim);
		std::getline(line, average, delim);
		std::getline(line, personName, delim);
		std::getline(line, personId, delim);
		std::getline(line, personCountryId, delim);
		std::getline(line, formatId, delim);
		std::getline(line, value1, delim);
		std::getline(line, value2, delim);
		std::getline(line, value3, delim);
		std::getline(line, value4, delim);
		std::getline(line, value5, delim);
		std::getline(line, regionalSingleRecord, delim);
		std::getline(line, regionalAverageRecord);

		return true;
	}
	else
	{
		return false;
	}
}

int FileParser::LineNo() const
{
	return lineNo;
}

bool FileParser::GoToLine(int in_line_no)
{
	file.seekg(std::ios::beg); // Go to beginning of file

	std::string dump;
	std::getline(file, dump); // First line is column headings
	lineNo = 1;

	for (int i = 1; i < in_line_no; i++)
	{
		if(!NextLine()) return false;
	}
	return true;
}

std::string FileParser::GetCompetitionId() const
{
	return competitionId;
}

std::string FileParser::GetEventId() const
{
	return eventId;
}

std::string FileParser::GetRoundTypeId() const
{
	return roundTypeId;
}

std::string FileParser::GetPos() const
{
	return pos;
}

std::string FileParser::GetBest() const
{
	return best;
}

std::string FileParser::GetAverage() const
{
	return average;
}

std::string FileParser::GetPersonName() const
{
	return personName;
}

std::string FileParser::GetPersonId() const
{
	return personId;
}

std::string FileParser::GetPersonCountryId() const
{
	return personCountryId;
}

std::string FileParser::GetFormatId() const
{
	return formatId;
}

std::string FileParser::GetValue1() const
{
	return value1;
}

std::string FileParser::GetValue2() const
{
	return value1;
}

std::string FileParser::GetValue3() const
{
	return value1;
}

std::string FileParser::GetValue4() const
{
	return value1;
}

std::string FileParser::GetValue5() const
{
	return value1;
}

std::string FileParser::GetRegionalSingleRecord() const
{
	return regionalSingleRecord;
}

std::string FileParser::GetRegionalAverageRecord() const
{
	return regionalAverageRecord;
}
