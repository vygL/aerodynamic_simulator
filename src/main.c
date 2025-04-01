#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

void error_callback(int error, const char* description) {
    fprintf(stderr, "GLFW Error: %s", description);
}

int main(int argc, char* argv[]) {
    if (!glfwInit()) {
        fprintf(stderr, "%s", "Failed to Initialized GLFW");
    }
    glfwSetErrorCallback(error_callback);
    glfwTerminate();
    return 0;
}