#pragma once

#include "vertex.hpp"

class IShader {
public:
    IShader() {};
    virtual ~IShader() {};

    virtual Vertex compute(Vertex& vertex) = 0;
    virtual void updateUniforms() = 0;
};
