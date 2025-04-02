#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "linmath.h"

#include <stdio.h>

#include "callback.h"

#include "test.c"


int main(int argc, char* argv[]) {
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        fprintf(stderr, "%s", "Failed to Initialized GLFW");
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    const char* pName = "AeroSim";
    int wWidth = 800;
    int wHeight = 600;
    GLFWwindow* window = glfwCreateWindow(wWidth, wHeight, pName, NULL, NULL);
    if (!window) {
        fprintf(stderr, "%s", "Failed to Initialized Window");
        return -1;
    }
    glfwSetFramebufferSizeCallback(window, framebuffersize_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "%s", "Failed to load GLAD");
        return -1;
    }
    glfwSwapInterval(1);


    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    glViewport(0, 0, w, h);



    while (!glfwWindowShouldClose(window)) {
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}