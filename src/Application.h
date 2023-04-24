//
// Created by kkeiper1103 on 4/21/2023.
//

#ifndef FRAMEWORK_APPLICATION_H
#define FRAMEWORK_APPLICATION_H

// we define it here because the Application handles initializing SDL
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <glad/glad.h>
#include <Utility/Timer.h>
#include <Objects/BaseObject.h>
#include <Gui/Nuklear.h>
#include <Objects/State.h>

namespace Framework {

    extern SDL_Window* window;
    extern SDL_GLContext glContext;

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

        void MapStates(const Framework::Objects::States& statesList) {
            states = statesList;
        }

        template <typename T>
        Objects::Object Create() {
            return Objects::Object(new T(this));
        }

    protected:
        void Input();
        void Update(float dt);
        void Render();

        std::shared_ptr<Framework::Objects::State> state() {
            return states[currentStateId];
        }

    private:
        struct nk_context* nkContext = nullptr;
        struct nk_font_atlas* nkFontAtlas = nullptr;

        Objects::StateID currentStateId = Objects::STATE_INTRO;
        Framework::Objects::States states;

    private:
        ApplicationSettings settings;

        void InitNuklear();
        void InitGL() const;
        void InitSDL();
        void ApplyGuiStyles(nk_context *pContext);
    };
}

#endif //FRAMEWORK_APPLICATION_H
