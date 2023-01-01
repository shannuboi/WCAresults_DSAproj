#pragma once
#include<iostream>
#include <string>

void StringHasher(const std::string& s) {
    const int p = 37, m = 1e9 + 7;
    unsigned int hash_value;
    unsigned int hash_so_far = 0;
    unsigned long p_pow = 1;
    const int n = s.length();
    for (int i = 0; i < n; ++i) {
        hash_so_far = (hash_so_far + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    hash_value = hash_so_far;
}

// THIS IS OPERATOR OVERLOADING IGUESS.. CHECK THIS IF IT IS OF ANY USE HERE    
// bool operator==(const Hash& other) {
//     return (hash_value == other.hash_value);
// };

