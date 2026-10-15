# MagicSort
## Description
In this lab, you will use your knowledge of stacks to build a simplified console version of a color-sorting puzzle game. You will practice using stack operations, working with a vector of objects, validating user actions, and determining when a puzzle has been solved.

## Background
Before starting, try playing Magic Sort to see how a color-sorting puzzle works.

In this type of game, you move colored liquid between bottles until each nonempty bottle contains only one color. The challenge is deciding which moves to make while following the rules.

For our C++ version, each bottle is represented by a stack. The top of the stack represents the top layer of liquid, so you can only access the top color using stack operations.

## Game Rules
Your program will use a fixed starting puzzle with five bottles. Each bottle can hold up to four units of liquid, and two bottles start empty.

The goal is to sort the colors so that every nonempty bottle contains only one color.

Follow these rules:


You may only remove liquid from the top of a bottle.
- You may pour into an empty bottle or a bottle whose top color matches the color being poured. 
- You cannot pour into a full bottle.
- You cannot pour from an empty bottle. 
- You cannot pour from a bottle into itself. 
- A bottle is considered complete when it is empty or full of a single color.

For this version of the game, each move transfers one unit of liquid.

## Required Class
Complete the designated TODO sections in the MagicSort class. You will implement the logic that validates moves, transfers colors between stacks, and checks whether the puzzle has been solved.

### Implement isValidPour()
Determine whether a move follows the game rules.

Your method should return true only when:
- Both bottle indices are valid. 
- The source and destination are different bottles. 
- The source bottle is not empty. 
- The destination bottle is not full. 
- The destination is empty or its top color matches the source's top color.

Return false if any of these conditions are not met.

### Implement the pour()
Move one unit of liquid from the source bottle to the destination bottle.

Use the stack operations you have already implemented. Remove the top color from the source stack and push that color onto the destination stack.

The method assumes the move has already been validated by isValidPour().

### Implement the checkWin()
Determine whether the puzzle has been solved.

Use the isComplete() method provided by the Stack class to check each bottle. Return true when every bottle is complete and false otherwise.


### main()
Write the code that allows a player to play Magic Sort.

Your main() function should:
- Create a MagicSort object to initialize the puzzle. 
- Display a welcome message and explain the goal of the game. 
- Repeatedly display the bottles and prompt the player for a source and destination bottle. 
- Allow the player to enter 0 to quit the game. 
- Convert the player's bottle numbers to the indices used by the class. 
- Call isValidPour() to determine whether the move is allowed. 
- If the move is valid, call pour() to perform it. Otherwise, display an appropriate message and allow the player to try again. 
- Call checkWin() to determine whether the puzzle has been solved. 
- Display a congratulatory message and end the game when the player wins.

Use a loop to continue playing until the player quits or solves the puzzle.

**Note: the display shows bottles 1-5:  You will need to adjust for the array at positions 0 - 4**

## Sample Run
```angular2html

```