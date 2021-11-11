#include "graphics/RendererCommand.hpp"
using namespace re;

void RendererCommand::OnStart(Window* window)
{
    SetCull(true);
    SetBlend(true);

    SetCullFace(GL_BACK);
    SetBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    SetClearColor(0.0f, 0.0f, 0.0f);

    SetViewport(0, 0, window->GetWidth(), window->GetHeight());
}

void RendererCommand::SetCull(bool value)
{
    value ? glEnable(GL_CULL_FACE) : glDisable(GL_CULL_FACE);
}
void RendererCommand::SetBlend(bool value)
{
    value ? glEnable(GL_BLEND) : glDisable(GL_BLEND);
}
void RendererCommand::SetCullFace(UI32 face)
{
    glCullFace(face);
}
void RendererCommand::SetBlendFunc(UI32 src, UI32 dst)
{
    glBlendFunc(src, dst);
}
void RendererCommand::SetClearColor(float r, float g, float b)
{
    glClearColor(r, g, b, 1.0f);
}
void RendererCommand::SetViewport(SI32 x, SI32 y, SI32 w, SI32 h)
{
    glViewport(x, y, w, h);
}

void RendererCommand::ClearBuffers(UI32 buffers)
{
    glClear(buffers);
}
void RendererCommand::DrawArrays(UI32 mode, GLVertexArray* vao, UI32 vertex_count)
{
    vao->Bind();
    glDrawArrays(mode, 0, vertex_count);
    vao->UnBind();
}
void RendererCommand::DrawElements(UI32 mode, GLVertexArray* vao, GLIndexBuffer* ibo, UI32 index_count)
{
    vao->Bind();
    ibo->Bind();
    glDrawElements(mode, index_count, GL_UNSIGNED_INT, nullptr);
    ibo->UnBind();
    vao->UnBind();
}