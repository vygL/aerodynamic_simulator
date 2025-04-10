cmake_minimum_required(VERSION 3.24)
project(aero_sim)

include_directories(
    model/
    shader/
    include/
    extern/glad/include/
    extern/glfw/include/
    extern/linmath.h/
)

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )
set( GLAD_GL "" )

find_package(OpenGL REQUIRED)
add_executable(aero_sim)

add_subdirectory(
    extern/glfw
)

set (
    SOURCES
    src/main.c
    src/callback.c
    src/setup.c
    src/shader.c
)

target_sources(
    aero_sim
    PRIVATE
    ${SOURCES}
    extern/glad/src/glad.c
)

target_compile_features(
    aero_sim
    PRIVATE
    c_std_23
)

target_link_libraries(
    aero_sim
    glfw
    OpenGL::GL
)
