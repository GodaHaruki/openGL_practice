#include <fstream>
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include "shader.hpp"

inline bool is_compiled(GLuint shader_id){
  GLint result;
  int info_log_length;

  glGetShaderiv(shader_id, GL_COMPILE_STATUS, &result);
  if(result == GL_TRUE) return true;

  glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &info_log_length);

  std::vector<char> shader_error_message(info_log_length);
  glGetShaderInfoLog(shader_id, info_log_length, NULL, &shader_error_message[0]);
  
  std::cerr << "shader compile failed" << std::endl;
  std::string shader_error_message_string(shader_error_message.begin(), shader_error_message.end());
  std::cerr << shader_error_message_string << std::endl;

  return false;
}

inline GLuint compile_shader(GLuint shader_id, const char * shader_file_path){
  std::string shader_code;
  std::ifstream shader_stream(shader_file_path, std::ios::in);

  if(shader_stream.is_open()){
    std::string line;
    while(getline(shader_stream, line)){
      shader_code += line + "\n";
    }

    shader_stream.close();
  } else {
    std::string shader_file_path_string = shader_file_path;
    std::cerr << "can't open shader_file: " + shader_file_path_string << std::endl;
  }

  char const * shader_code_pointer = shader_code.c_str();
  glShaderSource(shader_id, 1, &shader_code_pointer, NULL);
  glCompileShader(shader_id);

  return shader_id;
}

shader::shader(const char * vertex_file_path, const char * fragment_file_path){
  _vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  compile_shader(_vertex_shader, vertex_file_path);
  is_compiled(_vertex_shader);

  _fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  compile_shader(_fragment_shader, fragment_file_path);
  is_compiled(_fragment_shader);

  _program = glCreateProgram();
  glAttachShader(_program, _vertex_shader);
  glAttachShader(_program, _vertex_shader);
  glLinkProgram(_program);

  GLint result;
  glGetProgramiv(_program, GL_LINK_STATUS, &result);
  
  if(!result){
    int info_log_length;
    glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &info_log_length);
    
    std::vector<char> program_error_message(info_log_length);
    glGetProgramInfoLog(_program, info_log_length, NULL, &program_error_message[0]);

    std::string program_error_message_string = &program_error_message[0];
    std::cerr << "make shader program failed" << std::endl;
    std::cerr << program_error_message_string << std::endl;
  }
}

shader::~shader(){
  glDeleteProgram(_program);
  glDeleteShader(_vertex_shader);
  glDeleteShader(_fragment_shader);
}

void shader::activate(){
  glUseProgram(_program);
}