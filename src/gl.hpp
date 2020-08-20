#pragma once

typedef struct {
    glm::vec4 position;
    glm::vec4 normal;
    glm::vec2 texCoord;
} attributes_t;

typedef struct {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoord;
} varyings_t;

typedef struct {
    int nothing;
} uniforms_t;
