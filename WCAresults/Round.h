#pragma once

#include "Attempt.h"
#include "Pair.h"
#include <string>
#include <vector>

class Round
{
public:
    Round(const std::string& in_eventId, const std::string& in_roundType);
    std::string GetEventType() const;
    std::string GetRoundType() const;
    void AddAttempt(const Attempt& attempt);
private:
    std::string eventId;
    std::string roundType;
    std::vector<Attempt> attempts;
};