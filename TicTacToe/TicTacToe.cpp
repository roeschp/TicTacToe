//
// Created by Paulus on 25.02.2023.
//

#include "TicTacToe.h"

#define STANDARD_SIZE 3

/// <summary>
/// Create a square field N x N with the value Undefined
/// </summary>
/// <param name="nSize"></param>
TicTacToe::TicTacToe()
{
    size = STANDARD_SIZE;

    for (int indexX = 0; indexX < size; indexX++)
    {
        field.push_back(std::vector<Util::state>());

        for (int indexY = 0; indexY < size; indexY++)
        {
            field[indexX].push_back(Util::state::Undefined);
        }
    }
}

/// <summary>
/// Place the state by coordination inside the twodimensional vector
/// </summary>
/// <param name="nPosX"></param>
/// <param name="nPosY"></param>
/// <param name="nState"></param>
/// <returns></returns>
bool TicTacToe::setState(int nPosX, int nPosY, Util::state nState)
{
    if (nPosX >= 0 && nPosY >= 0 && nPosX <= size && nPosY <= size)
    {
        field[nPosY][nPosX] = nState;
        return true;
    }

    return false;
}

/// <summary>
/// Return the size of the N x N playground
/// </summary>
/// <returns></returns>
int TicTacToe::getSize()
{
    return size;
}

/// <summary>
/// Return current state of one box by coordination
/// </summary>
/// <param name="nPosX"></param>
/// <param name="nPosY"></param>
/// <returns></returns>
Util::state TicTacToe::getState(int nPosX, int nPosY)
{
    if (nPosX >= 0 && nPosY >= 0 && nPosX <= size && nPosY <= size)
    {
        return field[nPosY][nPosX];
    }
    else
    {
        // added new return - might not work with this line
        return Util::state::Undefined;
    }
}

/// <summary>
/// Iterate through the field and check if one player has won
/// </summary>
/// <param name="nState"></param>
/// <returns></returns>
bool TicTacToe::getFinishState(Util::state nState)
{
    for (int y = 0; y < size; y++)
    {
        if (field[y][0] == nState && field[y][1] == nState && field[y][2] == nState)
        {
            return true;
        }
    }
    for (int x = 0; x < size; x++)
    {
        if (field[0][x] == nState && field[1][x] == nState && field[2][x] == nState)
        {
            return true;
        }
    }

    bool DiaMatchRight = true;
    bool DiaMatchLeft = true;

    for (int index = 0; index < size; index++)
    {
        if (field[size - index - 1][index] != nState)
        {
            DiaMatchRight = false;
        }
        if (field[index][index] != nState)
        {
            DiaMatchLeft = false;
        }
    }

    if (DiaMatchRight || DiaMatchLeft)
    {
        return true;
    }

    return false;
}

/// <summary>
/// Iterate through field and check if one box is not set
/// </summary>
/// <returns></returns>
bool TicTacToe::checkFieldCompleted()
{
    for (auto row : field)
    {
        for (auto element : row)
        {
            if (element == Util::state::Undefined)
            {
                return false;
            }
        }
    }

    return true;
}

/// <summary>
/// Print current field to console
/// </summary>
/// <param name="os"></param>
/// <param name="ttt"></param>
/// <returns></returns>
std::ostream& operator<< (std::ostream& os, const TicTacToe& ttt)
{
    int cCount = 0;
    int rCount = 0;

    os << CYAN << "\tX0\t" << "\tX1\t" << "\tX2\t" << RESET << std::endl;
    //os << CYAN << "|" << std::endl << "v" << std::endl << "Y" << RESET << std::endl;

    for (auto column : ttt.field)
    {
        os << "\t\t|\t\t|\t\t" << std::endl;
        os << CYAN << "Y" << cCount << RESET;
        for (auto row : column)
        {
            os << "\t";

            auto symbol = Util::symbol.find(row)->second;

            if (row == Util::state::Human)
                os << GREEN << symbol << RESET;

            else if (row == Util::state::Machine)
                os << RED << symbol << RESET;

            else
                os << symbol;

            if(rCount <= 1)
                std::cout << "\t|";

            rCount++;
        }
        rCount = 0;

        os << "\n";

        if(cCount <= 1)
            os << "________________|_______________|________________\n";


        cCount++;
    }

    os << "\t\t|\t\t|\t\t" << std::endl;

    return os;
}