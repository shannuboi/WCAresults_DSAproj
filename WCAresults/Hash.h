#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "pair.h"

template <typename keytype, typename valuetype>
class HASH {
public:

    HASH(int cap);
    int Hash(keytype key);
    void Insert(keytype key, valuetype val);
    valuetype Search(keytype key);

private:

    int capacity;
    std::vector <Pair<keytype, valuetype>> hashtable;

};

template <typename keytype, typename valuetype>
HASH<typename keytype, typename valuetype>::HASH(int cap)
    :
    capacity(cap),
    hashtable(cap)
{
}


template <typename keytype, typename valuetype>
int HASH<typename keytype, typename valuetype>::Hash(keytype key) {
    std::hash<keytype> hasher;
    return hasher(key) % capacity;
}


template <typename keytype, typename valuetype>
void HASH<typename keytype, typename valuetype>::Insert(keytype key, valuetype val) {
    int index = Hash(key);
    hashtable[index].first = key;
    hashtable[index].second = val;
}

template <typename keytype, typename valuetype>
valuetype HASH<typename keytype, typename valuetype>::Search(keytype key) {
    int index = Hash(key);
    if (hashtable[index].first == key)
        return hashtable[index].second;
    else
        std::cout << "Value not found!!!!" << std::endl;
}