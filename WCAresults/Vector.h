#include <iostream>
namespace my {


    template <typename type>
    class Vector {
    public:
        Vector(int maxCapacity);
        ~Vector();
        bool isEmpty();
        bool isFull();
        int  Search(type);
        void DynamicExpansion();
        void Pushback(type);
    private:
        int maxCapacity;
        type* array;
        int listSize;
    };

    template <typename type>
    Vector<type>::Vector(int maxCapacity)
        :
        maxCapacity(maxCapacity)
    {
        array = new type[maxCapacity];
        listSize = 0;
    }

    template <typename type>
    Vector<type>::~Vector()
    {
        delete[] array;
    }

    template <typename type>
    bool Vector<type>::isEmpty() {
        if (listSize == 0) { return true; }
        else return false;
    }

    template <typename type>
    bool Vector<type>::isFull() {
        if (listSize == maxCapacity) {
            return true;
        }
        else return false;
    }

    template <typename type>
    int Vector<type>::Search(type val) {
        for (int i = 0; i < listSize; i++) {
            if (array[i] == val) {
                return i;
            }
            else { return -1; }
        }
    }

    template <typename type>
    void Vector<type>::DynamicExpansion() {
        int* temp;
        temp = array;
        array = new type[maxCapacity + 10];
        for (int i = 0; i < maxCapacity; i++) {
            array[i] = temp[i];
        }
        maxCapacity = maxCapacity + 10;
        delete temp;

    }

    template <typename type>
    void Vector<type>::Pushback(type val) {
        if (Search(val) >= 0) {
            std::cout << "Value is already in the list" << std::endl;
        }
        else {
            array[listSize++] = val;
        }
        if (isFull() == true) {
            DynamicExpansion();
        }
    }



}

