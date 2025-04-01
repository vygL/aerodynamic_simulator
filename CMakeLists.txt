cmake_minimum_required(VERSION 3.24)
project(aero_sim)

include_directories(
    include/
    extern/glad/include/
    extern/glfw/include/
)

find_package(OpenGL REQUIRED)
add_executable(aero_sim)

target_sources(
    aero_sim
    PRIVATE
    src/main.c
    extern/glad/src/glad.c
)

target_compile_features(
    aero_sim
    PRIVATE
    c_std_23
)


