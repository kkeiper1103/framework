//
// Created by kkeiper1103 on 4/20/2023.
//

#ifndef SDL_TEMPLATE_SHADER_H
#define SDL_TEMPLATE_SHADER_H

#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Framework::GL {
    class Shader {
    public:
        Shader(const char* vertexSource, const char* fragmentSource, const char* geometrySource = nullptr);
        static Shader FromFiles(const char* vertexFile, const char* fragmentFile);
        static Shader FromFiles(const char* vertexFile, const char* fragmentFile, const char* geometryFile);

        ~Shader();

        inline void use() const {
            glUseProgram(id);
        }

        // Utility uniform functions
        void setBool(const std::string& name, bool value) const {
            glUniform1i(glGetUniformLocation(id, name.c_str()), value);
        }

        void setInt(const std::string& name, int value) const {
            glUniform1i(glGetUniformLocation(id, name.c_str()), value);
        }

        void setFloat(const std::string& name, float value) const {
            glUniform1f(glGetUniformLocation(id, name.c_str()), value);
        }

        void setVec2(const std::string& name, const glm::vec2& value) const {
            glUniform2fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
        }

        void setVec2(const std::string& name, float x, float y) const {
            glUniform2f(glGetUniformLocation(id, name.c_str()), x, y);
        }

        void setVec3(const std::string& name, const glm::vec3& value) const {
            glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
        }

        void setVec3(const std::string& name, float x, float y, float z) const {
            glUniform3f(glGetUniformLocation(id, name.c_str()), x, y, z);
        }

        void setVec4(const std::string& name, const glm::vec4& value) const {
            glUniform4fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
        }

        void setVec4(const std::string& name, float x, float y, float z, float w) const {
            glUniform4f(glGetUniformLocation(id, name.c_str()), x, y, z, w);
        }

        void setMat2(const std::string& name, const glm::mat2& mat) const {
            glUniformMatrix2fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
        }

        void setMat3(const std::string& name, const glm::mat3& mat) const {
            glUniformMatrix3fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
        }

        void setMat4(const std::string& name, const glm::mat4& mat) const {
            glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
        }

    private:
        GLuint id;

        static std::string get_file_contents(const char* file);
        static GLuint compileShader(GLuint type, const char* src);
    };
}

#endif //SDL_TEMPLATE_SHADER_H
