#include <iostream>


template <typename type>
class DynamicArray{
public:
    DynamicArray(int maxCapacity);
    ~DynamicArray();
    bool isEmpty();
    bool isFull();
    int  Search(type);
    void DynamicExpansion();
    void Pushback(type);
private:
    int maxCapacity;
    type *array;
    int listSize;
};

template <typename type>
DynamicArray<type>::DynamicArray(int maxCapacity)
:
maxCapacity(maxCapacity)
{
    array = new type[maxCapacity];
    listSize=0;
}

template <typename type>
DynamicArray<type>::~DynamicArray() 
{
    delete[] array;
}

template <typename type>
bool DynamicArray<type>::isEmpty() {
    if (listSize == 0) {return true;}
    else return false;
}

template <typename type>
bool DynamicArray<type>::isFull() {
    if (listSize == maxCapacity) {
        return true;
    }
    else return false;
}

template <typename type>
int DynamicArray<type>::Search(type val) {
    for (int i = 0; i<listSize; i++) {
        if (array[i] == val) {
            return i;
        }
        else {return -1;}
    }
}

template <typename type>
void DynamicArray<type>::DynamicExpansion() {
    int *temp;
    temp = array; 
    array= new type[maxCapacity+10];
    for (int i=0; i<maxCapacity; i++) {
        array[i] = temp[i];
    }
    maxCapacity = maxCapacity+10;
    delete temp;

}

template <typename type>
void DynamicArray<type>::Pushback(type val) {
    if (Search(val)>=0) {
        std::cout << "Value is already in the list" << std::endl;
    }
    else {
        array[listSize++] = val;
    }
    if (isFull() == true) {
        DynamicExpansion();
    }
} 

