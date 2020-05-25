#pragma once

#include "vertexShader.hpp"
#include "primitiveAssembly.hpp"
#include "rasterizer.hpp"
#include "fragmentShader.hpp"
#include "mesh.hpp"

class GraphicsPipeline {
private:
    IShader*           mVertexShader;
    PrimitiveAssembly* mTriangle;
    Rasterizer*        mRasterizer;
    IShader*           mFragmentShader;

    void startVertexShader(Mesh& mesh);
    void startRasterizer();
    void startFragmentShader();

public:
    GraphicsPipeline();
    ~GraphicsPipeline();

    void configure();
    void setup();
    void render(Mesh& mesh);
};
