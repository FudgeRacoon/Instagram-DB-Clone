#ifndef ENGINE_API_HPP
#define ENGINE_API_HPP

#include "PlatformDetection.hpp"

#ifdef RE_WINDOWS_PLATFORM
    #ifdef API_EXPORT
        #define API __declspec(dllexport)
    #else
        #define API __declspec(dllimport)
    #endif
#endif

#endif