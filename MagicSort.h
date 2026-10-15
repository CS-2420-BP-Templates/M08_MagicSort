//
// Created by kmurphy on 10/13/2026.
//

#ifndef MAGICSORT_MAGICSORT_H
#define MAGICSORT_MAGICSORT_H
#include <vector>
#include <iostream>
#include "Stack.h"

class MagicSort {
private:
    std::vector<Stack> bottles;

public:
    MagicSort() ;

    void setupGame() ;

    void displayBottles() const ;
    bool isValidPour(int source, int destination);
    void pour(int source, int destination) ;

    bool checkWin() const ;

    void play() ;
};


#endif //MAGICSORT_MAGICSORT_H
