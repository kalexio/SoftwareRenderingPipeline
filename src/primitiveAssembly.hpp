#pragma once

#include <vector>

#include "triangle.hpp"


class PrimitiveAssembly {
private:
    enum class PRIMITIVE_MODE {
        POINTS = 1,
        LINES,
        TRIANGLES
    } primitiveMode;

public:
    std::vector<Triangle> mTriangles;

    PrimitiveAssembly();
    ~PrimitiveAssembly();
};
