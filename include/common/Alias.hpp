#ifndef ALIAS_HPP
#define ALIAS_HPP

#include <memory>

typedef char                CHAR;

typedef char*               PSTR;
typedef void*               PVOID;

typedef unsigned char       BYTE;

typedef unsigned char       UI8;
typedef unsigned short      UI16;
typedef unsigned int        UI32;
typedef unsigned long long  UI64;

typedef signed char         SI8;
typedef signed short        SI16;
typedef signed int          SI32;
typedef signed long long    SI64;

typedef UI64                SIZE;

constexpr UI8               MAX_UI8  = 0xFF;
constexpr UI16              MAX_UI16 = 0xFFFF;
constexpr UI32              MAX_UI32 = 0xFFFFFFFF;
constexpr UI64              MAX_UI64 = 0xFFFFFFFFFFFFFFFF;

namespace re
{
    template<typename T>
    using Scope = std::unique_ptr<T>;

    template<typename T>
    using Ref = std::shared_ptr<T>;

    template<typename T>
    using WeakRef = std::weak_ptr<T>;
}

#endif