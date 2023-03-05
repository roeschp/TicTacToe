//
// Created by Paulus on 25.02.2023.
//

#include "Playground.h"

std::ostream& operator<<(std::ostream& os, const Playground& pg)
{
    for (auto column : pg.field)
    {
        for (auto row : column)
        {
            os << Util::symbol.find(row)->second << " ";
        }
        os << "\n";
    }

    return os;
}
