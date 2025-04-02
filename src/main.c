#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "linmath.h"

#include <stdio.h>
#include <unistd.h>

#include "setup.h"
#include "callback.h"
#include "shader.h"

#include "test.c"


int main(int argc, char* argv[]) {
    char cwd[512];
    getcwd(cwd, 512);

    GLFWwindow* window = default_setup();
    if (!window) {
        return -1;
    }

    unsigned int VBO, VAO;
    unsigned int shaderID;

    char vertexPath[512], fragmentPath[512];
    strcpy(vertexPath, "../shader/vertex.glsl\0");
    strcpy(fragmentPath, "../shader/fragment.glsl\0");

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(mTriangle), mTriangle, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    shaderID = createShaderProgram(vertexPath, fragmentPath);


    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(shaderID);
        
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}