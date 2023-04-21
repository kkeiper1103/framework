//
// Created by kkeiper1103 on 4/21/2023.
//

#ifndef SDL_TEMPLATE_CIRCLE_H
#define SDL_TEMPLATE_CIRCLE_H

#include "GL/Mesh.h"

namespace Framework::GL::Meshes {
class Circle : public Framework::GL::Mesh {
public:
    explicit Circle(unsigned int points = 32);
};
}



#endif //SDL_TEMPLATE_CIRCLE_H
