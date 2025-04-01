cmake_minimum_required(VERSION 3.24)
project(aero_sim)

include_directories(
    include/
    extern/
)

find_package(OpenGL REQUIRED)
add_executable(aero_sim)

target_sources(
    aero_sim
    PRIVATE
    src/main.c
)

target_compile_features(
    aero_sim
    PRIVATE
    c_std_23
)


