#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <stdio.h>

void error_callback(int error, const char* description) {
    fprintf(stdout, "GLFW Error: %s", description);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

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
    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);


    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    glViewport(0, 0, w, h);

    glfwSwapInterval(1);
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}