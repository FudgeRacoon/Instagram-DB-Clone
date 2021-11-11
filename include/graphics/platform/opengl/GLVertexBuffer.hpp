#ifndef GL_VERTEX_BUFFER_HPP
#define GL_VERTEX_BUFFER_HPP

#include "../../../common/Alias.hpp"

#include "GLBuffer.hpp"

namespace re
{
    class GLVertexBuffer : public GLBuffer
    {
    public:
        GLVertexBuffer(PVOID data, SIZE bytes, UI32 usage)
            :GLBuffer(data, bytes, usage)
        {
            m_type = GLBuffer::BufferType::VERTEX_BUFFER;
        }
       ~GLVertexBuffer() = default;
    };
}

#endif