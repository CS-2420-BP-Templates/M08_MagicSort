//
// Created by kmurphy on 10/13/2026.
//

#include "Stack.h"
#include <iostream>

std::string colorName(Color color) {
    switch (color) {
        case Color::Red:   return "Red";
        case Color::Blue:  return "Blue";
        case Color::Green: return "Green";
    }
    return "";
}

/*
 * Push the given parameter onto the stack
 */
bool Stack::push(const Color &color) {
    //TODO
    if (count == CAPACITY) {
        return false;
    }

    items[count] = color;
    count++;
    return true;
}

/*
 * Remove and return the top of the stack
 *  Or throw and out_of_range exception
 */
Color Stack::pop() {
    //TODO
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }

    count--;
    return items[count];
}

/*
 * Return the top of the stack
 * Or an empty color if the stack is empty
 */
Color Stack::top() const {
    //TODO
    if (empty()) {
        return Color::EMPTY_COLOR;;
    }

    return items[count-1];
}

/*
 * Return true of the stack is empty and false otherwise
 */
bool Stack::empty() const {
    //TODO
    return count == 0;
}

/*
 * Return true of the stack is full and false otherwise
 */
bool Stack::full() const {
    //TODO
    return count == CAPACITY;
}

/*
 * Return the color name at a given position in the stack (for the display)
 * Or an empty string if the position is empty
 */
std::string Stack::operator[](int index) const {
    if (index >= count || index < 0) {
        return "";
    }
    return colorName(items[index]);
}

/*
 * Returns true if any of the following conditions are true
 * - stack is empty
 * - full and of all the same color
 */
bool Stack::isComplete() const {
    //TODO
    if (empty()) {
        return true;
    }

    for (int i = 1; i < count; i++) {
        if (items[i] != items[0]) {
            return false;
        }
    }

    return full();
}