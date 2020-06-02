#pragma once

#include "vertex.hpp"

class IShader {
public:
    virtual ~IShader() {};

    virtual void compute(Vertex& vertex) = 0;
    virtual void updateUniforms(glm::mat4& model, glm::mat4& view, glm::mat4& projection, glm::mat4& viewport) = 0;
};
