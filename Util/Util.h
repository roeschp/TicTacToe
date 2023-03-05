//
// Created by Paulus on 25.02.2023.
//

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <map>

#define RED     "\033[31m"
#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"

class Util
{
public:

    /// <summary>
    /// State enumeration for two player game
    /// </summary>
    enum class state
    {
        Undefined = -1,
        Human = 2,
        Machine = 0
    };

    /// <summary>
    /// Evaluation enumeration for two player game
    /// </summary>
    enum class evaluation
    {
        Incomplete = -1,
        MachineWin = 0,
        Draw = 1,
        HumanWin = 2
    };

    /// <summary>
    /// Definition of coordination variable
    /// </summary>
    typedef struct Position
    {
        int X;
        int Y;
    };

    /// <summary>
    /// Definition for Look-Up Table output characters
    /// </summary>
    typedef std::map<state, char> Symbols;

    /// <summary>
    /// Look-Up Map for output characters
    /// </summary>
    static Symbols symbol;

};

#endif
