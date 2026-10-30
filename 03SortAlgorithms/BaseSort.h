//
// Created by kmurphy on 10/27/2026.
//

#ifndef BASESORT_H
#define BASESORT_H

#include <random>
#include <string>
#include <chrono>


using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename T>
class BaseSort {
public:
    BaseSort(const string& sortName, const unsigned int capacity);
    ~BaseSort();
    string getName() { return sortName; }
    void loadRandomValues();
    void printValues() const;
    void verifySort() const;

    virtual void runSort() = 0; // Pure virtual function.
    // It makes the class **abstract**.  In other words,
    // nothing can instantiate an object of this class.
protected:
    string sortName;
    T* arr{ nullptr };
    unsigned int capacity{ 0 };
private:

};

template <typename T>
BaseSort<T>::BaseSort(const string& sortName, const unsigned int capacity) {
    this->sortName = sortName;
    this->capacity = capacity;
    this->arr = new T[capacity];
}
template <typename T>
BaseSort<T>::~BaseSort() {
    delete[] arr;
}

template <typename T>
void BaseSort<T>::loadRandomValues() {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<unsigned int> distrib(0, 0xffffffff);

    for (unsigned int i = 0; i < capacity; ++i) {
        this->arr[i] = distrib(gen);
    }
}

template <typename T>
void BaseSort<T>::printValues() const {
    if (capacity < 50) {
        for (unsigned int i = 0; i < capacity; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void BaseSort<T>::verifySort() const {
    for (unsigned int i = 0; i < capacity - 1; i++) {
        if (arr[i + 1] < arr[i]) {
            cout << "Not sorted at index: " << (i + 1) << endl;
            return;
        }
    }
    cout << "Sorted!" << endl;
}

#endif //BASESORT_H
