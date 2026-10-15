

#include <iostream>
#include <sstream>

#include <stdexcept>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// #include "MagicSort.cpp"




#include "../MagicSort.h"

using namespace std;



// -------------------- push() --------------------

TEST_CASE("Push adds a color to the stack", "[Stack][push]") {
    Stack stack;

    REQUIRE(stack.push(Color::Red));
    REQUIRE(stack.top() == Color::Red);
    REQUIRE_FALSE(stack.empty());
}

TEST_CASE("Push can fill the stack to capacity", "[Stack][push]") {
    Stack stack;

    REQUIRE(stack.push(Color::Red));
    REQUIRE(stack.push(Color::Blue));
    REQUIRE(stack.push(Color::Green));
    REQUIRE(stack.push(Color::Red));

    REQUIRE(stack.full());
    REQUIRE(stack.top() == Color::Red);
}

TEST_CASE("Push fails when the stack is full", "[Stack][push]") {
    Stack stack;

    stack.push(Color::Red);
    stack.push(Color::Blue);
    stack.push(Color::Green);
    stack.push(Color::Red);

    REQUIRE_FALSE(stack.push(Color::Blue));

    // The failed push should not change the stack.
    REQUIRE(stack.full());
    REQUIRE(stack.top() == Color::Red);
}

// -------------------- pop() --------------------

TEST_CASE("Pop removes and returns the top color", "[Stack][pop]") {
    Stack stack;

    stack.push(Color::Red);
    stack.push(Color::Blue);

    REQUIRE(stack.pop() == Color::Blue);
    REQUIRE(stack.top() == Color::Red);
}

TEST_CASE("Pop removes the final item", "[Stack][pop]") {
    Stack stack;
    stack.push(Color::Green);

    REQUIRE(stack.pop() == Color::Green);
    REQUIRE(stack.empty());
    REQUIRE_FALSE(stack.full());
}

TEST_CASE("Pop throws when the stack is empty", "[Stack][pop]") {
    Stack stack;

    REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
}

// -------------------- top() --------------------

TEST_CASE("Top returns the most recently pushed color",
          "[Stack][top]") {
    Stack stack;

    stack.push(Color::Red);
    stack.push(Color::Blue);
    stack.push(Color::Green);

    REQUIRE(stack.top() == Color::Green);

    // Calling top should not remove the item.
    REQUIRE(stack.top() == Color::Green);
    REQUIRE_FALSE(stack.empty());
}

TEST_CASE("Top returns the empty color when the stack is empty",
          "[Stack][top]") {
    Stack stack;

    REQUIRE(stack.top() == Color::EMPTY_COLOR);
}

// -------------------- empty() --------------------

TEST_CASE("Empty identifies an empty stack", "[Stack][empty]") {
    Stack stack;

    REQUIRE(stack.empty());

    stack.push(Color::Red);
    REQUIRE_FALSE(stack.empty());

    stack.pop();
    REQUIRE(stack.empty());
}

// -------------------- full() --------------------

TEST_CASE("Full identifies a full stack", "[Stack][full]") {
    Stack stack;

    REQUIRE_FALSE(stack.full());

    stack.push(Color::Red);
    stack.push(Color::Blue);
    stack.push(Color::Green);
    REQUIRE_FALSE(stack.full());

    stack.push(Color::Red);
    REQUIRE(stack.full());

    stack.pop();
    REQUIRE_FALSE(stack.full());
}

// -------------------- isComplete() --------------------

TEST_CASE("An empty stack is complete", "[Stack][isComplete]") {
    Stack stack;

    REQUIRE(stack.isComplete());
}

TEST_CASE("A partially filled stack of one color is not complete",
          "[Stack][isComplete]") {
    Stack stack;

    stack.push(Color::Red);
    stack.push(Color::Red);

    REQUIRE_FALSE(stack.isComplete());
}

TEST_CASE("A full stack of one color is complete",
          "[Stack][isComplete]") {
    Stack stack;

    stack.push(Color::Red);
    stack.push(Color::Red);
    stack.push(Color::Red);
    stack.push(Color::Red);

    REQUIRE(stack.isComplete());
}

TEST_CASE("A full stack with different colors is not complete",
          "[Stack][isComplete]") {
    Stack stack;

    stack.push(Color::Red);
    stack.push(Color::Red);
    stack.push(Color::Red);
    stack.push(Color::Blue);

    REQUIRE_FALSE(stack.isComplete());
}

TEST_CASE("A partially filled stack with different colors is not complete",
          "[Stack][isComplete]") {
    Stack stack;

    stack.push(Color::Green);
    stack.push(Color::Green);
    stack.push(Color::Blue);

    REQUIRE_FALSE(stack.isComplete());
}


