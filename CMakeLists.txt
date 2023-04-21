cmake_minimum_required(VERSION 3.25)
project(framework)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

add_subdirectory(vendor/sdl2)

add_library(framework
        main.cpp
        src/Application.cpp
        src/GL/Texture.cpp
        src/GL/Shader.cpp
        src/GL/Mesh.cpp
        src/GL/Meshes/Triangle.cpp
        src/GL/Meshes/Square.cpp
        src/GL/Meshes/Circle.cpp
        vendor/glad/glad.cpp)

target_include_directories(framework PUBLIC src/ vendor/ vendor/glm)
target_link_libraries(framework PUBLIC SDL2::SDL2 OpenGL::GL)