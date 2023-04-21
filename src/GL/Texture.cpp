//
// Created by kkeiper1103 on 4/21/2023.
//

#define STB_IMAGE_IMPLEMENTATION

#include <stdexcept>
#include "Texture.h"

using namespace Framework::GL;

Texture::Texture(const char *filename, GLenum target) : target{target} {
    glGenTextures(1, &id);

    int w, h, channels;
    unsigned char* data = stbi_load(filename, &w, &h, &channels, STBI_default);

    GLenum format;
    switch(channels) {
        case 1: format = GL_RED; break;
        case 3: format = GL_RGB; break;
        case 4: format = GL_RGBA; break;
        default: throw std::runtime_error("Unsupported Pixel Format!"); break;
    }

    glBindTexture(target, id);
    {
        glTexImage2D(target, 0, format, w, h, 0, format, GL_UNSIGNED_BYTE, data);

        // Generate mipmaps for the texture
        glGenerateMipmap(target);

        // Set texture parameters
        glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    glBindTexture(target, 0);

    stbi_image_free(data);
}

Texture::~Texture() {
    glDeleteTextures(1, &id);
}
