#include <iostream>

#include "vertex.hpp"

Vertex::Vertex()
 : mPosition(glm::vec4(0.0f)),
   mNormal(glm::vec4(0.0f))
{

}

Vertex::Vertex(glm::vec4 position, glm::vec4 normal)
 : mPosition(position), mNormal(normal)
{

}

Vertex::~Vertex()
{

}

glm::vec4& Vertex::getPosition()
{
    return mPosition;
}

glm::vec4& Vertex::getNormal()
{
    return mNormal;
}

void Vertex::positionMulMat(glm::mat4& matrix)
{
    mPosition = matrix * mPosition;
}

void Vertex::normalMulMat(glm::mat4& matrix)
{
    mNormal = matrix * mNormal;
}

void Vertex::perspectiveDivide()
{
    float w_inv = 1.0f / mPosition.w;
    mPosition.x = mPosition.x * w_inv;
    mPosition.y = mPosition.y * w_inv;
    mPosition.z = mPosition.z * w_inv;
    mPosition.w = 1.0f;
}

