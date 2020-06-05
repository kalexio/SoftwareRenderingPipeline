#include "graphicsPipeline.hpp"

GraphicsPipeline::GraphicsPipeline(unsigned int width, unsigned int height)
 : mVertexShader(new VertexShader()),
   mPrimitive(new PrimitiveAssembler()),
   mRasterizer(new Rasterizer()),
   mFragmentShader(new FragmentShader()),
   mCamera(new Camera(width, height)),
   mFramebuffer(new Framebuffer(width, height))
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
}

void GraphicsPipeline::render(float zoom)
{
    unsigned int numFaces = mMesh.getFacesCount();
    Vertex attributes[3];
    glm::vec3 attrPos[3];

    mCamera->setZoom(zoom);

    for (unsigned int i = 0; i < numFaces; ++i) {
        for (unsigned int j = 0; j < 3; ++j) {
            attributes[j] = mMesh.getVertexAt(i * 3 + j);
            glm::vec3 v(attributes[j].getPosition());
            attrPos[j] = v;
        }
        startVertexShader(attributes);
        startPrimitiveAssembler();
        startRasterizer(attributes, attrPos);
        startFragmentShader();
    }
}

void GraphicsPipeline::startVertexShader(Vertex* attributes)
{
    glm::mat4 model = mCamera->getModelMatrix();
    glm::mat4 view = mCamera->getViewMatrix();
    glm::mat4 projection = mCamera->getProjectionMatrix();
    glm::mat4 viewport = mCamera->getViewportMatrix();

    mVertexShader->updateUniforms(model, view, projection, viewport);
    for (unsigned int i = 0; i < 3; i++) {
        mVertexShader->compute(attributes[i]);
    }
}

void GraphicsPipeline::startPrimitiveAssembler()
{
    return;
}

void GraphicsPipeline::startRasterizer(Vertex* attributes, glm::vec3* attrPos)
{
    mRasterizer->updatePoints(attributes, attrPos);
    mRasterizer->compute(mFramebuffer);
}

void GraphicsPipeline::startFragmentShader()
{
    return;
}

void GraphicsPipeline::setMesh(Mesh mesh)
{
    mMesh = mesh;
}

