#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Vertex {
public:
    glm::vec3 mPosition;
    glm::vec3 mNormal;

    Vertex();
    Vertex(glm::vec3 position, glm::vec3 normal);
    ~Vertex();
};
