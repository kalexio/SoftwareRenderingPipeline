#include "framebuffer.hpp"

#include <limits>
#include <cstring>

const Color PURPLE = Color(128, 0, 128, 255);
const Color RED = Color(128, 0, 0, 255);

Framebuffer::Framebuffer(unsigned int width, unsigned int height)
 : mColorBuffer(nullptr), mDepthBuffer(nullptr), mWidth(width), mHeight(height)
{
    uint32_t numOfPixels = mWidth * mHeight;
    mColorBuffer = new uint32_t[numOfPixels]();
    mDepthBuffer = new float[numOfPixels];

    clearFramebuffer();
}

Framebuffer::~Framebuffer()
{
    delete[] mColorBuffer;
    delete[] mDepthBuffer;
}

void Framebuffer::clearColorBuffer()
{
    uint32_t numOfPixels = mWidth * mHeight;
    for(uint32_t i = 0; i < numOfPixels; ++i) {
        std::memcpy(mColorBuffer + i, PURPLE.raw, 4);
    }
}

void Framebuffer::clearDepthBuffer()
{
    uint32_t numOfPixels = mWidth * mHeight;
    for(uint32_t i = 0; i < numOfPixels; ++i) {
        mDepthBuffer[i] = std::numeric_limits<float>::max();
    }
}

void Framebuffer::clearFramebuffer()
{
    clearColorBuffer();
    clearDepthBuffer();
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

bool Framebuffer::depthBufferTest(unsigned int x, unsigned int y, float depth)
{
    if (depth < mDepthBuffer[((mHeight - 1 - y) * mWidth) + x]) {
        return true;
    }

    return false;
}

void Framebuffer::setDepth(unsigned int x, unsigned int y, float depth)
{
    std::memcpy(mDepthBuffer + ((mHeight - 1 - y) * mWidth) + x, &depth, sizeof(float));
    return;
}
