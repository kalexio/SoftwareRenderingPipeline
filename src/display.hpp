#pragma once

#include <SDL2/SDL.h>

class Display {
private:
    SDL_Window* mWindow;
    SDL_Surface* mSurface;
    const char* mTitle;
    unsigned int mWidth;
    unsigned int mHeight;
    bool mQuit;
    float mZoom;

    bool init();

public:
    Display(unsigned int width, unsigned int height);
    ~Display();

    void handleEvents();
    bool requestClose() const;
    void swapBuffer(const uint32_t* colorBuffer);
    void update() const;
    float getZoom() const;
};
