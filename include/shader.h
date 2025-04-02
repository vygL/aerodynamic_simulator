#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <stdio.h>
#include <stdlib.h>

unsigned int createShaderProgram(const char* vertexPath, const char* fragmentPath);
void setBool(const char* name, int value);
void setInt(const char* name, int value);
void setFloat(const char* name, float value);