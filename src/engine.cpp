#include <iostream>

#include "engine.hpp"

Engine::Engine()
 : mDisplay(nullptr), mCamera(nullptr), mPipeline(nullptr), mModel(nullptr)
{

}

Engine::~Engine()
{
    delete mCamera;
    delete mPipeline;
    delete mModel;
    delete mDisplay;
}

void Engine::setup(const char* modelPath, unsigned int width, unsigned int height)
{
    mDisplay  = new Display(width, height);
    mCamera   = new Camera();
    mPipeline = new GraphicsPipeline();
    mModel    = new Model(modelPath);

    //TODO:: better call one function instead of 3
    //the values will be depending on mouse and keyboard actions
    mCamera->setModelMatrix();
    mCamera->setViewMatrix();
    mCamera->setProjectionMatrix();
    mCamera->setViewportMatrix();
    mPipeline->setup();
}

void Engine::run()
{
    while(!mDisplay->requestClose()) {
        mDisplay->update();
        mDisplay->handleEvents();
        mPipeline->mFramebuffer->setColorBuffer();

        /* Loop through all the meshes fo the model, push it to
         * the graphics pipeline and start rendering them */
        for(unsigned int i = 0; i < mModel->getMeshesCount(); ++i) {
            mPipeline->setMesh(mModel->getMeshAt(i));
            //std::cout << "Calling pipeline render " << std::endl;

            mPipeline->render(mCamera->getModelMatrix(),
                              mCamera->getViewMatrix(),
                              mCamera->getProjectionMatrix(),
                              mCamera->getViewportMatrix());
        }
        mDisplay->swapBuffer(mPipeline->mFramebuffer->getColorBuffer());
    }
}

