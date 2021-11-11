#ifndef WINDOW_PROPS_HPP
#define WINDOW_PROPS_HPP

#include "../common/Alias.hpp"
#include "WindowCursorState.hpp"
#include "WindowDisplayState.hpp"

namespace re
{
    struct  WindowProps
    {
        PSTR title                       = "Instagram";
        UI32 width                       = 800;
        UI32 height                      = 600;
        WindowCursor cursor              = WindowCursor::ARROW;
        WindowCursorState cursor_state   = WindowCursorState::NORMAL;
        WindowDisplayState display_state = WindowDisplayState::NOMRAL;
    };
}

#endif