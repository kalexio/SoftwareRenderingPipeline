#include "framebuffer.hpp"

#include <limits>
#include <cstring>

const Color PURPLE = Color(128, 0, 128, 255);
const Color RED = Color(128, 0, 0, 255);

Framebuffer::Framebuffer(unsigned int width, unsigned int height)
 : mColorBuffer(nullptr), mDepthBuffer(nullptr), mWidth(width), mHeight(height)
{
    unsigned long size = mWidth * mHeight;
    mColorBuffer = new uint32_t[size]();
    mDepthBuffer = new float[size];
    for(unsigned int i = 0; i < width * height; ++i) {
       mDepthBuffer[i] = std::numeric_limits<float>::lowest();
    }
}

Framebuffer::~Framebuffer()
{
    delete[] mColorBuffer;
    delete[] mDepthBuffer;
}

void Framebuffer::setColorBuffer()
{
    for(unsigned int i = 0; i < mWidth * mHeight; ++i) {
        std::memcpy(mColorBuffer + i, PURPLE.raw, 4);
    }
}

uint32_t* Framebuffer::getColorBuffer()
{
    return mColorBuffer;
}

float* Framebuffer::getDepthBuffer()
{
    return mDepthBuffer;
}

void Framebuffer::setPixel(unsigned int x, unsigned int y, const Color& color)
{
    std::memcpy(mColorBuffer + ((mHeight - 1 - y) * mWidth) + x, color.raw, 4);
}

bool Framebuffer::depthBufferTest()
{
    return true;
}

void Framebuffer::setDepth()
{
    return;
}

