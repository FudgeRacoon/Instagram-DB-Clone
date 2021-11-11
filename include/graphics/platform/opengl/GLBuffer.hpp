#ifndef GL_BUFFER_HPP
#define GL_BUFFER_HPP

#include "glew/glew.h"

#include "../../../common/Alias.hpp"

namespace re
{
    class GLBuffer
    {
    public:
        GLBuffer(const PVOID data, SIZE bytes, UI32 usage);
        virtual ~GLBuffer();

    protected:
        UI32 m_id;

    protected:
        enum class BufferType
        {
            INDEX_BUFFER  = 0x8893,
            VERTEX_BUFFER = 0x8892
        }m_type;

    public:
        void UpdateData(SIZE offset_bytes, SIZE bytes, const PVOID data);

    public:
        void Bind();
        void UnBind();
    };
}

#endif