#pragma once

#include "vertexShader.hpp"
#include "primitiveAssembler.hpp"
#include "fragmentShader.hpp"
#include "rasterizer.hpp"
#include "mesh.hpp"
#include "framebuffer.hpp"
#include "camera.hpp"
#include "program.hpp"

class GraphicsPipeline {
private:
    VertexShader*        mVertexShader;
    PrimitiveAssembler*  mPrimitive;
    Rasterizer*          mRasterizer;
    Mesh                 mMesh;
    Camera*              mCamera;
    Program*             mProgram;

    void startVertexShader(Vertex* attributes);
    void startPrimitiveAssembler();
    void startRasterizer(Vertex* attributes, glm::vec3* attrPos);
    void startFragmentShader();

public:
    Framebuffer*         mFramebuffer;
    FragmentShader*      mFragmentShader;
    
    GraphicsPipeline(unsigned int width, unsigned int height);
    ~GraphicsPipeline();

    void render(float zoom);
    void setMesh(Mesh mesh);
};
