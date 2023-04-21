//
// Created by kkeiper1103 on 4/21/2023.
//

#include "Circle.h"
#include <cmath>

using namespace Framework::GL::Meshes;

Circle::Circle(unsigned int points) {
    const float radius = 0.5f;

    std::vector<float> positions;
    std::vector<float> uvs;
    std::vector<float> indices;

// Generate positions and UVs
    positions.reserve(3 * (points + 1));
    uvs.reserve(2 * (points + 1));

    positions.push_back(0.0f); // Center of the circle
    positions.push_back(0.0f);
    positions.push_back(0.0f);
    uvs.push_back(0.5f); // Center of the UV coordinates
    uvs.push_back(0.5f);

    for (int i = 0; i < points; ++i) {
        float angle = 2.0f * M_PI * i / static_cast<float>(points);
        float x = radius * std::cos(angle);
        float y = radius * std::sin(angle);

        positions.push_back(x);
        positions.push_back(y);
        positions.push_back(0.0f);

        uvs.push_back((x / radius + 1.0f) * 0.5f);
        uvs.push_back(1 - ((y / radius + 1.0f) * 0.5f));
    }

    // Generate indices
    indices.reserve(3 * points);

    for (int i = 0; i < points; ++i) {
        indices.push_back(0); // Center vertex
        indices.push_back((i + 1) % points + 1);
        indices.push_back((i + 2) % points + 1);
    }

    // Set the buffer data
    setBufferData(Framework::GL::BUFFER_POSITION, positions);
    setBufferData(Framework::GL::BUFFER_UVS, uvs, 2);
    setBufferData(Framework::GL::BUFFER_INDICES, indices);
}
