#include <iostream>

#include "graphicsPipeline.hpp"

GraphicsPipeline::GraphicsPipeline()
 : mVertexShader(nullptr), mPrimitive(nullptr), mRasterizer(nullptr),
   mFragmentShader(nullptr), mFramebuffer(nullptr)
{

}

GraphicsPipeline::~GraphicsPipeline()
{
    delete mVertexShader;
    delete mPrimitive;
    delete mRasterizer;
    delete mFragmentShader;
    delete mFramebuffer;
}

void GraphicsPipeline::configure()
{

}

void GraphicsPipeline::setup()
{
    mVertexShader   = new VertexShader();
    mPrimitive      = new PrimitiveAssembler();
    mRasterizer     = new Rasterizer();
    mFragmentShader = new FragmentShader();
    mFramebuffer    = new Framebuffer(800, 600);
}

//should activate all the pipeline stages one by one
//TODO: better design to pass the uniforms to the vertex shader
void GraphicsPipeline::render(glm::mat4& model, glm::mat4& view, glm::mat4& projection, glm::mat4& viewport)
{
    startVertexShader(model, view, projection, viewport);
    startPrimitiveAssembler();
    startRasterizer();
    startFragmentShader();
}

/* Update glm related data for correct coordinate transformation
 * and pass all vertices from the vertex shader stage process */
void GraphicsPipeline::startVertexShader(glm::mat4& model, glm::mat4& view, glm::mat4& projection, glm::mat4& viewport)
{
    mVertexShader->updateUniforms(model, view, projection, viewport);
    for (unsigned int i = 0; i < mMesh.getIndicesCount(); i++) {
        mVertexShader->compute(mMesh.getVertexAt(i));
    }
}

void GraphicsPipeline::startPrimitiveAssembler()
{
    return;
}

void GraphicsPipeline::startRasterizer()
{
    for (unsigned int i = 0; i < mMesh.getIndicesCount(); i+=3) {
        mRasterizer->updatePoints(mMesh.getVertexAt(i),
                                  mMesh.getVertexAt(i+1),
                                  mMesh.getVertexAt(i+2));
        mRasterizer->compute(mFramebuffer);
    }
}

void GraphicsPipeline::startFragmentShader()
{
    return;
}

void GraphicsPipeline::setMesh(Mesh mesh)
{
    mMesh = mesh;
}

