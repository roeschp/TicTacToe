//
// Created by Paulus on 25.02.2023.
//
#include "Console.h"
#include <limits>
#include <chrono>
#include <thread>

#define DISPLAY_TIME 1500

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27
#define KB_ENTER 13

#define CLEAR_CLS_LINE "\x1b[2K"
#define MOVE_CRS_UP "\x1b[1A"
#define LAST_LINES 3

/// <summary>
/// Loop input validation to get 0 or 1, for the player who can make the first move
/// Print out the play who start the game and return the value
/// </summary>
/// <returns></returns>
bool Console::getStartPlayer()
{
    bool input = 0;

    std::cout << "Which player should start" << std::endl;
    std::cout << "(0) Machine" << std::endl << "(1) You" << std::endl << ">> ";

    while (!(std::cin >> input) || input < 0 || input > 1)
    {
        system("cls");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << RED << R"(Wrong input pls enter '0' or '1')" << RESET << std::endl;
        std::cout << "Which player should start" << std::endl;
        std::cout << "(0) Machine" << std::endl << "(1) You" << std::endl << ">> ";
    }

    if (input)
    {
        std::cout << CYAN << "You will make the first move" << RESET << std::endl;
    }
    else
    {
        std::cout << CYAN << "Machine will start the game" << RESET << std::endl;
    }

    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::milliseconds(DISPLAY_TIME));

    return input;
}

/// <summary>
/// Print an input field to select the character by arrow keys
/// Loop through the list to get all characters until ENTER or ESC is pressed
/// When selected a value this character will be saved inside the list for the human player
/// </summary>
void Console::chooseYourCharacter()
{
    std::list<char>::iterator iter = characters.begin();
    std::cout << RESET << "\tTIC TAC TOE" << std::endl << GREEN << "YOU\t" << RESET << "\tvs.\t" << RED "\tMACHINE" << RESET << std::endl;

    std::cout << std::endl << "Choose your character!" << std::endl;
    std::cout << "\t" << "<  " << *iter << "  >";
    int KB_code = 0;

    while (KB_code != KB_ESCAPE && KB_code != KB_ENTER)
    {
        if (_kbhit())
        {
            KB_code = _getch();

            switch (KB_code)
            {
                case KB_LEFT:

                    if (iter == characters.begin())
                    {
                        iter = characters.end();
                    }

                    iter = std::next(iter, -1);

                    break;

                case KB_RIGHT:

                    iter = std::next(iter, 1);

                    if (iter == characters.end())
                    {
                        iter = characters.begin();
                    }

                    break;
            }

            std::cout << CLEAR_CLS_LINE << "\r";
            std::cout << "\t" << "<  " << *iter << "  >";
        }
    }

    system("cls");

    auto charIter = Util::symbol.find(Util::state::Human);

    if (charIter != Util::symbol.end())
    {
        charIter->second = *iter;
    }
}

/// <summary>
/// Get input from human and check if it is valid.
/// Loop through until a correct input is made
/// </summary>
/// <returns></returns>
Util::Position Console::getPositionValue()
{
    Util::Position nPosition = { 0 };
    int xInput = 0;
    int yInput = 0;

    std::cout << "Your X Value: " << std::endl << ">> ";

    while (!(std::cin >> nPosition.X) || nPosition.X < 0 || nPosition.X > 2)
    {
        for (int i = 1; i < LAST_LINES; i++) {
            std::cout << MOVE_CRS_UP << CLEAR_CLS_LINE << "\r"; // Delete the entire line
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << RED << "Wrong input pls enter between \'0\' and \'2\'" << RESET << std::endl;
        std::cout << "Your X Value: " << std::endl << ">> ";
    }

    std::cout << "Your Y Value: " << std::endl << ">> ";

    while (!(std::cin >> nPosition.Y) || nPosition.Y < 0 || nPosition.Y > 2)
    {
        for (int i = 1; i < LAST_LINES; i++) {
            std::cout << MOVE_CRS_UP << CLEAR_CLS_LINE << "\r"; // Delete the entire line
        }
        std::cout << CLEAR_CLS_LINE << "\r";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << RED << "Wrong input pls enter between \'0\' and \'2\'" << RESET << std::endl;
        std::cout << "Your Y Value: " << std::endl << ">> ";
    }

    return nPosition;
}

/// <summary>
/// Print the result of the game in different colors to console, depending on the parameter
/// </summary>
/// <param name="nResult"></param>
void Console::printEvaluation(Util::evaluation nResult)
{
    std::cout << "\t\t" << "Game is finished!" << std::endl;

    switch (nResult)
    {
        case Util::evaluation::MachineWin:

            std::cout << RED << "\t\t" << "Machine Win!" << RESET << std::endl;
            break;

        case Util::evaluation::HumanWin:

            std::cout << GREEN << "\t\t" << "You Win!" << RESET << std::endl;
            break;

        case Util::evaluation::Draw:

            std::cout << CYAN << "\t\t" << "Draw!" << RESET << std::endl;
            break;

        default:

            std::cout << RED << "Something failed when calculating the evaluation!" << RESET << std::endl;
    }
}
