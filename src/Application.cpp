//
// Created by kkeiper1103 on 4/21/2023.
//

#include "Application.h"

using namespace Framework;
using namespace Framework::Utility;

SDL_Window* Framework::window = nullptr;

Application::Application(const ApplicationSettings& settings) : settings(settings) {
    SDL_Init(SDL_INIT_EVERYTHING);
}

Application::~Application() {
    SDL_Quit();
}

int Application::Run() {

    int flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
    if(settings.fullscreen) {
        flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
        SDL_DisplayMode display;
        SDL_GetCurrentDisplayMode(0, &display);

        settings.width = display.w;
        settings.height = display.h;
    }
    window = SDL_CreateWindow(settings.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, settings.width, settings.height, flags);

    Timer t(1000.f / settings.fps);
    while(!SDL_QuitRequested()) {
        Input();

        t.tick([&](float dt) {
            Update(dt);
        });

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
