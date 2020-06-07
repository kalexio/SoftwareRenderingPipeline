#pragma once

#include "vertex.hpp"
#include "framebuffer.hpp"
#include "color.hpp"
#include "fragmentShader.hpp"

class Rasterizer {
private:
    unsigned int x0;
    unsigned int y0;
    unsigned int x1;
    unsigned int y1;

    void barycentric(Framebuffer* framebuffer, FragmentShader* fragmentShader);
    glm::vec3 edgeFunction(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 pixel);
    void computeAABB();
    bool faceCulling();
    float interpolate_depth(glm::vec3 depths, glm::vec3 weights);

    Vertex mVertex1;
    Vertex mVertex2;
    Vertex mVertex3;

    glm::vec3 attrPos1;
    glm::vec3 attrPos2;
    glm::vec3 attrPos3;

public:
    Rasterizer();
    ~Rasterizer();

    void compute(Framebuffer* framebuffer, FragmentShader* fragmentShader);
    void updatePoints(Vertex* attributes, glm::vec3* attrPos);
};
