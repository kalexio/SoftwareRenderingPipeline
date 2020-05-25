#pragma once

#include "ishader.hpp"

class VertexShader final : public IShader {
public:
    VertexShader();
    virtual ~VertexShader() override;

    virtual Vertex compute(Vertex& vertex) override;
    virtual void updateUniforms() override;
};
