/* This class is like a triangle mesh */

#pragma once

#include <vector>

#include "triangle.hpp"

class PrimitiveAssembler {
public:
    Triangle mTriangle;

    PrimitiveAssembler();
    ~PrimitiveAssembler();

    void Assemble();
};
