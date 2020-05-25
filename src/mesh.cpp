#include "mesh.hpp"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
 : mVertices(vertices), mIndices(indices)
{

}

Mesh::~Mesh()
{

}

unsigned int Mesh::getIndicesCount() const
{
    return mIndices.size();
}

Vertex& Mesh::getVertexAt(unsigned int i)
{
    return mVertices[i];
}

