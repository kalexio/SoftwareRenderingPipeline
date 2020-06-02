#pragma once

#include "ishader.hpp"

class VertexShader final : public IShader {
public:
    VertexShader();
    virtual ~VertexShader() override;

    virtual void compute(Vertex& vertex) override;
    virtual void updateUniforms(glm::mat4& model, glm::mat4& view, glm::mat4& projection, glm::mat4& viewport) override;

private:
    glm::mat4 mModel;
    glm::mat4 mView;
    glm::mat4 mProjection;
    glm::mat4 mViewport;

    void projectionMVP(Vertex& vertex);
    void perspectiveDivision(Vertex& vertex);
    void viewportTransformation(Vertex& vertex);
};
