//
// Created by Paulus on 25.02.2023.
//

#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <iostream>
#include <vector>

#include "../Util/Util.h"


class Playground
{
private:

    int size = 99999;

public:

    std::vector<std::vector<Util::state>> field;

    /// <summary>
    /// Set a defined state by coordination
    /// </summary>
    /// <param name="nPosX"></param>
    /// <param name="nPosY"></param>
    /// <param name="nState"></param>
    /// <returns></returns>
    virtual bool setState(int nPosX, int nPosY, Util::state nState)
    {
        return false;
    }


    /// <summary>
    /// Return the N x N size for the playground
    /// </summary>
    /// <returns></returns>
    virtual int getSize()
    {
        return size;
    }

    /// <summary>
    /// Return the state by coordination
    /// </summary>
    /// <param name="nPosX"></param>
    /// <param name="nPosY"></param>
    /// <returns></returns>
    virtual Util::state getState(int nPosX, int nPosY)
    {
        return Util::state::Undefined;
    }


    /// <summary>
    /// Return whether one player gained
    /// </summary>
    /// <param name="nState"></param>
    /// <returns></returns>
    virtual bool getFinishState(Util::state nState)
    {
        return false;
    }

    /// <summary>
    /// Return status if the game is done by complete field
    /// </summary>
    /// <returns></returns>
    virtual bool checkFieldCompleted()
    {
        return false;
    }
};

#endif