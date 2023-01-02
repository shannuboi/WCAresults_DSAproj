#pragma once

#include <string>
#include "LinkedList.h"
#include "AVLtree.h"

class Person
{
public:
    Person() = default;
    Person(const std::string& in_name, const std::string& in_country, const std::string& in_personId);
    std::string GetName() const;
    std::string GetCountry() const;
    std::string GetPersonId() const;
    void AddCompetion(const std::string& compID);
    const my::LinkedList<std::string>& GetCompIds() const;
    void AddSolve(const std::string& solve);
    const my::AVLtree<int>& GetAll3x3Solves() const;
    void Print() const;
    void Print(int nComps, int nSolves) const;
private:
    std::string name;
    std::string country;
    std::string personId;
    my::LinkedList<std::string> competitionIds;
    my::AVLtree<int> all3x3Solves;
};

