#pragma once

#include "vertex.hpp"
#include "gl.hpp"

class VertexShader {
public:
    VertexShader(unsigned int width, unsigned int height);
    ~VertexShader();

    void compute(Vertex& vertex);
    void compute1(attributes_t* attribute, varyings_t* varying);
    void updateUniforms(glm::mat4& model, glm::mat4& view, glm::mat4& projection, glm::mat4& viewport);

private:
    glm::mat4 mModel;
    glm::mat4 mView;
    glm::mat4 mProjection;
    glm::mat4 mViewport;
    unsigned int mWidth;
    unsigned int mHeight;

    void projectionMVP(Vertex& vertex);
    void perspectiveDivision(Vertex& vertex);
    void viewportTransformation(Vertex& vertex);
};

