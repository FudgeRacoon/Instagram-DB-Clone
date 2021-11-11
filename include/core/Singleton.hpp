#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include "../common/EngineAPI.hpp"

namespace re
{
    template<typename T>
    class Singleton
    {   
    protected:
        Singleton() = default;
        virtual ~Singleton() = default;

    protected:
        Singleton(Singleton<T>&& singleton) = delete;
        Singleton(const Singleton<T>& singleton) = delete;

    protected:
        Singleton& operator=(Singleton<T>&& singleton) = delete;
        Singleton& operator=(const Singleton<T>& singleton) = delete;

    public:
        static T& GetInstanceRef()
        {
            static T instance = T();
            return instance;
        }
    };
}

#endif