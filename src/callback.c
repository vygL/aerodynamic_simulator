#include "callback.h"


void error_callback(int error, const char* description) {
    fprintf(stdout, "GLFW Error: %s", description);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void framebuffersize_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
