//
// Created by kkeiper1103 on 4/21/2023.
//

#include "Application.h"


#define MAX_VERTEX_MEMORY 512 * 1024
#define MAX_ELEMENT_MEMORY 128 * 1024

using namespace Framework;
using namespace Framework::Utility;

SDL_Window* Framework::window = nullptr;
SDL_GLContext Framework::glContext = nullptr;

Application::Application(const ApplicationSettings& settings) : settings(settings) {
    SDL_Init(SDL_INIT_EVERYTHING);
}

Application::~Application() {
    SDL_Quit();
}

int Application::Run() {

    InitSDL();

    // init gl
    InitGL();

    // initialize gui
    InitNuklear();


    Timer t(1000.f / settings.fps);
    while(!SDL_QuitRequested()) {
        Input();

        t.tick([&](float dt) {
            Update(dt);
        });

        if(state()) state()->Gui(nkContext);

        Render();
    }

    nk_sdl_shutdown();
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);

    return 0;
}

void Application::InitSDL() {
    int flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
    if(settings.fullscreen) {
        flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
        SDL_DisplayMode display;
        SDL_GetCurrentDisplayMode(0, &display);

        settings.width = display.w;
        settings.height = display.h;
    }
    window = SDL_CreateWindow(settings.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, settings.width, settings.height, flags);
}

void Application::InitGL() const {
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    glContext = SDL_GL_CreateContext(window);

    SDL_GL_MakeCurrent(window, glContext);

    if(!gladLoadGL((GLADloadfunc) SDL_GL_GetProcAddress)) {
        printf("Couldn't Load OpenGL 3\n");
    }
}

void Application::InitNuklear() {
    nkContext = nk_sdl_init(window);
    struct nk_font_config config = nk_font_config(0);
    struct nk_font *font;

    nk_sdl_font_stash_begin(&nkFontAtlas);
    font = nk_font_atlas_add_default(nkFontAtlas, 13, &config);
    nk_sdl_font_stash_end();

    nk_style_set_font(nkContext, &font->handle);

    ApplyGuiStyles(nkContext);
}

void Application::Input() {
    SDL_Event e;

    nk_input_begin(nkContext);
    while(SDL_PollEvent(&e)) {

        if(state()) state()->Input(e);

        nk_sdl_handle_event(&e);
    }
    nk_input_end(nkContext);
}

void Application::Update(float dt) {
    if(state()) state()->Update(dt);
}

void Application::Render() {
    glViewport(0, 0, settings.width, settings.height);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(.1, .1, .1, 1.f);

    if(state()) state()->Render();

    nk_sdl_render(NK_ANTI_ALIASING_ON, MAX_VERTEX_MEMORY, MAX_ELEMENT_MEMORY);
    SDL_GL_SwapWindow(window);
}

void Application::ApplyGuiStyles(nk_context *pContext) {
    struct nk_color table[NK_COLOR_COUNT];
    table[NK_COLOR_TEXT] = nk_rgba(70, 70, 70, 255);
    table[NK_COLOR_WINDOW] = nk_rgba(175, 175, 175, 255);
    table[NK_COLOR_HEADER] = nk_rgba(175, 175, 175, 255);
    table[NK_COLOR_BORDER] = nk_rgba(0, 0, 0, 255);
    table[NK_COLOR_BUTTON] = nk_rgba(185, 185, 185, 255);
    table[NK_COLOR_BUTTON_HOVER] = nk_rgba(170, 170, 170, 255);
    table[NK_COLOR_BUTTON_ACTIVE] = nk_rgba(160, 160, 160, 255);
    table[NK_COLOR_TOGGLE] = nk_rgba(150, 150, 150, 255);
    table[NK_COLOR_TOGGLE_HOVER] = nk_rgba(120, 120, 120, 255);
    table[NK_COLOR_TOGGLE_CURSOR] = nk_rgba(175, 175, 175, 255);
    table[NK_COLOR_SELECT] = nk_rgba(190, 190, 190, 255);
    table[NK_COLOR_SELECT_ACTIVE] = nk_rgba(175, 175, 175, 255);
    table[NK_COLOR_SLIDER] = nk_rgba(190, 190, 190, 255);
    table[NK_COLOR_SLIDER_CURSOR] = nk_rgba(80, 80, 80, 255);
    table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgba(70, 70, 70, 255);
    table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgba(60, 60, 60, 255);
    table[NK_COLOR_PROPERTY] = nk_rgba(175, 175, 175, 255);
    table[NK_COLOR_EDIT] = nk_rgba(150, 150, 150, 255);
    table[NK_COLOR_EDIT_CURSOR] = nk_rgba(0, 0, 0, 255);
    table[NK_COLOR_COMBO] = nk_rgba(175, 175, 175, 255);
    table[NK_COLOR_CHART] = nk_rgba(160, 160, 160, 255);
    table[NK_COLOR_CHART_COLOR] = nk_rgba(45, 45, 45, 255);
    table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgba( 255, 0, 0, 255);
    table[NK_COLOR_SCROLLBAR] = nk_rgba(180, 180, 180, 255);
    table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgba(140, 140, 140, 255);
    table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgba(150, 150, 150, 255);
    table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(160, 160, 160, 255);
    table[NK_COLOR_TAB_HEADER] = nk_rgba(180, 180, 180, 255);
    nk_style_from_table(pContext, table);
}
