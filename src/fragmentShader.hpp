#pragma once

#include "ishader.hpp"

class FragmentShader final : public IShader {
public:
    FragmentShader();
    virtual ~FragmentShader() override;

    virtual void compute(Vertex& vertex) override;
    virtual void updateUniforms(glm::mat4& model, glm::mat4& view, glm::mat4& projection, glm::mat4& viewport) override;
};

