#pragma once

#include "Attempt.h"
#include "Pair.h"
#include <string>
#include "Vector.h"

class Round
{
public:
    Round() = default;
    Round(const std::string& in_eventId, const std::string& in_roundType);
    std::string GetEventType() const;
    std::string GetRoundType() const;
    const my::Vector<Attempt>& GetAttempts() const;
    void AddAttempt(const Attempt& attempt);
    void Print(int n) const;
private:
    std::string eventId;
    std::string roundType;
    my::Vector<Attempt> attempts;
};