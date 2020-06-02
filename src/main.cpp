#include <iostream>

#include "engine.hpp"

const char* MODEL_PATH = "/home/user/Desktop/graphics/sw-graphics-pipeline-rasterizer/obj/monkey_smooth.obj";
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    std::cout << "The beginning of a journey" << '\n';

    Engine engine;
    engine.setup(MODEL_PATH, SCR_WIDTH, SCR_HEIGHT);
    engine.run();

    return 0;
}

