#include <string>
#include "LinkedList.h"

class Person
{
public:
    Person(const std::string& in_name, const std::string& in_country, const std::string& in_personId);
    std::string GetName() const;
    std::string GetCountry() const;
    std::string GetPersonId() const;
    void AddCompetion(const std::string& compID);
    const my::LinkedList<std::string>& GetCompIds() const;
private:
    std::string name;
    std::string country;
    std::string personId;
    my::LinkedList<std::string> competitionIds;
};

