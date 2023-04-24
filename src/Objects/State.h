//
// Created by kkeiper1103 on 4/23/2023.
//

#ifndef TEMPLATE_STATE_H
#define TEMPLATE_STATE_H

#include <vector>
#include <unordered_map>

#include "BaseObject.h"

#include "Gui/Nuklear.h"

namespace Framework::Objects {
    enum StateID {
        STATE_INTRO = 0,
        STATE_TITLE,
        STATE_SETTINGS,
        STATE_PLAY,
        STATE_PAUSE,
        STATE_GAMEOVER,
        STATE_VICTORY,
        STATE_CREDITS,

        NUM_STATES
    };


    class State : public BaseObject {
    public:
        explicit State(Application *const app) : BaseObject(app) {};
        ~State() override = default;

        virtual void Gui(nk_context *const ctx) {};

        virtual void OnEnter() {};
        virtual void OnExit() {};

        virtual void OnSave() {};
        virtual void OnLoad() {};
    };

    typedef std::unordered_map<StateID, std::shared_ptr<State>> States;
}

#endif //TEMPLATE_STATE_H
