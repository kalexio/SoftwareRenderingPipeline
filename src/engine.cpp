#include <iostream>

#include "engine.hpp"

Engine::Engine()
 : mPipeline(nullptr), mModel(nullptr)
{

}

Engine::~Engine()
{
    delete mPipeline;
    delete mModel;
}

void Engine::setup(const char* modelPath)
{
    mPipeline = new GraphicsPipeline();
    mModel    = new Model(modelPath);

    mPipeline->setup();
}

void Engine::run()
{
    for(unsigned int i = 0; i < mModel->getMeshesCount(); i++) {
        std::cout << "Calling pipeline run " << std::endl;
        mPipeline->render(mModel->getMeshAt(i));
    }
}

