#include "camera.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>
#include <iostream>

// Default camera values
const float ZOOM =  45.0f;

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

Camera::Camera()
 : mPosition(glm::vec3(0.0f, 0.0f, 3.0f)),
   mTarget(glm::vec3(0.0f, 0.0f, 0.0f)),
   mUp(glm::vec3(0.0f, 1.0f, 0.0f))
{

}

Camera::~Camera()
{

}

glm::mat4& Camera::getModelMatrix()
{
    return mModel;
}

glm::mat4& Camera::getViewMatrix()
{
    return mView;
}

glm::mat4& Camera::getProjectionMatrix()
{
    return mProjection;
}

glm::mat4& Camera::getViewportMatrix()
{
    return mViewport;
}

void Camera::setModelMatrix()
{
    mModel = glm::mat4(1.0f);
    std::cout << glm::to_string(mModel) << std::endl;
}

void Camera::setViewMatrix()
{
    mView = glm::lookAt(mPosition, mTarget, mUp);
    std::cout << glm::to_string(mView) << std::endl;
}

void Camera::setProjectionMatrix()
{
    mProjection = glm::perspective(glm::radians(ZOOM), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    std::cout << glm::to_string(mProjection) << std::endl;
}

void Camera::setViewportMatrix()
{
    mViewport = glm::mat4(1.0f);
    mViewport[0][0] = 400.0f;
    mViewport[0][3] = 400.0f;
    mViewport[1][1] = 300.0f;
    mViewport[1][3] = 300.0f;
    std::cout << glm::to_string(mModel) << std::endl;
}

