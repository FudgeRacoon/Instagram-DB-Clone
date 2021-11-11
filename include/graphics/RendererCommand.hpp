#ifndef RENDERER_COMMAND_HPP
#define RENDERER_COMMAND_HPP

#include "glew/glew.h"

#include "../common/Alias.hpp"

#include "../core/Window.hpp"

#include "platform/opengl/GLVertexBuffer.hpp"
#include "platform/opengl/GLIndexBuffer.hpp"
#include "platform/opengl/GLVertexArray.hpp"

namespace re
{
    class RendererCommand
    {
    private:
        RendererCommand() = delete;
       ~RendererCommand() = delete;

    public:
        static void OnStart(Window* window);

    public:
        static void SetCull(bool value);
        static void SetBlend(bool value);
        static void SetCullFace(UI32 face);
        static void SetBlendFunc(UI32 src, UI32 dst);
        static void SetClearColor(float r, float g, float b);
        static void SetViewport(SI32 x, SI32 y, SI32 w, SI32 h);

    public:
        static void ClearBuffers(UI32 buffers);
        static void DrawArrays(UI32 mode, GLVertexArray* vao, UI32 vertex_count);
        static void DrawElements(UI32 mode, GLVertexArray* vao, GLIndexBuffer* ibo, UI32 index_count);
    };
}

#endif