#include "core/Window.hpp"
using namespace re;

Window* Window::Create()
{
    return new Window();
}
void Window::Destroy(Window* window)
{
    if(window->window_handle)
        glfwDestroyWindow(window->window_handle);
    
    if(window->cursor_handle)
        glfwDestroyCursor(window->cursor_handle);

    delete window;
}

void Window::Init(const WindowProps& props)
{
    this->props = props;

    if(glfwInit() != 1)
    {
        printf("Failed to intitialize glfw\n");
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_NATIVE_CONTEXT_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    this->window_handle = glfwCreateWindow(
        props.width,
        props.height,
        props.title,
        nullptr,
        nullptr
    );

    if(!this->window_handle)
    {
        printf("Failed to create glfw native window\n");
        exit(EXIT_FAILURE);
    }

    this->SetCursor(props.cursor);
    this->SetCursorState(props.cursor_state);
    this->SetDisplayState(props.display_state);

    this->running = true;
}
void Window::Quit()
{
    this->running = false;
}

PSTR Window::GetTitle()
{
    return this->props.title;
}
UI32 Window::GetWidth()
{
    return this->props.width;
}
UI32 Window::GetHeight()
{
    return this->props.height;
}
WindowCursor Window::GetCursor()
{
    return props.cursor;
}
WindowCursorState Window::GetCursorState()
{
    return props.cursor_state;
}
WindowDisplayState Window::GetDisplayState()
{
    return props.display_state;
}

WindowHandle Window::GetWindowHandle()
{
    return this->window_handle;
}
CursorHandle Window::GetCursorHandle()
{
    return this->cursor_handle;
}

void Window::SetTitle(PSTR title)
{
    this->props.title = title;
    glfwSetWindowTitle(this->window_handle, title);
}
void Window::SetWidth(UI32 width)
{
    this->props.width = width;
    glfwSetWindowSize(this->window_handle, width, this->props.height);
}
void Window::SetHeight(UI32 height)
{
    this->props.height = height;
    glfwSetWindowSize(this->window_handle, this->props.width, height);
}
void Window::SetCursor(WindowCursor cursor)
{
    this->props.cursor = cursor;

    switch(this->props.cursor)
    {
        case WindowCursor::ARROW     : {
                                            if(cursor_handle) 
                                                glfwDestroyCursor(this->cursor_handle); 
                                            
                                            this->cursor_handle = glfwCreateStandardCursor(GLFW_ARROW_CURSOR); 
                                            glfwSetCursor(this->window_handle, this->cursor_handle);
                                            
                                            break;
                                       }
        case WindowCursor::HAND      : {
                                            if(cursor_handle) 
                                                glfwDestroyCursor(this->cursor_handle); 
                                            
                                            this->cursor_handle = glfwCreateStandardCursor(GLFW_HAND_CURSOR); 
                                            glfwSetCursor(this->window_handle, this->cursor_handle);

                                            break;
                                       }
        case WindowCursor::IBEAM     : {
                                            if(cursor_handle) 
                                                glfwDestroyCursor(this->cursor_handle); 

                                            this->cursor_handle = glfwCreateStandardCursor(GLFW_IBEAM_CURSOR); 
                                            glfwSetCursor(this->window_handle, this->cursor_handle);
                                            
                                            break;
                                       }
        case WindowCursor::HRESIZE   : {
                                            if(cursor_handle) 
                                                glfwDestroyCursor(this->cursor_handle); 

                                            this->cursor_handle = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR); 
                                            glfwSetCursor(this->window_handle, this->cursor_handle);
                                            
                                            break;
                                       }
        case WindowCursor::VRESIZE   : {
                                            if(cursor_handle) 
                                                glfwDestroyCursor(this->cursor_handle); 

                                            this->cursor_handle = glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR); 
                                            glfwSetCursor(this->window_handle, this->cursor_handle);
                                            
                                            break;
                                       }
        case WindowCursor::CROSSHAIR : {
                                            if(cursor_handle) 
                                                glfwDestroyCursor(this->cursor_handle); 

                                            this->cursor_handle = glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR); 
                                            glfwSetCursor(this->window_handle, this->cursor_handle);
                                            
                                            break;
                                       }
        case WindowCursor::CUSTOM    : {
                                            //TODO:
                                            // if(cursor_handle) 
                                            //     glfwDestroyCursor(this->cursor_handle);  
                                            // GLFWimage image;
                                            // image.width = this->custom_cursor_tex->width;
                                            // image.height = this->custom_cursor_tex->height;
                                            // image.pixels = this->custom_cursor_tex->pixels;
                                            // this->cursor_handle = glfwCreateCursor(&image, 0, 0);
                                       }
    }
}
void Window::SetCursorState(WindowCursorState cursor_state)
{
    this->props.cursor_state = cursor_state;

    switch(this->props.cursor_state)
    {
        case WindowCursorState::NORMAL   : glfwSetInputMode(this->window_handle, GLFW_CURSOR, GLFW_CURSOR_NORMAL); break;
        case WindowCursorState::HIDDEN   : glfwSetInputMode(this->window_handle, GLFW_CURSOR, GLFW_CURSOR_HIDDEN); break;
        case WindowCursorState::DISABLED : glfwSetInputMode(this->window_handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED); break; 
    }
}
void Window::SetDisplayState(WindowDisplayState display_state)
{
    this->props.display_state = display_state;

    switch(this->props.display_state)
    {
        case WindowDisplayState::NOMRAL     : glfwShowWindow(this->window_handle); break;
        case WindowDisplayState::HIDDEN     : glfwHideWindow(this->window_handle); break;
        case WindowDisplayState::MAXMIZED   : glfwMaximizeWindow(this->window_handle); break;
        case WindowDisplayState::FULLSCREEN : {
                                                    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
                                                    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

                                                    glfwSetWindowMonitor(this->window_handle, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
                                                    
                                                    break;
                                              }
    }
}

bool Window::IsRunning()
{
    return this->running;
}