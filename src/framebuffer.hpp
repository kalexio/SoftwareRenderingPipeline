#pragma once

#include "color.hpp"
#include <cstdint>

class Framebuffer {
private:
    uint32_t* mColorBuffer;
    float* mDepthBuffer;
    unsigned int mWidth;
    unsigned int mHeight;

    void clearColorBuffer();
    void clearDepthBuffer();

public:
    Framebuffer(unsigned int width, unsigned int height);
    ~Framebuffer();

    void clearFramebuffer();
    uint32_t* getColorBuffer();
    float* getDepthBuffer();
    void setPixel(unsigned int x, unsigned y, const Color& color);
    bool depthBufferTest(unsigned int x, unsigned int y, float depth);
    void setDepth(unsigned int x, unsigned int y, float depth);
};
