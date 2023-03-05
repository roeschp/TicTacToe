//
// Created by Paulus on 25.02.2023.
//

#ifndef MINIMAX_H
#define MINIMAX_H

#include <iostream>

#include "../Util/Util.h"
#include "../Playground/Playground.h"

class Minimax
{

private:
    /// <summary>
    /// Return the highest value for each move in every undefined box
    /// </summary>
    /// <param name="field"></param>
    /// <returns></returns>
    int maxRule(Playground& field, int restDepth, int alpha, int beta);

    /// <summary>
    /// Return the lowest value for each move in every undefined box
    /// </summary>
    /// <param name="field"></param>
    /// <returns></returns>
    int minRule(Playground& field, int restDepth, int alpha, int beta);

public:
    /// <summary>
    /// Return the evalution whether one player finished
    /// </summary>
    Util::evaluation checkOption(Playground& field);

    /// <summary>
    /// Start the Minimax algorithm and return the next move
    /// </summary>
    Util::Position getMachineMove(Playground& field, int depth);
};

#endif