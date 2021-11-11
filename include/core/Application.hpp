#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "../common/Alias.hpp"
#include "../common/EngineAPI.hpp"

#include "../graphics/GraphicsContext.hpp"
#include "../graphics/RendererCommand.hpp"
#include "../graphics/platform/opengl/GLVertexBuffer.hpp"
#include "../graphics/platform/opengl/GLIndexBuffer.hpp"
#include "../graphics/platform/opengl/GLVertexArray.hpp"

#include "Window.hpp"
#include "ApplicationProps.hpp"

#include "../events/Event.hpp"
#include "../events/EventHandler.hpp"
#include "../events/EventDispatcher.hpp"

#include "../input/InputManager.hpp"
#include "../input/KeyCodes.hpp"
#include "../input/MouseCodes.hpp"
#include "../input/KeyListener.hpp"
#include "../input/MouseListener.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

namespace re
{
    class Application : public EventHandler
    {
    protected:
        Window* m_window;
        ApplicationProps m_props;
        
    public:
        Application(const ApplicationProps& props);
        virtual ~Application() = default;

    public:
        void Run();

    public:
        virtual void OnWindowClose(WindowClosedEvent* event);
        virtual void OnWindowResize(WindowResizedEvent* event);

    public:
        virtual void OnStart() = 0;
        virtual void OnEvent(Event* event) = 0;
        virtual void OnUpdate() = 0;
        virtual void OnShutDown() = 0;
    };  
}

#endif