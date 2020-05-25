#include <iostream>

#include "engine.hpp"

const char* MODEL_PATH = "/home/user/Desktop/graphics/sw-graphics-pipeline-rasterizer/obj/monkey_smooth.obj";

int main() {
    std::cout << "The beginning of a journey" << std::endl;

    Engine engine;
    engine.setup(MODEL_PATH);
    engine.run();

    return 0;
}

