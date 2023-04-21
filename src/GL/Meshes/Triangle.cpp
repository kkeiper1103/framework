//
// Created by kkeiper1103 on 4/21/2023.
//

#include "Triangle.h"

using namespace Framework::GL::Meshes;

Triangle::Triangle() : Framework::GL::Mesh() {
    setBufferData(Framework::GL::BUFFER_POSITION, {
            -0.5f, 0.0f, 0.0f,  // bottom left
            0.5f, 0.0f, 0.0f,  // bottom right
            0.0,  0.5f, 0.0f   // top center
    });

    setBufferData(Framework::GL::BUFFER_UVS, {
            0, 1,
            1, 1,
            .5, 0,
    }, 2);

    setBufferData(Framework::GL::BUFFER_INDICES, {
            0, 1, 2,   // first triangle
    });
}
