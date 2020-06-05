#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Vertex {
public:
    glm::vec4 mPosition;
    glm::vec4 mNormal;

    Vertex();
    Vertex(glm::vec4 position, glm::vec4 normal);
    ~Vertex();

    glm::vec4& getPosition();
    glm::vec4& getNormal();

    void positionMulMat(glm::mat4& matrix);
    void normalMulMat(glm::mat4& matrix);
    void perspectiveDivide();
};

