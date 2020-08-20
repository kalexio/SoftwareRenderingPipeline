#pragma once

#include "vertex.hpp"
#include "framebuffer.hpp"
#include "color.hpp"
#include "fragmentShader.hpp"
#include "gl.hpp"

class Rasterizer {
private:
    unsigned int x0;
    unsigned int y0;
    unsigned int x1;
    unsigned int y1;
    unsigned int mWidth;
    unsigned int mHeight;

    void barycentric(Framebuffer* framebuffer, FragmentShader* fragmentShader, varyings_t* varyings);
    glm::vec3 edgeFunction(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 pixel);
    void computeAABB(varyings_t* varyings);
    bool faceCulling(varyings_t* varyings);
    float interpolate_depth(glm::vec3 depths, glm::vec3 weights);

public:
    Rasterizer(unsigned int width, unsigned int height);
    ~Rasterizer();

    void compute(Framebuffer* framebuffer, FragmentShader* fragmentShader, varyings_t* varyings);
};
