#pragma once

#include <vector>

#include "vertex.hpp"

class Mesh {
private:
    std::vector<Vertex>       mVertices;
    std::vector<unsigned int> mIndices;

public:
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
    Mesh();
    ~Mesh();

    unsigned int getIndicesCount() const;
    Vertex& getVertexAt(unsigned int i);
};

