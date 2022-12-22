#include <string>

class Attempt
{
public:
    Attempt(int in_best, int in_average, const std::string& in_personId,
        int val1, int val2, int val3, int val4, int val5 );
    int GetBest() const;
    int GetAverage() const;
    std::string GetPersonId() const;
private:
    int best;
    int average;
    std::string personID;
    int solves[5];
};