#include "Model.h"

#include <cstring>

Model::Model() {
  memset(&vao, 0, sizeof(GLuint));
  memset(&vbo[0], 0, sizeof(GLuint) * 2);
}

Model::~Model() {
}

bool Model::load() {

  // clang-format off
  float positionData[]
      = { 
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
        };
   
  float colorData[]
      = { 1.0f, 0.0f, 0.0f,
          0.0f, 1.0f, 0.0f,
          0.0f, 0.0f, 1.0f 
        };
  // clang-format on
  
  //Create a vaO
  glGenVertexArrays(1,&vao);
  glGenBuffers(2, vbo);
  
  glBindVertexArray(vao);

  glBindBuffer(GL_ARRAY_BUFFER,vbo[0]);
  glEnableVertexAttribArray(0);
  glBindVertexBuffer(0,vbo[0],0,sizeof(float) * 3);
  glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
  glVertexAttribBinding(0,0);
  glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), positionData, GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
  glEnableVertexAttribArray(1);
  glBindVertexBuffer(1, vbo[1], 0, sizeof(float) * 3);
  glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 0);
  glVertexAttribBinding(1, 1);
  glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), colorData, GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER,0);
  glBindVertexArray(0);

  return true;
} 

void Model::render() {

  glBindVertexArray(vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}
