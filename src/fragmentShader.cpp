#include "fragmentShader.hpp"

FragmentShader::FragmentShader()
 : mOutColor(0)
{

}

FragmentShader::~FragmentShader()
{

}

Color FragmentShader::compute(unsigned int x, unsigned y, const Color& color)
{
    Color outColor = color;

    return outColor;
}

