#include <iostream>

namespace my
{

template <typename type>
class Array {
public:
    Array(int maxCapacity);
    ~Array();
    bool isEmpty();
    bool isFull();
    void Pushback(type val);
    void Delete(type val);
    void Print();
private:
    const int maxCapacity;
    int listsize;
    type* array;

};

template<typename type>
Array<type>::Array(int maxCapacity)
    :
    maxCapacity(maxCapacity)
{
    array = new type[maxCapacity];// previously was int[maxCapacity]
    listsize = 0;
}

template <typename type>
Array<type>::~Array()
{
    delete[] array;
}

template<typename type>
bool Array<type>::isEmpty() {
    return listsize == 0;
}


template<typename type>
bool Array<type>::isFull() {
    return listsize == maxCapacity;
}


template<typename type>
void Array<type>::Delete(type val) {
    int index{ -1 };
    for (int i{ 0 }; i < listsize; i++) {
        if (array[i] == val) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        std::cout << "Value is not in the array" << std::endl;
    }
    else {
        for (int i{ index }; i < maxCapacity; i++) {
            array[i] = array[i + 1];
        }
        listsize--;

    }
}
template<typename type>
void Array<type>::Pushback(type val) {
    if (!isFull()) {
        array[listsize++] = val;
    }
}
template<typename type>
void Array<type>::Print() {
    int count = 0;
    while (count != listsize) {
        std::cout << array[count++] << std::endl;

    }
}

}