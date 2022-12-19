#include "Person.h"

Person::Person(const std::string& in_name, const std::string& in_country, const std::string& in_personId)
	:
	country(in_country),
	name(in_name),
	personId(in_personId)
{
}

std::string Person::GetName() const
{
	return name;
}

std::string Person::GetCountry() const
{
	return country;
}

std::string Person::GetPersonId() const
{
	return personId;
}
