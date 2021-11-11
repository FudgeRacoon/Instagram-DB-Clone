#ifndef WINDOW_CURSOR_STATE
#define WINDOW_CURSOR_STATE

namespace re
{
    enum class WindowCursor
    {
        HAND,
        ARROW,
        IBEAM,
        CUSTOM,
        HRESIZE,
        VRESIZE,
        CROSSHAIR,
    };

    enum class WindowCursorState
    {
        NORMAL,
        HIDDEN,
        DISABLED
    };
}

#endif
