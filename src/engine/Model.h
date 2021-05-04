#pragma once
#ifdef _WIN64
	#include <Windows.h>
#endif // _WIN64

#include <GL/glew.h>
#include <GL/gl.h>

class Model {
public:
  Model();
  ~Model();
  bool load();
  void render();
private:
  GLuint vao;
  GLuint vbo[2];
};
