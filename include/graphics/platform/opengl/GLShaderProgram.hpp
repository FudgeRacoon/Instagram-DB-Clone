#ifndef GL_SHADER_PROGRAM_HPP
#define GL_SHADER_PROGRAM_HPP

#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>

#include "glew/glew.h"

#include "../../../common/Alias.hpp"

namespace re
{
    class GLShaderProgram
    {   
    private:
        UI32 m_id;

    public:
        GLShaderProgram(const char* vertexPath, const char* fragmentPath);
       ~GLShaderProgram();

    private:
        std::string ParseShader(const char* filepath);
        void CreateShader(const char* filepath, int shader_type);

    public:
        void SetInt(const char* var_name, SI32 value) const;
        void SetBool(const char* var_name, SI32 value) const;
        void SetFloat(const char* var_name, float value) const;
        void SetVec2i(const char* var_name, SI32 x, SI32 y) const;
        void SetVec2f(const char* var_name, float x, float y) const;
        void SetVec4i(const char* var_name, SI32 x, SI32 y, SI32 z, SI32 w) const;
        void SetVec4f(const char* var_name, float x, float y, float z, float w) const;
        void SetMat4(const char* var_name, const float* data) const;

    public:
        void Bind() const;
        void UnBind() const;
    };
}

#endif