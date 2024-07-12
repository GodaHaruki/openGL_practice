#pragma once
#include <string>
#include <glad/glad.h>

#define SIMPLE_VERTEX_SHADER_PATH "../src/shaders/simple.vert"
#define SIMPLE_FRAGMENT_SHADER_PATH "../src/shaders/simple.frag"

class shader{
  public:
  shader(const char * vertex_file_path, const char * fragment_file_path);
  ~shader();

  void activate();

  private:
  GLuint _vertex_shader;
  GLuint _fragment_shader;
  GLuint _program;
};