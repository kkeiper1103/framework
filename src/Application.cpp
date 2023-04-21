//
// Created by kkeiper1103 on 4/21/2023.
//

#include "Application.h"

using namespace Framework;

SDL_Window* window = nullptr;

Application::Application() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

Application::~Application() {
    SDL_Quit();
}

int Application::Run() {

    window = SDL_CreateWindow("testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    while(!SDL_QuitRequested()) {
        Input();

        Update(0.016);
        Render();
    }

    SDL_DestroyWindow(window);

    return 0;
}

void Application::Input() {
    SDL_Event e;
    while(SDL_PollEvent(&e)) {

    }
}

void Application::Update(float dt) {
    //
}

void Application::Render() {
    //
}
