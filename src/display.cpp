#include "display.hpp"
#include <iostream>

Display::Display(unsigned int width, unsigned int height)
 : mWindow(nullptr), mSurface(nullptr),
   mTitle("SoftwareRenderingPipeline"), mWidth(width), mHeight(height),
   mQuit(false), mZoom(0.0f)
{
    init();
}

Display::~Display()
{
    SDL_FreeSurface(mSurface);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

bool Display::init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        return false;
    }

    mWindow = SDL_CreateWindow(mTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWidth, mHeight, SDL_WINDOW_SHOWN);
    if (!mWindow) {
        return false;
    }
    mSurface = SDL_GetWindowSurface(mWindow);
    if (!mSurface) {
        return false;
    }

    SDL_GL_SetSwapInterval(1);

    return true;
}

void Display::swapBuffer(const uint32_t* colorBuffer)
{
    SDL_LockSurface(mSurface);
    memcpy(mSurface->pixels, colorBuffer, mWidth * mHeight * 4);
    SDL_UnlockSurface(mSurface);
    return;
}

void Display::handleEvents()
{
    mZoom = 0.0f;
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT: {
                mQuit = true;
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
                    mQuit = true;
                    break;
                }
            }
        }
    }
}

bool Display::requestClose() const
{
    return mQuit;
}

void Display::update() const
{
    SDL_UpdateWindowSurface(mWindow);
}

float Display::getZoom() const
{
    return mZoom;
}

