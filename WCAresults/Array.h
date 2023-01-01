#pragma once

#include <iostream>
#include <assert.h>

namespace my
{

template <typename type>
class Array {
public:
    // Iterators
    class ConstIterator
    {
    public:
        ConstIterator(type* p)
            :
            pData(p)
        {}
        const type& operator*() const
        {
            return *pData;
        }
        ConstIterator& operator++()
        {
            pData = pData + 1;
            return *this;
        }
        ConstIterator operator++(int)
        {
            ConstIterator temp(pData);
            pData = pData + 1;
            return temp;
        }
        ConstIterator& operator--()
        {
            pData = pData - 1;
            return *this;
        }
        ConstIterator operator--(int)
        {
            ConstIterator temp(pData);
            pData = pData - 1;
            return temp;
        }
        bool operator==(ConstIterator rhs) const
        {
            return pData == rhs.pData;
        }
        bool operator!=(ConstIterator rhs) const
        {
            return !(*this == rhs);
        }
    private:
        type* pData;
    };
    class Iterator
    {
    public:
        Iterator(type* p)
            :
            pData(p)
        {}
        type& operator*()
        {
            return *pData;
        }
        Iterator& operator++()
        {
            pData = pData + 1;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator temp(pData);
            pData = pData + 1;
            return temp;
        }
        Iterator& operator--()
        {
            pData = pData - 1;
            return *this;
        }
        Iterator operator--(int)
        {
            Iterator temp(pData);
            pData = pData - 1;
            return temp;
        }
        bool operator==(Iterator rhs) const
        {
            return pData == rhs.pData;
        }
        bool operator!=(Iterator rhs) const
        {
            return !(*this == rhs);
        }
        operator ConstIterator()
        {
            return ConstIterator(pData);
        }
    private:
        type* pData;
    };
public:
    Array(int maxCapacity);
    ~Array();
    Array(const Array& source);
    Array(Array&& source);
    Array& operator=(const Array& rhs);
    Array& operator=(Array&& rhs);
    const type& operator[](int loc) const;
    type& operator[](int loc);
    int GetLength() const;
    void Print();

    ConstIterator begin() const
    {
        return ConstIterator(arrayPtr);
    }
    Iterator begin()
    {
        return Iterator(arrayPtr);
    }
    ConstIterator end() const
    {
        return ConstIterator(arrayPtr + maxCapacity);
    }
    Iterator end()
    {
        return Iterator(arrayPtr + maxCapacity);
    }
private:
    const int maxCapacity;
    type* arrayPtr;

};

// Constructor
template<typename type>
Array<type>::Array(int maxCapacity)
    :
    maxCapacity(maxCapacity),
    arrayPtr(new type[maxCapacity])
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
    arrayPtr(source.arrayPtr)
{
    source.arrayPtr = nullptr;
}

// Copy Assignment
template<typename type>
inline Array<type>& Array<type>::operator=(const Array<type>& rhs)
{
    assert(maxCapacity >= rhs.maxCapacity);
    for (int i = 0; i < rhs.maxCapacity; i++)
    {
        arrayPtr[i] = rhs.arrayPtr[i];
    }
    return *this;
}

// Move Assignment
template<typename type>
inline Array<type>& Array<type>::operator=(Array<type>&& rhs)
{
    assert(maxCapacity >= rhs.maxCapacity);
    arrayPtr = rhs.arrayPtr;
    rhs.arrayPtr = nullptr;
    return *this;
}

// Const access
template<typename type>
inline const type& Array<type>::operator[](int index) const
{
    assert(index >= 0 && index < maxCapacity);
    return arrayPtr[index];
}

// Non-const access
template<typename type>
inline type& Array<type>::operator[](int index)
{
    assert(index >= 0 && index < maxCapacity);
    return arrayPtr[index];
}

template<typename type>
inline int Array<type>::GetLength() const
{
    return maxCapacity;
}

template<typename type>
void Array<type>::Print() {
    int count = 0;
    while (count != maxCapacity) {
        std::cout << arrayPtr[count++] << std::endl;

    }
}

}