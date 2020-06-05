#pragma once

#include "display.hpp"
#include "model.hpp"
#include "graphicsPipeline.hpp"
#include "timer.hpp"

class Engine {
private:
    Display*          mDisplay;
    Model*            mModel;
    GraphicsPipeline* mPipeline;
    Timer             mTimer;

    void renderModels(float zoom);

public:
    Engine(const char* modelPath, unsigned int width, unsigned int height);
    ~Engine();

    void run();
};

