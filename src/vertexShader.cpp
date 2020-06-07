#include <iostream>

#include "vertexShader.hpp"

VertexShader::VertexShader(unsigned int width, unsigned int height)
 : mWidth(width), mHeight(height)
{

}

VertexShader::~VertexShader()
{

}

void VertexShader::compute(Vertex& vertex)
{
    //std::cout << "Vertex: " << vertex.getPosition().x << std::endl;
    projectionMVP(vertex);
    //std::cout << "MVP Vertex: " << vertex.getPosition().x << std::endl;
    perspectiveDivision(vertex);
    //std::cout << "Divide Vertex: " << vertex.getPosition().x << std::endl;
    viewportTransformation(vertex);
    //std::cout << "Viewport Vertex: " << vertex.getPosition().x << std::endl;

    return;
}

void VertexShader::updateUniforms(glm::mat4& model, glm::mat4& view, glm::mat4& projection, glm::mat4& viewport)
{
    mModel      = model;
    mView       = view;
    mProjection = projection;
    mViewport   = viewport;
}

void VertexShader::projectionMVP(Vertex& vertex)
{
    glm::mat4 matrixMVP = mProjection * mView * mModel;
    vertex.positionMulMat(matrixMVP);
}

void VertexShader::perspectiveDivision(Vertex& vertex)
{
    vertex.perspectiveDivide();
}

void VertexShader::viewportTransformation(Vertex& vertex)
{
    //vertex.positionMulMat(mViewport);
    float halfWidth = float(mWidth) / 2.0f;
    float halfHeight = float(mHeight) / 2.0f;
    vertex.mPosition.x = (vertex.mPosition.x + 1.0f) * halfWidth;
    vertex.mPosition.y = (vertex.mPosition.y + 1.0f) * halfHeight;
}

