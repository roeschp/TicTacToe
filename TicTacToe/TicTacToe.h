//
// Created by Paulus on 25.02.2023.
//

#pragma once
#include <iostream>
#include <vector>

#include "../Util/Util.h"
#include "../Playground/Playground.h"

class TicTacToe : public Playground
{
private:
    int size = 0;
    std::vector<std::vector<Util::state>> field;

public:
    /// <summary>
    /// Constructor for the Tic Tac Toe function
    /// </summary>
    /// <param name="nSize"></param>
    TicTacToe();

    /// <summary>
    /// Set one box with a value
    /// </summary>
    /// <param name="nPosX"></param>
    /// <param name="nPosY"></param>
    /// <param name="nState"></param>
    /// <returns></returns>
    bool setState(int nPosX, int nPosY, Util::state nState);

    /// <summary>
    /// Return the size from the field
    /// </summary>
    /// <returns></returns>
    int getSize();

    /// <summary>
    /// Return the state of a box
    /// </summary>
    /// <param name="nPosX"></param>
    /// <param name="nPosY"></param>
    /// <returns></returns>
    Util::state getState(int nPosX, int nPosY);

    /// <summary>
    /// Return for one player whether this is finished
    /// </summary>
    /// <param name="nState"></param>
    /// <returns></returns>
    bool getFinishState(Util::state nState);

    /// <summary>
    /// Return true when field is complete
    /// </summary>
    /// <returns></returns>
    bool checkFieldCompleted();

    friend std::ostream& operator<< (std::ostream& os, const TicTacToe& ttt);
};

