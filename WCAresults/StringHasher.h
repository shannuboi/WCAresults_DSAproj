#pragma once

#include <string>

namespace my
{

class StringHasher
{
public:
	unsigned int operator()(const std::string& s) const
    {
        unsigned int hash_so_far = 0;
        unsigned long p_pow = 1;
        for (auto ch : s) {
            hash_so_far = (hash_so_far + (ch - '0' + 1) * p_pow) % Mod;
            p_pow = (p_pow * Base) % Mod;
        }
        return hash_so_far;
    }
private:
    static constexpr int Base = 37;
    static constexpr int Mod = 1000007;
};

}