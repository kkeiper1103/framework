//
// Created by kkeiper1103 on 4/20/2023.
//

#ifndef SDL_TEMPLATE_MESH_H
#define SDL_TEMPLATE_MESH_H

#include <vector>

#include <glm/glm.hpp>
#include <glad/glad.h>

namespace Framework::GL {
    enum BufferType {
        BUFFER_POSITION = 0,
        BUFFER_UVS,
        BUFFER_NORMALS,
        BUFFER_INDICES
    };

    class Mesh {
    public:
        Mesh();
        virtual ~Mesh();

        void setBufferData(BufferType buffer, const std::vector<GLfloat>& data, int numComponents = 3);
        void setIndices(const std::vector<GLuint>& data);

        virtual void render() const {
            glBindVertexArray(vaoId);

            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

            glBindVertexArray(0);
        }

    protected:
        GLuint vaoId;
        std::vector<GLuint> buffers {0, 0, 0, 0};

        std::vector<GLuint> indices;
    };
}


#endif //SDL_TEMPLATE_MESH_H
