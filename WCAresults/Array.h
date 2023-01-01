#pragma once

#include <iostream>
#include <assert.h>

namespace my
{

template <typename type>
class Array {
public:
    Array(int maxCapacity);
    ~Array();
    Array(const Array& source);
    Array(Array&& source);
    Array& operator=(const Array& rhs);
    Array& operator=(Array&& rhs);
    const type& operator[](int loc) const;
    type& operator[](int loc);
    bool isEmpty() const;
    bool isFull() const;
    int GetLength() const;
    void Pushback(const type& val);
    void Delete(const type& val);
    void Print();
private:
    const int maxCapacity;
    int listsize;
    type* arrayPtr;

};

// Constructor
template<typename type>
Array<type>::Array(int maxCapacity)
    :
    maxCapacity(maxCapacity),
    arrayPtr(new type[maxCapacity]),
    listsize(0)
{
}

// Destructor
template <typename type>
Array<type>::~Array()
{
    delete[] arrayPtr;
}

// Copy Constructor
template<typename type>
inline Array<type>::Array(const Array<type>& source)
    :
    maxCapacity(source.maxCapacity),
    arrayPtr(new type[maxCapacity])
{
    *this = source;
}

// Move Constructor
template<typename type>
inline Array<type>::Array(Array<type>&& source)
    :
    maxCapacity(source.maxCapacity),
    listsize(source.listsize),
    arrayPtr(source.arrayPtr)
{
    source.listsize = 0;
    source.arrayPtr = nullptr;
}

// Copy Assignment
template<typename type>
inline Array<type>& Array<type>::operator=(const Array<type>& rhs)
{
    assert(maxCapacity >= rhs.listsize);
    listsize = rhs.listsize;
    for (int i = 0; i < rhs.listsize; i++)
    {
        Pushback(rhs[i]);
    }
    return *this;
}

// Move Assignment
template<typename type>
inline Array<type>& Array<type>::operator=(Array<type>&& rhs)
{
    assert(maxCapacity >= rhs.listsize);
    listsize = rhs.listsize;
    arrayPtr = rhs.arrayPtr;
    rhs.listsize = 0;
    rhs.arrayPtr = nullptr;
    return *this;
}

// Const access
template<typename type>
inline const type& Array<type>::operator[](int loc) const
{
    assert(loc >= 0 && loc < maxCapacity);
    return arrayPtr[loc];
}

// Non-const access
template<typename type>
inline type& Array<type>::operator[](int loc)
{
    assert(loc >= 0 && loc < maxCapacity);
    return arrayPtr[loc];
}

template<typename type>
bool Array<type>::isEmpty() const {
    return listsize == 0;
}

template<typename type>
bool Array<type>::isFull() const {
    return listsize == maxCapacity;
}

template<typename type>
inline int Array<type>::GetLength() const
{
    return listsize;
}

template<typename type>
void Array<type>::Delete(const type& val) {
    int index{ -1 };
    for (int i{ 0 }; i < listsize; i++) {
        if (arrayPtr[i] == val) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        std::cout << "Value is not in the array" << std::endl;
    }
    else {
        for (int i{ index }; i < maxCapacity; i++) {
            arrayPtr[i] = arrayPtr[i + 1];
        }
        listsize--;

    }
}
template<typename type>
void Array<type>::Pushback(const type& val) {
    if (!isFull()) {
        arrayPtr[listsize++] = val;
    }
}
template<typename type>
void Array<type>::Print() {
    int count = 0;
    while (count != listsize) {
        std::cout << arrayPtr[count++] << std::endl;

    }
}

}