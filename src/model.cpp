#include <iostream>

#include "model.hpp"

unsigned int meshes = 0;
unsigned int faces = 0;

Model::Model(const char* objfile)
{
    loadModel(objfile);
}

void Model::loadModel(const char* objfile)
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(objfile, aiProcess_Triangulate);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
        return;
    }

    processNode(scene->mRootNode, scene);
    std::cout << "Num of meshes: " << meshes << '\n';
    std::cout << "Num of faces: " << faces << '\n';
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
    for (unsigned int i = 0; i < node->mNumMeshes; ++i) {
        meshes += node->mNumMeshes;
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        mMeshes.push_back(processMesh(mesh, scene));
    }

    for (unsigned int i = 0; i < node->mNumChildren; ++i) {
        processNode(node->mChildren[i], scene);
    }
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
        Vertex vertex;

        vertex.mPosition.x = mesh->mVertices[i].x;
        vertex.mPosition.y = mesh->mVertices[i].y;
        vertex.mPosition.z = mesh->mVertices[i].z;
        vertex.mPosition.w = 1.0f;

        vertex.mNormal.x = mesh->mNormals[i].x;
        vertex.mNormal.y = mesh->mNormals[i].y;
        vertex.mNormal.z = mesh->mNormals[i].z;
        vertex.mNormal.w = 0.0f;

        vertices.push_back(vertex);
    }

    faces += mesh->mNumFaces;
    for (unsigned int i = 0; i < mesh->mNumFaces; ++i) {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; ++j) {
            indices.push_back(face.mIndices[j]);
        }
    }

    return Mesh(vertices, indices, mesh->mNumFaces);
}

unsigned int Model::getMeshesCount() const
{
    return mMeshes.size();
}

Mesh Model::getMeshAt(unsigned int i)
{
    return mMeshes[i];
}

