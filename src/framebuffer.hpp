#pragma once

#include "color.hpp"
#include <cstdint>

class Framebuffer {
private:
    uint32_t* mColorBuffer;
    float* mDepthBuffer;
    unsigned int mWidth;
    unsigned int mHeight;

public:
    Framebuffer(unsigned int width, unsigned int height);
    ~Framebuffer();

    void setColorBuffer();
    uint32_t* getColorBuffer();
    float* getDepthBuffer();
    void setPixel(const Color& color);
    bool depthBufferTest();
    void setDepth();
};
