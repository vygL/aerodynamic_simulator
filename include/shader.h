#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <stdio.h>
#include <stdlib.h>

unsigned int createShaderProgram(const char* vertexPath, const char* fragmentPath);
void setBool(GLuint programID, const char* name, int value);
void setInt(GLuint programID, const char* name, int value);
void setFloat(GLuint programID, const char* name, float value);