#pragma once

#include <vector>

#include "vertex.hpp"

class Mesh {
private:
    std::vector<Vertex>       mVertices;
    std::vector<unsigned int> mIndices;
    unsigned int mFaces;

public:
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, unsigned int faces);
    Mesh();
    ~Mesh();

    unsigned int getIndicesCount() const;
    unsigned int getFacesCount() const;
    Vertex& getVertexAt(unsigned int i);
};

