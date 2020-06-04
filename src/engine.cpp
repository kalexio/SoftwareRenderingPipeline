#include <iostream>

#include "engine.hpp"

Engine::Engine(const char* modelPath, unsigned int width, unsigned int height)
 : mCamera(new Camera(width, height)),
   mDisplay(new Display(width, height)),
   mModel(new Model(modelPath)),
   mPipeline(new GraphicsPipeline(width, height))
{

}

Engine::~Engine()
{
    delete mCamera;
    delete mDisplay;
    delete mModel;
    delete mPipeline;
}

void Engine::run()
{
    while(!mDisplay->requestClose()) {
        mTimer.startRecording();
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
        mTimer.stopRecording();
        mTimer.getFPS();
    }
}

