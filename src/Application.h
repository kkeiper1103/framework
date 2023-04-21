//
// Created by kkeiper1103 on 4/21/2023.
//

#ifndef FRAMEWORK_APPLICATION_H
#define FRAMEWORK_APPLICATION_H

#include <SDL.h>

namespace Framework {

    extern SDL_Window* window;

class Application {
public:
    Application();
    virtual ~Application();

    int Run();

protected:

    void Input();
    void Update(float dt);
    void Render();

private:


};


}

#endif //FRAMEWORK_APPLICATION_H
