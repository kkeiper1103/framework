//
// Created by kkeiper1103 on 4/21/2023.
//

#include "Square.h"

using namespace Framework::GL::Meshes;

Square::Square() : Framework::GL::Mesh() {
    setBufferData(Framework::GL::BUFFER_POSITION, {
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f   // top left
    });

    setBufferData(Framework::GL::BUFFER_UVS, {
            1, 0,
            1, 1,
            0, 1,
            0, 0,
    }, 2);

    setBufferData(Framework::GL::BUFFER_INDICES, {
            0, 1, 3,   // first triangle
            1, 2, 3    // second triangle
    });
}
