#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "vertexShader.hpp"
#include "fragmentShader.hpp"
#include "gl.hpp"


class Program {
private:
    VertexShader* mVertexShader;
    FragmentShader* mFragmentShader;

public:
    attributes_t attributes[3];
    varyings_t varyings[3];

    Program();
    ~Program();

    void attachVertexShader(VertexShader* shader);
    void attachFragmentShader(FragmentShader* shader);
    void setAttributes(Vertex& vertex, unsigned int index);
};
