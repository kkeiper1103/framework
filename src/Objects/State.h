//
// Created by kkeiper1103 on 4/23/2023.
//

#ifndef TEMPLATE_STATE_H
#define TEMPLATE_STATE_H

#include "BaseObject.h"

#include "Gui/Nuklear.h"

namespace Framework::Objects {
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
}

#endif //TEMPLATE_STATE_H
