#include "rasterizer.hpp"
#include <iostream>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>
#include <iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

Rasterizer::Rasterizer()
{

}

Rasterizer::~Rasterizer()
{

}

void Rasterizer::updatePoints(Vertex& v1, Vertex& v2, Vertex& v3)
{
    mVertex1 = v1;
    mVertex2 = v2;
    mVertex3 = v3;
}

void Rasterizer::compute(Framebuffer* framebuffer)
{
    bool discard = false;

    discard = faceCulling();
    if (discard == true) {
        //std::cout << "discarded" << std::endl;
        return;
    }

    computeAABB();
    barycentric(framebuffer);
}

void Rasterizer::computeAABB()
{
    float xmin, xmax, ymin, ymax;

    xmin = std::min(std::min(mVertex1.getPosition().x, mVertex2.getPosition().x), mVertex3.getPosition().x),
    ymin = std::min(std::min(mVertex1.getPosition().y, mVertex2.getPosition().y), mVertex3.getPosition().y);
    xmax = std::max(std::max(mVertex1.getPosition().x, mVertex2.getPosition().x), mVertex3.getPosition().x);
    ymax = std::max(std::max(mVertex1.getPosition().y, mVertex2.getPosition().y), mVertex3.getPosition().y);
    //std::cout << "xmin: " << xmin << std::endl;
    //std::cout << "ymin: " << ymin << std::endl;
    //std::cout << "xmax: " << xmax << std::endl;
    //std::cout << "ymax: " << ymax << std::endl;

    x0 = std::max((unsigned int)0, (unsigned int)(std::floor(xmin)));
    x1 = std::min(SCR_WIDTH - 1, (unsigned int)(std::floor(xmax)));
    y0 = std::max((unsigned int)0, (unsigned int)(std::floor(ymin)));
    y1 = std::min(SCR_HEIGHT - 1, (unsigned int)(std::floor(ymax)));
    //std::cout << "xmin: " << x0 << std::endl;
    //std::cout << "ymin: " << y0 << std::endl;
    //std::cout << "xmax: " << x1 << std::endl;
    //std::cout << "ymax: " << y1 << std::endl;
}

void Rasterizer::barycentric(Framebuffer* framebuffer)
{
    glm::vec3 v1(mVertex1.getPosition());
    glm::vec3 v2(mVertex2.getPosition());
    glm::vec3 v3(mVertex3.getPosition());

    //TODO compute light direction and pass the correct light to fragment
    Color color(rand()%255, rand()%255, rand()%255, 255);
    for(unsigned int y = y0; y <= y1; ++y) {
        for(unsigned int x = x0; x <= x1; ++x) {
            glm::vec3 pixel(x + 0.5, y +0.5, 0);
            glm::vec3 weights = edgeFunction(v1, v2, v3, pixel);

            if(weights.x >= 0 && weights.y>= 0 && weights.z >= 0) {
                framebuffer->setPixel(x, y, color);
            }
        }
    }
}

bool Rasterizer::faceCulling()
{
    bool faceCulling = false;
    glm::vec3 v1(mVertex1.getPosition());
    glm::vec3 v2(mVertex2.getPosition());
    glm::vec3 v3(mVertex3.getPosition());


    glm::vec3 normal = glm::cross(v3 - v1, v2 - v1);
    if ( normal.z < 0) {
        faceCulling = true;
    }

    return faceCulling;
}

glm::vec3 Rasterizer::edgeFunction(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 pixel)
{
    glm::vec3 ab = v2 - v1;
    glm::vec3 ac = v3 - v1;
    glm::vec3 ap = pixel - v1;

    float factor = 1 / (ab.x * ac.y - ab.y * ac.x);
    float s = (ac.y * ap.x - ac.x * ap.y) * factor;
    float t = (ab.x * ap.y - ab.y * ap.x) * factor;

    glm::vec3 weights(1 - s - t, s, t);
    return weights;
}

