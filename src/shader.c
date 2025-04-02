#include "shader.h"

void readFileIntoBuffer(const char* filePath, char* strbuf) {
    FILE* file;
    size_t newLen;

    file = fopen(filePath, "r");
    if (!file) {
        fprintf(stderr, "%s", "Unable to open shader file");
        return -1;
    }
    if (fseek(file, 0, SEEK_END) == 0) {
        long fSize = ftell(file);
        if (fSize == -1) {
            fprintf(stderr, "%s", "Unable to read file size");
            return -1;
        }
        rewind(file);
        strbuf = malloc(fSize + 1);
        newLen = fread(strbuf, 1, fSize, file);
        if (ferror(file) != 0) {
            fprintf(stderr, "%s", "Error reading file");
            return -1;
        }
        strbuf[newLen++] = '\0';
    }
    fclose(file);
}

unsigned int createShader(GLenum shaderType, const char* shaderSource) {
    unsigned int s;
    int success;
    char infoLog[512];


    s = glCreateShader(shaderType);
    glShaderSource(s, 1, shaderSource, NULL);
    glCompileShader(s);
    glGetShaderiv(s, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(s, 512, NULL, infoLog);
        fprintf(stderr, "%s", infoLog);
        return -1;
    }
}

void linkShaders(GLuint programID, GLuint vShader, GLuint fShader) {
    int success;
    char infoLog[512];


    glAttachShader(programID, vShader);
    glAttachShader(programID, fShader);
    glLinkProgram(programID);
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(programID, 512, NULL, infoLog);
        fprintf(stderr, "%s", infoLog);
    }
}

unsigned int createShaderProgram(const char* vertexPath, const char* fragmentPath) {
    unsigned int id;
    unsigned int v, f;
    char* vSource, fSource;
    int success;
    char infoLog[512];


    readFileIntoBuffer(vertexPath, vSource);
    readFileIntoBuffer(fragmentPath, fSource);

    v = createShader(GL_VERTEX_SHADER, vSource);
    f = createShader(GL_FRAGMENT_SHADER, fSource);

    id = glCreateProgram();
    linkShaders(id, v, f);

    free(vSource);
    free(fSource);
    return id;
}

void setBool(const char* name, int value) {

}

void setInt(const char* name, int value) {

}

void setFloat(const char* name, float value) {
    
}