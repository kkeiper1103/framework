//
// Created by kkeiper1103 on 4/22/2023.
//

#ifndef TEMPLATE_BASEOBJECT_H
#define TEMPLATE_BASEOBJECT_H

#include <vector>
#include <string>
#include <memory>
#include <map>

#include <glad/glad.h>
#include <SDL.h>
#include <glm/glm.hpp>

namespace Framework {

    // forward decl for parent/child association
    class Application;

    namespace Objects {

        class BaseObject;
        typedef std::shared_ptr<BaseObject> Object;

        class BaseObject {
        public:
            glm::vec3 position, velocity, direction, bounds;

        public:
            explicit BaseObject(Application *const app, BaseObject* parent = nullptr) : app(app), parent(parent), ID(++nextId) {}
            virtual ~BaseObject() = default;

            // this method is meant to be overwritten, not extended
            // so the Init() function signature will look different for each object that is extended
            void Init(const glm::vec3& position, const glm::vec3& bounds, const glm::vec3& velocity = {}, const glm::vec3& direction = {});

            virtual void Input(const SDL_Event& e);
            virtual void Update(float dt);
            virtual void Render();


            // Overload the << operator
            friend std::ostream& operator<<(std::ostream& os, const BaseObject& obj) {

                char buffer[255];
                sprintf(buffer, "Object #%d (%s) <x:%.2f y:%.2f z:%.2f w:%.2f h:%.2f d:%.2f>\n", obj.ID, typeid(obj).name(), obj.position.x, obj.position.y, obj.position.z, obj.bounds.x, obj.bounds.y, obj.bounds.z);

                os << std::string{buffer};

                for(auto& child: obj.children) {
                    os << std::string{"\t"} << *child;
                }

                return os;
            }


            template <typename T>
            Object CreateChild(const glm::vec3& position = {}, const glm::vec3& bounds = {1, 1, 1}, const glm::vec3& velocity = {}, const glm::vec3& direction = {}) {
                auto ptr = Object(new T(app, this));
                ptr->Init(position, bounds, velocity, direction);

                children.push_back(ptr);

                return ptr;
            }

            template <typename T>
            Object CreateChild(const glm::vec2& position = {}, const glm::vec2& bounds = {1, 1}, const glm::vec2& velocity = {}, const glm::vec2& direction = {}) {
                auto ptr = Object(new T(app, this));
                ptr->Init(glm::vec3{ position, 0 }, glm::vec3{ bounds, 0}, glm::vec3{ velocity, 0}, glm::vec3{ direction, 0});

                children.push_back(ptr);

                return ptr;
            }

        protected:
            const int ID = 0;

            Application *const app = nullptr;
            BaseObject *parent = nullptr;
            std::vector<Object> children;



        private:
            static int nextId;
        };

    } // Framework
} // Objects

#endif //TEMPLATE_BASEOBJECT_H
