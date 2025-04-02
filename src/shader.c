#include "shader.h"

long getFileSize(const char* filePath) {
    FILE* file;
    long len;
    
    file = fopen(filePath, "r");
    if (!file) {
        fprintf(stderr, "%s", "Unable to open file");
        exit(-1);
    }
    if (fseek(file, 0, SEEK_END) == 0) {
        len = ftell(file);
        if (len == -1) {
            fprintf(stderr, "%s", "Unable to read file size");
            exit(-1);
        }
    }

    fclose(file);

    return len;
}

void readFileIntoBuffer(const char* filePath, long fileSize, char* strbuf) {
    FILE* file;
    size_t newLen;

    file = fopen(filePath, "r");
    if (!file) {
        fprintf(stderr, "%s", "Unable to open shader file");
        exit(-1);
    }
    newLen = fread(strbuf, 1, fileSize, file);
    if (ferror(file) != 0) {
        fprintf(stderr, "%s", "Error reading file");
        exit(-1);
    }
    strbuf[newLen++] = '\0';

    fclose(file);
}

unsigned int createShader(GLenum shaderType, const char* shaderSource) {
    unsigned int s;
    int success;
    char infoLog[512];


    s = glCreateShader(shaderType);
    glShaderSource(s, 1, &shaderSource, NULL);
    glCompileShader(s);
    glGetShaderiv(s, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(s, 512, NULL, infoLog);
        fprintf(stderr, "%s", infoLog);
        exit(-1);
    }
    return s;
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
        exit(-1);
    }
}

unsigned int createShaderProgram(const char* vertexPath, const char* fragmentPath) {
    unsigned int id;
    unsigned int v, f;
    char* vSource;
    char* fSource;

    int success;
    char infoLog[512];

    long vFileSize, fFileSize;
    
    vFileSize = getFileSize(vertexPath);
    fFileSize = getFileSize(fragmentPath);

    vSource = malloc(vFileSize);
    fSource = malloc(fFileSize);

    readFileIntoBuffer(vertexPath, vFileSize, vSource);
    readFileIntoBuffer(fragmentPath, fFileSize, fSource);

    v = createShader(GL_VERTEX_SHADER, vSource);
    f = createShader(GL_FRAGMENT_SHADER, fSource);

    id = glCreateProgram();
    linkShaders(id, v, f);

    free(vSource);
    free(fSource);
    return id;
}

void setBool(GLuint programID, const char* name, int value) {
    glUniform1i(glGetUniformLocation(programID, name), value);
}

void setInt(GLuint programID, const char* name, int value) {
    glUniform1i(glGetUniformLocation(programID, name), value);
}

void setFloat(GLuint programID, const char* name, float value) {
    glUniform1f(glGetUniformLocation(programID, name), value);
}