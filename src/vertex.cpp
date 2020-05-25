#include "vertex.hpp"

Vertex::Vertex()
 : mPosition(glm::vec3(0.0f, 0.0f, 0.0f)),
   mNormal(glm::vec3(0.0f, 0.0f, 0.0f))
{

}

Vertex::Vertex(glm::vec3 position, glm::vec3 normal)
 : mPosition(position), mNormal(normal)
{

}

Vertex::~Vertex()
{

}

