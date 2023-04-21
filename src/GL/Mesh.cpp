//
// Created by kkeiper1103 on 4/20/2023.
//

#include <iostream>
#include "Mesh.h"

using namespace Framework::GL;

Mesh::Mesh() {
    glGenVertexArrays(1, &vaoId);
    glBindVertexArray(vaoId);
    {
        glGenBuffers(buffers.size(), &buffers[0]);
    }
    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteBuffers(buffers.size(), &buffers[0]);
    glDeleteVertexArrays(1, &vaoId);
}

void Mesh::setBufferData(BufferType buffer, const std::vector<GLfloat>& data, int numComponents) {
    if(buffer == BUFFER_INDICES) {
        std::vector<GLuint> indices_(data.size());

        for (size_t i = 0; i < data.size(); ++i) {
            indices_[i] = static_cast<GLuint>(data[i]);
        }

        return setIndices(indices_);
    }

    if(data.size() % numComponents != 0) {
        std::cerr << "The size of the data buffer is not divisible by the number of components requested! Are you using 2 component data in a 3 component buffer?" << std::endl;
    }

    glBindVertexArray(vaoId);
    {
        glBindBuffer(GL_ARRAY_BUFFER, buffers[buffer]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), &data[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(buffer);
        glVertexAttribPointer(buffer, numComponents, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * numComponents, nullptr);
    }
    glBindVertexArray(0);
}

void Mesh::setIndices(const std::vector<GLuint> &data) {
    indices = data;

    glBindVertexArray(vaoId);
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[BUFFER_INDICES]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * data.size(), &data[0], GL_STATIC_DRAW);
    }
    glBindVertexArray(0);
}
