//
// Created by Paulus on 25.02.2023.
//
#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <conio.h>
#include <cstdio>
#include <list>
#include <iterator>
#include <conio.h>
#include "../Util/Util.h"

class Console
{
private:

    /// <summary>
    /// Possible symbol selection to play with
    /// </summary>
    std::list<char> characters =
            {
                    'X',
                    '@',
                    '?',
                    '$'
            };

public:

    /// <summary>
    /// Print option to select which player should start the game
    /// </summary>
    /// <returns></returns>
    bool getStartPlayer();

    /// <summary>
    /// Method to call character selection in console
    /// </summary>
    void chooseYourCharacter();

    /// <summary>
    /// Get coordination from humans input
    /// </summary>
    /// <returns></returns>
    Util::Position getPositionValue();

    /// <summary>
    /// Print the result of the game in console
    /// </summary>
    /// <param name="nEvaluation"></param>
    void printEvaluation(Util::evaluation nEvaluation);


};

#endif