#include "FileParser.h"
#include <assert.h>
#include <sstream>

// File is opened
// Line no. is set to 1 meaning curline is column-headings which arent read into variables
FileParser::FileParser(const std::string& fileName)
	:
	file(fileName),
	lineNo(1)
{
	assert(file); // Will throw exception if file dosn't open
	std::string dump;
	std::getline(file, dump); // First line is column headings
}

// reads data from next file and transfers into member variables
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
	
	return false;
}

// Line number of the currently stored data
// LineNo starts at 1 and the first line is the column headings
// Column heading are not saved in member variables, instead they are set to empty strings when lineNo = 1
int FileParser::Line() const
{
	return lineNo;
}

// First line is lineNo 1 and it corrsponds to the column headings (member variables cleared)
// returns true only if line is read successfully
bool FileParser::GoToLine(int in_line_no)
{
	file.seekg(std::ios::beg); // Go to beginning of file

	std::string dump;
	for (int i = 0; i < in_line_no - 1; i++) // loop and goes to line just before in_line_no
	{
		lineNo = i + 1;
		if(!std::getline(file, dump)) return false;
	}

	if (in_line_no == 1)
	{
		lineNo = 1;

		competitionId = "";
		eventId = "";
		roundTypeId = "";
		pos = "";
		best = "";
		average = "";
		personName = "";
		personId = "";
		personCountryId = "";
		formatId = "";
		value1 = "";
		value2 = "";
		value3 = "";
		value4 = "";
		value5 = "";
		regionalSingleRecord = "";
		regionalAverageRecord = "";

		return true;
	}

	return NextLine();
}

// Below are all geters for each column

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
	return value2;
}

std::string FileParser::GetValue3() const
{
	return value3;
}

std::string FileParser::GetValue4() const
{
	return value4;
}

std::string FileParser::GetValue5() const
{
	return value5;
}

std::string FileParser::GetRegionalSingleRecord() const
{
	return regionalSingleRecord;
}

std::string FileParser::GetRegionalAverageRecord() const
{
	return regionalAverageRecord;
}