// -------------------- isValidPour() --------------------

TEST_CASE("An empty destination is a valid pour",
          "[MagicSort][isValidPour]") {
    MagicSort game;

    REQUIRE(game.isValidPour(0, 3));
    REQUIRE(game.isValidPour(0, 4));
}

TEST_CASE("Pouring onto a different color is invalid",
          "[MagicSort][isValidPour]") {
    MagicSort game;

    // Bottle 1 has Red on top; Bottle 2 has Blue on top.
    REQUIRE_FALSE(game.isValidPour(0, 1));
    REQUIRE_FALSE(game.isValidPour(0, 2));
}

TEST_CASE("Pouring into a bottle with a matching top color is valid",
          "[MagicSort][isValidPour]") {
    MagicSort game;

    // Move Red from Bottle 0 to empty Bottle 3.
    game.pour(0, 3);

    // Bottle 0 now has Blue on top, matching Bottle 1.
    
    REQUIRE(game.isValidPour(1, 0));
}

TEST_CASE("Pouring from an empty bottle is invalid",
          "[MagicSort][isValidPour]") {
    MagicSort game;

    REQUIRE_FALSE(game.isValidPour(3, 0));
    REQUIRE_FALSE(game.isValidPour(3, 1));
}

TEST_CASE("Pouring into a full bottle is invalid",
          "[MagicSort][isValidPour]") {
    MagicSort game;

    // Both bottles start full.
    REQUIRE_FALSE(game.isValidPour(0, 1));
    REQUIRE_FALSE(game.isValidPour(1, 0));
}

TEST_CASE("Pouring into the same bottle is invalid",
          "[MagicSort][isValidPour]") {
    MagicSort game;

    for (int bottle = 0; bottle < 5; bottle++) {
        REQUIRE_FALSE(game.isValidPour(bottle, bottle));
    }
}

TEST_CASE("Bottle numbers outside the valid range are invalid",
          "[MagicSort][isValidPour]") {
    MagicSort game;

    REQUIRE_FALSE(game.isValidPour(-1, 1));
    REQUIRE_FALSE(game.isValidPour(1, -1));
    REQUIRE_FALSE(game.isValidPour(5, 1));
    REQUIRE_FALSE(game.isValidPour(1, 5));
}

// -------------------- pour() --------------------

TEST_CASE("Pour moves the top color to the destination",
          "[MagicSort][pour]") {
    MagicSort game;

    game.pour(0, 3);

    // Bottle 1 originally had Red on top.
    // Bottle 4 should now have Red on top.
    REQUIRE(game.isValidPour(0, 3) == false);
    REQUIRE(game.checkWin() == false);
}

TEST_CASE("Pour removes one color from the source",
          "[MagicSort][pour]") {
    MagicSort game;

    game.pour(0, 3);

    // Bottle 0 originally contained four units.
    // Bottle 3 originally contained zero units.
    // Verify the result through the public pour behavior.
    REQUIRE(game.isValidPour(0, 3) == false);
    REQUIRE(game.isValidPour(3, 4));
}

TEST_CASE("Pour can move a color onto a matching color",
          "[MagicSort][pour]") {
    MagicSort game;

    // Bottle 0: move Red to Bottle 3.
    game.pour(0, 3);

    // Bottle 0 now has Blue on top.
    // Move Blue from Bottle 1 to Bottle 4 to free space.
    game.pour(1, 4);

    // Bottle 0's Blue can now be placed on Bottle 1's Blue.
    REQUIRE(game.isValidPour(1, 3));

    game.pour(1, 3);

    REQUIRE_FALSE(game.checkWin());
}

// -------------------- checkWin() --------------------

TEST_CASE("The initial puzzle is not solved",
          "[MagicSort][checkWin]") {
    MagicSort game;

    REQUIRE_FALSE(game.checkWin());
}

TEST_CASE("The game is won when all nonempty bottles are sorted",
          "[MagicSort][checkWin]") {
    MagicSort game;

    // Solve the fixed starting puzzle using legal moves.
    const int moves[][2] = {
        {0, 3},
        {0, 4},
        {0, 3},
        {0, 4},
        {1, 4},
        {1, 3},
        {1, 4},
        {2, 0},
        {2, 3},
        {0, 2},
        {1, 2}
    };

    for (const auto& move : moves) {
        REQUIRE(game.isValidPour(move[0], move[1]));
        game.pour(move[0], move[1]);
    }

    REQUIRE(game.checkWin());
}
