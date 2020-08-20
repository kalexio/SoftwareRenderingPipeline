#include "graphicsPipeline.hpp"
#include <x86intrin.h>
#include <iostream>

GraphicsPipeline::GraphicsPipeline(unsigned int width, unsigned int height)
 : mVertexShader(new VertexShader(width, height)),
   mPrimitive(new PrimitiveAssembler()),
   mRasterizer(new Rasterizer(width, height)),
   mCamera(new Camera(width, height)),
   mProgram(new Program()),
   mFramebuffer(new Framebuffer(width, height)),
   mFragmentShader(new FragmentShader())
{

}

GraphicsPipeline::~GraphicsPipeline()
{
    delete mVertexShader;
    delete mPrimitive;
    delete mRasterizer;
    delete mFragmentShader;
    delete mFramebuffer;
    delete mCamera;
    delete mProgram;
}

/* Render all the faces of one mesh */
void GraphicsPipeline::render(float zoom)
{
    //uint64_t startCycleCount = _rdtsc();

    unsigned int numFaces = mMesh.getFacesCount();
    Vertex attributes[3];
    glm::vec3 attrPos[3];

    mCamera->setZoom(zoom);

    //mProgram->attachVertexShader(mVertexShader);

    for (unsigned int i = 0; i < numFaces; ++i) {
        for (unsigned int j = 0; j < 3; ++j) {
            mProgram->setAttributes(mMesh.getVertexAt(i * 3 + j), j);
        }
        startVertexShader(attributes);
        startPrimitiveAssembler();
        startRasterizer(attributes, attrPos);
        startFragmentShader();
    }

    //uint64_t endCycleCount = _rdtsc();
    //uint64_t elapsedCycleCount = endCycleCount - startCycleCount;
    //std::cout << "Barycentric cycles: " << elapsedCycleCount << '\n';
}

void GraphicsPipeline::startVertexShader(Vertex* attributes)
{
    glm::mat4 model = mCamera->getModelMatrix();
    glm::mat4 view = mCamera->getViewMatrix();
    glm::mat4 projection = mCamera->getProjectionMatrix();
    glm::mat4 viewport = mCamera->getViewportMatrix();

    mVertexShader->updateUniforms(model, view, projection, viewport);
    for (unsigned int i = 0; i < 3; ++i) {
        mVertexShader->compute1(&mProgram->attributes[i], &mProgram->varyings[i]);
    }
}

void GraphicsPipeline::startPrimitiveAssembler()
{
    return;
}

void GraphicsPipeline::startRasterizer(Vertex* attributes, glm::vec3* attrPos)
{
    mRasterizer->compute(mFramebuffer, mFragmentShader, mProgram->varyings);
}

void GraphicsPipeline::startFragmentShader()
{
    return;
}

void GraphicsPipeline::setMesh(Mesh mesh)
{
    mMesh = mesh;
}

