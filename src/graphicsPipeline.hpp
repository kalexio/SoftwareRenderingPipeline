#pragma once

#include "vertexShader.hpp"
#include "primitiveAssembler.hpp"
#include "rasterizer.hpp"
#include "fragmentShader.hpp"
#include "mesh.hpp"
#include "framebuffer.hpp"

class GraphicsPipeline {
private:
    IShader*             mVertexShader;
    PrimitiveAssembler*  mPrimitive;
    Rasterizer*          mRasterizer;
    IShader*             mFragmentShader;
    Mesh                 mMesh;

    void startVertexShader(glm::mat4& model, glm::mat4& view, glm::mat4& projection, glm::mat4& viewport);
    void startPrimitiveAssembler();
    void startRasterizer();
    void startFragmentShader();

public:
    GraphicsPipeline();
    ~GraphicsPipeline();

    void configure();
    void setup();
    void render(glm::mat4& model, glm::mat4& view, glm::mat4& projection, glm::mat4& viewport);
    void setMesh(Mesh mesh);

    Framebuffer*         mFramebuffer;
};
