#include "Attempt.h"
#include "Pair.h"
#include <string>
#include <vector>

class Round
{
public:
    Round(int in_number, const std::string& in_eventId);
    my::Pair<int, int> GetRoundNum() const;
    std::string GetType() const;
    void AddAttempt(const Attempt& attempt);
    void SetTotalRounds(int totrounds);
private:
    int number;
    int totalrounds;
    std::string eventId;
    std::vector<Attempt> attempts;
};