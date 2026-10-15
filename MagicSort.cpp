//
// Created by kmurphy on 10/13/2026.
//

#include "MagicSort.h"
#include <iomanip>

 MagicSort::MagicSort() {
        setupGame();
    }

/**
 *  Sets up the following magic sort scenario
 *      _________   _________   _________   _________   _________
 *      | Red   |   | Blue  |   | Green |   |       |   |       |
 *      | Blue  |   | Red   |   | Red   |   |       |   |       |
 *      | Red   |   | Blue  |   | Green |   |       |   |       |
 *      | Blue  |   | Green |   | Green |   |       |   |       |
 *      |_______|   |_______|   |_______|   |_______|   |_______|
 *      Bottle 1    Bottle 2    Bottle 3    Bottle 4    Bottle 5
 */
void MagicSort::setupGame() {
        bottles.clear();

        // Create five bottles.
        for (int i = 0; i < 5; i++) {
            bottles.push_back(Stack());
        }

        // Bottle 1, top to bottom:
        // Red, Blue, Red, Blue
        bottles[0].push(Color::Blue);
        bottles[0].push(Color::Red);
        bottles[0].push(Color::Blue);
        bottles[0].push(Color::Red);

        // Bottle 2, top to bottom:
        // Blue, Red, Blue, Green
        bottles[1].push(Color::Green);
        bottles[1].push(Color::Blue);
        bottles[1].push(Color::Red);
        bottles[1].push(Color::Blue);

        // Bottle 3, top to bottom:
        // Green, Red, Green, Green
        bottles[2].push(Color::Green);
        bottles[2].push(Color::Green);
        bottles[2].push(Color::Red);
        bottles[2].push(Color::Green);

        // Bottles 4 and 5 start empty.
    }
    /*
     *  Display's the bottles all the bottles.
     */
    void MagicSort::displayBottles() const {
     std::cout << "\n==================== MAGIC SORT =========================\n";

     std::cout << "_________   _________   _________   _________   _________" << std::endl;
     for (int r = CAPACITY-1; r >= 0; r--) {
         std::cout << std::left;
         for (int i = 0; i < bottles.size(); i++) {
                std::cout << std::setw(7) <<  "| " + bottles[i][r] << std::setw(5) << " |";
         }
         std::cout << std::endl;

     }
     std::cout << "|_______|   |_______|   |_______|   |_______|   |_______|" << std::endl;
     std::cout << "Bottle 1    Bottle 2    Bottle 3    Bottle 4    Bottle 5" << std::endl;
     std::cout << "=========================================================\n";
    }
    /*
     *  Given a source and destination number Determine if it is a valid pour with the following rules
     *  - Source and Destination must be in bounds of the array
     *  - Source must not be the same bottle as the destination
     *  - Destination must not be full and source must not be empty
     *  - source and destination must match or destination must be empty
     */
    bool MagicSort::isValidPour(int source, int destination) {
     //TODO
         if (source < 0 || source >= bottles.size() || destination < 0 || destination >= bottles.size()) {
             return false;
         }
         else if (source == destination) {
             return false;
         }
         else if (bottles[source].empty()) {
             return false;
         }
         else if (bottles[destination].full()) {
             return false;
         }
         else if (bottles[destination].top() == bottles[source].top() || bottles[destination].top() == Color::EMPTY_COLOR) {
             return true;
         }
         return false;
    }

    /*
     * Pop the value of the source stack and push it onto the destination stack
     */
    void MagicSort::pour(int source, int destination) {
     //TODO

        Color pouringColor = bottles[source].top();
        bottles[source].pop();
        bottles[destination].push(pouringColor);

    }

    /*
     * If every bottle is a single color, return true, if not return empty
     */
    bool MagicSort::checkWin() const {
     //TODO
        for (const Stack& bottle : bottles) {
            if (!bottle.isComplete()) {
                return false;
            }
        }

        return true;
    }

    /*
     * Create a game loop to iterate till checkWin() is true
     * Have the user enter the source and destination
     * If they are valid according to the rules, pour the source into the destination container
     * Check to see if the user has won
     */
    void MagicSort::play() {
     //TODO
        std::cout << "Welcome to Magic Sort!\n";
        std::cout << "Sort the liquid so each nonempty bottle "
             << "contains only one color.\n";
       std:: cout << "Each bottle holds up to " << CAPACITY
             << " units.\n";

        while (true) {
            displayBottles();

            if (checkWin()) {
                std::cout << "\nCongratulations! You sorted the bottles!\n";
                return;
            }

            int source;
            std::cout << "\nSource bottle (1-5, or 0 to quit): ";

            std::cin >> source;

            if (source == 0) {
               std:: cout << "Thanks for playing!\n";
                return;
            }
            source --;

            int destination;
            std::cout << "Destination bottle (1-5): ";

            std::cin >> destination;
            destination --;
            if (isValidPour(source, destination)) {
                pour(source, destination);
            }


            if (checkWin()) {
                displayBottles();
                std::cout << "\nCongratulations! You sorted the bottles!\n";
                return;
            }
        }
    }