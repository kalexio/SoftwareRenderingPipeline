#pragma once

#include "vertex.hpp"
#include "framebuffer.hpp"
#include "color.hpp"

class Rasterizer {
private:
    unsigned int x0;
    unsigned int y0;
    unsigned int x1;
    unsigned int y1;

    void barycentric(Framebuffer* framebuffer);
    glm::vec3 edgeFunction(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 pixel);
    void computeAABB();
    bool faceCulling();

    Vertex mVertex1;
    Vertex mVertex2;
    Vertex mVertex3;

public:
    Rasterizer();
    ~Rasterizer();

    void compute(Framebuffer* framebuffer);
    void updatePoints(Vertex& v1, Vertex& v2, Vertex& v3);
};
