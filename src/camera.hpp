#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
private:
    glm::vec3 mPosition;
    glm::vec3 mTarget;
    glm::vec3 mUp;

    glm::mat4 mModel;
    glm::mat4 mView;
    glm::mat4 mProjection;
    glm::mat4 mViewport;

    unsigned int mWidth;
    unsigned int mHeight;

    void setModelMatrix();
    void setViewMatrix();
    void setProjectionMatrix();
    void setViewportMatrix();

public:
    Camera(unsigned int width, unsigned int height);
    ~Camera();

    glm::mat4& getModelMatrix();
    glm::mat4& getViewMatrix();
    glm::mat4& getProjectionMatrix();
    glm::mat4& getViewportMatrix();

    void prepareTransormationMatrices();
};

