#include "program.hpp"

Program::Program()
 : mVertexShader(nullptr), mFragmentShader(nullptr),
   attributes{}, varyings{}
{

}

Program::~Program()
{

}

void Program::attachVertexShader(VertexShader* shader)
{
    mVertexShader = shader;
}

void Program::attachFragmentShader(FragmentShader* shader)
{
    mFragmentShader = shader;
}

void Program::setAttributes(Vertex& vertex, unsigned int index)
{
    attributes[index].position = vertex.getPosition();
    attributes[index].normal = vertex.getPosition();
}