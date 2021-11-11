#include "graphics/platform/opengl/GLShaderProgram.hpp"
using namespace re;

GLShaderProgram::GLShaderProgram(const char* vertexFilepath, const char* fragmentFilepath)
{
    m_id = glCreateProgram();

    if(this->m_id == 0)
    {
        printf("Failed to create shader program\n");
        return;
    }

    CreateShader(vertexFilepath, GL_VERTEX_SHADER);
    CreateShader(fragmentFilepath, GL_FRAGMENT_SHADER);

    glLinkProgram(m_id);
    glValidateProgram(m_id);

    SI32 result;
    char buffer[512];
    glGetProgramiv(m_id, GL_LINK_STATUS, &result);

    if(result == 0)
    {
        glGetProgramInfoLog(m_id, 512, nullptr, buffer);
        printf("Failed to link Shader\n%s", buffer);
        return;
    }
}

GLShaderProgram::~GLShaderProgram()
{
    glDeleteProgram(m_id);
}

std::string GLShaderProgram::ParseShader(const char* filepath)
{
    std::fstream file(filepath, std::ios::in);

    if(!file)
    {
        printf("Failed to open shader file.");
        return std::string();
    }
    
    std::string line;
    std::stringstream ss;

    while(getline(file, line))
        ss << line << '\n';
    
    return ss.str();
}
void GLShaderProgram::CreateShader(const char* filepath, SI32 shader_type)
{
    std::string source = ParseShader(filepath);
    if(source.empty())
        return;

    const char* source_cstr = source.c_str();

    SI32 shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &source_cstr, nullptr);
    glCompileShader(shader);

    SI32 result;
    char buffer[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

    if(result == 0)
    {
        glGetShaderInfoLog(shader, 512, nullptr, buffer);
        switch(shader_type)
        {
            case GL_VERTEX_SHADER: printf("Failed to compile Vertex Shader.\n%s", buffer); return;
            case GL_FRAGMENT_SHADER: printf("Failed to compile Fragment Shader.\n%s", buffer); return;
        }
    }

    glAttachShader(m_id, shader);
    glDeleteShader(shader);
}

void GLShaderProgram::SetInt(const char* var_name, SI32 value) const
{
    SI32 uniformId = glGetUniformLocation(m_id, var_name);
    glUniform1i(uniformId, value);
}
void GLShaderProgram::SetBool(const char* var_name, SI32 value) const
{
    SI32 uniformId = glGetUniformLocation(m_id, var_name);
    glUniform1i(uniformId, value);
}
void GLShaderProgram::SetFloat(const char* var_name, float value) const
{
    SI32 uniformId = glGetUniformLocation(m_id, var_name);
    glUniform1f(uniformId, value);
}
void GLShaderProgram::SetVec2i(const char* var_name, SI32 x, SI32 y) const
{
    SI32 uniformId = glGetUniformLocation(m_id, var_name);
    glUniform2i(uniformId, x, y);
}
void GLShaderProgram::SetVec2f(const char* var_name, float x, float y) const
{
    SI32 uniformId = glGetUniformLocation(m_id, var_name);
    glUniform2f(uniformId, x, y);
}
void GLShaderProgram::SetVec4i(const char* var_name, SI32 x, SI32 y, SI32 z, SI32 w) const
{
    SI32 uniformId = glGetUniformLocation(m_id, var_name);
    glUniform4i(uniformId, x, y, z, w);
}
void GLShaderProgram::SetVec4f(const char* var_name, float x, float y, float z, float w) const
{
    SI32 uniformId = glGetUniformLocation(m_id, var_name);
    glUniform4f(uniformId, x, y, z, w);
}
void GLShaderProgram::SetMat4(const char* var_name, const float* data) const
{
    SI32 uniformId = glGetUniformLocation(m_id, var_name);
    glUniformMatrix4fv(uniformId, 1, false, data);
}

void GLShaderProgram::Bind() const
{
    glUseProgram(m_id);
}
void GLShaderProgram::UnBind() const
{
    glUseProgram(0);
}