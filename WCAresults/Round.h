#include "Attempt.h"
#include <string>
#include <vector>

class Round
{
public:
    Round(int in_number, const std::string& in_eventId);
    int GetNumber() const;
    std::string GetType() const;
    void AddAttempt(const Attempt& attempt);
private:
    int number;
    std::string eventId;
    std::vector<Attempt> attempts;
};