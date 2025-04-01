#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <stdio.h>

void error_callback(int error, const char* description) {
    fprintf(stderr, "GLFW Error: %s", description);
}

int main(int argc, char* argv[]) {
    if (!glfwInit()) {
        fprintf(stderr, "%s", "Failed to Initialized GLFW");
    }
    glfwSetErrorCallback(error_callback);

    const char* pName = "AeroSim";
    int wWidth = 800;
    int wHeight = 600;
    GLFWwindow* window = glfwCreateWindow(wWidth, wHeight, pName, NULL, NULL);
    if (!window) {
        fprintf(stderr, "%s", "Failed to Initialized Window");
    }
    glfwTerminate();
    return 0;
}