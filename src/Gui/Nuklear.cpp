//
// Created by kkeiper1103 on 4/23/2023.
//


#define NK_IMPLEMENTATION
#define NK_SDL_GL3_IMPLEMENTATION

#include "Nuklear.h"

using namespace Framework::Gui;

nk_context* Framework::Gui::ctx = nullptr;
nk_font_atlas* Framework::Gui::atlas = nullptr;