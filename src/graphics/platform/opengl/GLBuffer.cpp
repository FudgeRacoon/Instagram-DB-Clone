#include "graphics/platform/opengl/GLBuffer.hpp"
using namespace re;

GLBuffer::GLBuffer(const PVOID data, SIZE bytes, UI32 usage)
{
    glGenBuffers(1, &m_id);
    glBindBuffer((UI32)m_type, m_id);
    glBufferData((UI32)m_type, bytes, data, usage);
    glBindBuffer((UI32)m_type, 0);
}
GLBuffer::~GLBuffer()
{
    glDeleteBuffers(1, &m_id);
}

void GLBuffer::UpdateData(SIZE offset_bytes, SIZE bytes, const PVOID data)
{
    glBufferSubData((UI32)m_type, offset_bytes, bytes, data);
}

void GLBuffer::Bind()
{
    glBindBuffer((UI32)m_type, m_id);
}
void GLBuffer::UnBind()
{
    glBindBuffer((UI32)m_type, 0);
}