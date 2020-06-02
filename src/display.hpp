#pragma once

#include <SDL2/SDL.h>

class Display {
private:
    SDL_Window* window;
    SDL_Surface* surface;
    const char* title;
    unsigned int width;
    unsigned int height;
    bool quit;

    bool init();

public:
    Display(unsigned int width, unsigned int height);
    ~Display();

    void handleEvents();
    bool requestClose() const;
    void swapBuffer(const uint32_t* colorBuffer);
    void update();
};
