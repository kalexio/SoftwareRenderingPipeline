#pragma once

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>

#include "mesh.hpp"

class Model {
private:
    std::vector<Mesh> mMeshes;

    void loadModel(const char* objfile);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);

public:
    Model(const char* objfile);
    unsigned int getMeshesCount() const;
    Mesh getMeshAt(unsigned int);
};

