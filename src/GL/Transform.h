//
// Created by kkeiper1103 on 4/20/2023.
//

#ifndef SDL_TEMPLATE_TRANSFORM_H
#define SDL_TEMPLATE_TRANSFORM_H

#include <glad/glad.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtx/quaternion.hpp>
#include <glm/glm/gtx/euler_angles.hpp>

namespace GL {
    struct Transform {
        glm::vec3 position {0, 0, 0};
        glm::vec3 rotation {0, 0, 0};
        float scale {1.f};

        inline glm::mat4 model() {
            glm::mat4 model(1.f);

            model = glm::translate(model, position);

            model = rotateModelMatrix(model, rotation);

            model = glm::scale(model, {scale, scale, scale});

            return model;
        }

        glm::mat4 rotateModelMatrix(const glm::mat4& model, const glm::vec3& rotationAngles) {
            // Convert rotation angles from degrees to radians
            glm::vec3 radians = glm::radians(rotationAngles);

            // Calculate the quaternion from Euler angles
            glm::quat q = glm::quat(radians);

            // Normalize the quaternion
            q = glm::normalize(q);

            // Convert the quaternion to a 4x4 rotation matrix
            glm::mat4 rotationMatrix = glm::mat4_cast(q);

            // Apply the rotation to the model matrix
            glm::mat4 rotatedModel = model * rotationMatrix;

            return rotatedModel;
        }
    };
}

#endif //SDL_TEMPLATE_TRANSFORM_H
