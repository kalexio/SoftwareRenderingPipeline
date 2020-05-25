#pragma once

#include "model.hpp"
#include "graphicsPipeline.hpp"

class Engine {
private:
    GraphicsPipeline* mPipeline;
    Model*            mModel;

public:
    Engine();
    ~Engine();

    void setup(const char* modelPath);
    void run();
};

