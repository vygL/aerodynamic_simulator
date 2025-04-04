#pragma once

#include "GLFW/glfw3.h"

#include <stdio.h>

void error_callback(int error, const char* description);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

void framebuffersize_callback(GLFWwindow* window, int width, int height);