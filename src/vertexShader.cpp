#include <iostream>

#include "vertexShader.hpp"

VertexShader::VertexShader()
{

}

VertexShader::~VertexShader()
{

}

Vertex VertexShader::compute(Vertex& vertex)
{
    //std::cout << "Vertices: " << vertex.mPosition.x << std::endl;
    //GLM multiplication
    //MVP , perspective, viewport
    //declare a vec4 here
    return Vertex();
}

void VertexShader::updateUniforms()
{
    return;
}

