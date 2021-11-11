#ifndef GL_INDEX_BUFFER_HPP
#define GL_INDEX_BUFFER_HPP

#include "../../../common/Alias.hpp"

#include "GLBuffer.hpp"

namespace re
{
    class GLIndexBuffer : public GLBuffer
    {
    public:
        GLIndexBuffer(UI32* data, SIZE bytes, UI32 usage)
            :GLBuffer(data, bytes, usage)
        {
            m_type = GLBuffer::BufferType::INDEX_BUFFER;
        }
       ~GLIndexBuffer() = default;
    };
}

#endif