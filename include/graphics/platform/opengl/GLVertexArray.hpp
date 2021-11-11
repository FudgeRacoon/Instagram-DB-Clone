#ifndef GL_VERTEX_ARRAY_HPP
#define GL_VERTEX_ARRAY_HPP

#include "glew/glew.h"

#include "../../../common/Alias.hpp"

#include "GLVertexBuffer.hpp"
#include "../../VertexLayout.hpp"

namespace re
{
    class GLVertexArray
    {
    private:
        UI32 m_id;

    public:
        GLVertexArray();
       ~GLVertexArray();

    public: 
        void SetVertexBuffer(GLVertexBuffer* vbo, const VertexLayout& layout);

    public:
        void Bind();
        void UnBind();
    };
}

#endif