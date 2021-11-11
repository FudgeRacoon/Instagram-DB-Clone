#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <stdio.h>
#include <stdlib.h>

#include "glfw/glfw3.h"

#include "../common/Alias.hpp"
#include "../common/EngineAPI.hpp"

#include "WindowProps.hpp"

namespace re
{
    typedef GLFWwindow* WindowHandle;
    typedef GLFWcursor* CursorHandle;
}   

namespace re
{
    class Window
    {
    private:
        bool running = false;

    private:
        WindowProps props;
        WindowHandle window_handle = nullptr;
        CursorHandle cursor_handle = nullptr;

    private:
        Window() = default;
       ~Window() = default; 

    public:
        static Window* Create();
        static void Destroy(Window* window);

    public:
        void Init(const WindowProps& props);
        void Quit();

    public:
        PSTR GetTitle();
        UI32 GetWidth();
        UI32 GetHeight();
        WindowCursor GetCursor();
        WindowCursorState GetCursorState();
        WindowDisplayState GetDisplayState();

    public:
        WindowHandle GetWindowHandle();
        CursorHandle GetCursorHandle();
    
    public:
        void SetTitle(PSTR title);
        void SetWidth(UI32 width);
        void SetHeight(UI32 height);
        void SetCursor(WindowCursor cursor);
        void SetCursorState(WindowCursorState cursor_state);
        void SetDisplayState(WindowDisplayState display_state);
    
    public:
        bool IsRunning();
    };  
}

#endif