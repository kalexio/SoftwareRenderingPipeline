cmake_minimum_required(VERSION 3.5)
project(SoftwareRenderingPipeline)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -Wall -funroll-loops -Wextra -Winline -Wreturn-type -Wuninitialized -Winit-self -Werror -Wno-unused-parameter -Wno-unused-function")

find_package(ASSIMP REQUIRED)
find_package(SDL2 REQUIRED)

set(SOURCES
    src/camera.cpp
    src/display.cpp
    src/engine.cpp
    src/fragmentShader.cpp
    src/framebuffer.cpp
    src/graphicsPipeline.cpp
    src/main.cpp
    src/mesh.cpp
    src/model.cpp
    src/primitiveAssembler.cpp
    src/program.cpp
    src/rasterizer.cpp
    src/timer.cpp
    src/triangle.cpp
    src/vertex.cpp
    src/vertexShader.cpp
)

set(TARGET SoftwareRenderingPipeline)
add_executable(${TARGET} ${SOURCES})

include_directories(${ASSIMP_INCLUDE_DIRS}
                    ${SDL2_INCLUDE_DIRS})
target_link_libraries(${TARGET} ${ASSIMP_LIBRARIES} ${SDL2_LIBRARIES})

set(OBJS_SRC "${CMAKE_SOURCE_DIR}/obj")
set(OBJS_DST "$<TARGET_FILE_DIR:${TARGET}>/obj")

set(OBJS_CMD create_symlink)
set(OBJS_MSG "Link assets")

add_custom_command(
    TARGET ${TARGET} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo
    "${OBJS_MSG}: ${OBJS_SRC} to ${OBJS_DST}"
)
add_custom_command(
    TARGET ${TARGET} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E ${OBJS_CMD}
    "${OBJS_SRC}" "${OBJS_DST}"
)
