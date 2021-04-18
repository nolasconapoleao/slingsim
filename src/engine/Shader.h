#pragma once
#ifdef _WIN64
	#include <Windows.h>
#endif // _WIN64

#include <string>

#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/matrix.hpp>

class Shader {
public:
  enum class SHADER_TYPE { VERTEX_SHADER = 0, FRAGMENT_SHADER = 1, COUNT = 2 };
  enum class MATRICES { MODEL_MATRIX = 0, VIEW_MATRIX = 1, PROJECTION_MATRIX = 2, COUNT = 3 };

  Shader();
  ~Shader();
  void init();
  bool create(const std::string &shader, SHADER_TYPE shaderType);
  void bind();
  void unbind();
  bool enable();
  void disable();
  void sendUniform(glm::mat4 matrix, MATRICES matrixCode);
  void sendUniform(glm::vec3 matrix, int code);
  void uniformInit(std::string matrixName, MATRICES matrixCode);
  int uniformInit(std::string matrixName);

private:
  // TODO: [FILESYSTEM] remove loadFileAsString and put it in the filesystem handler
  std::string loadFileAsString(const std::string &filepath);
  GLuint createShaderIndex(SHADER_TYPE shaderType);
  bool isCompilationValid(SHADER_TYPE shaderType);
  bool isLinkingValid();

  GLuint mIndex;
  GLuint mShaderIndexes[static_cast<unsigned int>(SHADER_TYPE::COUNT)];
  GLint mMatricesIndexes[static_cast<unsigned int>(MATRICES::COUNT)];
  bool mIsEnabled;
  bool mInited;
};
