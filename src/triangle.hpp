#pragma once

#include "vertex.hpp"

class Triangle {
private:
    Vertex mVertex1;
    Vertex mVertex2;
    Vertex mVertex3;

public:
    Triangle() {};
    Triangle(Vertex& v1, Vertex& v2, Vertex& v3);
    ~Triangle();

    Vertex getVertex1();
    Vertex getVertex2();
    Vertex getVertex3();
};
