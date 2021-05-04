#include "Shader.h"

#include <cstring>
#include <fstream>
#include <iostream>

#include <glm/gtc/type_ptr.hpp>

Shader::Shader() : mIsEnabled{false} {
  memset(&mShaderIndexes[0], 0, sizeof(GLuint) * static_cast<unsigned int>(SHADER_TYPE::COUNT));
  memset(&mMatricesIndexes[0], -1, sizeof(GLint) * static_cast<unsigned int>(MATRICES::COUNT));
}

Shader::~Shader() {

  if (mIsEnabled) {
    for (unsigned int i = 0; i < static_cast<unsigned int>(SHADER_TYPE::COUNT); i++) {
      glDetachShader(mIndex, mShaderIndexes[i]);
      glDeleteShader(mShaderIndexes[i]);
      glDeleteProgram(mIndex);
    }
  }
}

void Shader::bind() {
  glUseProgram(mIndex);
}

void Shader::unbind() {
  glUseProgram(0);
}

bool Shader::create(const std::string &shader, SHADER_TYPE shaderType) {

  bool status = false;

  if (mInited) {
    std::string shaderFileString = loadFileAsString(shader);
    mShaderIndexes[static_cast<unsigned int>(shaderType)] = createShaderIndex(shaderType);
    const char *shaderCString = shaderFileString.c_str();
    glShaderSource(mShaderIndexes[static_cast<unsigned int>(shaderType)], 1, &shaderCString, nullptr);
    glCompileShader(mShaderIndexes[static_cast<unsigned int>(shaderType)]);

    status = isCompilationValid(shaderType);

    glAttachShader(mIndex, mShaderIndexes[static_cast<unsigned int>(shaderType)]);
  }
  return status;
} 

GLuint Shader::createShaderIndex(SHADER_TYPE shaderType) {
  GLuint shaderIndex;

  switch (shaderType) {
    case SHADER_TYPE::VERTEX_SHADER: {
      shaderIndex = glCreateShader(GL_VERTEX_SHADER);
    } break;
    case SHADER_TYPE::FRAGMENT_SHADER: {
      shaderIndex = glCreateShader(GL_FRAGMENT_SHADER);
    } break;
    default:
      shaderIndex = 0;
  }

  return shaderIndex;
}

std::string Shader::loadFileAsString(const std::string &filepath) {
  std::ifstream ifs(filepath);
  return std::string(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());
}

bool Shader::isCompilationValid(SHADER_TYPE shaderType) {

  bool isValid = true;
  GLint result;
  glGetShaderiv(mShaderIndexes[static_cast<unsigned int>(shaderType)], GL_COMPILE_STATUS, &result);
  if (result == GL_FALSE) {
    GLint loglen;
    glGetShaderiv(mShaderIndexes[static_cast<unsigned int>(shaderType)], GL_INFO_LOG_LENGTH, &loglen);
    if (loglen > 0) {
      std::string log(loglen, ' ');
      GLsizei written;
      glGetShaderInfoLog(mShaderIndexes[static_cast<unsigned int>(shaderType)], loglen, &written, &log[0]);
      std::cout << "Shader Log:\n" << log;
    }
    isValid = false;
  }
  return isValid;
}

bool Shader::isLinkingValid() {
  bool isValid = true;
  GLint result;
  glGetProgramiv(mIndex, GL_LINK_STATUS, &result);
  if (result == GL_FALSE) {
    GLint loglen;
    glGetProgramiv(mIndex, GL_INFO_LOG_LENGTH, &loglen);
    if (loglen > 0) {
      std::string log(loglen, ' ');
      GLsizei written;
      glGetProgramInfoLog(mIndex, loglen, &written, &log[0]);
      std::cout << "Program Log:\n" << log;
    }
    isValid = false;
  }
  return isValid;
}

void Shader::init() {
  if (!mInited) {
    mIndex = glCreateProgram();
    mInited = true;
  }
}

bool Shader::enable() {
  bool status = false;

  if (mInited) {
    glLinkProgram(mIndex);

    bool status = isLinkingValid();

    for (unsigned int i = 0; i < static_cast<unsigned int>(SHADER_TYPE::COUNT); i++) {
      glDetachShader(mIndex, mShaderIndexes[i]);
      glDeleteShader(mShaderIndexes[i]);
    }
    mIsEnabled = true;
  }
  return status;
}

void Shader::sendUniform(glm::mat4 matrix, MATRICES matrixCode) {
  if (mInited && mIsEnabled) {
    if (mMatricesIndexes[static_cast<unsigned int>(matrixCode)] >= 0) {
      glUniformMatrix4fv(mMatricesIndexes[static_cast<unsigned int>(matrixCode)], 1, GL_FALSE, glm::value_ptr(matrix));
    }
  }
}

void Shader::sendUniform(glm::vec3 data, int code) {
  if (mInited && mIsEnabled) {
    if (code >= 0) {
      glUniform3fv(code, 1, glm::value_ptr(data));
    }
  }
}

int Shader::uniformInit(std::string matrixName) {
  if (mInited && mIsEnabled) {
    return glGetUniformLocation(mIndex, matrixName.c_str());
  }
}

void Shader::uniformInit(std::string matrixName, MATRICES matrixCode) {
  if (mInited && mIsEnabled) {
    mMatricesIndexes[static_cast<unsigned int>(matrixCode)] = glGetUniformLocation(mIndex, matrixName.c_str());
  }
}

void Shader::disable() {
  if (mInited) {
    glDeleteProgram(mIndex);
    mInited = false;
  }
}
