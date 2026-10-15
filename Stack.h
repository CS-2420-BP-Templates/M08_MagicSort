//
// Created by kmurphy on 10/13/2026.
//

#ifndef MAGICSORT_STACK_H
#define MAGICSORT_STACK_H
#include <string>

#endif //MAGICSORT_STACK_H
const int CAPACITY = 4;

enum class Color {
    Red,
    Blue,
    Green,
    EMPTY_COLOR = -1
};

std::string colorName(Color color) ;

class Stack {
private:
    Color items[CAPACITY];
    int count = 0;

public:

    bool push(const Color &color) ;

    Color pop() ;

    Color top() const;

    bool empty() const;

    bool full() const ;

    std::string operator[](int index) const ;

    bool isComplete() const;
};






