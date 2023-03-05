# TicTacToe
Console application to play TicTacToe against the computer.
The machine uses the Minimax algorithm with 3 game modies.

# Minimax algorithm
This recursive algorithm is for choosing the next machine move and calculate the best possible move.

## Game modies
The modes are set in the code by defines and can be selected in the main.cpp.
Choose one level and set the depth in the main function. The integers represent the numbers of recursive calls for the minimax algorithm.
````
#define LEVEL_EASY 0
#define LEVEL_STANDARD 1
#define LEVEL_HARD 5

// Set other values to change the difficulty
int depth = LEVEL_EASY;
````
