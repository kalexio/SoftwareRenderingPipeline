#include "display.hpp"
#include <iostream>

Display::Display(unsigned int width, unsigned int height)
 : window(nullptr), surface(nullptr),
   title("SoftwareRenderingPipeline"), width(width), height(height),
   quit(false), mZoom(0.0f)
{
    init();
}

Display::~Display()
{
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Display::init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        return false;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        return false;
    }
    surface = SDL_GetWindowSurface(window);
    if (!surface) {
        return false;
    }

    SDL_GL_SetSwapInterval(1);

    return true;
}

void Display::swapBuffer(const uint32_t* colorBuffer)
{
    SDL_LockSurface(surface);
    memcpy(surface->pixels, colorBuffer, width * height * 4);
    SDL_UnlockSurface(surface);
    return;
}

void Display::handleEvents()
{
    mZoom = 0.0f;
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT: {
                quit = true;
                break;
            }
            case SDL_MOUSEWHEEL: {
                if (event.wheel.y > 0) {
                    mZoom = 1.0f;
                    break;
                }
                if (event.wheel.y < 0) {
                    mZoom = -1.0f;
                    break;
                }
                break;
            }
            case SDL_KEYDOWN: {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;
                    break;
                }
            }
        }
    }
}

bool Display::requestClose() const
{
    return quit;
}

void Display::update() const
{
    SDL_UpdateWindowSurface(window);
}

float Display::getZoom() const
{
    return mZoom;
}

