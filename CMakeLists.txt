cmake_minimum_required(VERSION 3.5)

project(GraphicsPipeline)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -Wall -funroll-loops -g -Wextra -Winline -Wreturn-type -Wuninitialized -Winit-self -Werror -Wno-unused-parameter -Wno-unused-function")

find_package(ASSIMP REQUIRED)

set(SOURCE_FILES
    src/engine.cpp
    src/fragmentShader.cpp
    src/graphicsPipeline.cpp
    src/main.cpp
    src/mesh.cpp
    src/model.cpp
    src/primitiveAssembly.cpp
    src/triangle.cpp
    src/vertex.cpp
    src/vertexShader.cpp
)

add_executable(app ${SOURCE_FILES})

include_directories(${ASSIMP_INCLUDE_DIRS})
target_link_libraries(app ${ASSIMP_LIBRARIES})

