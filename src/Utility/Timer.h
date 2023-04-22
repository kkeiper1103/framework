//
// Created by kkeiper1103 on 4/22/2023.
//

#ifndef TEMPLATE_TIMER_H
#define TEMPLATE_TIMER_H

#include <functional>

#include <SDL.h>

namespace Framework::Utility {
    class Timer {
    private:
        Uint64 last;
        float t, dt, accum;

    public:
        explicit Timer(int fps = 60) : dt(1000.f / fps), t{0}, last{SDL_GetTicks64()}, accum{0} {}

        void tick(const std::function<void(float)>& tick) {
            auto now = SDL_GetTicks64();
            auto elapsed = now - last;
            last = now;

            if(elapsed > 25 * dt)
                elapsed = 25 * dt;

            accum += dt;

            while(accum >= dt) {
                tick(dt / 1000.f);

                accum -= dt;
                t += dt;
            }
        }
    };
}


#endif //TEMPLATE_TIMER_H
