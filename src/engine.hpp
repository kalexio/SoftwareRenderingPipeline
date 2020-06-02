#pragma once

#include "camera.hpp"
#include "display.hpp"
#include "model.hpp"
#include "graphicsPipeline.hpp"

class Engine {
private:
    Display*          mDisplay;
    Camera*           mCamera;
    GraphicsPipeline* mPipeline;
    Model*            mModel;

public:
    Engine();
    ~Engine();

    void setup(const char* modelPath, unsigned int width, unsigned int height);
    void run();
};

