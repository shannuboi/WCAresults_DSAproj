#pragma once
#include <iostream>
#include <string>
#include "Pair.h"
#include "LinkedList.h"
#include "Array.h"

namespace my
{

template <typename keytype, typename valuetype, class Hasher = std::hash<keytype>>
class Hashmap {
    typedef LinkedList<Pair<keytype, valuetype>> bucket;
    typedef Pair<valuetype, bool> returnVal;

public:
    Hashmap(int cap)
        :
        capacity(cap),
        hashtable(cap)
    {}
    int Hash(const keytype& key) {
        return hasher(key) % capacity;
    }
    // returns bool indicating whether insertion was successful (no dublicates allowed)
    bool Insert(const keytype& key, const valuetype& val) {
        int index = Hash(key);
        for (auto val : hashtable[index])
        {
            if (val.first == key)
            {
                return false;
            }
        }
        hashtable[index].PushBack(Pair<keytype, valuetype>{ key, val });
        return true;
    }
    // returns pair with first being value and second being bool indicating if key was found
    returnVal Search(const keytype& key) {
        int index = Hash(key);
        for (auto val : hashtable[index])
        {
            if (val.first == key)
            {
                return returnVal{ val.second, true };
            }
        }
        return returnVal{ valuetype(), false };
    }

private:
    Hasher hasher;
    int capacity;
    my::Array<bucket> hashtable;

};

}