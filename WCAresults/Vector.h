#pragma once

#include <iostream>
#include <assert.h>
#include "Utilities.h"

namespace my 
{

template <typename type>
class Vector {
public:
    Vector();
    Vector(int maxCapacity);
    ~Vector();
    Vector(const Vector& src);
    Vector(Vector&& src);
    Vector& operator=(const Vector& rhs);
    Vector& operator=(Vector&& rhs);
    const type& operator[](int index) const;
    type& operator[](int index);
    bool isEmpty() const;
    bool isFull() const;
    int GetLength() const;
    int Search(const type&) const;
    void Pushback(const type&);
    void ChangeCapacity(int newsize);
private:
    int maxCapacity;
    type* arrayPtr;
    int listSize;
};


// Defualt constructor (max size is set to 16)
template<typename type>
inline Vector<type>::Vector()
    :
    maxCapacity(0),
    arrayPtr(new type[maxCapacity]),
    listSize(0)
{
}

// Constructor
template <typename type>
Vector<type>::Vector(int maxCapacity)
    :
    maxCapacity(maxCapacity),
    arrayPtr(new type[maxCapacity]),
    listSize(0)
{
}

// Destructor
template <typename type>
Vector<type>::~Vector()
{
    delete[] arrayPtr;
}


// Copy constructor
template<typename type>
inline Vector<type>::Vector(const Vector<type>& src)
    :
    arrayPtr(nullptr)
{
    *this = src;
}

// Move constructor
template<typename type>
inline Vector<type>::Vector(Vector<type>&& src)
{
    *this = std::move(src);
}

// Copy assignment
template<typename type>
inline Vector<type>& Vector<type>::operator=(const Vector<type>& rhs)
{
    if (arrayPtr) delete[] arrayPtr; // only delete if not null

    listSize = 0;
    maxCapacity = rhs.maxCapacity;
    arrayPtr = (new type[maxCapacity]);

    for (int i = 0; i < rhs.listSize; i++)
    {
        Pushback(rhs[i]);
    }

    return *this;
}

// Move assignment
template<typename type>
inline Vector<type>& Vector<type>::operator=(Vector<type>&& rhs)
{
    arrayPtr = rhs.arrayPtr;
    listSize = rhs.listSize;
    maxCapacity = rhs.maxCapacity;

    rhs.arrayPtr = nullptr;
    rhs.maxCapacity = 0;
    rhs.listSize = 0;

    return *this;
}

// Const access
template<typename type>
inline const type& Vector<type>::operator[](int index) const
{
    assert(index >= 0 && index < listSize);
    return arrayPtr[index];
}

// non-Const access
template<typename type>
inline type& Vector<type>::operator[](int index)
{
    assert(index >= 0 && index < listSize);
    return arrayPtr[index];
}

template <typename type>
bool Vector<type>::isEmpty() const {
    return listSize == 0;
}

template <typename type>
bool Vector<type>::isFull() const {
    return listSize >= maxCapacity;
}

template<typename type>
inline int Vector<type>::GetLength() const
{
    return listSize;
}

template <typename type>
int Vector<type>::Search(const type& val) const {
    for (int i = 0; i < listSize; i++) {
        if (arrayPtr[i] == val) {
            return i;
        }
    }
    return -1;
}

template <typename type>
void Vector<type>::Pushback(const type& val) {
    if (maxCapacity == 0) ChangeCapacity(16);

    arrayPtr[listSize++] = val;
    if (isFull()) {
        ChangeCapacity(maxCapacity * 2);
    }
}

// Changes capicity to newsize (if newsize < listsize then extra elements get deleated)
template <typename type>
void Vector<type>::ChangeCapacity(int newsize) {
    assert(newsize >= 0);
    int* temp;
    temp = arrayPtr;
    arrayPtr = new type[newsize];

    int copySize = my::min(newsize, listSize);
    for (int i = 0; i < copySize ; i++) {
        arrayPtr[i] = temp[i];
    }
    maxCapacity = newsize;
    delete[] temp;
}

}

