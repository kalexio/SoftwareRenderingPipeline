#include <iostream>

#include "graphicsPipeline.hpp"

GraphicsPipeline::GraphicsPipeline()
 : mVertexShader(nullptr), mTriangle(nullptr), mRasterizer(nullptr), mFragmentShader(nullptr)
{

}

GraphicsPipeline::~GraphicsPipeline()
{
    delete mVertexShader;
    delete mTriangle;
    delete mRasterizer;
    delete mFragmentShader;
}

void GraphicsPipeline::configure()
{

}

void GraphicsPipeline::setup()
{
    mVertexShader   = new VertexShader();
    mTriangle       = new PrimitiveAssembly();
    mRasterizer     = new Rasterizer();
    mFragmentShader = new FragmentShader();
}

//should activate all the pipeline stages one by one
void GraphicsPipeline::render(Mesh& mesh)
{
    startVertexShader(mesh);
    startRasterizer();
    startFragmentShader();
}

void GraphicsPipeline::startVertexShader(Mesh& mesh)
{
    mVertexShader->updateUniforms();

    for(unsigned int i = 0; i < mesh.getIndicesCount(); ++i) {
        std::cout << "Calling vertex shader compute " << i << std::endl;
        mVertexShader->compute(mesh.getVertexAt(i));
    }
}

void GraphicsPipeline::startRasterizer()
{
    return;
}

void GraphicsPipeline::startFragmentShader()
{
    return;
}

