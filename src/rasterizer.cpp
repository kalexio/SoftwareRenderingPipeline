#include "rasterizer.hpp"
#include <iostream>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

Rasterizer::Rasterizer(unsigned int width, unsigned int height)
 : mWidth(width), mHeight(height)
{

}

Rasterizer::~Rasterizer()
{

}

void Rasterizer::compute(Framebuffer* framebuffer, FragmentShader* fragmentShader, varyings_t* varyings)
{
    bool discard = false;

    discard = faceCulling(varyings);
    if (discard == true) {
        return;
    }

    computeAABB(varyings);
    barycentric(framebuffer, fragmentShader, varyings);

}

void Rasterizer::computeAABB(varyings_t* varyings)
{
    float xmin, xmax, ymin, ymax;

    xmin = std::min(std::min(varyings[0].position.x, varyings[1].position.x), varyings[2].position.x),
    ymin = std::min(std::min(varyings[0].position.y, varyings[1].position.y), varyings[2].position.y);
    xmax = std::max(std::max(varyings[0].position.x, varyings[1].position.x), varyings[2].position.x);
    ymax = std::max(std::max(varyings[0].position.y, varyings[1].position.y), varyings[2].position.y);

    x0 = std::max((unsigned int)0, (unsigned int)(std::floor(xmin)));
    x1 = std::min(mWidth - 1, (unsigned int)(std::floor(xmax)));
    y0 = std::max((unsigned int)0, (unsigned int)(std::floor(ymin)));
    y1 = std::min(mHeight - 1, (unsigned int)(std::floor(ymax)));
}

void Rasterizer::barycentric(Framebuffer* framebuffer, FragmentShader* fragmentShader, varyings_t* varyings)
{
    glm::vec3 v1(varyings[0].position);
    glm::vec3 v2(varyings[1].position);
    glm::vec3 v3(varyings[2].position);

    glm::vec3 lightDir = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::vec3 v3v1 = varyings[2].normal - varyings[0].normal;
    glm::vec3 v2v1 = varyings[1].normal - varyings[0].normal;
    glm::vec3 n = glm::normalize(glm::cross(v3v1, v2v1));

    float intensity = glm::dot(n, lightDir);

    if (intensity > 0 ) {
        Color color(intensity * 255, intensity * 255, intensity * 255, 255);
        for(unsigned int y = y0; y <= y1; ++y) {
            for(unsigned int x = x0; x <= x1; ++x) {
                glm::vec3 pixel(x + 0.5, y +0.5, 0);
                glm::vec3 weights = edgeFunction(v1, v2, v3, pixel);

                if(weights.x >= 0 && weights.y>= 0 && weights.z >= 0) {
                    glm::vec3 depths(v1.z, v2.z, v3.z);
                    float depth = interpolate_depth(depths, weights);
                    bool test = framebuffer->depthBufferTest(x, y, depth);
                    if (test) {
                        Color outColor = fragmentShader->compute(x, y, color);
                        framebuffer->setDepth(x, y, depth);
                        framebuffer->setPixel(x, y, outColor);
                    }
                }
            }
        }
    }
}

bool Rasterizer::faceCulling(varyings_t* varyings)
{
    bool faceCulling = false;

    glm::vec3 normal = glm::cross(varyings[2].normal - varyings[0].normal, varyings[1].normal - varyings[0].normal);
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

float Rasterizer::interpolate_depth(glm::vec3 depths, glm::vec3 weights) {
     float depth0 = depths.x * weights.x;
     float depth1 = depths.y * weights.y;
     float depth2 = depths.z * weights.z;
     return depth0 + depth1 + depth2;
}
