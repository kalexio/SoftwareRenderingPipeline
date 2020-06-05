#include "mesh.hpp"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, unsigned int faces)
 : mVertices(vertices), mIndices(indices), mFaces(faces)
{

}

Mesh::Mesh()
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
    return mVertices[mIndices[i]];
}

unsigned int Mesh::getFacesCount() const
{
    return mFaces;
}

