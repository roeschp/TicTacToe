//
// Created by Paulus on 25.02.2023.
//

#include "../Util/Util.h"

/// <summary>
/// Character Look-Up table for all states
/// </summary>
Util::Symbols Util::symbol =
        {
                { Util::state::Undefined, '-'},
                { Util::state::Human, 'X'},
                { Util::state::Machine, 'O'}
        };
