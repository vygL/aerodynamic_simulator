#include "setup.h"


GLFWwindow* default_setup() {
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        fprintf(stderr, "%s", "Failed to Initialized GLFW");
        return NULL;
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
        return NULL;
    }
    glfwSetFramebufferSizeCallback(window, framebuffersize_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "%s", "Failed to load GLAD");
        return NULL;
    }
    glfwSwapInterval(1);


    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    glViewport(0, 0, w, h);

    return window;
}