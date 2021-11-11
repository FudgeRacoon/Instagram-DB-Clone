#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include "../common/Alias.hpp"
#include "../common/EngineAPI.hpp"

#include "Event.hpp"
#include "EventDispatcher.hpp"

namespace re
{
    class EventHandler
    {
    public:
        virtual void OnEvent(Event* event) = 0;
    };
}

#endif