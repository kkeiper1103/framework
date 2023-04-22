//
// Created by kkeiper1103 on 4/21/2023.
//

#ifndef FRAMEWORK_APPLICATION_H
#define FRAMEWORK_APPLICATION_H

// we define it here because the Application handles initializing SDL
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <Utility/Timer.h>
#include <Objects/BaseObject.h>

namespace Framework {

    extern SDL_Window* window;

    struct ApplicationSettings {
        const char* title = "(Application Title)";
        int width = 800;
        int height = 600;
        bool fullscreen = false;
        int fps = 60;
    };

    class Application {
    public:
        explicit Application(const ApplicationSettings& settings);
        virtual ~Application();

        int Run();


        template <typename T>
        std::shared_ptr<Framework::Objects::BaseObject> Create() {
            return std::shared_ptr<Framework::Objects::BaseObject>(new T(this));
        }

    protected:

        void Input();
        void Update(float dt);
        void Render();

    private:
        ApplicationSettings settings;

    };


}

#endif //FRAMEWORK_APPLICATION_H
