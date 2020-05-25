#pragma once

#include "ishader.hpp"

class FragmentShader final : public IShader {
public:
    FragmentShader();
    virtual ~FragmentShader() override;

    virtual Vertex compute(Vertex& vertex) override;
    virtual void updateUniforms() override;
};

