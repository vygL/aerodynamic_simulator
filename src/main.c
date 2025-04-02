#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "linmath.h"

#include <stdio.h>

#include "setup.h"
#include "callback.h"

#include "test.c"


int main(int argc, char* argv[]) {
    GLFWwindow* window = default_setup();
    if (!window) {
        return -1;
    }
    
    while (!glfwWindowShouldClose(window)) {
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}