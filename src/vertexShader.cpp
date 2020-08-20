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

void VertexShader::compute1(attributes_t* attribute, varyings_t* varying)
{
    varying->normal = glm::vec3(attribute->position.x, attribute->position.y, attribute->position.z);

    glm::mat4 matrixMVP = mProjection * mView * mModel;
    attribute->position = matrixMVP * attribute->position;

    float w_inv = 1.0f / attribute->position.w;
    attribute->position.x = attribute->position.x * w_inv;
    attribute->position.y = attribute->position.y * w_inv;
    attribute->position.z = attribute->position.z * w_inv;
    attribute->position.w = 1.0f;

    float halfWidth = float(mWidth) / 2.0f;
    float halfHeight = float(mHeight) / 2.0f;
    attribute->position.x = (attribute->position.x + 1.0f) * halfWidth;
    attribute->position.y = (attribute->position.y + 1.0f) * halfHeight;

    varying->position = glm::vec3(attribute->position.x, attribute->position.y, attribute->position.z);
    //varying->normal = glm::vec3(attribute->normal);
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
