//
// Created by kkeiper1103 on 4/23/2023.
//

#ifndef TEMPLATE_NUKLEAR_H
#define TEMPLATE_NUKLEAR_H

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT

#include <nuklear/nuklear.h>
#include <nuklear/nuklear_sdl_gl3.h>

namespace Framework::Gui {
    extern nk_context* ctx;
    extern nk_font_atlas* atlas;
}

#endif //TEMPLATE_NUKLEAR_H
