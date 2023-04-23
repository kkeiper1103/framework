//
// Created by kkeiper1103 on 4/22/2023.
//

#include "BaseObject.h"
#include <Application.h>

using namespace Framework::Objects;

int BaseObject::nextId = 0;

void BaseObject::Init(const glm::vec3& position, const glm::vec3& bounds, const glm::vec3& velocity, const glm::vec3& direction) {
    BaseObject::position = position;
    BaseObject::bounds = bounds;
    BaseObject::velocity = velocity;
    BaseObject::direction = direction;
}

void BaseObject::Input(const SDL_Event &e) {
    for(auto& c: children) c->Input(e);
}

void BaseObject::Update(float dt) {
    position = velocity * direction * dt;

    for(auto& c: children) c->Update(dt);
}

void BaseObject::Render() {
    for(auto& c: children) c->Render();
}
