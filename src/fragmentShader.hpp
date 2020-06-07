#pragma once

#include "color.hpp"

class FragmentShader {
private:
    Color mOutColor;

public:
    FragmentShader();
    ~FragmentShader();

    Color compute(unsigned int x, unsigned y, const Color& color);
};

