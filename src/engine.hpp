#pragma once

#include "camera.hpp"
#include "display.hpp"
#include "model.hpp"
#include "graphicsPipeline.hpp"
#include "timer.hpp"

class Engine {
private:
    Camera*           mCamera;
    Display*          mDisplay;
    Model*            mModel;
    GraphicsPipeline* mPipeline;
    Timer             mTimer;

public:
    Engine(const char* modelPath, unsigned int width, unsigned int height);
    ~Engine();

    void run();
};

