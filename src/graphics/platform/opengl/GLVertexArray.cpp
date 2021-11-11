#include "graphics/platform/opengl/GLVertexArray.hpp"
using namespace re;

GLVertexArray::GLVertexArray()
{
    glGenVertexArrays(1, &m_id);
}
GLVertexArray::~GLVertexArray()
{
    glDeleteVertexArrays(1, &m_id);
}

void GLVertexArray::SetVertexBuffer(GLVertexBuffer* vbo, const VertexLayout& vertex_layout)
{
    Bind();
    vbo->Bind();

    auto layouts = vertex_layout.GetLayouts();

    int offset = 0;
    for(int index = 0; index < layouts.size(); index++)
    {
        Layout layout = layouts[index];

        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, layout.format, layout.type, layout.normalized, vertex_layout.GetStride(), (const void*)offset);
        offset += layout.format * Layout::GetSizeOfType(layout.type);
    }   

    vbo->UnBind();
    UnBind();
}

void GLVertexArray::Bind()
{
    glBindVertexArray(m_id);
}   
void GLVertexArray::UnBind()
{
    glBindVertexArray(0);
}