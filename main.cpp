#include <iostream>
#include "Util/Util.h"
#include "Playground/Playground.h"
#include "MiniMax/MiniMax.h"
#include "TicTacToe/TicTacToe.h"
#include "Console/Console.h"

// Count of steps for machine to calculate moves
#define LEVEL_EASY 0
#define LEVEL_STANDARD 1
#define LEVEL_HARD 5

int main()
{
    // Set other values to change the difficulty
    int depth = LEVEL_EASY;

    // Generate objects from class
    TicTacToe field;
    Minimax minmax;
    Console console;
    Util::Position humanPos;
    Util::Position machinePos;

    console.chooseYourCharacter();

    // If machine is selected to start make first move
    if (console.getStartPlayer() == 0)
    {
        machinePos = minmax.getMachineMove(field, depth);
        field.setState(machinePos.X, machinePos.Y, Util::state::Machine);
    }

    // Loop until game is finished
    while (minmax.checkOption(field) == Util::evaluation::Incomplete)
    {
        system("cls");
        std::cout << field;

        // Get move from human
        humanPos = console.getPositionValue();

        if (humanPos.X >= field.getSize() || humanPos.Y >= field.getSize())
            continue;

        if (field.getState(humanPos.X, humanPos.Y) != Util::state::Undefined)
            continue;

        field.setState(humanPos.X, humanPos.Y, Util::state::Human);

        // Check whether game is finished with the latest move
        if (minmax.checkOption(field) != Util::evaluation::Incomplete)
            break;

        // Calculate next machine move
        machinePos = minmax.getMachineMove(field, depth);

        field.setState(machinePos.X, machinePos.Y, Util::state::Machine);

        // Check whether game is finished with the latest move
        if (minmax.checkOption(field) != Util::evaluation::Incomplete)
        {
            system("cls");
            std::cout << field;
            break;
        }
    }

    // Print evaluation to console
    system("cls");
    std::cout << field;
    console.printEvaluation(minmax.checkOption(field));
}