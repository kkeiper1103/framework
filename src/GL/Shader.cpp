//
// Created by kkeiper1103 on 4/20/2023.
//

#include "Shader.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace Framework::GL;

Shader::Shader(const char *vertexSource, const char *fragmentSource, const char *geometrySource) {
    id = glCreateProgram();
    std::vector<GLuint> shaders;

    if(vertexSource)
        shaders.push_back( compileShader(GL_VERTEX_SHADER, vertexSource) );

    if(fragmentSource)
        shaders.push_back( compileShader(GL_FRAGMENT_SHADER, fragmentSource) );

    if(geometrySource)
        shaders.push_back( compileShader(GL_GEOMETRY_SHADER, geometrySource) );

    for(auto& shaderId: shaders) {
        glAttachShader(id, shaderId);
    }

    glLinkProgram(id);
    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR: Program Linking\n" << infoLog << std::endl;
    }

    for(auto& shaderId: shaders) {
        glDeleteShader(shaderId);
    }
}

Shader Shader::FromFiles(const char *vertexFile, const char *fragmentFile) {
    return {
        get_file_contents(vertexFile).c_str(),
        get_file_contents(fragmentFile).c_str()
    };
}

Shader Shader::FromFiles(const char *vertexFile, const char *fragmentFile, const char *geometryFile) {
    return {
        get_file_contents(vertexFile).c_str(),
        get_file_contents(fragmentFile).c_str(),
        get_file_contents(geometryFile).c_str()
    };
}

Shader::~Shader() {
    glDeleteProgram(id);
}

std::string Shader::get_file_contents(const char *filename) {
    std::ifstream file(filename); // create ifstream object with filename
    std::string contents; // create a string to hold the file contents

    if (file.is_open()) { // check if file was successfully opened
        std::string line;
        while (getline(file, line)) { // read file line by line
            contents += line + "\n"; // add line to contents string
        }
        file.close(); // close file
    } else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }

    return contents;
}

GLuint Shader::compileShader(GLuint type, const char *src) {
    auto shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR: Shader COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    return shader;
}

