//
// Created by kkeiper1103 on 4/21/2023.
//

#ifndef SDL_TEMPLATE_TEXTURE_H
#define SDL_TEMPLATE_TEXTURE_H

#include <glad/glad.h>
#include <stb/stb_image.h>

namespace Framework::GL {
    class Texture {
    public:
        explicit Texture(const char* filename, GLenum target = GL_TEXTURE_2D);
        ~Texture();

        void use(int slot = 0) const {
            glActiveTexture(GL_TEXTURE0 + slot);
            glBindTexture(target, id);
        }

    protected:
        GLuint id;
        GLenum target;
    };
}




#endif //SDL_TEMPLATE_TEXTURE_H
