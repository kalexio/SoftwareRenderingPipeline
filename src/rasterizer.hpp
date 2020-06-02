#pragma once

#include "vertex.hpp"

class Rasterizer {
private:
    unsigned int x0;
    unsigned int y0;
    unsigned int x1;
    unsigned int y1;

    void barycentric();
    void computeAABB();
    bool faceCulling();

    Vertex mVertex1;
    Vertex mVertex2;
    Vertex mVertex3;

public:
    Rasterizer();
    ~Rasterizer();

    void compute();
    void updatePoints(Vertex& v1, Vertex& v2, Vertex& v3);
};
