//
// Created by Paulus on 25.02.2023.
//
#include "Minimax.h"

/// <summary>
/// Start Minimax algorithm with recursive method with minRule and maxRule to get best move
/// </summary>
/// <param name="field"></param>
/// <returns></returns>
Util::Position Minimax::getMachineMove(Playground& field, int depth)
{
    Util::Position position = { 0 };

    // Default some high values for Alpha-Beta-Pruning
    int beta = 999;
    int alpha = -999;

    int currentValue = 0;

    for (int posX = 0; posX < field.getSize(); posX++)
    {
        for (int posY = 0; posY < field.getSize(); posY++)
        {
            if (field.getState(posX, posY) == Util::state::Undefined)
            {
                field.setState(posX, posY, Util::state::Machine);
                currentValue = maxRule(field, depth, alpha, beta);

                if (currentValue < beta)
                {
                    // When the current value is lower than beta there is one good position for the machine
                    beta = currentValue;
                    position.X = posX;
                    position.Y = posY;
                }

                field.setState(posX, posY, Util::state::Undefined);
            }
        }
    }

    return position;
}

/// <summary>
/// Use callback from playground child to get status whether one player won
/// </summary>
/// <param name="field"></param>
/// <returns></returns>
Util::evaluation Minimax::checkOption(Playground& field)
{
    Util::evaluation player = Util::evaluation::MachineWin;

    for (int index = 0; index <= 1; index++)
    {
        if (field.getFinishState((Util::state)player))
        {
            return player;
        }

        player = Util::evaluation::HumanWin;
    }

    if (field.checkFieldCompleted() == false)
    {
        return Util::evaluation::Incomplete;
    }

    return Util::evaluation::Draw;
}

/// <summary>
/// Place status in each field and calculation whether one player won by compare max value
/// </summary>
/// <param name="field"></param>
/// <returns></returns>
int Minimax::maxRule(Playground& field, int restDepth, int alpha, int beta)
{
    if (checkOption(field) != Util::evaluation::Incomplete)
    {
        return (int)checkOption(field);
    }

    if (restDepth <= 0)
    {
        // Return draw so the computer can not decide if this branch is a good or a bad one
        return (int)Util::evaluation::Draw;
    }

    //int maximum = minVal;
    int currentValue = 0;

    // Iterate through all segments
    for (int posX = 0; posX < field.getSize(); posX++)
    {
        for (int posY = 0; posY < field.getSize(); posY++)
        {
            // If one box is not set start calculation
            if (field.getState(posX, posY) == Util::state::Undefined)
            {
                field.setState(posX, posY, Util::state::Human);
                currentValue = minRule(field, restDepth - 1, alpha, beta);

                if (currentValue > alpha)
                {
                    alpha = currentValue;
                }

                field.setState(posX, posY, Util::state::Undefined);

                if (alpha >= beta)
                {
                    // Return directly beta because this one is the best move for this branch
                    return beta;
                }
            }
        }
    }

    return alpha;
}

/// <summary>
/// Place status in each field and calculation whether one player won by compare min value
/// </summary>
/// <param name="field"></param>
/// <returns></returns>
int Minimax::minRule(Playground& field, int restDepth, int alpha, int beta)
{
    if (checkOption(field) != Util::evaluation::Incomplete)
    {
        return (int)checkOption(field);
    }

    if (restDepth <= 0)
    {
        // Return draw so the computer can not decide if this branch is a good or a bad one
        return (int)Util::evaluation::Draw;
    }

    int currentValue = 0;

    // Iterate through all segments
    for (int posX = 0; posX < field.getSize(); posX++)
    {
        for (int posY = 0; posY < field.getSize(); posY++)
        {
            // If one box is not set start calculation
            if (field.getState(posX, posY) == Util::state::Undefined)
            {
                field.setState(posX, posY, Util::state::Machine);
                currentValue = maxRule(field, restDepth - 1, alpha, beta);

                if (currentValue < beta)
                {
                    beta = currentValue;
                }

                field.setState(posX, posY, Util::state::Undefined);

                if (beta <= alpha)
                {
                    // Return directly alpha because this one is the best move for this branch
                    return alpha;
                }
            }
        }
    }

    return beta;
}