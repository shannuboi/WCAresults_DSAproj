#include "Attempt.h"
#include <string>
#include <vector>

class Round
{
public:
    Round(int in_number, const std::string& in_EventId);
    int GetNumber() const;
    std::string GetType() const;
private:
    int number;
    std::string EventId;
    std::vector<Attempt> Attempts;
};